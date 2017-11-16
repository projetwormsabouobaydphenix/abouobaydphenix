
#include "MobileElement.h"

namespace state{
    
    MobileElement::MobileElement(){
       
    }
    


    bool MobileElement::isStatic() const{
        return false;
    }
   
    Direction MobileElement::getD() const{
        return d;
    }
    
    void MobileElement::setD(Direction d){
        this->d= d;
    }
   
    
    
    
    
}

