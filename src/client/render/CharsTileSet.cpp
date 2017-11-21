
#include <iostream>

#include "CharsTileSet.h"
#include "state/Personnage.h"
#include "state/Direction.h"


using namespace std;


namespace render{

    CharsTileSet::CharsTileSet() {
        Tile vd(32,0,32,36); //vert droite
        Tile vg(0,0,32,36); //vert gauche
        Tile nd(32,36,32,36); //noir droite
        Tile ng(0,36,32,36); //noir gauche
        personnage.push_back(vd); //0
        personnage.push_back(vg); //1
        personnage.push_back(nd); //2
        personnage.push_back(ng); //3
        
    }
    

    int CharsTileSet::getCellHeight() const {
        return personnage[0].getHeight();
    }

    int CharsTileSet::getCellWidth() const {
        return personnage[0].getWidth();
    }

    const std::string CharsTileSet::getImageFile() const {
        return "res/personnage.png";
    }

    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        std::cout << "getTile de CharsTileSet" << std::endl;
        if (!e.isStatic()){
            //MobileElement* mobile = (MobileElement*) e;
            state::TypeId typeId = e.getTypeId();
            if (typeId == state::TypeId::PERSONNAGE){
                state::Personnage& p = (state::Personnage&) e;
                state::Status statut = p.getStatus();
                if(statut == state::Status::DEAD){
                    return this->personnage[0];
                }
                else if (statut == state::Status::ALIVE){
                    if (p.getD() == state::Direction::LEFT){ 
                        if (p.getColor() == 0){ //noir
                            return this->personnage[3];
                        }
                        else if (p.getColor() == 1){ //vert
                            return this->personnage[1];
                        }
                    } 
                    else if (p.getD() == state::Direction::RIGHT){ //droite
                        if (p.getColor() == 0){ //noir
                            return this->personnage[2];
                        }
                        else if (p.getColor() == 1){ //vert
                            return this->personnage[0];
                        }
                    } 
                }
            }
            else{
                std::cout << "Erreur, ce n'est pas un personnage" << std::endl;
                return personnage[0];
            }
        }
        else {
            return personnage[0];
        }
    }
}

