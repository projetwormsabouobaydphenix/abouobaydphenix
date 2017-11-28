

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

namespace ai{
    
    TestAI::TestAI() {
     
        //RandomAI* rai = new RandomAI();
        Engine moteur;
        State& state = moteur.getState();
        
        // initialisation de l'état
        Command* init = new LoadCommand("res/heuristic_ai.txt");    
        moteur.addCommand(0,init);
        moteur.update();

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());
       // ElementTabLayer layer2(state.getChars());

        sf::RenderWindow window(sf::VideoMode(800, 384), "Test Worms");      
        
        cout << "Appuyez sur Espace pour continuer" << endl;
        
        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                // fermeture de la fenêtre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed){
                    window.close();
                }
            }
            
            
            if(Keyboard::isKeyPressed(Keyboard::Space)){
                    
                cout << "ok" << endl;
                    //rai->run(moteur);
                    //sleep(milliseconds(1000));
            }
            
            //window.clear(Color::Black);
            window.clear();
            layer1->initSurface();
            layer2->initSurface();
            //cout << "sortie initSurface" << endl;
            window.draw(*(layer1->getSurface()));
            window.draw(*(layer2->getSurface()));

            // on dessine la surface des équipes
            window.display();
        }
    }
   
    
    
    TestAI::~TestAI(){
        
    }
}      
