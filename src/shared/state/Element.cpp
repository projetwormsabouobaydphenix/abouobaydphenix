
#include "Element.h"

namespace state{
    

    Element::Element(){
    
    }
    
    bool Element::equals(const Element& other) const {

    }
    
    int Element::getI() const {
        return this->i;
    }

    int Element::getJ() const {
        return this->j;
    }

    void Element::setI(int i) {
        this->i = i;
    }

    void Element::setJ(int j) {
        this->j = j;
    }

    Element::~Element() {

    }
    
}