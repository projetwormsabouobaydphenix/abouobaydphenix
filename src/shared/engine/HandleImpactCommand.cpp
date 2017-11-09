/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HandleImpactCommand.h"
#include "state.h"
#include <iostream>
#include <vector>


using namespace std;
using namespace state;


namespace engine {
    
    void HandleImpactCommand::lostLife(state::State& state, state::Status statusPerso){
        int Lifecount = state.getLifecount();
        state.setLifecount(Lifecount-1);
        cout << "Le personnage a perdu une vie" << endl;
        
        if (Lifecount==0){
            statusPerso=DEAD;
            cout<<"Le personnage est mort"<<endl;
        }
    }
    
    void HandleImpactCommand::destruct(state::State& state, int pos){
        ElementTab grid = state.getGrid();
        //grid.set(pos, state::Space.setSpaceTypeId(EMPTY) );
        cout<<"La case a été détruite par le tir"<<endl;
        
        }
    
    void engine::HandleImpactCommand::execute(state::State& state, int position){
        ElementTab tabchars= state.getChars();
        Element* type = tabchars.get(position);
        Element impact = *type;
        if (impact.equals(Space(SpaceTypeId::EMPTY)) or impact.equals(Space(SpaceTypeId::LIFE))){
            HandleImpactCommand::lostLife(state, state::Status::ALIVE);
        }
        else {
           engine::HandleImpactCommand::destruct(state, position);
        }
    }
     
     
     CommandTypeId engine::HandleImpactCommand::getTypeId () const{
         return CommandTypeId::HANDLE_IMPACT;
     }
}