
#include "GridTileSet.h"
#include "state/FloorTypeId.h"
#include "state/SpaceTypeId.h"

namespace render{

    GridTileSet::GridTileSet() {

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
        Tile tuile;
        tuile.setHeight(32);
        tuile.setWidth(32);
        if (e.getTypeId() == state::TypeId::FLOOR){
            if (state::FloorTypeId::FULL){ //gauche
                tuile.setX(0); //à revérifier
                tuile.setY(0);
            } 
            else if (state::FloorTypeId::WATER){ //droite
                tuile.setX(0); //à revérifier
                tuile.setY(0);
            } 
        }
        else if (e.getTypeId() == state::TypeId::SPACE){
            if (state::SpaceTypeId::EMPTY){
                if (state::SpaceTypeId::EMPTY){
                    tuile.setX(0); //à revérifier
                    tuile.setY(0);
                }
                else if (state::SpaceTypeId::LIFE){
                    tuile.setX(0); //à revérifier
                    tuile.setY(0);
                }
            }
        }
        return tuile;
    }
 
}

