/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "LoadCommand.h"
#include "HandleImpactCommand.h"
#include "HandleLifesCommand.h"
#include "ShootCommand.h"
#include "MoveCharCommand.h"
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
        //out<<"22" << endl;
        //currentCommands.insert(std::pair<int, Command>(priority,cmd));
        currentCommands[priority] = cmd;
        //cout<<"Ajout de la commande : " << cmd->getTypeId() << endl;

    }
    
    void Engine::addPassiveCommand(){
        Command* cmd;
        int priority;
        //addCommand(priority,cmd);
    }
    
   state::State& Engine::getState(){
        return this ->currentState;
    }
    
    std::stack<std::shared_ptr<Action>> Engine::update(){
        //cout<<"test update"<<endl;
        std::stack<std::shared_ptr<Action>> actions;
        for (int i=0; i<((int)(currentCommands.size()));i++){
            if ((currentCommands[i])->getTypeId() == LOAD){
                //cout << "load command" << endl;
                ((LoadCommand*)(currentCommands[i]))->execute(currentState, actions);
            }
            else if((currentCommands[i])->getTypeId() == MOVE_CHAR){
                //cout << "MoveCharcommand" << endl;
                ((MoveCharCommand*)(currentCommands[i]))->execute(currentState, actions);
            }
            else if((currentCommands[i])->getTypeId() == HANDLE_LIFE){
                //cout << "HandleLife" << endl;
                ((HandleLifesCommand*)(currentCommands[i]))->execute(currentState, actions);
            }
            else if((currentCommands[i])->getTypeId() == SHOOT){
                //cout << "HandleLife" << endl;
                ((ShootCommand*)(currentCommands[i]))->execute(currentState, actions);
            }
            /*else if((currentCommands[i])->getTypeId() == HANDLE_IMPACT){
                ((HandleImpactCommand*)(currentCommands[i]))->execute(currentState);
            }*/
            delete currentCommands[i];
            currentCommands.clear();
            }
        return actions;
    }
    
    void Engine::undo(std::stack<std::shared_ptr<Action> >& actions){
        for(size_t k=0; k<actions.size(); k++){
            shared_ptr<Action> action = actions.top();
            action->undo(currentState);
            actions.pop();
        }
    }
}
