/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "Command.h"
#include "LoadCommand.h"
#include "HandleLifesCommand.h"
#include "ShootCommand.h"
#include "MoveCharCommand.h"
#include "KillCharAction.h"
#include <algorithm>
#include <iostream>
#include "KillCharAction.h"
#include "LifeAction.h"
#include "MoveCharAction.h"
#include "ShootAction.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace state;
using namespace sf;

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
        //currentCommands[priority] = cmd;
        currentCommands.push_back(cmd);
        //cout<<"Ajout de la commande : " << cmd->getTypeId() << endl;

    }
    
    void Engine::addPassiveCommand(){
        
        //addCommand(priority,cmd);
    }
    
   state::State& Engine::getState(){
        return this ->currentState;
    }
    
    std::stack<std::shared_ptr<Action>>& Engine::update(){
        //cout<<"test update"<<endl;
        static std::stack<std::shared_ptr<Action>> actions;
        static Json::Value out;
        for (int i=0; i<((int)(currentCommands.size()));i++){
            if ((currentCommands[i])->getTypeId() == LOAD){
                //cout << "load command" << endl;
                ((LoadCommand*)(currentCommands[i]))->execute(currentState, actions);
                //((LoadCommand*)(currentCommands[i]))->serialize(out);
            }
            else if((currentCommands[i])->getTypeId() == MOVE_CHAR){
                //cout << "MoveCharcommand" << endl;
                ((MoveCharCommand*)(currentCommands[i]))->execute(currentState, actions);
                //((MoveCharCommand*)(currentCommands[i]))->serialize(out);
            }
            else if((currentCommands[i])->getTypeId() == HANDLE_LIFE){
                //cout << "HandleLife" << endl;
                ((HandleLifesCommand*)(currentCommands[i]))->execute(currentState, actions);
            }
            else if((currentCommands[i])->getTypeId() == SHOOT){
                //cout << "HandleLife" << endl;
                ((ShootCommand*)(currentCommands[i]))->execute(currentState, actions);
                //((ShootCommand*)(currentCommands[i]))->serialize(out);
            }
            /*else if((currentCommands[i])->getTypeId() == HANDLE_IMPACT){
                ((HandleImpactCommand*)(currentCommands[i]))->execute(currentState);
            }*/
            //delete currentCommands[i];
            currentCommands.clear();
            }
        return actions;
    }

    void Engine::undoe(std::stack<std::shared_ptr<Action> >& actions) {
        //cout << "debut undoe" << endl;
        for(size_t k=0; k<actions.size(); k++){
            //cout << "k = " << k << endl;
            if (actions.top().get()->getActionTypeId() == ActionTypeId::KILL_ACTION){
                //cout << "KILL" << endl;
                ((KillCharAction*)(actions.top().get()))->undo(currentState);
                //sleep(milliseconds(1000));
                actions.pop();
            }
            else if (actions.top().get()->getActionTypeId() == ActionTypeId::LIFE_ACTION){
                //cout << "LIFE" << endl;
                ((LifeAction*)(actions.top().get()))->undo(currentState);
                actions.pop();
                //sleep(milliseconds(1000));
            }
            else if (actions.top().get()->getActionTypeId() == ActionTypeId::MOVE_ACTION){
                //cout << "MOVE" << endl;
                ((MoveCharAction*)(actions.top().get()))->undo(currentState);
                //cout << "apres move" << endl;
                //sleep(milliseconds(1000));
                actions.pop();
                
                //cout << "apres" << endl;
            }
            else if (actions.top().get()->getActionTypeId() == ActionTypeId::SHOOT_ACTION){
                //cout << "SHOOT" << endl;
                ((ShootAction*)(actions.top().get()))->undo(currentState);
                actions.pop();
                //sleep(milliseconds(1000));
            }
            
            /*shared_ptr<Action> action = actions.top();
            action->undo(currentState);
            actions.pop();*/
        }
        //cout << "test fin undo " << endl;
    }
}
