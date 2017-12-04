

#include "HeuristicAI.h"
#include "engine/Engine.h"
#include "state/Personnage.h"
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
       /* //cout << "debut heuristic" << endl;
        State& state = engine.getState();
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();
        Element* top = chars.get(i,j);                    
        Point* ennemy= new Point(); 
        
        lifeMap.init(grid);       
        lifeMap.setWeights(4*grid.getWidth()+7,0);
        lifeMap.setWeights(3*grid.getWidth()+20,0);
        std::vector<int> weightslife = lifeMap.getWeights();
        //cout << "test 10" << endl;
        ennemyMap.init(grid);
        //cout << "test 11" << endl;
        if (top->getTypeId()== TypeId::PERSONNAGE){
            //cout << "test 1" << endl;
            Personnage* player = (Personnage*)top;
            for(size_t x = 0; x<grid.getWidth(); x++){
                //cout << x << endl;
                for(size_t y =0; y<grid.getHeight(); y++){
                    //cout << y << endl;
                    //if(lifeMap.getWeight(Point(x,y))==(std::numeric_limits<int>::max())){
                    if(weightslife[y*grid.getWidth()+x]==(std::numeric_limits<int>::max())){
                        //cout << "test 2" << endl;
                        int dist1 = sqrt((20-x)*(20-x)+(3-y)*(3-y));
                        int dist2 = sqrt((7-x)*(7-x)+(4-y)*(4-y));
                        //cout << "calcul" << endl;
                        lifeMap.setWeights(y*grid.getWidth()+x, min(dist1,dist2));
                       
                       
                    }

                    /*if(chars.get(x,y)->getTypeId()==TypeId::PERSONNAGE){
                        cout << "test 3" << endl;
                        Personnage* perso = (Personnage*)chars.get(x,y);
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
                        //cout << "test 4" << endl;
                        int dx = ennemy->getX();
                        int dy = ennemy->getY();
                        int dist = sqrt((dx-x)*(dx-x)+(dy-y)*(dy-y));                      
                        ennemyMap.setWeights(y*grid.getWidth()+x, dist);
                        
                    }
                }   
            }
            //if(player->getStepcount() != 3){              
                if(player->getLifecount()<3){
                    //cout << "test 5" << endl;
                    if(weightslife[j*grid.getWidth()+i+1]<0){
                        if(lifeMap.compare(weightslife[j*grid.getWidth()+i], weightslife[(j-1)*grid.getWidth()+i+1])){
                            Command* move = new MoveCharCommand(i,j, state::Direction::RIGHT); // ajout direction left
                            engine.addCommand(0, move);
                            engine.update();
                        }
                       
                        else {
                            Command* move = new MoveCharCommand(i,j, state::Direction::LEFT);
                            engine.addCommand(0,move);
                            engine.update();
                        }
                    }
                   
                    else if (lifeMap.compare(weightslife[j*grid.getWidth()+i+1], weightslife[(j)*grid.getWidth()+i])){
                            Command* move = new MoveCharCommand(i,j, state::Direction::RIGHT);
                            engine.addCommand(0,move);
                            engine.update();
                    }
                   
                    else {
                        //cout << "test 7" << endl;
                        Command* move = new MoveCharCommand(i,j, state::Direction::LEFT);
                        engine.addCommand(0,move);
                        engine.update();
                    }
        //}
                //player->setStepcount(player->getStepcount()+1);
        
        
        
        
    }
        
}
        else{
            cout << "test 12" << endl;
        }*/
    }
}
