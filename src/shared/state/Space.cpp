
#include "Space.h"

namespace state{
    
    bool Space::isSpace () const{
        return true;
    }
    
    TypeId Space::getTypeId () const{
        return TypeId::Space;
    }
    
    SpaceTypeId Space::getSpaceTypeId () const{
        return SpaceTypeId::Empty;  //Le vrai code sera inséré après
    }
    
    void Space::setSpaceTypeId(SpaceTypeId id) const {

    }

    
    
    
}

