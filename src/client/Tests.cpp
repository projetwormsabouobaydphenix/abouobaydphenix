

#include "Tests.h"
#include "engine/MoveCharCommand.h"
#include "state/ElementTab.h"
#include <SFML/Graphics.hpp>
#include "../shared/state.h"
#include <vector>
#include "../shared/ai.h"
#include "../shared/engine.h"
#include "render.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <fstream>
#include <SFML/Network.hpp>
#include <sstream>
#define LIMITE_FRAME 60

using namespace sf;
using namespace std;
using namespace state;
using namespace render;
using namespace ai;
using namespace engine;

mutex commands_mutex;
extern int nbJoueurs;
int i = 0;
Tests::Tests() {
}

void Tests::test_state() {
    cout << "Tests des états" << endl;
    cout << "Création d'une grille" << endl;
    ElementTab grille(0, 1);
    //Personnage* perso;
    //perso = new Personnage; 
    cout << "Vérifie que la largeur est nulle" << endl;
    // vérification de la largeur
    size_t largeur = grille.getWidth();
    if (largeur == 0) {
        cout << "La largeur est nulle" << endl;
    } else {
        cout << "La largeur n'est pas nulle" << endl;
    }

    cout << "Vérifie que la largeur est 1" << endl;
    size_t l2 = grille.getWidth();
    if (l2 == 1) {
        cout << "Largeur = 1" << endl;
    } else {
        cout << "Largeur différente de 1" << endl;
    }


    //Personnage* ptt; 
    //Floor floor;
    //Space s;
    cout << "Ajout d'un élement dans la grille" << endl;

    // size_t add = grille.add(fl);

    cout << "On vérifie que la largeur a changé :";
    /*if (add == 1){
        cout << "OK" << endl;
    }
    else{
        cout << "not ok" << endl;
    }*/
    cout << "Tests sur la grille" << endl;
    cout << "Redimmensionne en 5 par 7" << endl;
    grille.resize(5, 7);
    cout << "Vérifie que la largeur est correcte : ";
    if (grille.getWidth() == 5) {
        cout << "OK" << endl;
    } else {
        cout << "Not OK" << endl;
    }

    cout << "Vérifie que la hauteur est correcte : ";
    if (grille.getHeight() == 7) {
        cout << "OK" << endl;
    } else {
        cout << "Not OK" << endl;
    }

    //cout << "Vérifie que toutes les cases sont nulles ";
}

