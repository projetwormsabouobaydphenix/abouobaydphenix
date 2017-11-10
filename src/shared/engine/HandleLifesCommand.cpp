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
    
    void HandleLifesCommand::takeLife(state::State& state, int pos, state::SpaceTypeId tyletype){
        int Lifecount = state.getLifecount();
        if (Lifecount<3){
        state.setLifecount(Lifecount+1);
        }
        tyletype = EMPTY;
        cout<<"Le personnage a récupéré une vie."<<endl;
    }
    
    void engine::HandleLifesCommand::execute(state::State& state, int position){
        ElementTab tabgrid= state.getGrid();
        Element* type = tabgrid.get(position);
        Element heart = *type;
        if (heart.equals(Space(SpaceTypeId::LIFE))){
            HandleLifesCommand::takeLife(state, position, state::SpaceTypeId::LIFE);
        }
    }

    CommandTypeId engine::HandleLifesCommand::getTypeId () const{
        return CommandTypeId::HANDLE_LIFE;
    }
    
 
}
