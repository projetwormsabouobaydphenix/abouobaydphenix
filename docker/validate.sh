#!/bin/bash

function run_command() {
    local DESCRIPTION=$1
    shift 1
    local ARGS=("$@")
    echo -e "\e[1;34m *** $DESCRIPTION *** \e[0;0m"

    "${ARGS[@]}" || exit 2

    echo
}

if [ -z "$1" ]; then
    echo "Utilisation:"
    echo "  $0 <nom du conteneur docker> [<tag à tester>] [<dossier des scripts>] [<ignore check_repo.sh>]"
    exit 2
fi
TEAM_CONTAINER=$1
CURRENT_TAG=$2
SCRIPTS_DIR="$3"
IGNORE_CHECK_REPO=$4

TEAM_REPO_DIR=$(pwd)
if [ -z "$SCRIPTS_DIR" ]; then
    SCRIPTS_DIR=${TEAM_REPO_DIR}/docker
fi

if [ ! -d ".git" ]; then
    echo "Doit être exécuté dans le dossier git"
    exit 2
fi

if [ ! -f "${SCRIPTS_DIR}/check_repo.sh" ]; then
    echo "Le fichier ${SCRIPTS_DIR}/check_repo.sh n'a pas été trouvé"
    exit 2
fi


docker ps -q --filter name=$TEAM_CONTAINER
if [ ! -z "$(docker ps -qa --filter name=$TEAM_CONTAINER)" ]; then
    run_command "Supprime l'ancien conteneur" docker rm -f $TEAM_CONTAINER
    if [ $? -ne 0 ]; then
        exit 2;
    fi
fi

run_command 'Lance un nouveau conteneur' docker run \
    --workdir='/home/plt' \
    --network='none' \
    --name "$TEAM_CONTAINER" \
    --env="DISPLAY=$DISPLAY" \
    --volume="/etc/group:/etc/group:ro" \
    --volume="/etc/passwd:/etc/passwd:ro" \
    --volume="/etc/shadow:/etc/shadow:ro" \
    --volume="/etc/sudoers.d:/etc/sudoers.d:ro" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    -itd plt-initial
if [ $? -ne 0 ]; then
    exit 2;
fi
run_command 'Copie le dépôt vers le conteneur' docker cp "$TEAM_REPO_DIR" $TEAM_CONTAINER:/home/tmp
if [ $? -ne 0 ]; then
    exit 2;
fi
run_command 'Clone le dépôt' docker exec "$TEAM_CONTAINER" /bin/bash -c "git clone /home/tmp /home/plt"
if [ $? -ne 0 ]; then
    exit 2;
fi

if [ ! -z "$CURRENT_TAG" ]; then
    run_command "Checkout vers le tag $CURRENT_TAG" docker exec "$TEAM_CONTAINER" /bin/bash -c "cd /home/plt && git checkout -q $CURRENT_TAG"
    if [ $? -ne 0 ]; then
        exit 2;
    fi
fi
run_command 'Copie le script de vérification vers le conteneur' docker cp "$SCRIPTS_DIR/check_repo.sh" $TEAM_CONTAINER:/home/plt
if [ $? -ne 0 ]; then
    exit 2;
fi

run_command "Donne les droits à $USER" docker exec "$TEAM_CONTAINER" /bin/bash -c "cd /home && chown -R $USER:$USER plt"
if [ $? -ne 0 ]; then
    exit 2;
fi

if [ -z "$IGNORE_CHECK_REPO" ]; then
    run_command 'Vérifie le contenu du dépôt' docker exec --user=$(id -u $USER):$(id -g $USER) "$TEAM_CONTAINER" /bin/bash -c "cd /home/plt && ./check_repo.sh"
    if [ $? -ne 0 ]; then
        exit 2;
    fi
fi

if [ -d extern ]; then
    run_command 'Compile les dépendances externes (make extern)' docker exec --user=$(id -u $USER):$(id -g $USER) "$TEAM_CONTAINER" /bin/bash -c 'cd /home/plt && make extern'
    if [ $? -ne 0 ]; then
        exit 2;
    fi
fi

run_command 'Configure (make configure)' docker exec --user=$(id -u $USER):$(id -g $USER) "$TEAM_CONTAINER" /bin/bash -c 'cd /home/plt && make configure'
if [ $? -ne 0 ]; then
    exit 2;
fi
run_command 'Compile (make build)' docker exec --user=$(id -u $USER):$(id -g $USER) "$TEAM_CONTAINER" /bin/bash -c 'cd /home/plt && make build'
if [ $? -ne 0 ]; then
    exit 2;
fi