void Tests::test_render() {
    cout << "Test render" << endl;
    sf::RenderWindow window(sf::VideoMode(800, 384), "Worms");

    state::State state;

    ElementTab& grid = state.getGrid();
    ElementTab& chars = state.getChars();
    grid.resize(25, 12);
    chars.resize(25, 12);
    vector<int> vcarte = state.getGrid().load("res/heuristic_ai.txt");
    vector<int> pcarte = state.getChars().load("res/personnage_render.txt");
    //cout << vcarte.size() << endl;
    // cout << pcarte.size() << endl;


    for (int i = 0; i < (int) vcarte.size(); i++) {
        //cout << vcarte[i] << endl;
        if (vcarte[i] == 0) {
            //cout << "vcarte[i] = 0" << endl;
            Element* empty = new Space(SpaceTypeId::EMPTY);
            empty->setI(i % 25);
            empty->setJ(i / 25);
            grid.set(i % 25, i / 25, empty);
        } else if (vcarte[i] == 1) {
            //cout << "vcarte[i] = 1" << endl;
            Element* ground = new Floor(state::FloorTypeId::GROUND);
            ground->setI(i % 25);
            ground->setJ(i / 25);
            grid.set(i % 25, i / 25, ground);
        } else if (vcarte[i] == 2) {
            //cout << "vcarte[i] = 2" << endl;
            Element* grass = new Floor(state::FloorTypeId::GRASS);
            grass->setI(i % 25);
            grass->setJ(i / 25);
            grid.set(i % 25, i / 25, grass);
        } else if (vcarte[i] == 3) {
            //cout << "vcarte[i] = 3" << endl;
            Element* water = new Space(state::SpaceTypeId::WATER);
            water->setI(i % 25);
            water->setJ(i / 25);
            grid.set(i % 25, i / 25, water);
        } else if (vcarte[i] == 4) {
            Element* life = new Space(state::SpaceTypeId::LIFE);
            life->setI(i % 25);
            life->setJ(i / 25);
            grid.set(i % 25, i / 25, life);
        }

    }


    for (int i = 0; i < (int) pcarte.size(); i++) {
        //cout << vcarte[i] << endl;

        if (pcarte[i] == 1) { //vert gauche
            //cout << "vcarte[i] = 1" << endl;
            Element* vg = new Personnage(1, Direction::LEFT);
            vg->setI(i % 25);
            vg->setJ(i / 25);
            chars.set(i % 25, i / 25, vg);
        } else if (pcarte[i] == 2) { //vert droite
            //cout << "vcarte[i] = 2" << endl;
            Element* vd = new Personnage(1, Direction::RIGHT);
            vd->setI(i % 25);
            vd->setJ(i / 25);
            chars.set(i % 25, i / 25, vd);
        } else if (pcarte[i] == 3) { //noir gauche
            //cout << "vcarte[i] = 3" << endl;
            Element* ng = new Personnage(2, Direction::LEFT);
            ng->setI(i % 25);
            ng->setJ(i / 25);
            chars.set(i % 25, i / 25, ng);
        } else if (pcarte[i] == 4) { //noir droite
            Element* nd = new Personnage(2, Direction::RIGHT);
            nd->setI(i % 25);
            nd->setJ(i / 25);
            chars.set(i % 25, i / 25, nd);
        } else {
            chars.set(i % 25, i / 25, NULL);
        }
    }

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());



    while (window.isOpen()) {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();
    }

}

void Tests::test_engine() {
    Engine moteur;
    State& state = moteur.getState();

    Command* init = new LoadCommand("res/heuristic_ai.txt");
    moteur.addCommand(0, init);
    moteur.update();

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 384), "Test Worms");

    cout << "Appuyez sur Espace pour faire défiler les époques" << endl;
    int epoche = 0;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == Keyboard::Space) {
                    epoche = epoche + 1;

                    if (epoche == 1) {
                        cout << "Epoque " << epoche << endl;
                        Command* move = new MoveCharCommand(2, Direction::LEFT);
                        moteur.addCommand(0, move);
                        cout << "Le personnage noir s'est déplacé : OK" << endl;
                    }
                    if (epoche == 2) {
                        cout << "Epoque " << epoche << endl;
                        Command* move = new MoveCharCommand(2, Direction::LEFT);
                        moteur.addCommand(0, move);
                        cout << "Le personnage noir s'est déplacé : OK" << endl;
                    }
                    if (epoche == 3) {
                        cout << "Epoque " << epoche << endl;
                        cout << "Le personnage noir va tirer" << endl;
                        Command* shoot = new ShootCommand(2);
                        moteur.addCommand(0, shoot);
                    }
                    if (epoche == 4) {
                        cout << "Epoque " << epoche << endl;
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                        cout << "Le personnage vert s'est déplacé : OK" << endl;

                    }
                    if (epoche == 5) {
                        cout << "Epoque " << epoche << endl;
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                        cout << "Le personnage vert s'est déplacé : OK" << endl;
                    }
                    if (epoche == 6) {
                        cout << "Epoque " << epoche << endl;
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                        cout << "Le personnage vert s'est déplacé : OK" << endl;
                    }
                    if (epoche == 7) {
                        cout << "Epoque " << epoche << endl;
                        cout << "Le personnage vert va tirer" << endl;
                        Command* shoot = new ShootCommand(1);
                        moteur.addCommand(0, shoot);
                    }
                    if (epoche == 8) {
                        cout << "Epoque " << epoche << endl;
                        return;

                    }
                    if (epoche == 9) {
                        cout << "Epoque " << epoche << endl;
                        return;
                    }
                    if (epoche == 10) {
                        cout << "Epoque " << epoche << endl;
                    }

                }

            }
        }

        moteur.update();

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();
    }

}

