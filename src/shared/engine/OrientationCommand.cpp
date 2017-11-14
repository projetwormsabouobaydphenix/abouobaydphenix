/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "OrientationCommand.h"
#include "state/Direction.h"
#include <iostream>


using namespace std;
using namespace state;

namespace engine {
    
    OrientationCommand::OrientationCommand(int i, int j , state::Direction d){
        this->i=i;
        this->j=j;
        this->orientation= d;
        
    }
    
    CommandTypeId engine::OrientationCommand::getTypeId () const{
        return CommandTypeId::ORIENTATION;
    }
    
    void OrientationCommand::execute(state::State& state){
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        
        if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;
            perso->setD(this->orientation);
         cout<<"Le personnage est orienté "<<endl;
        
        }
    }
}