/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include <algorithm>

using namespace std;
using namespace state;

namespace engine {
    
    
    Engine::Engine(){
        //for_each(currentCommands.begin(), currentCommands.end(), Command.execute(currentState));
       for (std::map<int,std::unique_ptr<Command>>::iterator it = currentCommands.begin(); it != currentCommands.end(); ++it){
             it->second.get()->execute(currentState);
       }
        
        int epoch = currentState.getEpoch();
        epoch=epoch+1;
        currentState.setEpoch(epoch);
        currentCommands.clear();
    }
    
    Engine::~Engine(){
        
    }
    
    void Engine::addCommand(int priority, Command* cmd){
        //currentCommands.insert(std::pair<int, Command>(priority,cmd));
        currentCommands[priority]=std::unique_ptr<Command>(cmd);
    }
    
    void Engine::addPassiveCommand(){
        Command* cmd;
        int priority;
        addCommand(priority,cmd);
    }
    
   const state::State& Engine::getState() const{
        return this ->currentState;
    }
    
    void Engine::update(){
        currentState.setEpoch(0);
    }
    
}
