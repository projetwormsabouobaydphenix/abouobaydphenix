
#include "MobileElement.h"

namespace state{
    
    MobileElement::MobileElement(){
       
    }
    
    Direction MobileElement::getD() const {
        return this->d;
    }
    
    void MobileElement::setD(Direction d) {
        this->d = d;
    }

    bool MobileElement::isStatic() const{
        return false;
    }
   
   
    

}

