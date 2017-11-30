

#include "HeuristicAI.h"
#include "engine/Engine.h"
#include "state/Personnage.h"
#include "engine/OrientationCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/ShootCommand.h"
#include "state/Space.h"
#include "engine/HandleLifesCommand.h"
#include "engine/Command.h"
#include "state/Floor.h"
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;
using namespace state;
using namespace engine;

namespace ai {
    
    HeuristicAI::HeuristicAI(const state::State& state, int i, int j){
       
    }
    
    const PathMap& HeuristicAI::getEnnemyMap() const{
        return HeuristicAI::ennemyMap;
    }
    
    const PathMap& HeuristicAI::getLifeMap() const{
        return HeuristicAI::lifeMap;
    }
    
    bool HeuristicAI::dijkstra(){
        
    }
    
    void HeuristicAI::run(engine::Engine& engine, int i, int j){
        
        State& state = engine.getState();
        ElementTab& grid = state.getGrid();
        Element* top = grid.get(i,j);                    
        Point* ennemy= new Point(); 
        
        lifeMap.init(grid);       
        lifeMap.setWeights(4*grid.getWidth()+7,0);
        lifeMap.setWeights(3*grid.getWidth()+20,0);
        std::vector<int> weightslife = lifeMap.getWeights();

        ennemyMap.init(grid);
        
        if (top->getTypeId()== TypeId::PERSONNAGE){
            Personnage* player = (Personnage*)top;
            for(size_t x = 0; x<grid.getWidth(); x++){
                for(size_t y =0; y<grid.getHeight(); y++){
                    if(lifeMap.getWeight(Point(x,y))==(std::numeric_limits<int>::max())){
                        int dist1 = sqrt((20-x)*(20-x)+(3-y)*(3-y));
                        int dist2 = sqrt((7-x)*(7-x)+(4-y)*(4-y));
                        lifeMap.setWeights(y*grid.getWidth()+x, min(dist1,dist2));
                       
                       
                    }

                    if(grid.get(x,y)->getTypeId()==TypeId::PERSONNAGE){
                        Personnage* perso = (Personnage*)grid.get(x,y);
                        if(perso->getColor() != player->getColor()){                            
                            ennemy->setX(x);
                            ennemy->setY(y);
                            ennemyMap.setWeights(y*grid.getWidth()+x, 0);
                        }
                    }          
                }
            }
            for(size_t x = 0; x<grid.getWidth(); x++){
                for(size_t y =0; y<grid.getHeight(); y++){
                    if(ennemyMap.getWeight(Point(x,y))==(std::numeric_limits<int>::max())){
                        int dx = ennemy->getX();
                        int dy = ennemy->getY();
                        int dist = sqrt((dx-x)*(dx-x)+(dy-y)*(dy-y));                      
                        ennemyMap.setWeights(y*grid.getWidth()+x, dist);
                        
                    }
                }   
            }
            while(player->getStepcount() != 0){               
                if(player->getLifecount()<3){
                    //lifeMap (PointCompareWeight(Point(i-1,j), Point(i+1,j)));
                }
                   /* if(weightslife[j*grid.getWidth()+i-1] != 0 and weightslife[j*grid.getWidth()+i-1]< weightslife[j*grid.getWidth()+i]){
                        Command* orientleft = new engine::OrientationCommand(i,j,Direction::LEFT);
                        engine.addCommand(1,orientleft);
                        Command* move = new engine::MoveCharCommand(i,j);
                        engine.addCommand(2,move);
                        engine.update();
                    }
                    
                   
                    
                }*/
                
            }
        }
        
        
        
        
        
    }
        
}
