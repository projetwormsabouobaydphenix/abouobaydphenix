
#include "Space.h"

namespace state{
        
    Space::Space() {

    }

    
    bool state::Space::isSpace () const{
        return true;
    }
    
    TypeId state::Space::getTypeId () const{
        return TypeId::Space;
    }
    
    SpaceTypeId state::Space::getSpaceTypeId () const{
        return SpaceTypeId::Empty;  //Le vrai code sera inséré après
    }
    
    void state::Space::setSpaceTypeId(SpaceTypeId id) const {

    }
    
    bool state::Space::isStatic() const {
        return true;

    }


    
    
    
}

