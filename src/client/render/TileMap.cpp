
#include "TileMap.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

namespace render{
    
    TileMap::TileMap() {

    }

    void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation
        states.transform *= getTransform();
    
        // on applique la texture du tileset
        states.texture = &m_tileset;
    
        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
        
    }

    void TileMap::initQuads(int count) {
        quads.setPrimitiveType(sf::Quads);
        quads.resize(count * 4);
    }

    void TileMap::setSpriteLocation(int i, int x, int y) {
         sf::Vertex* quad = &m_vertices[i * 4];
        quad[0].position = sf::Vector2f(x * 32, y * 32);
        quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
        quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
        quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);
    }
 

    void TileMap::loadTexture(const std::string& image_file) {
        if (!texture.loadFromFile(image_file)){
            cout << "Erreur chargement de la texture" << endl;
        }
    }
    
    void TileMap::setSpriteTexture(int i, const Tile& tex) {
        sf::Vertex* quad = &m_vertices[i * 4];
        quad[0].texCoords = sf::Vector2f(tex.getX(), tex.getY());
        quad[1].texCoords = sf::Vector2f(tex.getX()+tile.getWidth(), tex.getY());
        quad[2].texCoords = sf::Vector2f(tex.getX()+tex.getWidth(), tex.getY()+tex.getHeight());
        quad[3].texCoords = sf::Vector2f(tex.getX(), tex.getY()+tex.getHeight());
    }
    
    /*bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize,  std::vector<int> tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!texture.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        quads.setPrimitiveType(sf::Quads);
        quads.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (texture.getSize().x / tileSize.x);
                int tv = tileNumber / (texture.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &quads[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }*/
    
   
    
    
}

