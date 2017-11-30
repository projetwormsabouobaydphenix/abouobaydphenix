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
    
    
    MoveCharCommand::MoveCharCommand(int xFrom, int yFrom, state::Direction direction) : xFrom(xFrom),
    yFrom(yFrom), direction(direction){

    }



    int MoveCharCommand::getXFrom() const {
        return this->xFrom;
    }

    

    int MoveCharCommand::getYFrom() const {
        return this->yFrom;
    }

    

    void MoveCharCommand::setXFrom(int xFrom) {
        this->xFrom = xFrom;
    }


    void MoveCharCommand::setYFrom(int yFrom) {
        this->yFrom = yFrom;
    }
    
    state::Direction MoveCharCommand::getDirection() const {
        return this->direction;
    }
    
    void MoveCharCommand::setDirection(state::Direction direction) {
        this->direction = direction;
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
                    Personnage* p = (Personnage*) e;
                    //Personnage* p2 = new Personnage(1, Direction::LEFT);
                    if (direction == Direction::LEFT){
                        p->setDirection(Direction::LEFT);
                        chars.list[(xFrom-1) + (yFrom) * chars.getWidth()].swap(chars.list[xFrom + yFrom * chars.getWidth()]);
                        //chars.set(xFrom-1, yFrom, p);
                        //chars.set(xFrom, yFrom, NULL);
                    }
                    else if (direction == Direction::RIGHT){
                        p->setDirection(Direction::RIGHT);
                        if (grid.get(xFrom+1, yFrom)->getTypeId() == TypeId::SPACE){
                            cout << "space" << endl;
                            if (grid.get(xFrom+1, yFrom+1)->getTypeId() == TypeId::FLOOR){
                                cout << "floor " << endl;
                                //chars.set(xFrom+1, yFrom, p);
                                chars.list[(xFrom+1) + (yFrom) * chars.getWidth()].swap(chars.list[xFrom + yFrom * chars.getWidth()]);
                                
                                //chars.set(xFrom, yFrom, NULL);
                            }
                            else {
                                cout << "else" << endl;
                                chars.list[(xFrom+1) + (yFrom+1) * chars.getWidth()].swap(chars.list[xFrom + yFrom * chars.getWidth()]);
                                //chars.set(xFrom+1, yFrom+1, p);
                                //chars.set(xFrom, yFrom, NULL);
                            }
                        
                        }
                        else if (grid.get(xFrom+1, yFrom)->getTypeId() == TypeId::FLOOR){
                            cout << "dloor 2" << endl;
                            chars.list[(xFrom+1) + (yFrom-1) * chars.getWidth()].swap(chars.list[xFrom + yFrom * chars.getWidth()]);
                            //chars.set(xFrom+1, yFrom-1, p);
                            //chars.set(xFrom, yFrom, NULL);
                        }
                    }   
            }
        }

    }
    
    
    

}