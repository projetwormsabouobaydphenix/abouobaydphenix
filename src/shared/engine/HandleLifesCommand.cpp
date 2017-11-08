/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HandleLifesCommand.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    void takeLife(state::State& state, int pos, state::SpaceTypeId tyletype){
        int Lifecount = state.getLifecount();
        if (Lifecount<3){
        state.setLifecount(Lifecount+1);
        }
        tyletype = EMPTY;
        cout<<"Le personnage a récupéré une vie."<<endl;
    }
}