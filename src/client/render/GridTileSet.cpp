

#include "GridTileSet.h"
#include "state/FloorTypeId.h"
#include "state/SpaceTypeId.h"
#include "state/Floor.h"
#include "state/Space.h"
#include <iostream>

using namespace state;
using namespace std;

namespace render{

    GridTileSet::GridTileSet() {
        Tile vide(0, 0, 32, 32); 
        Tile terre(32, 0, 32, 32); 
        Tile grass(64, 0, 32, 32); 
        Tile water(96, 0, 32, 32); 
        Tile life(128, 0, 32, 32);
        spaces.push_back(vide); //0
        spaces.push_back(life); //1
        floors.push_back(terre); //0
        floors.push_back(grass); //1
        floors.push_back(water); //2
    }

    int GridTileSet::getCellHeight() const {
        return spaces[0].getHeight();
    }

    int GridTileSet::getCellWidth() const {
        return spaces[0].getWidth();
    }

    const std::string GridTileSet::getImageFile() const {
        return "res/decor.png"; //à definir
    }

    const Tile& GridTileSet::getTile(const state::Element& e) const {
        //std::cout << "getTile de GridTileSet" << std::endl;
        if (e.getTypeId() == state::TypeId::FLOOR){
            //cout << "FLOOR" << endl;
            const Floor& f = (const Floor&) e;
            state::FloorTypeId floorId = f.getNature();
            if (floorId == state::FloorTypeId::GROUND){ //gauche
                //cout << "ground" << endl;
                return this->floors[0]; //à modifier
            } 
            else if (floorId == state::FloorTypeId::WATER){ //droite
                //cout << "water" << endl;
                return this->floors[2]; //à modifier
            } 
            else if (floorId == state::FloorTypeId::GRASS){ //droite
                //cout << "grass" << endl;
                return this->floors[1]; //à modifier
            } 
            else {
                cout << "erreur" << floorId << endl;
            }
        }
        
        else if (e.getTypeId() == state::TypeId::SPACE){
            const Space& f = (const Space&) e;
            state::SpaceTypeId spaceId = f.getNature();
            if (spaceId == state::SpaceTypeId::EMPTY){
            //cout << "space" << endl;
                return this->spaces[0]; //à modifier
            }
            else if (spaceId == state::SpaceTypeId::LIFE){
                return this->spaces[1];
            }
            
        else{
            std::cout << "Erreur, ceci n'est pas un élement du décor" << std::endl;
        }
    }
    }
 
}

