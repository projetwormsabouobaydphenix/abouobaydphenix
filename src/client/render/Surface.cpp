
#include "Surface.h"

namespace render{

    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation
        states.transform *= getTransform();
 
        // on applique la texture du tileset
        states.texture = &texture;
 
        // et on dessine enfin le tableau de vertex
        target.draw(quads, states);
    }

    void Surface::initQuads(int count) {
        quads(sf::Quads count);
        
    }

    void Surface::initTriangles(int count) {

    }

    void Surface::loadTexture(const std::string& image_file) {
        if (!texture.loadFromFile(image_file)){
            cout << "Erreur chargement de la texture" << endl;
        }
    }

    void Surface::setSpriteLocation(int i, int x, int y) {
        
        quads[0].position = sf::Vector2f(i * x, j * y);
        quads[1].position = sf::Vector2f((i + 1) * x, j * y);
        quads[2].position = sf::Vector2f((i + 1) * x, (j + 1) * y);
        quads[3].position = sf::Vector2f(i * x, (j + 1) * y);
        
    }

    void Surface::setSpriteTexture(int i, const Tile& tex) {
        int x = tex.getX();
        int y = tex.getY();
        int width = tex.getWidth();
        int height = tex.getHeight();
        
        int tu = i % (quads.getSize().x / tileSize.x);
        int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
 
        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        //sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
 
        // on définit ses quatre coordonnées de texture
        quads[0].texCoords = sf::Vector2f(tu * x, tv * y);
        quads[1].texCoords = sf::Vector2f((tu + 1) * x, tv * y);
        quads[2].texCoords = sf::Vector2f((tu + 1) * x, (tv + 1) * y);
        quads[3].texCoords = sf::Vector2f(tu * x, (tv + 1) * y);
        

    }
    
    
    
    
}

