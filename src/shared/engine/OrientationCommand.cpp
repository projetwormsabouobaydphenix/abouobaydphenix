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
    
    OrientationCommand::OrientationCommand(int c, state::Direction d){
        //Pourquoi représenter le character par un int ? Cette commande fonctionne-t-elle aussi pour les fantômes ?
        cout<<"Le personnage est orienté "<<endl;
    }
    
    CommandTypeId engine::OrientationCommand::getTypeId () const{
        return CommandTypeId::ORIENTATION;
    }
    
    void engine::OrientationCommand::execute(state::State& state){
         cout<<"Le personnage est orienté "<<endl;
        
    }
}