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
    return TypeId::Personnage;
}

int Personnage::getColor() const{
    return this->color;
}

void Personnage:: setColor(int color){
    this->color=color;
}

int Personnage::getStep() const{
    return this->step;
}

void Personnage::setStep(int step){
    this->step = step;
}

int Personnage::getShoot() const{
    return this->shoot;
}

void Personnage::setShoot(int shoot){
    this->shoot=shoot;
}

}
