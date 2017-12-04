/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HandleLifesCommand.h"
#include "state.h"
#include "state/SpaceTypeId.h"
#include <iostream>

using namespace std;
using namespace state;

namespace engine {
    
    HandleLifesCommand::HandleLifesCommand(int color) : color(color) {

    }
   
    
    void HandleLifesCommand::execute(state::State& state) {
        ElementTab& chars = state.getChars();
        ElementTab& grid = state.getGrid();
        
        size_t width = chars.getWidth();
        size_t height = chars.getHeight();
        
        for (int i = 0; i < (int)height; i++) {
            for (int j = 0; j < (int)width; j++) {
                if (chars.list[i * width + j].get() != NULL){
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* p = (Personnage*) chars.list[i * width + j].get();
                        if (p->getColor() == color) {
                            int x = p->getI();
                            int y = p->getJ();
                            if (grid.get(x, y)->getTypeId() == state::TypeId::SPACE){
                                Space* s = (Space*) grid.get(x, y);
                                    if (s->getNature() == SpaceTypeId::LIFE) {
                                        if (p->getLifecount() < 3){
                                            p->setLifecount(p->getLifecount() + 1);
                                            cout << "Super, le personnage a récupéré une vie" << endl;
                                            cout << "Il en a maintenant " << p->getLifecount() << endl;
                                        }
                                        else{
                                            cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                        }
                                    }
                            }
                        }
                    }
                }
            }
        }
    }

    


    CommandTypeId engine::HandleLifesCommand::getTypeId () const{
        return CommandTypeId::HANDLE_LIFE;
    }
    
 
}
