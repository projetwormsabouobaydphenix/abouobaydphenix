
#include "StaticElement.h"

namespace state{
    
    StaticElement::StaticElement() {

    }
    
    bool StaticElement::isStatic() const {
        return true;
    }

    bool StaticElement::isSpace() const {
        return true;
    }
}

