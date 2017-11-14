
#include "StateTileSet.h"

namespace render{

    StateTileSet::StateTileSet() {

    }

    int StateTileSet::getCellHeight() const {
        return chars[0].getHeight();
    }

    int StateTileSet::getCellWidth() const {
        return chars[0].getWidth();
    }

    const Tile& StateTileSet::getCharTile(char c) const {
        
    }

    const std::string StateTileSet::getImageFile() const {

    }
    
    
    
    
    
    
}