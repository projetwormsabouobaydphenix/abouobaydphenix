
#include "AI.h"
#include "../state.h"
#include "../engine.h"
#include <iostream>
#include <vector>

using namespace state;
using namespace engine;
using namespace std;

namespace ai{
        
    void AI::listCommands (std::vector<engine::Command*> list, state::State& state, int i, int j){
        
        ElementTab& chars = state.getChars();
        int playerStatus = state.getJoueur();
        Personnage* p = (Personnage*)chars.get(i,j);
        
        if (p->getColor() == playerStatus)
        {
            // on déclare les cases autour de la case de coordonnées (i,j)
            Personnage* pNordEst;
            Personnage* pEst;
            Personnage* pSudEst;
            Personnage* pSudOuest;
            Personnage* pOuest;
            Personnage* pNordOuest;
            
            // on récupère les tuiles correspondantes à toutes les directions
            // en distinguant si on se situe sur une ligne paire
            
            pNordEst = ((Personnage*)chars.get(i-1,j));
            pEst = ((Personnage*)chars.get(i,j+1));
            pSudEst = ((Personnage*)chars.get(i+1,j));
            pSudOuest = ((Personnage*)chars.get(i+1,j-1));
            pOuest = ((Personnage*)chars.get(i,j-1));
            pNordOuest = ((Personnage*)chars.get(i-1,j-1));
            
            // ou une ligne impaire
            /*else
            {
                teamNordEst = ((Team*)teamBoard.getElement(i-1,j+1));
                teamEst = ((Team*)teamBoard.getElement(i,j+1));
                teamSudEst = ((Team*)teamBoard.getElement(i+1,j+1));
                teamSudOuest = ((Team*)teamBoard.getElement(i+1,j));
                teamOuest = ((Team*)teamBoard.getElement(i,j-1));
                teamNordOuest = ((Team*)teamBoard.getElement(i-1,j));
            }*/
            
            
}
        /*ElementTab tabchars= state.getChars();
        Element* top;
        top= tabchars.get( i, j);
        ElementTab grid = state.getGrid();
        Element* nextl = grid.get(i-1,j);

        Element* nextr = grid.get(i+1,j);
        MoveCharCommand* move = new MoveCharCommand(i,j);
        OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
        OrientationCommand* orientleft = new OrientationCommand(i,j,LEFT);
       
        if(top->getTypeId()== PERSONNAGE){
           // Personnage* perso = (Personnage*)top;

        Element* nextr = grid.get(i+1,j);*/
        //cout<<"test random ai 2"<<endl;
       /* Command* commande;
        commande = new MoveCharCommand(i,j);
        list.push_back(commande);
        commande = new OrientationCommand(i,j, Direction::LEFT);
        list.push_back(commande);
        commande = new OrientationCommand(i,j, Direction::RIGHT);
        list.push_back(commande);*/
        //cout<<"test random ai 3"<<endl;
        /*if(top->getTypeId()== PERSONNAGE){
            Personnage* perso = (Personnage*)top;

            if(nextl->getTypeId()==FLOOR){
                OrientationCommand* orientright = new OrientationCommand(i,j,RIGHT);
                list.push_back(orientright);
                list.push_back(move);
                if(nextr->getTypeId()==SPACE){
                    Space* nextri = (Space*)nextr;
                    if (nextri->getNature()==LIFE){
                        HandleLifesCommand* add = new HandleLifesCommand;
                        list.push_back(add);
                    }
                }
            }
            
            if(nextr->getTypeId()==FLOOR){
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
            
            

        }*/   

        }   

    }
    
    