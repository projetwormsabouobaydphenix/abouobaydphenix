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

    int state::Personnage::getStepcount() const{
        return this->stepcount;
    }

    void state::Personnage::setStepcount(int step){
        this->stepcount = step;
    }

    int state::Personnage::getShootcount() const{
        return this->shootcount;
    }

    void state::Personnage::setShootcount(int shoot){
        this->shootcount=shoot;
        }

    bool Personnage::equals(const Element& other) const {
        if (other.getTypeId() == TypeId::PERSONNAGE){
            return true;
        }

        else{
            return false;
        }
    }


    int Personnage::getLifecount() const{
        return lifecount;
    }    

    void Personnage::setLifecount(int lifecount){
        this->lifecount=lifecount;
    }

    Status Personnage::getStatus() const{
        return this->status;
    }

    void Personnage::setStatus(Status status){
        this->status=status;
    }

    int Personnage::getI() const{
        return this->i;
    }

    int Personnage::getJ() const{
        return this->j;
    }

    void Personnage::setI(int i){
        this->i=i;
    }

    void Personnage::setJ(int j){
        this->j=j;
    }

}

