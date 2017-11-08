
#include <algorithm>

#include "Observable.h"

namespace state{

    void Observable::ajouterObserver(Observer* o) {
        observers.push_back(o);
    }

    void Observable::notifierObserver()  {
        for (auto observer:observers){
            observer->notifier() ;
        }
    }

    void Observable::supprimerObserver(Observer* o)  {
        std::vector<Observer*>::iterator it= std::find(observers.begin(), observers.end(),o);
        if(it != observers.end()){
            observers.erase(it);
        }
    }
    
    
    
}