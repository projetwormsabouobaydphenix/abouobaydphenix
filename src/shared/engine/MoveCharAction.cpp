/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharAction.h"
#include "state.h"

using namespace std;
using namespace state;

namespace engine {
    
    MoveCharAction::MoveCharAction(int color, int xFrom, int yFrom, int xTo, int yTo, Personnage* persoApAction, state::Direction precDir, state::Direction nextDir){
        this->color=color;
        this->xFrom=xFrom;
        this->yFrom=yFrom;
        this->xTo=xTo;
        this->yTo=yTo;
        this->persoApAction=persoApAction;
        this->precDir=precDir;
        this->nextDir=nextDir;
        
    }
    
    void MoveCharAction::apply(state::State& state){
        ElementTab& chars = state.getChars();
        persoApAction->setI(xTo);
        persoApAction->setJ(yTo);
        chars.changePosition(xFrom, yFrom, xTo, yTo, persoApAction);
    }
    
    void MoveCharAction::undo(state::State& state){
        ElementTab& chars = state.getChars();
        persoApAction->setI(xFrom);
        persoApAction->setJ(yFrom);
        persoApAction->setDirection(precDir);
        chars.changePosition(xTo,yTo,xFrom, yFrom, persoApAction);
    }
}