void Tests::test_heuristic_ai() {
    cout << "debut test hai" << endl;
    Engine moteur;
    State& state = moteur.getState();

    Command* init = new LoadCommand("res/heuristic_ai.txt");
    moteur.addCommand(0, init);
    moteur.update();
    //init->execute(state);

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());

    sf::RenderWindow window;
    window.setFramerateLimit(LIMITE_FRAME);
    window.create(sf::VideoMode(800, 384), "Test Worms");
    cout << "Bienvenue sur le jeu worms" << endl;
    cout << "Le personnage vert n'a qu'une seule vie. Normalement, il doit en récupérer s'il ne veut pas mourir" << endl;
    cout << "Appuyez sur Espace pour faire défiler" << endl;
    //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
    HeuristicAI heuristic(state, 2);
    int i = 0;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == Keyboard::Space) {
                    heuristic.run(moteur, 2);

                }
                if (event.key.code == Keyboard::Return) {
                    i = i + 1;
                    if (i == 1) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                    } else if (i == 2) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                    } else if (i == 3) {
                        cout << "Le personnage vert va tirer" << endl;
                        Command* shoot = new ShootCommand(1);
                        moteur.addCommand(0, shoot);
                    }
                }
            }
        }


        moteur.update();

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();

    }
}

void Tests::test_random_ai() {
    RandomAI* rai = new RandomAI();
    Engine moteur;
    State& state = moteur.getState();

    //stack<shared_ptr<Action> >& actions   ;

    // initialisation de l'état
    Command* init = new LoadCommand("res/heuristic_ai.txt");
    moteur.addCommand(0, init);
    moteur.update();
    //init->execute(state);

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 384), "Jeu Worms");

    //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
    //cout << "Appuyez sur la touche T pour tirer" << endl;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        rai->run(moteur, 1);


        moteur.update();


        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();
    }
}

void Tests::test_rollback() {

    cout << "debut test hai" << endl;
    Engine moteur;
    State& state = moteur.getState();

    // initialisation de l'état
    Command* init = new LoadCommand("res/heuristic_ai.txt");
    moteur.addCommand(0, init);
    moteur.update();
    //init->execute(state);

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());
    stack<shared_ptr < Action>> actions;
    stack<shared_ptr < Action>> actionsTmp;
    vector<shared_ptr < Action>> vectActions;

    sf::RenderWindow window;
    window.setFramerateLimit(LIMITE_FRAME);
    window.create(sf::VideoMode(800, 384), "Test Worms");
    cout << "Bienvenue sur le jeu worms" << endl;
    //cout << "Le personnage vert n'a qu'une seule vie. Normalement, il doit en récupérer s'il ne veut pas mourir" << endl;
    cout << "Appuyez sur Entrée pour faire défiler" << endl;
    cout << "Appuyez sur BackSpace pour revenir en arrière" << endl;
    //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
    HeuristicAI heuristic(state, 2);
    int i = 0;
    //int k = 0;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == Keyboard::N) {
                    cout << "Appuyez sur Entrée pour faire défiler" << endl;
                    cout << "Appuyez sur BackSpace pour revenir en arrière" << endl;
                    //cout << "" << endl;
                    /*i = i + 1;
                    if (i == 1) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(0, move);
                    } else if (i == 2) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(1, move);
                    } else if (i == 3) {
                        Command* move = new MoveCharCommand(2, Direction::LEFT);
                        moteur.addCommand(2, move);
                    } else if (i == 4) {
                        Command* move = new MoveCharCommand(2, Direction::RIGHT);
                        moteur.addCommand(2, move);
                    } else if (i == 5) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        moteur.addCommand(2, move);
                    } */
                    heuristic.run(moteur, 2);
                } else if (event.key.code == Keyboard::V) {
                    i = i + 1;
                    if (i == 1) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        cout << "move1" << endl;
                        moteur.addCommand(0, move);
                    } else if (i == 2) {
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        cout << "move2" << endl;
                        moteur.addCommand(0, move);
                    } else if (i == 3) {
                        cout << "Le personnage vert va tirer" << endl;
                        Command* shoot = new ShootCommand(1);
                        moteur.addCommand(0, shoot);
                    }
                }

                    //sleep(milliseconds(1000));

                else if (event.key.code == Keyboard::BackSpace) {
                    cout << "il y a " << actionsTmp.size() << "actions" << endl;
                    moteur.undoe(actionsTmp);
                    //i = 0;
                    //actions.pop()
                    //sleep(milliseconds(1000));
                }

            }
        }
        actionsTmp = moteur.update();
        //                int lActions = (int) actionsTmp.size();
        // cout<<"nbre actions tempo"<<actionsTmp.size()<<endl;
        /*for (int i = 0; i < lActions; i++) {
            vectActions.push_back(actionsTmp.top());
            actionsTmp.pop();
        }
       // cout<<"taille de vectActions : "<<vectActions.size()<<endl;
        for (int j = 0; j < (int) vectActions.size(); j++) {
            int n = (int) vectActions.size();
            actions.push(vectActions[n - j - 1]);
        }
       // cout<<"taille de actions : "<<actions.size()<<endl;
        vectActions.clear();*/



        //moteur.update();

        // moteur.undo(actions);

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();


    }
}

