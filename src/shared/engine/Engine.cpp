/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    
    Engine::Engine() {

    }

    
    Engine::~Engine(){
        
    }
    
    void Engine::moteur(){

    }
    
    void Engine::addCommand(int priority, Command* cmd){
        //currentCommands.insert(std::pair<int, Command>(priority,cmd));
        currentCommands[priority]=cmd;
        cout<<"Ajout de la commande : " << cmd->getTypeId()<<endl;

    }
    
    void Engine::addPassiveCommand(){
        Command* cmd;
        int priority;
        //addCommand(priority,cmd);
    }
    
   state::State& Engine::getState(){
        return this ->currentState;
    }
    
    void Engine::update(){
        for (std::map<int,Command*>::iterator it = currentCommands.begin(); it != currentCommands.end(); ++it){
            it->second->execute(currentState);
            //get()execute(currentState);
        }
        
        int epoch = currentState.getEpoch();
        epoch=epoch+1;
        currentState.setEpoch(epoch);
        currentCommands.clear();
    }
}
