

#include <SFML/Window/Keyboard.hpp>

#include "TestEngine.h"
#include "state.h"
#include "engine.h"

#include <iostream>
using namespace std;



using namespace state;

namespace engine{
    TestEngine::TestEngine() {
        Command* comm;
        
        
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Engine enginetest;
            state::State& state = enginetest.getState();
            //enginetest.getState()=state;
            state::ElementTab elementTab(2,2);
            
            
            Element* p;
            Personnage* perso = new Personnage();
            p = perso;
            //Floor* f = new Floor();
            //elementTab.add(f);
            elementTab.set(0, 0, p);
            state.getChars()=elementTab;
            cout<<"** Epoque 1**\n"<<endl;
            comm = new OrientationCommand(0,0, state::Direction::LEFT);
            enginetest.addCommand(1,comm);
            Command* comm2 = new MoveCharCommand(0,0);
            enginetest.addCommand(2, comm2);
            enginetest.update();
          
            
        //}
        
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

