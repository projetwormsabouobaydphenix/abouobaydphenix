
#include "Space.h"

namespace state{
        
    Space::Space(SpaceTypeId id) {

    }

    
    bool state::Space::isSpace () const{
        return true;
    }
    
    TypeId state::Space::getTypeId () const{
        return TypeId::SPACE;
    }
    
    SpaceTypeId state::Space::getSpaceTypeId () const{
        return SpaceTypeId::EMPTY;  //Le vrai code sera inséré après
    }
       

    bool state::Space::isStatic() const {
        return true;

    }
    
    void Space::setSpaceTypeId(SpaceTypeId id) {
        
    }

    bool Space::equals(const Element& other) const {
        /*if (other.getTypeId() == TypeId::SPACE){
            return true;
        }
        
        else{
            return false;
        }*/
        return true;
    }



    
    
    
}

