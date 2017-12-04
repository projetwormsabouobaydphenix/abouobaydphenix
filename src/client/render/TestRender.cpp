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
#include "../../shared/state.h"

using namespace state;

namespace render{
TestRender::TestRender() {
    sf::RenderWindow window(sf::VideoMode(800, 384), "Worms");
    
    state::State state;
    
    ElementTab& grid = state.getGrid();
    ElementTab& chars = state.getChars();
    grid.resize(25, 12);
    chars.resize(25, 12);
    std::vector<int> vcarte = state.getGrid().load("res/heuristic_ai.txt");
    std::vector<int> pcarte = state.getChars().load("res/personnage_render.txt");
    //cout << vcarte.size() << endl;
    // cout << pcarte.size() << endl;
        
        
        for (int i = 0; i<(int)vcarte.size(); i++){
            //cout << vcarte[i] << endl;
            if (vcarte[i] == 0){
                //cout << "vcarte[i] = 0" << endl;
                Element* empty = new Space(SpaceTypeId::EMPTY);
                empty->setI(i%25);
                empty->setJ(i/25);
                grid.set(i%25, i/25, empty);
            }
            else if (vcarte[i] == 1){
                //cout << "vcarte[i] = 1" << endl;
                Element* ground = new Floor(state::FloorTypeId::GROUND);
                ground->setI(i%25);
                ground->setJ(i/25);
                grid.set(i%25, i/25, ground);
            }
            else if (vcarte[i] == 2){
                //cout << "vcarte[i] = 2" << endl;
                Element* grass = new Floor(state::FloorTypeId::GRASS);
                grass->setI(i%25);
                grass->setJ(i/25);
                grid.set(i%25, i/25, grass);
            }
            else if (vcarte[i] == 3){
                //cout << "vcarte[i] = 3" << endl;
                Element* water = new Floor(state::FloorTypeId::WATER);
                water->setI(i%25);
                water->setJ(i/25);
                grid.set(i%25, i/25, water);
            }
            else if (vcarte[i] == 4){
                Element* life = new Space(state::SpaceTypeId::LIFE);
                life->setI(i%25);
                life->setJ(i/25);
                grid.set(i%25, i/25, life);
            }
            
            }
        
    
        for (int i = 0; i<(int)pcarte.size(); i++){
            //cout << vcarte[i] << endl;
            
            if (pcarte[i] == 1){ //vert gauche
                //cout << "vcarte[i] = 1" << endl;
                Element* vg = new Personnage(1, Direction::LEFT);
                vg->setI(i%25);
                vg->setJ(i/25);
                chars.set(i%25, i/25, vg);
            }
            else if (pcarte[i] == 2){ //vert droite
                //cout << "vcarte[i] = 2" << endl;
                Element* vd = new Personnage(1, Direction::RIGHT);
                vd->setI(i%25);
                vd->setJ(i/25);
                chars.set(i%25, i/25, vd);
            }
            else if (pcarte[i] == 3){ //noir gauche
                //cout << "vcarte[i] = 3" << endl;
                Element* ng = new Personnage(2, Direction::LEFT);
                ng->setI(i%25);
                ng->setJ(i/25);
                chars.set(i%25, i/25, ng);
            }
            else if (pcarte[i] == 4){ //noir droite
                Element* nd = new Personnage(2, Direction::RIGHT);
                nd->setI(i%25);
                nd->setJ(i/25);
                chars.set(i%25, i/25, nd);
            }
            else{
                chars.set(i%25, i/25, NULL);
            }
            }
    
     Layer* layer1 = new ElementTabLayer(state.getGrid());
    Layer* layer2 = new ElementTabLayer(state.getChars());
    
    

    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        layer1->initSurface();
        window.draw(*(layer1->getSurface()));
            
        layer2->initSurface();
        window.draw(*(layer2->getSurface()));

        window.display();
        window.clear();
    }


    
}

TestRender::~TestRender() {
}
}
