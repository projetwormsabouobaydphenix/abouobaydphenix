
#include "AI.h"
#include "state.h"
#include "engine.h"
#include <iostream>
#include <vector>

using namespace state;
using namespace engine;
using namespace std;

namespace ai{
        
    void AI::listCommands (std::vector<engine::Command*> list, state::State& state, int i, int j){
        ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        ElementTab grid = state.getGrid();
        Element* nextl = grid.get(i-1,j);
        Element* nextr = grid.get(i+1,j);
        MoveCharCommand* move = new MoveCharCommand(i,j);
        if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;
            if(nextl->getTypeId()==FLOOR){
                OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
                list.push_back(orientright);
                list.push_back(move);
            }
            
            if(nextr->getTypeId()==FLOOR){
                OrientationCommand* orientleft = new OrientationCommand(i,j,LEFT);
                list.push_back(orientleft);
                list.push_back(move);
            }            
        }   
    }
}    