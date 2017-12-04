

#include "TestAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>



#include <iostream>
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;

namespace ai {

    TestAI::TestAI() {

        //RandomAI* rai = new RandomAI();
        Engine moteur;
        State& state = moteur.getState();

        // initialisation de l'état
        Command* init = new LoadCommand("res/heuristic_ai.txt");
        moteur.addCommand(0, init);
        moteur.update();
        //init->execute(state);

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());
        // ElementTabLayer layer2(state.getChars());

        sf::RenderWindow window;
        window.create(sf::VideoMode(800, 384), "Test Worms");

        cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
        cout << "Appuyez sur la touche T pour tirer" << endl;
        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyReleased){
                    if (event.key.code == Keyboard::V){
                         cout << "C'est le personnage vert qui va jouer" << endl;
                        //cout << "x = " << x << ", y = " << y << endl;
                        Command* move = new MoveCharCommand(1, Direction::RIGHT);
                        //cout << "Test : apres new command" << endl;
                        moteur.addCommand(0, move);
                        //cout << "Test : apres add command" << endl;
                    }
                    else if(event.key.code == Keyboard::N){
                        cout << "C'est le personnage noir qui va jouer" << endl;
                        Command* move = new MoveCharCommand(2, Direction::LEFT);
                        moteur.addCommand(0, move);
                    }
                    else if(event.key.code == Keyboard::L){
                        cout << "le noir va tirer" << endl;
                        Command* shoot = new ShootCommand(2);
                        moteur.addCommand(0, shoot);
                    }
                }
            }

            /*if (Keyboard::isKeyPressed(Keyboard::V)) {
                cout << "C'est le personnage vert qui va jouer" << endl;
                //cout << "x = " << x << ", y = " << y << endl;
                Command* move = new MoveCharCommand(1, Direction::LEFT);
                cout << "Test : apres new command" << endl;
                moteur.addCommand(0, move);
                cout << "Test : apres add command" << endl;
            }*/

            /*if (Keyboard::isKeyPressed(Keyboard::N)) {
                cout << "C'est le personnage noir qui va jouer" << endl;
                Command* move = new MoveCharCommand(2, Direction::RIGHT);
                moteur.addCommand(0, move);
            }*/
            
            

            moteur.update();

            layer1->initSurface();
            window.draw(*(layer1->getSurface()));

            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();
        }
    }

    TestAI::~TestAI() {

    }
}












