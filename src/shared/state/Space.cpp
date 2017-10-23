
#include "Space.h"

namespace state{
        
    Space::Space() {

    }

    
    bool state::Space::isSpace () const{
        return true;
    }
    
    TypeId state::Space::getTypeId () const{
        return TypeId::SPACE;
    }
    
    
    bool state::Space::isStatic() const {
        return true;

    }


    
    
    
}

