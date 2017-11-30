/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShootCommand.h"
#include "state.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine{
    
    ShootCommand::ShootCommand(int i, int j){
        this->i = i;
        this->j = j;
    }
    
    CommandTypeId ShootCommand::getTypeId() const{
        return CommandTypeId::SHOOT;
    }
    
    void ShootCommand::execute(state::State& state){
        ElementTab tabchars = state.getChars();
        Element* top;
        top = tabchars.get( i, j);
        if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;
            int lifecount = perso->getLifecount();
            perso->setLifecount(lifecount-1);
        
      
            cout<< "Le personnage a perdu une vie"<<endl;

            if (lifecount==0){
                perso->setStatus(DEAD);
                perso->~Personnage();
                cout<<"Le personnage est mort"<<endl;
            }
        }
    }
    
    
    
}