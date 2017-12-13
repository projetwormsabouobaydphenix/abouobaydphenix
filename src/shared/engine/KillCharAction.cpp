/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "KillCharAction.h"
#include "state/State.h"
#include <iostream>


using namespace std;
using namespace state;

namespace engine {
    
    KillCharAction::KillCharAction(int color, int xFrom, int yFrom, state::Personnage* persoAvAction){
        this->color=color;
        this->xFrom=xFrom;
        this->yFrom=yFrom;
        this->persoAvAction = persoAvAction;
    }
    
    void KillCharAction::apply(state::State& state){
        ElementTab& chars = state.getChars();
        int width = chars.getWidth();
        chars.list[xFrom+yFrom*width].reset();
        //cout << "Le personnage est tombé dans l'eau. Il est mort." << endl;
    }
    
    void KillCharAction::undo(state::State& state){
        ElementTab& chars = state.getChars();
        //int width = chars.getWidth();
        chars.set(xFrom, yFrom, persoAvAction);
    }
    
    ActionTypeId KillCharAction::getActionTypeId() const {
        return ActionTypeId::KILL_ACTION;
    }

}