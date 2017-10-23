
#include "Floor.h"


namespace state{ 
    
    Floor::Floor(){
    
    }

    bool state::Floor::isSpace() const{
        return false;
    }

    TypeId state::Floor::getTypeId() const{
       return TypeId::FLOOR;
    }
        bool Floor::isStatic() const {
            return true;

    }


}