
#include "Layer.h"

namespace render{
    
    Layer::Layer() {
        this->tilemap = unique_ptr<TileMap>(new TileMap());
        this->tileset = shared_ptr<GridTileSet>(new GridTileSet());
    }
    
    
    void Layer::initTileMap() {
        /*int x;
        int y;
        this->tilemap.get()->initQuads(400);
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                x = int(i / 20);
                y = i % 20;
                this->tilemap.get()->loadTexture(this->tileset.get()->getImageFile());
                this->tilemap.get()->setSpriteLocation(i+j*32, i, j);
                this->tilemap.get()->setSpriteTexture(i+j*32, this->tileset.get()->getTile());
            }
        }
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                x = int(i / 20);
                y = i % 20;
                this->surfaceplayer->loadTexture(this->tilesetChars->getImageFile());
                this->surfaceplayer->setSpriteLocation(i + j * state.grid->getWidth(), i, j);
                if (state.chars->getElement(i, j) != NULL) {
                    this->surfaceplayer->setSpriteTexture(i + j * state.grid->getWidth(), this->tilesetChars->getTile(*(state.chars->getElement(i, j))));
                } else {
                    // Tile tmp = new Tile(0,0,0,32);
                    this->surfaceplayer->setSpriteTexture(i + j * state.grid->getWidth(), Tile(0, 0, 0, 32));
                }*/

    }
    
    void Layer::setTileMap(TileMap* tilemap) {
        this->tilemap = (std::unique_ptr<TileMap>) tilemap;
    }
    
    void Layer::setTilemap(const std::unique_ptr<TileMap>& tilemap) {
        this->tilemap = tilemap;
    }

    void Layer::setTileset(const std::shared_ptr<TileSet>& tileset) {
        this->tileset = tileset;
    }

    const std::unique_ptr<TileMap>& Layer::getTilemap() const {
        return this->tilemap;
    }
    
    const std::shared_ptr<TileSet>& Layer::getTileset() const {
        return this->tileset;
    }
    
    Layer::~Layer() {

    }



}

