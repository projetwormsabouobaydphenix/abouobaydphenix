/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HandleLifesCommand.h"
#include "state.h"
#include "state/SpaceTypeId.h"
#include "LifeAction.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace state;

namespace engine {
    
  

    void HandleLifesCommand::addLife(int color, state::State& state){
        //ElementTab tabgrid= state.getGrid();
        //Element* pos;
        //pos= tabgrid.get(i,j);
        ElementTab& chars= state.getChars();
        int width = chars.getWidth();
        int height = chars.getHeight();
        //Element* top;
        
        for (int i = 0; i < (int)height; i++) {
            for (int j = 0; j < (int)width; j++) {
                if (chars.get(i,j) != NULL){
                    if (chars.get(i,j)->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* persoAction = (Personnage*) chars.get(i,j);
                        int lifecount = persoAction->getLifecount();
                        if (lifecount<3){
                            persoAction->setLifecount(lifecount+1);
                            cout<<"Le personnage a récupéré une vie."<<endl;

                        }
                    }
                }
            }
        }
    }
           
    
    void engine::HandleLifesCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>& actions){

            
                    //ElementTab tabgrid= state.getGrid();
        //Element* pos;
        //pos= tabgrid.get(i,j);
        ElementTab& chars= state.getChars();
        int width = chars.getWidth();
        int height = chars.getHeight();
        
        for (int i = 0; i < (int)height; i++) {
            for (int j = 0; j < (int)width; j++) {
                if (chars.get(i,j) != NULL){
                    if (chars.get(i,j)->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* persoApAction = (Personnage*) chars.get(i,j);
                        int lifecount = persoApAction->getLifecount();
                        if (lifecount<3){
                            engine::Action* life = new LifeAction(color,lifecount+1, persoApAction);
                            actions.push(shared_ptr<Action>(life));
                            life->apply(state);
                            cout<<"Le personnage a récupéré une vie."<<endl;
                        }
                    }
                }
            }
        }
        
        cout<<"le personnage a récupéré une vie"<<endl;
    }


    CommandTypeId engine::HandleLifesCommand::getTypeId () const{
        return CommandTypeId::HANDLE_LIFE;
    }

 /*   HandleLifesCommand* HandleLifesCommand::deserialize(const Json::Value& in) {

    }

    void HandleLifesCommand::serialize(Json::Value& out) const {

    }*/
    
 
}
