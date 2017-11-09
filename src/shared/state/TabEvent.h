// Generated by dia2code
#ifndef STATE__TABEVENT__H
#define STATE__TABEVENT__H


namespace state {
  class Event;
}

#include "EventTypeId.h"
#include "Event.h"

namespace state {

  /// class TabEvent - 
  class TabEvent : public state::Event {
    // Attributes
  public:
    int x;
    int y;
    // Operations
  public:
    TabEvent (int x, int y);
    EventTypeId getEventType () const;
    // Setters and Getters
  };

};

#endif
