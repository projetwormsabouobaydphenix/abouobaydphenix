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
    

    MoveCharCommand::MoveCharCommand(int i, int j) {
        this->i=i;
        this->j=j;
  
    }
    
    CommandTypeId engine::MoveCharCommand::getTypeId () const{
        return CommandTypeId::MOVE_CHAR;
    }
    
    void engine::MoveCharCommand::execute (state::State& state){
        
        ElementTab tabgrid= state.getGrid();
        Element* casenext;
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;   
            int stepcount =perso->getStepcount();
            
            if(stepcount<3){
                cout<<"Le personnage s'est déplacé d'une case."<<endl; 
                stepcount=stepcount+1;
                perso->setStepcount(stepcount);
                if((perso->getD())==LEFT){
                    casenext = tabgrid.get(i-1,j);
                    if((casenext->getTypeId())!=FLOOR){
                        perso->setI(i-1);
                        while(((tabgrid.get(i-1,j-1))->getTypeId())==SPACE){
                            this->j=j-1;
                        }
                        
                        if (((tabgrid.get(i-1,j))->getTypeId())==FLOOR){
                            Element* next = (tabgrid.get(i-1,j));
                            Floor* eau = (Floor*)next;
                            if (eau->getNature()==WATER){
                            perso->setLifecount(0);
                            perso->setStatus(DEAD);
                            }
                        }
                        
                        else {
                            perso->setJ(j);
                        }                        
                    }
                }
                else if((perso->getD())==RIGHT){
                    if(((tabgrid.get(i+1,j))->getTypeId())!=FLOOR){
                        perso->setI(i+1);
                        while(((tabgrid.get(i+1,j-1))->getTypeId())==SPACE){
                            this->j=j-1;
                        }
                        Element* next = tabgrid.get(i+1,j);
                        Floor* eau = (Floor*)next;
                        if (eau->getNature()==WATER){
                            perso->setLifecount(0);
                            perso->setStatus(DEAD);
                        }

                        else {
                            perso->setJ(j);
                        }                    
                    }  
                } 
            }                     
        }
        else {
            cout<<"Le personnage a épuisé le nombre de pas autorisés pour un tour."<<endl;
        } 
    }
    
    int engine::MoveCharCommand::getCharacter() const{
        return this->character;
    }
    
    void setCharacter(int character){
     //  (this->character)=character;
    }
    
    
}