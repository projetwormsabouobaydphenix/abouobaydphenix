// Generated by dia2code
#ifndef STATE__MOBILEELEMENT__H
#define STATE__MOBILEELEMENT__H


namespace state {
  class Element;
}

#include "Direction.h"
#include "Element.h"

namespace state {

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Operations
  public:
    MobileElement (Direction id);
    bool equals (const Element& other) const;
    bool isStatic () const;
    // Setters and Getters
  };

};

#endif
