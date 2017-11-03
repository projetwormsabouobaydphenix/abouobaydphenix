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
    TileMap p;
    TileMap l;
    TileMap b;
    
    std::vector<int> terre = t.loadLayer("res/cterre.txt");
    std::vector<int> mer = m.loadLayer("res/cmer.txt");
    std::vector<int> perso = p.loadLayer("res/cpersonnages.txt");
    std::vector<int> life = l.loadLayer("res/clife.txt");
    std::vector<int> back = b.loadLayer("res/back.txt");
    
    if (!t.load("res/tilemap.png", sf::Vector2u(32, 32), terre, 155, 40))
        cout << "Erreur chargement texture terre" << endl;
    
    if (!m.load("res/water.png", sf::Vector2u(32, 32), mer, 155, 40))
        cout << "Erreur chargement texture mer" << endl;
    
    if (!p.load("res/Worms/wormsteam.png", sf::Vector2u(32, 32), perso, 155, 40))
        cout << "Erreur chargement texture personnages" << endl;
    
    if (!l.load("res/life.png", sf::Vector2u(32, 32), life, 155, 40))
        cout << "Erreur chargement texture life" << endl;
    
    if (!l.load("res/back.png", sf::Vector2u(32, 32), back, 155, 40))
        cout << "Erreur chargement texture back" << endl;

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
        window.draw(b);
        window.draw(l);
        window.draw(m);
        window.draw(p);
        window.draw(t);
        window.display();
    }


    
}

TestRender::~TestRender() {
}
}
