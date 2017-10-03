
#include "Element.h"

using namespace std;
namespace state{
    

    Element::Element(){
    
    }   

    int Element:: getX() const{
        return this->x;
    }

    int Element:: getY() const{
        return this->y;
    }

    void Element::setX(int x){
        this->x=x;
    }

    void Element::setY(int y){
        this->y=y;
    }
}