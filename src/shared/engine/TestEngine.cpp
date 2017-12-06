

#include <SFML/Window/Keyboard.hpp>

#include "TestEngine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;



namespace engine{
    TestEngine::TestEngine() {
        
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
                }
                else if (event.type == sf::Event::KeyReleased){
                    
                    if (event.key.code == Keyboard::Space){
                        epoche = epoche+1;
                        
                        if (epoche == 1){
                            cout << "Epoque "  << epoche << endl;
                            Command* move = new MoveCharCommand(2, Direction::LEFT);
                            moteur.addCommand(0, move);
                            cout << "Le personnage noir s'est déplacé : OK" << endl;
                        }
                        if (epoche == 2){
                            cout << "Epoque "  << epoche << endl;
                            Command* move = new MoveCharCommand(2, Direction::LEFT);
                            moteur.addCommand(0, move);
                            cout << "Le personnage noir s'est déplacé : OK" << endl;
                        }
                        if (epoche == 3){
                            cout << "Epoque " << epoche << endl;
                            cout << "Le personnage noir va tirer" << endl;
                            Command* shoot = new ShootCommand(2);
                            moteur.addCommand(0, shoot);
                        }
                        if (epoche == 4){
                            cout << "Epoque " << epoche << endl;
                            Command* move = new MoveCharCommand(1, Direction::RIGHT);
                            moteur.addCommand(0, move);
                            cout << "Le personnage vert s'est déplacé : OK" << endl;
                            
                        }
                        if (epoche == 5){
                            cout << "Epoque " << epoche << endl;
                            Command* move = new MoveCharCommand(1, Direction::RIGHT);
                            moteur.addCommand(0, move);
                            cout << "Le personnage vert s'est déplacé : OK" << endl;
                        }
                        if (epoche == 6){
                            cout << "Epoque " << epoche << endl;
                            Command* move = new MoveCharCommand(1, Direction::RIGHT);
                            moteur.addCommand(0, move);
                            cout << "Le personnage vert s'est déplacé : OK" << endl;
                        }
                        if (epoche == 7){
                            cout << "Epoque " << epoche << endl;
                            cout << "Le personnage vert va tirer" << endl;
                            Command* shoot = new ShootCommand(1);
                            moteur.addCommand(0, shoot);
                        }
                        if (epoche == 8){
                            cout << "Epoque " << epoche << endl;
                            return;
                            
                        }
                        if (epoche == 9){
                            cout << "Epoque " << epoche << endl;
                            return;
                        }
                        if (epoche == 10){
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



    TestEngine::~TestEngine() {
    }

}

