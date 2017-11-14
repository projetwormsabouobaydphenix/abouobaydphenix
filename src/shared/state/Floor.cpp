
#include "Floor.h"


namespace state{ 
    
    Floor::Floor(FloorTypeId id){
    
    }

    bool state::Floor::isSpace() const{
        return false;
    }

    TypeId state::Floor::getTypeId() const{
       return TypeId::FLOOR;
    }
    
    bool Floor::equals(const Element& other) const {
        if (other.getTypeId() == TypeId::FLOOR){
            return true;
        }
        
        else{
            return false;
        }

    }

    FloorTypeId Floor::getNature() const{
        return this->nature;
    }
    
    void Floor::setNature(FloorTypeId nature){
        this->nature =nature;
    }

}