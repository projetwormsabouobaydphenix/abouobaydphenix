
#include "Layer.h"

namespace render{
    
    Layer::Layer() {

    }

    const Surface* Layer::getSurface() const {
        return surface;
    }

    const std::shared_ptr<TileSet>& Layer::getTileset() const {
        return tileset;
    }

    void Layer::initSurface() {
        Surface s = surface.get();

    }

    void Layer::setSurface(Surface* surface) {

    }
    
    void Layer::setTileset(const std::shared_ptr<TileSet>& tileset) {

    }




}

