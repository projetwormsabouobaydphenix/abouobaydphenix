
#include "State.h"

namespace state{
        
    ElementTab& State::getChars() {
        return this->chars;
    }
    
    int State::getEpoch() const {
        return this->epoch;
    }

    int State::getEpochrate() const {
        return this->epochrate;
    }
    
    ElementTab& State::getGrid() {
        return this->grid;
    }

    int State::getStepcount() const {
        return this->stepcount;
    }

    void State::setEpoch(int epoch) {
        this->epoch=epoch;
    }

    void State::setEpochrate(int epochrate) {
        this->epochrate=epochrate;
    }

    void State::setStepcount(int stepcount) {
        this->stepcount=stepcount;
    }
    
    
}