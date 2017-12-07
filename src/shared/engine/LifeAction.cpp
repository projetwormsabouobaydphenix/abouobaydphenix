/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LifeAction.h"
#include "HandleLifesCommand.h"

using namespace std;
using namespace state;

namespace engine{
    
    LifeAction::LifeAction(int color, int lifeCount, Personnage* persoApAction){
        this->color=color;
        this->lifeCount=lifeCount;
        this->persoApAction= persoApAction;
    }
    
    void LifeAction::apply(state::State& state){
        persoApAction->setLifecount(lifeCount+1);
    }
    
    void LifeAction::undo(state::State& state){
        persoApAction->setLifecount(lifeCount);
    }

    ActionTypeId LifeAction::getActionTypeId() const {
        return ActionTypeId::LIFE_ACTION;
    }

}