void Tests::thread_secondaire(engine::Engine& moteur, int color) {
    State& state = moteur.getState();
    HeuristicAI heuristicnoir(state, 2);
    HeuristicAI heuristicvert(state, 1);
    //int nbreaction =0;

    while (1) {
        int nbreaction = 0;
        if (color == 1) {
            while (nbreaction < 4) {
                {
                    lock_guard<mutex> lock(commands_mutex);
                    cout << "heuristic vert" << endl;
                    heuristicvert.run(moteur, 1);
                    nbreaction += 1;
                }
                this_thread::sleep_for(chrono::seconds(1));

            }
            color = 2;
        } else if (color == 2) {
            while (nbreaction < 3) {
                {
                    lock_guard<mutex> lock(commands_mutex);
                    cout << "heuristic noir" << endl;
                    heuristicnoir.run(moteur, 2);
                    nbreaction += 1;
                }
                this_thread::sleep_for(chrono::seconds(1));
            }
            color = 1;
        } else {
            cout << "erreur la couleur n'est pas bonne" << endl;
        }

        //cout<<"le personnage qui va jouer est "<<color<<endl;
        //1sleep(milliseconds(1000));
    }
}

void Tests::test_thread() {
    cout << "debut test thread" << endl;
    Engine moteur;
    State& state = moteur.getState();

    Command* init = new LoadCommand("res/heuristic_ai.txt");
    moteur.addCommand(0, init);
    moteur.update();

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());

    sf::RenderWindow window;
    window.setFramerateLimit(LIMITE_FRAME);
    window.create(sf::VideoMode(800, 384), "Test Worms");
    cout << "Bienvenue sur le jeu worms" << endl;
    /*cout << "Le personnage vert n'a qu'une seule vie. Normalement, il doit en récupérer s'il ne veut pas mourir" << endl;
    cout << "Appuyez sur Espace pour faire défiler" << endl;*/

    int color = 1;
    thread th_second(&Tests::thread_secondaire, this, ref(moteur), ref(color));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        lock_guard<mutex> lock(commands_mutex);

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();

        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();

    }
    th_second.join();

}

