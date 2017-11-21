

#include "GridTileSet.h"
#include "state/FloorTypeId.h"
#include "state/SpaceTypeId.h"
#include "state/Floor.h"
#include "state/Space.h"
#include <iostream>

using namespace state;

namespace render{

    GridTileSet::GridTileSet() {
        Tile tuile;
        tuile.setHeight(32);
        tuile.setWidth(32);
        
    }

    int GridTileSet::getCellHeight() const {
        return spaces[0].getHeight();
    }

    int GridTileSet::getCellWidth() const {
        return spaces[0].getWidth();
    }

    const std::string GridTileSet::getImageFile() const {
        return "m"; //à definir
    }

    const Tile& GridTileSet::getTile(const state::Element& e) const {
        
        if (e.getTypeId() == state::TypeId::FLOOR){
            Floor& f = (Floor&) e;
            state::FloorTypeId floorId = f.getNature();
            if (floorId == state::FloorTypeId::GROUND){ //gauche
                return this->floors[0]; //à modifier
            } 
            else if (floorId == state::FloorTypeId::WATER){ //droite
                return this->floors[0]; //à modifier
            } 
            else if (floorId == state::FloorTypeId::GRASS){ //droite
                return this->floors[0]; //à modifier
            } 
        }
        
        else if (e.getTypeId() == state::TypeId::SPACE){
            state::Space& s = (state::Space&) e;
            state::SpaceTypeId spaceId = s.getNature();
            if (spaceId == state::SpaceTypeId::EMPTY){
                 return this->spaces[0]; //à modifier
            }
            else if (spaceId == state::SpaceTypeId::EMPTY){
                return this->spaces[0];
            }
        }
        
        else{
            std::cout << "Erreur, ceci n'est pas un élement du décor" << std::endl;
        }
    }
 
}

