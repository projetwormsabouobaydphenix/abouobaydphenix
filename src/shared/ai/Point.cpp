/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Point.h"

using namespace std;

namespace ai{
    
    Point::Point(int x, int y, int w){
        
    }
    
    int Point::getWeight() const{
        return weight;
    }
    
    int Point::getX() const{
        return x;
    }
    
    int Point::getY() const{
        return y;
    }
    
    void Point::setWeight(int weight){
        this->weight = weight;
    }
    
    void Point::setX(int x){
        this->x=x;
    }
    
    void Point::setY(int y){
        this->y = y;
    }
    
    Point Point::transform(state::Direction d){
        /*if (d==state::Direction::LEFT){
            if(weight>0){
            return Point(x-1, y, weight);
            }
            else{
                return Point(x-1, y+1, )
            }
            //setX(x-1);
        }
        else {
            return Point(x+1, y, weight);
            //setX(x+1);
        }*/
    }
}