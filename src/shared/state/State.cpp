
#include "State.h"

namespace state{
        
    ElementTab& state::State::getChars() {
        return this->Chars;
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

  
    

    void state::State::setEpoch(int epoch) {
        this->epoch=epoch;
    }

    void state::State::setEpochrate(int epochrate) {
        this->epochrate=epochrate;
    }

   
    
}