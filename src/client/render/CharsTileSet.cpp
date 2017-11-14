
#include <iostream>

#include "CharsTileSet.h"
#include "state/Personnage.h"
#include "state/Direction.h"


using namespace std;

namespace render{

    CharsTileSet::CharsTileSet() {

    }
    

    int CharsTileSet::getCellHeight() const {
        return personnage[0].getHeight();
    }

    int CharsTileSet::getCellWidth() const {
        return personnage[0].getWidth();
    }

    const std::string CharsTileSet::getImageFile() const {
        return "/home/sanaa/Documents/abouobaydphenix/res/Worms/worms.png";
    }

    const Tile& CharsTileSet::getTile(const state::Element& e) const {
        Tile tuile;
        tuile.setHeight(64);
        tuile.setWidth(32);
        if (e.getTypeId() == state::TypeId::PERSONNAGE){
            if (state::Direction::LEFT){ //gauche
                tuile.setX(1); //à revérifier
                tuile.setY(0);
            } 
            else if (state::Direction::RIGHT){ //droite
                tuile.setX(0); //à revérifier
                tuile.setY(0);
            } 
        }
        else{
            std::cout << "Erreur, ce n'est pas un personnage" << std::endl;
        }
        
        return tuile;
    }
   
    
}

