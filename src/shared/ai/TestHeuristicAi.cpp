
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

namespace ai{
    TestHeuristicAi::TestHeuristicAi() {
         
        Engine moteur;
        State& state = moteur.getState();
        
        // initialisation de l'état
        Command* init = new LoadCommand("res/heuristic_ai.txt");    
        moteur.addCommand(0,init);
        moteur.update();
        //init->execute(state);

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());

        sf::RenderWindow window; 
        window.create(sf::VideoMode(800, 384), "Test Worms");      
        
        cout << "Appuyez sur Espace pour faire défiler" << endl;
        //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
        //HeuristicAI heuristic(state);
        
        while (window.isOpen()){
            
            sf::Event event;
            while (window.pollEvent(event)){
                // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                /*if (event.type == sf::Event::EventType::KeyPressed){
                    if (event.key.code == sf::Keyboard::Space){
                        Command* move = new MoveCharCommand(2, 3, 2, 3);
                        moteur.addCommand(0, move);
                    }
                    else if (event.key.code == sf::Keyboard::Return){
                        Command* move = new MoveCharCommand(16, 3, 15, 3);
                        moteur.addCommand(0, move);
                    }
                        
                    }*/
            }
            
            
            
            if(Keyboard::isKeyPressed(Keyboard::Space)){
                //heuristic.run(e);
                
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


    TestHeuristicAi::~TestHeuristicAi() {
    }
}
