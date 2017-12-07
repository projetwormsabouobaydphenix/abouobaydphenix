/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShootAction.h"
#include "state.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    ShootAction::ShootAction(int color, Personnage* ennemy, int life){
        this->color=color;
        this->ennemy= ennemy;
        this->life=life;
    }
    
    void ShootAction::apply(state::State& state){
        ennemy->setLifecount(life-1);
        cout << "Il a perdu une vie. Il en a maintenant : " << ennemy->getLifecount() << endl;
    }
    
    void ShootAction::undo(state::State& state){
        ennemy->setLifecount(life);
    }

    ActionTypeId ShootAction::getActionTypeId() const {
        return ActionTypeId::SHOOT_ACTION;
    }
    
}