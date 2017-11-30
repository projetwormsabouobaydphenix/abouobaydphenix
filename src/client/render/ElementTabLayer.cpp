
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

            surface_grid->loadTexture("res/decor.png");

            // initialise la liste des sprites
            surface_grid->initQuads(width*height);
            
            // pour chaque cellule de la grille
            for (size_t i = 0; i < height; i++){
                for (size_t j = 0; j < width; j++){
                    // - la positionne dans la fenêtre
                    surface_grid->setSpriteLocation(i*width+j, j, i);
                    // - prend la partie de texture correspondante
                    Element* element = tab.get(j, i);
                    Tile tile = m_tileset->getTile(*element);
                    surface_grid->setSpriteTexture(i*width+j, tile);
                    
                }
            }
            surface = std::unique_ptr<Surface> (surface_grid);
        }
        
        else {
            TileSet* m_tileset = new CharsTileSet();
            //cout << "Test 1" << endl;
            size_t width = tab.getWidth();
            size_t height = tab.getHeight();

            Surface* surface_perso = new Surface();

            surface_perso->loadTexture("res/personnage.png");
            surface_perso->initQuads(width*height);

            // pour chaque cellule de la grille
            for (size_t i = 0; i < height; i++){
                //cout << "i =" << i << endl;
                for (size_t j = 0; j < width; j++){
                    //cout << "j=" <<j << endl;
                    //cout << "Test 1" << endl;
                    surface_perso->setSpriteLocation(i*width+j, j, i);
                    //cout << "Test t" << endl;
                    Element* element = tab.get(j, i);
                    if (element == NULL){
                        //cout << "Test 3"  << endl;
                    }
                    else {
                        //cout << "test 4" << element->getTypeId() << endl;
                    }
                    Tile tile = m_tileset->getTile(*element);
                    //cout << "Test 2" << endl;
                    surface_perso->setSpriteTexture(i*width+j, tile);
                    //cout << "ok" << endl;
                    
                }
            }
            surface = std::unique_ptr<Surface> (surface_perso);
        }
            
        }
        
        
       
    }
    
