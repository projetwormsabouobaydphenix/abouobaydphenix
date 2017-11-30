
#include "Point.h"
#include <iostream>

namespace ai{

    Point::Point(int x, int y, int weight) : x(x), y(y), weight(weight) {

    }
    
    int Point::getWeight() const {
        return this->weight;
    }

    int Point::getX() const {
        return this->x;
    }

    int Point::getY() const {
        return this->y;
    }

    void Point::setWeight(int weight) {
       this->weight = weight;
    }

    void Point::setX(int x) {
        this->x = x;
    }

    void Point::setY(int y) {
        this->y = y;
    }

    Point Point::transform(state::Direction d) {
        
        Point p(x,y,weight);
        //if(d == UP) p.y++;
        if(d == state::Direction::RIGHT){
            p.x++;
        }
        else if(d == state::Direction::LEFT){
            p.x--;
        }
        
        else {
            std::cout << "Erreur : Ce n'est pas une direction" << std::endl;
        }
        
        return p; 

    }











}
