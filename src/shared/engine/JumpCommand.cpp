/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "JumpCommand.h"
#include "OrientationCommand.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    JumpCommand::JumpCommand(int i, int j){
        this->i = i;
        this->j = j;
    }
    
    CommandTypeId JumpCommand::getTypeId() const{
        return CommandTypeId::JUMP;
    }
    
    int JumpCommand::getI() const{
        return i;
    }
    
    int JumpCommand::getJ() const{
        return j;
    }
    
    void JumpCommand::setI(int i){
        this->i;
    }
    
    void JumpCommand::setJ(int j){
        this->j = j;
    }
    
    void JumpCommand::execute(state::State& state){
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get(i, j);
        
        top->setI(i+1);
        top->setJ(j+1);
    }
    
    
}