void Tests::test_play() {

    Engine moteur;
    State& state = moteur.getState();

    ifstream ifs("res/replay.txt");
    int i = 0;
    Json::Reader reader;
    Json::Value obj;
    Json::Value in;
    Json::Value inn;
    reader.parse(ifs, obj); // reader can also read strings
    //cout << obj[0].toStyledString() << endl;
    inn = obj[1];
    stack<shared_ptr < Action>> actions;
    // initialisation de l'état
    Command* init = new LoadCommand("res/heuristic_ai.txt");
    init->deserialize(obj[0][0]);
    //moteur.addCommand(0, init);
    moteur.update();
    init->execute(state, actions);

    Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());


    sf::RenderWindow window;
    window.setFramerateLimit(LIMITE_FRAME);
    window.create(sf::VideoMode(800, 384), "Test Worms");
    cout << "Bienvenue sur le jeu worms" << endl;
    cout << "Appuyez sur Entrée pour faire défiler" << endl;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == Keyboard::Return) {
                    if (i != (int) inn.size()) {
                        //cout << "i = " << i << endl;
                        //Command* comm;
                        Json::Value in = inn[i];
                        //cout << in.toStyledString() << endl;
                        //cout<<"voila<"<<in["commande"].asString()<<endl;
                        cout << "Commande = " << in["commande"].asString() << endl;

                        if (in["commande"].asString() == "MoveCharCommand") {
                            MoveCharCommand* move = new MoveCharCommand(1, Direction::LEFT);


                            //moteur.addCommand(0, move->deserialize(in));
                            //moteur.update();
                            move->deserialize(in);
                            //cout << "test move " << endl;

                            move->execute(state, actions);
                        } else if (in["commande"].asString() == "ShootCommand") {
                            ShootCommand* shoot = new ShootCommand(1);
                            shoot->deserialize(in);
                            moteur.addCommand(0, shoot);
                            moteur.update();
                        }
                        cout << " " << endl;
                        i++;
                    } else {
                        cout << "Plus de commande" << endl;
                        return;
                    }



                }

            }
        }


        //moteur.update();
        layer1->initSurface();
        window.draw(*(layer1->getSurface()));

        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();
    }
}

void Tests::test_network() {
    
    std::vector<sf::Http::Response> tabResponse;
    
    while(i != 2){
    string color;
    cout << "Entrez la couleur du joueur que vous voulez ajouter " << endl;
    cin >> color;
    Json::Value data;
    data["color"] = color;
    
    sf::Http connection("http://localhost", 8080);
    
    sf::Http::Request* request = new sf::Http::Request;
    sf::Http::Request* request_get = new sf::Http::Request;
    request->setHttpVersion(1, 1);
    request->setField("Content-Type", "application/x-www-form-urlencoded");
    request_get->setHttpVersion(1, 1);
    request_get->setField("Content-Type", "application/x-www-form-urlencoded");
    
    sf::Http::Response response;
    sf::Http::Response response_get;
    Json::Value jsonResponse;
    Json::Reader jsonReader;
    
    request->setUri("/player");
    request->setMethod(sf::Http::Request::Put);
    request->setBody(data.toStyledString());
        
    response = connection.sendRequest(*request);
    //cout << response.getBody() << endl;
    if (response.getStatus() == sf::Http::Response::ServiceNotAvailable) {
        cout << "Service not available !" << endl;

        delete (sf::Http::Request*)request;
        //return;

    } 
    else if (response.getStatus() == sf::Http::Response::BadRequest) {
        cout << "Requete invalide " << endl;
        delete request;
        //return;

    } 
    else if (response.getStatus() == sf::Http::Response::NoContent) {
        cout << "Joueur ajouté à la partie !" << endl;
    }
    else {
        
        cout << "Status : " << response.getStatus() << endl;
    }


    if (!(jsonReader.parse(response.getBody(), jsonResponse, false))) {
        cout << jsonReader.getFormattedErrorMessages() << endl;
    }
    
    
    
    //std::string s = std::to_string();
    string d = response.getBody();
    stringstream ss;
    string s;
    char e = d.at(12);
    ss << e;
    ss >> s;
    cout << "e = " << e << endl;
    string uri = "/player/" +s;
    cout << "uri = " << uri << endl;
    request_get->setUri(uri);
    request_get->setMethod(sf::Http::Request::Get);
    
    response_get = connection.sendRequest(*request_get);
    //cout << "Status : " << response_get.getStatus() << endl;
    //cout << response_get.getBody() << endl;
    if (!(jsonReader.parse(response_get.getBody(), jsonResponse, false))) {
        cout << jsonReader.getFormattedErrorMessages() << endl;
    };
    i++;
    //delete request;
    tabResponse.push_back(response_get);
        }
    cout << "Les joueurs présents dans la partie sont : " << endl;
    for (int j = 0; j<(int)tabResponse.size(); j++){
        //cout << "j = " << j << endl;
        cout  << tabResponse[j].getBody() << endl;
    }
    
    //cout << "test " << endl;
    

}

Tests::~Tests() {

}



