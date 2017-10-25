// Generated by dia2code
#ifndef STATE__FLOOR__H
#define STATE__FLOOR__H


namespace state {
  class StaticElement;
}

#include "FloorTypeId.h"
#include "TypeId.h"
#include "StaticElement.h"

namespace state {

  /// class Floor - 
  class Floor : public state::StaticElement {
    // Operations
  public:
    Floor (FloorTypeId id);
    bool isSpace () const;
    TypeId getTypeId () const;
    bool isStatic () const;
    // Setters and Getters
  };

};

#endif
