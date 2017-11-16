#include "Personnage.h"
#include "State.h"

namespace state {
     
    Personnage::Personnage() {
        
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

    int Personnage::getLifecount() const {
        return this->lifecount;
    }

    int Personnage::getShootcount() const {
        return this->shootcount;
    }

    int Personnage::getStepcount() const {
        return this->stepcount;
    }

    void Personnage::setLifecount(int lifecount) {
        this->lifecount = lifecount;
    }

    void Personnage::setShootcount(int shootcount) {
        this->shootcount = shootcount;
    }
    
    void Personnage::setStepcount(int stepcount) {
        this->stepcount = stepcount;
    }
    
    bool Personnage::equals(const Element& other) const {
        if (other.getTypeId() == TypeId::PERSONNAGE){
            return true;
        }

        else{
            return false;
        }
        return true;
    }

    Status Personnage::getStatus() const{
        return status;
    }
    
    void Personnage::setStatus(Status status){
        this->status=status;
    }
   
}



