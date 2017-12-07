
#include "TestRollBack.h"
#include "HeuristicAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include "HeuristicAI.h"
//#include <stack>
#include <iostream>
#include <vector>
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;

#define LIMITE_FRAME 60

namespace ai {

    TestRollBack::TestRollBack() {

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

    TestRollBack::~TestRollBack() {
    }
}

