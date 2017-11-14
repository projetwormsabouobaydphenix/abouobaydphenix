// Generated by dia2code
#ifndef STATE__PERSONNAGE__H
#define STATE__PERSONNAGE__H


namespace state {
  class Element;
  class MobileElement;
}

#include "Status.h"
#include "TypeId.h"
#include "MobileElement.h"

namespace state {

  /// class Personnage - 
  class Personnage : public state::MobileElement {
    // Associations
    // Attributes
  protected:
    int color;
    int stepcount     = 0;
    int shootcount     = 0;
    int lifecount     = 3;
    Status status;
    // Operations
  public:
    Personnage  ();
    ~Personnage ();
    TypeId  getTypeId () const;
    bool equals (const Element& other) const;
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
    int getStepcount() const;
    void setStepcount(int stepcount);
    int getShootcount() const;
    void setShootcount(int shootcount);
    int getLifecount() const;
    void setLifecount(int lifecount);
    Status getStatus() const;
    void setStatus(Status status);
  };

};

#endif
