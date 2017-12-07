
#include "PathMap.h"
#include "../state.h"
#include <iostream>
#include <limits>

using namespace state;
using namespace std;

namespace ai {
    
    int PathMap::getWeight(const Point& p) const{
        return p.getWeight();
    }
    
    void PathMap::init(const state::ElementTab& grid){
        weights.resize(grid.getWidth()*grid.getHeight());
        //cout << "taille weights" << weights.size()<< endl;

        Point* p = new Point();
        for (size_t i =0; i< grid.getWidth(); i++){
            for (size_t j =0; j < grid.getHeight(); j++){
                if((grid.list[j*width+i].get()->getTypeId())== state::TypeId::FLOOR){
                    //cout << "test 9" << endl;
                    weights[j*grid.getWidth()+i]= -1;
                    p->setX(i);
                    p->setY(j);
                    int& w = weights[j*grid.getWidth()+i];
                    p->setWeight(w);
                    //cout<<"le poids est"<<p->getWeight()<<"."<<endl;
                    queue.push(*p);    
                    }
                
                else {
                    //cout << "test 8" << endl;
                    weights[j*grid.getWidth()+i]= std::numeric_limits<int>::max();
                    //p->setX(i);
                    //p->setY(j);
                    //int& w = weights[j*grid.getWidth()+i];
                    //p->setWeight(w);
                    //queue.push(*p);     
                    //cout << "test 10" << endl;
                }
            }
        }
    }
    
    void PathMap::addSink(Point p, int weight){
        PathMap::queue.push(p);
    }
    
    const std::vector<int> PathMap::getWeights() const{
        //const int* p1 = &weights[0];
        return weights;
    }
    
    void PathMap::setWeight(const Point& p, int w){
        //p.setWeight(w);
       
    }
    
    void PathMap::setWeights(int indice, int valeur){
       // cout << "test 14" << endl;
        weights[indice] = valeur;
        
    }

    void PathMap::update(const state::ElementTab& grid) {

        size_t width = grid.getWidth();
        size_t height = grid.getHeight();
        int w = 1;
        for (int i = 0; i<(int)height; i++){
            for (int j = 0; j<(int)width; j++){
                if (grid.get(j,i)->getTypeId() == TypeId::SPACE){
                    weights[i*width+j] = w;
                    w = w + 1;
                }
                else{
                    weights[i*width+j] = 0;
                }
            }
        }
    }
    
    bool PathMap::compare(int a, int b){
        return (a<b);
    }
    
}

