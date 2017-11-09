
#include "TabEvent.h"

namespace state{

    TabEvent::TabEvent(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    
    EventTypeId TabEvent::getEventType() const {
        return EventTypeId::EVENT_TAB;
    }
    
    
    
}
