
#include "Element.h"

namespace state{
    

    Element::Element(){
    
    }
    
    Element::~Element(){
        
    }
    
    int Element::getI() const{
        return i;
    }
    
    int Element::getJ() const{
        return j;
    }
    
    void Element::setI(int i){
        this->i=i;
    } 
    
    void Element::setJ(int j){
        this->j=j;
    }

}