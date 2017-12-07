/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharAction.h"
#include "state.h"
#include <iostream>

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
        Element* e = chars.get(xFrom, yFrom);
        if (e != NULL){
            Personnage* p = new Personnage(color, nextDir);
            p->setI(xTo);
            p->setJ(yTo);
        //cout << "xfrom = " << xFrom << " yFrom = " << yFrom << endl;
        //cout << "xto = " << xTo << " yTo = " << yTo << endl;
        chars.changePosition(xFrom, yFrom, xTo, yTo, p);
        }
    }
    
    void MoveCharAction::undo(state::State& state){
        ElementTab& chars = state.getChars();
        Element* e = chars.get(xTo, yTo);
        if (e != NULL){
            Personnage* p = new Personnage(color, precDir);
            p->setI(xFrom);
            p->setJ(yFrom);
            //cout << "xfrom2 = " << xFrom << " yFrom2 = " << yFrom << endl;
            //cout << "xto2 = " << xTo << " yTo2 = " << yTo << endl;
            //persoApAction->setDirection(precDir);
            chars.changePosition(xTo,yTo,xFrom, yFrom, p);
        }
        else{
            cout << "erreur, pas de perso" << endl;
        }
    }

    ActionTypeId MoveCharAction::getActionTypeId() const {
        return ActionTypeId::MOVE_ACTION;
    }

}