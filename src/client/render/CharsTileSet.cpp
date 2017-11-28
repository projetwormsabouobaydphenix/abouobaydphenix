
#include <iostream>

#include "CharsTileSet.h"
#include "state/Personnage.h"
#include "state/Direction.h"


using namespace std;
using namespace state;


namespace render{

    CharsTileSet::CharsTileSet() {
        Tile vide(0, 0, 32, 32); //vide
        Tile vg(32, 0, 32, 32); //vert gauche
        Tile vd(64, 0, 32, 32); //vert droite
        Tile ng(96, 0, 32, 32); //noir gauche
        Tile nd(128, 0, 32, 32); //noir gauche
        personnage.push_back(vide); //0
        personnage.push_back(vg); //1
        personnage.push_back(vd); //2
        personnage.push_back(ng); //3
        personnage.push_back(nd); //4
        
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
        //std::cout << "getTile de CharsTileSet" << std::endl;
        //state::TypeId typeId = e.getTypeId();
        if (e.getTypeId() == state::TypeId::PERSONNAGE){
            //cout << "personnage" << endl;
            const Personnage& p = (const Personnage&) e;
            /*state::Status statut = p.getStatus();
            if(statut == state::Status::DEAD){
                return this->personnage[0];
            }*/
            if (p.getDirection() == state::Direction::LEFT){ 
                //cout << "left" << endl;
                    if (p.getColor() == 1){ //vert
                        //cout << "vert" << endl;
                        return this->personnage[1];
                    }
                        else if (p.getColor() == 2){ //noir
                            //cout << "noir" << endl;
                            return this->personnage[3];
                        }
                        else{
                            //std::cout << "Ce n'est pas un personnage" << std::endl;
                            return personnage[0];
                        }
                    } 
                    else if (p.getDirection() == state::Direction::RIGHT){ //droite
                        //cout << "right" << endl;
                        if (p.getColor() == 1){ //vert
                            //cout << "vert" << endl;
                            return this->personnage[2];
                        }
                        else if (p.getColor() == 2){ //noir
                            //cout << "noir" << endl;
                            return this->personnage[4];
                        }
                        else{
                            //std::cout << "Ce n'est pas un personnage" << std::endl;
                            return personnage[0];
                        }
                    } 
            
            }
            
            
        
        }
    }


