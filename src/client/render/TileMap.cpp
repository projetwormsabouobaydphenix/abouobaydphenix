
#include "TileMap.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

namespace render{

    void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // on applique la transformation
        states.transform *= getTransform();
 
        // on applique la texture du tileset
        states.texture = &texture;
 
        // et on dessine enfin le tableau de vertex
        target.draw(quads, states);
        
    }

    /*void TileMap::initQuads(int count) {
        quads.setPrimitiveType(sf::Quads);
        quads.resize(count * 4);
    }


    void TileMap::loadTexture(const std::string& image_file) {
        if (!texture.loadFromFile(image_file)){
            cout << "Erreur chargement de la texture" << endl;
        }
    }
    
    void TileMap::setSpriteLocation(int i, int x, int y, const Tile& tile) {
        int halfHeight = tile.getHeight()/2;
        int halfWidth = tile.getWidth()/2;
        quads[i][0].position = sf::Vector2f(x - halfWidth, y + halfHeight);
        quads[i][1].position = sf::Vector2f(x + halfWidth, y + halfHeight);
        quads[i][2].position = sf::Vector2f(x - halfWidth, y - halfHeight);
        quads[i][3].position = sf::Vector2f(x + halfWidth, y - halfHeight);
    }


    void TileMap::setSpriteTexture(int i, const Tile& tex) {
        int x = tex.getX();
        int y = tex.getY();
        int width = tex.getWidth();
        int height = tex.getHeight();
        
        //int tu = i % (quads.getSize().x / tileSize.x);
        //int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
 
        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        //sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
 
        // on définit ses quatre coordonnées de texture
        quads[i].texCoords = sf::Vector2f(x, y);
        
        quads[1].texCoords = sf::Vector2f((tu + 1) * x, tv * y);
        quads[2].texCoords = sf::Vector2f((tu + 1) * x, (tv + 1) * y);
        quads[3].texCoords = sf::Vector2f(tu * x, (tv + 1) * y);
        

    }*/
    
    bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize,  std::vector<int> tiles, unsigned int width, unsigned int height)
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
    }
    
    std::vector<int> TileMap::loadLayer(const std::string& path) {
 
       std::vector<int> vcarte;
       
        string n;
	std::ifstream fichier(path);
        //fichier.open("terre.csv", std::ios::in);
        if (!fichier.is_open()) std::cout << "Erreur open file" << endl;
        while(fichier.good()){
            getline(fichier, n, ',');
            vcarte.push_back(std::stoi(n));
            
            
        }
        
       for (int i = 0; i<vcarte.size(); i++){
            if (vcarte[i] == -1){
               vcarte[i] = 0;
            }
       }
        
        
        return vcarte;
        
    }
    
    
}

