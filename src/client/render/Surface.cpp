
#include "Surface.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

namespace render{

    Surface::Surface() {

    }

    void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &m_texture;
        target.draw(m_quads, states);
    }

    void Surface::initQuads(int count) {
        m_quads.setPrimitiveType(Quads);
        m_quads.resize(count*4);
    }

    void Surface::loadTexture(const std::string& image_file) {
    if (!m_texture.loadFromFile(image_file)){
                throw std::runtime_error("Impossible de charger la texture");
        }
    }

    void Surface::setSpriteLocation(int i, int x, int y) {
        //cout << "setSpriteLocation" << endl;
        sf::Vertex* quad = &m_quads[i*4];
        quad[0].position = Vector2f(x*32, y*32);
        quad[1].position = Vector2f((x+1)*32, y*32);
        quad[2].position = Vector2f((x+1)*32,(y+1)*32);
        quad[3].position = Vector2f(x*32,(y+1)*32);
        //cout << "fin set sprite location" << endl;
    }

    void Surface::setSpriteTexture(int i, const Tile& tex) {
        //cout << "setSpriteTexture" << endl;
        sf::Vertex* quad = &m_quads[i*4];
        quad[0].texCoords = Vector2f(tex.getX(), tex.getY());
        quad[1].texCoords = Vector2f(tex.getX()+tex.getWidth(), tex.getY());
        quad[2].texCoords = Vector2f(tex.getX()+tex.getWidth(), tex.getY()+tex.getHeight());
        quad[3].texCoords = Vector2f(tex.getX(), tex.getY()+tex.getHeight());
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

