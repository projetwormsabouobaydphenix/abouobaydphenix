
#include "StateEvent.h"

namespace state{

    StateEvent::StateEvent(StateEventId se) {
        this->stateEvent = se;
    }

    EventTypeId StateEvent::getEventType() const {
        return EventTypeId::EVENT_STATE;
    }
    
    
    
    
    
    
}