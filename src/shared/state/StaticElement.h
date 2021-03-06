// Generated by dia2code
#ifndef STATE__STATICELEMENT__H
#define STATE__STATICELEMENT__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class StaticElement - 
  class StaticElement : public state::Element {
    // Operations
  public:
    StaticElement ();
    virtual bool isSpace () const = 0;
    bool isStatic () const;
    // Setters and Getters
  };

};

#endif
