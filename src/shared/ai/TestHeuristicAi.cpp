
#include "TestHeuristicAi.h"

#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include "HeuristicAI.h"



#include <iostream>
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;


#define LIMITE_FRAME 60


namespace ai {

    TestHeuristicAi::TestHeuristicAi() {
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
        HeuristicAI heuristicnoir(state, 2);
        HeuristicAI heuristicvert(state,1);
        //int i = 0;
        //int k = 0;
        int color =1;
        while (window.isOpen()) {
            
            if (color==1){
                heuristicvert.run(moteur,1);
                //moteur.update();
                sleep(milliseconds(1000));
                color =2;
            }
            else if (color==2){
                heuristicnoir.run(moteur, 2);
                //moteur.update();
                sleep(milliseconds(1000));
                color=1;
            }
            else {
                cout<<"erreur la couleur n'est pas bonne"<<endl;
            }

               

            
            //sf::Event event;
            /*while (window.pollEvent(event)) {
                // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyReleased){
                    
                    if (event.key.code == Keyboard::Space){
                        heuristic.run(moteur, 2);
                        
                    }
                    if (event.key.code == Keyboard::Return){
                        i = i + 1;
                        if (i == 1){
                            Command* move = new MoveCharCommand(1, Direction::RIGHT);
                            moteur.addCommand(0, move);
                        }
                        else if (i == 2){
                            Command* move = new MoveCharCommand(1, Direction::RIGHT);
                            moteur.addCommand(0, move);
                        }
                        else if (i == 3){
                            cout << "Le personnage vert va tirer" << endl;
                            Command* shoot = new ShootCommand(1);
                            moteur.addCommand(0, shoot);
                        }
                    }
                }
            }*/

           
            //moteur.update();

            layer1->initSurface();
            window.draw(*(layer1->getSurface()));

            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();

        }
        
    }
        

    TestHeuristicAi::~TestHeuristicAi() {
    }
}
