/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharCommand.h"
#include "state.h"
#include "state/Personnage.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    MoveCharCommand::MoveCharCommand(int xFrom, int yFrom, int xTo, int yTo) :
    xFrom(xFrom), yFrom(yFrom), xTo(xTo), yTo(yTo) {}

    int MoveCharCommand::getXFrom() const {
        return this->xFrom;
    }

    int MoveCharCommand::getXTo() const {
        return this->xTo;
    }

    int MoveCharCommand::getYFrom() const {
        return this->yFrom;
    }

    int MoveCharCommand::getYTo() const {
        return this->yTo;
    }

    void MoveCharCommand::setXFrom(int xFrom) {
        this->xFrom = xFrom;
    }

    void MoveCharCommand::setXTo(int xTo) {
        this->xTo = xTo;
    }

    void MoveCharCommand::setYFrom(int yFrom) {
        this->yFrom = yFrom;
    }

    void MoveCharCommand::setYTo(int yTo) {
        this->yTo = yTo;
    }

    
    CommandTypeId engine::MoveCharCommand::getTypeId () const{
        return CommandTypeId::MOVE_CHAR;
    }
    
    void engine::MoveCharCommand::execute (state::State& state){

        //cout<<"Le personnage s'est déplacé"<<endl;
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();
        
        Element* e = chars.get(xFrom, yFrom);
        
        if (e == NULL){
            cout << "Erreur : Il n'y a rien à déplacer " << endl;
        }
        else{
            if (e->getTypeId() == PERSONNAGE){
                if (chars.get(xTo, yTo) == NULL){
                    Personnage* p = (Personnage*) e;
                    chars.set(xTo, yTo, p);
                    //cout<<"set to ok"<<endl;
                    chars.set(xFrom, yFrom, NULL);
                    //cout<<"set from ok"<<endl;
                }
            }
        }

    }
    
    
    

}