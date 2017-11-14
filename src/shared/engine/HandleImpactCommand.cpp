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
    

    void HandleImpactCommand::lostLife (state::State& state, int i, int j){
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;
            int lifecount = perso->getLifecount();
            perso->setLifecount(lifecount-1);
        
      
            cout << "Le personnage a perdu une vie" << endl;

            if (lifecount==0){
                perso->setStatus(DEAD);
                perso->~Personnage();
                cout<<"Le personnage est mort"<<endl;
            }
        }
    }
    
    void HandleImpactCommand::destruct(state::State& state, int i, int j){
        ElementTab grid = state.getGrid();
        Element* top = grid.get(i,j);
        Space* space;
        if ((top->getTypeId())==SPACE){
            space = (Space*)top;
            space->setNature(EMPTY);
            grid.set(i, j+1, space);
            cout<<"La case a été détruite par le tir"<<endl;
        }
    }

    void engine::HandleImpactCommand::execute(state::State& state, int i, int j){
        ElementTab tabgrid= state.getGrid();
        Element* top;
        top= tabgrid.get(i,j);
        
       
            
            if ((top->getTypeId())==PERSONNAGE){
                HandleImpactCommand::lostLife(state, i,j);
            }
        
            else if ((top->getTypeId())==SPACE) {
               HandleImpactCommand::destruct(state, i,j);
            }
        }
   
     
     
     CommandTypeId engine::HandleImpactCommand::getTypeId () const{
         return CommandTypeId::HANDLE_IMPACT;
     }
     
     Command::~Command(){
         
     }
}
