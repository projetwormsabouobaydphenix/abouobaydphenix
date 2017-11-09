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
        
        int stepcount=state.getStepcount();
        if(stepcount<3){
            cout<<"Le personnage s'est déplacé d'une case."<<endl;
        stepcount=stepcount+1;
        state.setStepcount(stepcount);
        ElementTab chars= state.getChars();
        
        }
        else {
            cout<<"Le personnage a épuisé le nombre de pas autorisés pour un tour."<<endl;
        } 
    }
    
    CommandTypeId engine::MoveCharCommand::getTypeId () const{
        return CommandTypeId::MOVE_CHAR;
    }
    
    void engine::MoveCharCommand::execute (state::State& state){
        int stepcount=state.getStepcount();
        if(stepcount<3){
            cout<<"Le personnage s'est déplacé d'une case."<<endl;
        stepcount=stepcount+1;
        state.setStepcount(stepcount);
        ElementTab chars= state.getChars();
        //Voir comment on peut sélectionner un personnage en particulier et le décaler d'une case dans la grille
        }
        else {
            cout<<"Le personnage a épuisé le nombre de pas autorisés pour un tour."<<endl;
        } 
    }
    
    int engine::MoveCharCommand::getCharacter() const{
        //return this->character;
    }
    
    void setCharacter(int character){
       //this->character=character;
    }
    
    Command::~Command(){}
}