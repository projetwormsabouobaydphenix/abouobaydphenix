#include "Personnage.h"

namespace state {

    
    Personnage::Personnage(int color) {
        if (color == 1 or color == 2){
            this->color = color;
        }
        else{
            this->color=0;
        }

    }
    
    Personnage::~Personnage() {

    }

    
TypeId state::Personnage::getTypeId() const{
    return TypeId::PERSONNAGE;
}

int state::Personnage::getColor() const{
    return this->color;
}

void state::Personnage:: setColor(int color){
    this->color=color;
}

int state::Personnage::getStep() const{
    return this->Step;
}

void state::Personnage::setStep(int step){
    this->Step = step;
}

int state::Personnage::getShoot() const{
    return this->Shoot;
}

void state::Personnage::setShoot(int shoot){
    this->Shoot=shoot;
    }
}

