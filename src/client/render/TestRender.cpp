/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestRender.cpp
 * Author: sanaa
 * 
 * Created on 17 octobre 2017, 11:28
 */

#include "TestRender.h"
#include <SFML/Graphics.hpp>


namespace render{
TestRender::TestRender() {
    sf::RenderWindow window(sf::VideoMode(4960, 1280), "Worms");
    
      const int level[] =
    {
        280, 280,280,280,280,280,280,280,280,280,280,280,
        280,280,280,280,280,280,280, 190,  190, 190, 190, 190, 190,
        190, 190, 190, 190, 190, 190, 190, 190, 190, 190
    };
    
    TileMap map;
    if (!map.load("/home/sanaa/Documents/abouobaydphenix/res/tilemap.png", sf::Vector2u(32, 32), map.loadLayer(), 16, 32))
        cout << "Erreur chargement texture" << endl;
    
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }


    
}

TestRender::~TestRender() {
}
}
