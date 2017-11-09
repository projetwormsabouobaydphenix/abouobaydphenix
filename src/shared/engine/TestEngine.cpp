

#include <SFML/Window/Keyboard.hpp>

#include "TestEngine.h"
#include "state.h"
#include "engine.h"

#include <iostream>
using namespace std;


namespace engine{
    TestEngine::TestEngine() {
        Command *comm ;
        Engine enginetest;
        
        
        comm = new OrientationCommand(1, state::Direction::LEFT);
        
        enginetest.addCommand(1,comm);
        enginetest.moteur();
        
        comm = new MoveCharCommand(1, enginetest.getState());
        enginetest.addCommand(2,comm);
        enginetest.moteur();
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Engine enginetest;
            state::State state;
            enginetest.getState()=state;
            state::ElementTab elementTab(2,2);
            state.getChars()=elementTab;
            
            //state::Element p = new state::Personnage(1);
            //elementTab.add(*p);
            cout<<"** Epoque 1**\n"<<endl;
            //comm = new OrientationCommand();
            enginetest.addCommand(1,comm);
            
            enginetest.moteur();
          
            
        }
        
       /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Engine enginetest = new Engine;
            cout<<"** Epoque 2**\n"<<endl;
            enginetest.addCommand(1,OrientationCommand);
            enginetest.addCommand(2,MoveCharCommand);
            
        }*/
    
    
    
    }



    TestEngine::~TestEngine() {
    }

}

