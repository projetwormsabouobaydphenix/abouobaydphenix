

#include "Tests.h"
#include "state/ElementTab.h"
#include <SFML/Graphics.hpp>
#include "../shared/state.h"
#include <vector>
#include "../shared/ai.h"
#include "../shared/engine.h"
#include "render.h"
#include <iostream>
#define LIMITE_FRAME 60

using namespace sf;
using namespace std;
using namespace state;
using namespace render;
using namespace ai;
using namespace engine;

Tests::Tests() {
}

void Tests::test_render() {
    sf::RenderWindow window(sf::VideoMode(800, 384), "Worms");

    state::State state;

    ElementTab& grid = state.getGrid();
    ElementTab& chars = state.getChars();
    grid.resize(25, 12);
    chars.resize(25, 12);
    std::vector<int> vcarte = state.getGrid().load("res/heuristic_ai.txt");
    std::vector<int> pcarte = state.getChars().load("res/personnage_render.txt");
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

    //std::stack<std::shared_ptr<Action> >& actions   ;

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
        std::stack<std::shared_ptr < Action>> actions;
        std::stack<std::shared_ptr < Action>> actionsTmp;
        std::vector<std::shared_ptr < Action>> vectActions;

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

                    if (event.key.code == Keyboard::Return) {
                        cout << "Appuyez sur Entrée pour faire défiler" << endl;
                        cout << "Appuyez sur BackSpace pour revenir en arrière" << endl; 
                        //cout << "" << endl;
                        i = i + 1;
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
                        } 
                   
                        actionsTmp = moteur.update();
                        
                        int lActions = (int) actionsTmp.size();
                        for (int i = 0; i < lActions; i++) {
                            vectActions.push_back(actionsTmp.top());
                            actionsTmp.pop();
                        }
                        for (int j = 0; j < (int) vectActions.size(); j++) {
                            int n = (int) vectActions.size();
                            actions.push(vectActions[n - j - 1]);
                        }
                        vectActions.clear();
                        //sleep(milliseconds(1000));
                        
                    } else if (event.key.code == Keyboard::BackSpace) {
                        moteur.undoe(actions);
                        i = 0;
                        //actions.pop()
                       //sleep(milliseconds(1000));
                        

                    }
                }
            }





            moteur.update();
            // moteur.undo(actions);

            layer1->initSurface();
            window.draw(*(layer1->getSurface()));

            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();

        }
}

void Tests::test_record() {
TestJson test("Sanaa", 22);
        
        Json::Value out;
        test.serialize(out);
        cout << out["nom"].asString() << endl;
        cout << out["age"].asInt() << endl;

}



Tests::~Tests() {
}

