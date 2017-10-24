
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
    
<<<<<<< HEAD
    SpaceTypeId state::Space::getSpaceTypeId () const{
        return SpaceTypeId::EMPTY;  //Le vrai code sera inséré après
    }
       
=======
    
>>>>>>> 354a9cd21019c6cacb51d82aa3781ccb62ff8e6b
    bool state::Space::isStatic() const {
        return true;

    }


    
    
    
}

