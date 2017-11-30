

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
        //init->execute(state);

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());
       // ElementTabLayer layer2(state.getChars());

        sf::RenderWindow window; 
        window.create(sf::VideoMode(800, 384), "Test Worms");      
        
        cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
        
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
            
            
            
            if(Keyboard::isKeyPressed(Keyboard::V)){
                cout << "C'est le personnage vert qui va jouer" << endl;
                //for (int i = 0; i < (int)state.getChars().getHeight(); i++){
                  //  for (int j = 0; j < (int)state.getChars().getWidth(); j++){
                        //cout << state.getChars().getWidth() << state.getChars().getHeight() << endl;
                    //    Element* e = state.getChars().get(j, i);
                      //  if (e != NULL){
                        //if (e->getTypeId() == PERSONNAGE){
                          //  Personnage* p = (Personnage*) e;
                            //if (p->getColor() == 1){
                              //  cout << "test" << endl;
                                //int x = p->getI();
                                //int y = p->getI();
                                //cout << "x = " << x << ", y = " << y << endl;
                                Command* move = new MoveCharCommand(16, 3, Direction::LEFT);
                                moteur.addCommand(0, move);
                                
                                
                                //cout << "add ok" << endl;
                                //move->execute(state);
                            //}
                            
                        //}
                    //}
                    //}
                }
            
            if (Keyboard::isKeyPressed(Keyboard::N)){
                cout << "C'est le personnage noir qui va jouer" << endl;
                Command* move = new MoveCharCommand(9, 4, Direction::LEFT);
                moteur.addCommand(0, move);
            }
            if (Keyboard::isKeyPressed(Keyboard::O)){
                cout << "C'est le personnage noir qui va jouer" << endl;
                Command* move = new MoveCharCommand(15, 3, Direction::LEFT);
                moteur.addCommand(0, move);
            }
                
                
                //cout << "update ok" << endl;
                    //rai->run(moteur);
                //sleep(milliseconds(1000));
            
            moteur.update();
            
            layer1->initSurface();
            window.draw(*(layer1->getSurface()));
            
            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();
        }
    }
    
    
    TestAI::~TestAI(){
        
    }
}  
    

        
        
        
        
        
        
        



