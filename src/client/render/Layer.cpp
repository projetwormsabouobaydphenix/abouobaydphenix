
#include "Layer.h"
#include "CharsTileSet.h"
#include "GridTileSet.h"
#include <iostream>

#include <memory>
#include "stdlib.h"

using namespace std;

namespace render{
    
    Layer::Layer() {
        
    }

    

    const std::unique_ptr<Surface>& Layer::getSurface() const {
        //cout << "Foction getSurface " << endl;
        return this->surface;
    }

    const std::shared_ptr<TileSet>& Layer::getTileset() const {
        return this->tileset;
    }

    void Layer::setSurface(Surface* surface) {
        this->surface = std::unique_ptr<Surface>(surface);
    }

    void Layer::setTileset(TileSet* tileset) {
       this->tileset = std::shared_ptr<TileSet>(tileset);
    }

    
   
    
    Layer::~Layer() {
    

    }
    




}

