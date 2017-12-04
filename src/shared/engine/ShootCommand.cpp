/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShootCommand.h"
#include "state.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace state;

namespace engine{

    ShootCommand::ShootCommand(int color) : color(color) {}
    
   
    CommandTypeId ShootCommand::getTypeId() const{
        return CommandTypeId::SHOOT;
    }
    
    void ShootCommand::execute(state::State& state){
        cout << "debut shoot" << endl;
        ElementTab& tabchars = state.getChars();
        
        size_t width = tabchars.getWidth();
        size_t height = tabchars.getHeight();
        int xp, yp, xe, ye;
        
        
        for (int i = 0; i < (int)height; i++) {
            //cout << "test" << endl;
            for (int j = 0; j < (int)width; j++) {
                //cout << "test2" << endl;
                if (tabchars.list[i * width + j].get() != NULL){
                    if (tabchars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* p = (Personnage*) tabchars.list[i * width + j].get();
                        if (p->getColor() == color) {
                            xp = p->getI();
                            yp = p->getJ();
                            cout << "xp = " << xp << ", yp = " << yp << endl;
                        }
                        else{
                            xe = p->getI();
                            ye = p->getJ();
                            cout << "xe = " << xe << ", ye = " << ye << endl;
                        }
                    }
                }
            }
        }
        
        int distance = sqrt((xp-xe)*(xp-xe)+(yp-ye)*(yp-ye));
        cout << "distance = " << distance << endl;
        if (distance < 10){
            cout << "L'ennemi a été touché." << endl;
            Personnage* ennemy = (Personnage*) tabchars.get(xe, ye);
            int life = ennemy->getLifecount();
            
            if (life > 0){
                ennemy->setLifecount(life-1);
                cout << "Il a perdu une vie. Il en a maintenant : " << ennemy->getLifecount() << endl;
                return;
            }
            else{
                ennemy->setLifecount(life-1);
                cout << "Il n'avait qu'une vie restante. Il est mort" << endl;
                return;
            }
            
        }
    }
}
   