
#include "State.h"

namespace state{
        
    ElementTab& state::State::getChars() {
        return this->chars;
    }
    
    int state::State::getEpoch() const {
        return this->epoch;
    }

    int state::State::getEpochrate() const {
        return this->epochrate;
    }
    
    ElementTab& state::State::getGrid() {
        return this->grid;
    }

    int state::State::getStepcount() const {
        return this->stepcount;
    }

    void state::State::setEpoch(int epoch) {
        this->epoch=epoch;
    }

    void state::State::setEpochrate(int epochrate) {
        this->epochrate=epochrate;
    }

    void state::State::setStepcount(int stepcount) {
        this->stepcount=stepcount;
    }
    
    
}