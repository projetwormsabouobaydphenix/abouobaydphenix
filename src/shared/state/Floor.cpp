
#include "Floor.h"


namespace state{ 
    
    

    Floor::Floor() : state::StaticElement(){
    
    }

    bool Floor :: isSpace() const{
        return false;
    }

    TypeId state::Floor::getTypeId() const{
       return TypeId::Floor;
    }

}