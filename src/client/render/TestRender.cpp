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
    
    TileMap t;
    TileMap m;
    
    std::vector<int> terre = t.loadLayer("/home/sanaa/Documents/abouobaydphenix/res/terre.txt");
    std::vector<int> mer = m.loadLayer("/home/sanaa/Documents/abouobaydphenix/res/mer.txt");
    
    if (!t.load("/home/sanaa/Documents/abouobaydphenix/res/tilemap.png", sf::Vector2u(32, 32), terre, 155, 40))
        cout << "Erreur chargement texture terre" << endl;
    
    if (!m.load("/home/sanaa/Documents/abouobaydphenix/res/water.png", sf::Vector2u(32, 32), mer, 155, 40))
        cout << "Erreur chargement texture mer" << endl;

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
        window.draw(m);
        window.draw(t);
        window.display();
    }


    
}

TestRender::~TestRender() {
}
}
