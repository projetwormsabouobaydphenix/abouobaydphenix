
#include "ElementTabLayer.h"
#include "state/ElementTab.h"
#include "state/Element.h"
#include "TileSet.h"
#include "GridTileSet.h"
#include "CharsTileSet.h"
#include <iostream>

using namespace std;
using namespace state;

namespace render {

    ElementTabLayer::ElementTabLayer(state::ElementTab& tab) : tab(tab) {
       
        //this->tab = tab;
    }

    void ElementTabLayer::initSurface() {
        //cout << "Foction InitSurface d'ElementTabLayer" << endl;
        if (tab.get(0,0)!= NULL){
            TileSet* m_tileset = new GridTileSet();
            size_t width = tab.getWidth();
            size_t height = tab.getHeight();

            Surface* surface_grid = new Surface();

            // charge la texture : loadTexture
            //string texture_grid = m_tileset->getImageFile();
            surface_grid->loadTexture("res/decor.png");
            //cout << "load texture ok" << endl;

            // initialise la liste des sprites : initHexas
            surface_grid->initQuads(width*height);
            //cout << "width = " << width << endl;
            //cout << "height = " << height << endl;
            //cout << "x = " << tab.get(5,1)->getI() << "et" << tab.get(5,1)->getJ() << endl;
            

            // pour chaque cellule de la grille
            for (size_t i = 0; i < width; i++){
                //cout << i << endl;
                for (size_t j = 0; j < height; j++){
                    //cout << j << endl;
                    //cout << "i" << endl;
                    //size_t i = x*width+y;
                    // - la positionne dans la fenêtre
                    surface_grid->setSpriteLocation(j*width+i, i, j);
                    // - prend la partie de texture correspondante
                    Element* element = tab.get(i, j);
                    //cout << "x=" << element->getI() << ", y= " << element->getJ() <<endl;
                    //cout << "typeid = " << element->getTypeId() << endl;
                    Tile tile = m_tileset->getTile(*element);
                    surface_grid->setSpriteTexture(j*width+i, tile);
                    
                }
            }
            surface = std::unique_ptr<Surface> (surface_grid);
        }
        
        else {
            TileSet* m_tileset = new CharsTileSet();
            size_t width = tab.getWidth();
            size_t height = tab.getHeight();

            Surface* surface_perso = new Surface();

            // charge la texture : loadTexture
            //string texture_grid = m_tileset->getImageFile();
            surface_perso->loadTexture("res/personnage.png");
            //cout << "load texture ok" << endl;

            // initialise la liste des sprites : initHexas
            surface_perso->initQuads(width*height);
            //cout << "width = " << width << endl;
            //cout << "height = " << height << endl;
            //cout << "x = " << tab.get(5,1)->getI() << "et" << tab.get(5,1)->getJ() << endl;
            

            // pour chaque cellule de la grille
            for (size_t i = 0; i < width; i++){
                //cout << i << endl;
                for (size_t j = 0; j < height; j++){
                    //cout << j << endl;
                    //cout << "i" << endl;
                    //size_t i = x*width+y;
                    // - la positionne dans la fenêtre
                    surface_perso->setSpriteLocation(j*width+i, i, j);
                    // - prend la partie de texture correspondante
                    Element* element = tab.get(i, j);
                    //cout << "x=" << element->getI() << ", y= " << element->getJ() <<endl;
                    //cout << "typeid = " << element->getTypeId() << endl;
                    Tile tile = m_tileset->getTile(*element);
                    surface_perso->setSpriteTexture(j*width+i, tile);
                    
                }
            }
            surface = std::unique_ptr<Surface> (surface_perso);
        }
            
        }
        
        
       
    }
    
