/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharCommand.h"
#include "state/State.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
   
    MoveCharCommand::MoveCharCommand(int c, state::State& state) {
        
    }
    
    CommandTypeId engine::MoveCharCommand::getTypeId () const{
        return CommandTypeId::MOVE_CHAR;
    }
    
    void engine::MoveCharCommand::execute (state::State& state){
        
    }
    
    int engine::MoveCharCommand::getCharacter() const{
        //return this->character;
    }
    
    void setCharacter(int character){
       //this->character=character;
    }
    
    Command::~Command(){}
}