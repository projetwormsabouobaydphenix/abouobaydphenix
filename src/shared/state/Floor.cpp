
#include "Floor.h"
namespace state{ 
    
    

    Floor::Floor(){
    
    }

    bool Floor :: isSpace() const{
        return false;
    }

    TypeId Floor::getTypeId() const{
       return TypeId::Floor;
    }

}