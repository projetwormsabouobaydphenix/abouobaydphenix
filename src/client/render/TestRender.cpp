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
#include "state/ElementTab.h"
#include <SFML/Graphics.hpp>


namespace render{
TestRender::TestRender() {
    /*sf::RenderWindow window(sf::VideoMode(4960, 1280), "Worms");
    
    state::ElementTab terre(32,32);
    state::ElementTab mer(32,32);
    state::ElementTab perso(32,32);
    state::ElementTab life(32,32);
    state::ElementTab back(32,32);
    
    
    TileMap t;
    TileMap m;
    TileMap p;
    TileMap l;
    TileMap b;
    
    std::vector<int> t_terre = terre.load("res/cterre.txt");
    std::vector<int> t_mer = mer.load("res/cmer.txt");
    std::vector<int> t_perso = perso.load("res/cpersonnages.txt");
    std::vector<int> t_life = life.load("res/clife.txt");
    std::vector<int> t_back = back.load("res/back.txt");
    
    for (size_t i = 0; i<t_terre.size(); i++){
            if (t_terre[i] == -1){
               t_terre[i] = 0;
            }
    }
    
    
    if (!t.load("res/tilemap.png", sf::Vector2u(32, 32), t_terre, 155, 40))
        cout << "Erreur chargement texture terre" << endl;
    
    if (!m.load("res/water.png", sf::Vector2u(32, 32), t_mer, 155, 40))
        cout << "Erreur chargement texture mer" << endl;
    
    if (!p.load("res/Worms/wormsteam.png", sf::Vector2u(32, 32), t_perso, 155, 40))
        cout << "Erreur chargement texture personnages" << endl;
    
    if (!l.load("res/life.png", sf::Vector2u(32, 32), t_life, 155, 40))
        cout << "Erreur chargement texture life" << endl;
    
    if (!l.load("res/back.png", sf::Vector2u(32, 32), t_back, 155, 40))
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
        //window.draw(b);
        //window.draw(l);
        window.draw(m);
        window.draw(p);
        window.draw(t);
        window.display();
    }*/


    
}

TestRender::~TestRender() {
}
}
