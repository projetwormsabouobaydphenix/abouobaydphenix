/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HandleLifesCommand.h"
#include "state.h"
#include "state/SpaceTypeId.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    HandleLifesCommand::HandleLifesCommand(int i, int j){
        this->i=i;
        this->j=j;
    }
    
    void takeLife(state::State& state, int pos, state::SpaceTypeId tyletype){
        /*int Lifecount = state.getLifecount();
        if (Lifecount<3){
        state.setLifecount(Lifecount+1);
        }
        tyletype = EMPTY;*/
        cout<<"Le personnage a récupéré une vie."<<endl;
    }
    

    void HandleLifesCommand::addLife(int i, int j, state::State& state){
        //ElementTab tabgrid= state.getGrid();
        //Element* pos;
        //pos= tabgrid.get(i,j);
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        
        /*if ((pos->getTypeId())==SPACE){
            Space* lieu = (Space*)pos;*/
        
            if(top->getTypeId()== PERSONNAGE){
                Personnage* perso = (Personnage*)top;
                int lifecount = perso->getLifecount();
                if (lifecount<3){
                    perso->setLifecount(lifecount+1);
                    cout<<"Le personnage a récupéré une vie."<<endl;
                }
                //lieu->setNature(EMPTY);
            }
        //}
    }
    
    void engine::HandleLifesCommand::execute(state::State& state){
        /*ElementTab tabgrid= state.getGrid();
        Element* heart;
        heart = tabgrid.get(i,j);
        
        if ((heart->getTypeId())== SPACE){
            Space* vie = (Space*)heart;
            if ((vie->getNature())==LIFE){*/
            HandleLifesCommand::addLife(i,j , state);
        
        cout<<"le personnage a récupéré une vie"<<endl;
    }

    CommandTypeId engine::HandleLifesCommand::getTypeId () const{
        return CommandTypeId::HANDLE_LIFE;
    }
    
 
}
