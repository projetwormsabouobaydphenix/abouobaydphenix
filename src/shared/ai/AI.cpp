
#include "AI.h"
#include "../state.h"
#include "../engine.h"
#include <iostream>
#include <vector>

using namespace state;
using namespace engine;
using namespace std;

namespace ai{
        
    void AI::listCommands (std::vector<engine::Command*>& list, state::State& state, int i, int j){
        ElementTab& tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        top->setI(i);
        top->setJ(j);
        ElementTab& grid = state.getGrid();
        Element* nextr;
        Element* nextl;
        
        if(i!=0){
            nextl = grid.get(i-1,j);
        }
        else { nextl= grid.get(i,j);}
        
        int width = grid.getWidth();
        
        if(i != (width-1)){
            nextr = grid.get(i+1,j);
        }
        else { nextr = grid.get(i,j);}
        
        MoveCharCommand* move = new MoveCharCommand(i,j);
        //OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
        //OrientationCommand* orientleft = new OrientationCommand(i,j,LEFT);
       
   
        cout<<"test random ai 2"<<endl;
       
        if(top->getTypeId()== PERSONNAGE){
            //cout<<"test perso"<<endl;
            //Personnage* perso = (Personnage*)top;
            
            cout<<"test nextl"<<endl;
            if((nextl->getTypeId())==FLOOR){
                cout<<"test passé"<<endl;
                OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
                list.push_back(orientright);
                list.push_back(move);
                if((nextr->getTypeId())==SPACE){
                    Space* nextri = (Space*)nextr;
                    if (nextri->getNature()==LIFE){
                        HandleLifesCommand* add = new HandleLifesCommand;
                        list.push_back(add);
                    }
                }
            }
            
            else if(nextr->getTypeId()==FLOOR){
                cout<<"nextr fonctionne"<<endl;
                OrientationCommand* orientleft = new OrientationCommand(i,j,LEFT);
                list.push_back(orientleft);
                list.push_back(move);
                if(nextl->getTypeId()==SPACE){
                    Space* nextle = (Space*)nextl;
                    if (nextle->getNature()==LIFE){
                        HandleLifesCommand* add = new HandleLifesCommand;
                        list.push_back(add);
                    }
                }
            }

            else {
                OrientationCommand* orientleft = new OrientationCommand(i,j,LEFT);
                list.push_back(orientleft);
                OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
                list.push_back(orientright);
                list.push_back(move);
                if(nextl->getTypeId()==SPACE){
                    Space* nextle = (Space*)nextl;
                    if (nextle->getNature()==LIFE){
                        HandleLifesCommand* add = new HandleLifesCommand;
                        list.push_back(add);
                    }
                }
            }
        } 
    }    
}
    
    