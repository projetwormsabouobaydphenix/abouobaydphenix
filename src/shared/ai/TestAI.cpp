

#include "TestAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>


#include <iostream>
using namespace std;

namespace ai{
    
    TestAI::TestAI() {
        
        sf::RenderWindow window(sf::VideoMode(350, 350), "Test Worms");
         
        // ----------------------------------------------------------------------------------
        render::TileMap mapt; //création d'une mini map
        render::TileMap mapm;
        std::vector<int> t_terre = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,132,132, -1,-1,-1,-1,-1,-1,-1,132,164,164,
            132,132,-1,-1,-1,-1,132,164,164,164, 164,164,132,132,132,132,164,164,164,164,
            164,164,164,164,164,164,164,164,164,164, 164,164,164,164,164,164,164,164,164,164,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        
        for (size_t i = 0; i<t_terre.size(); i++){
            if (t_terre[i] == -1){
               t_terre[i] = 0;
            }
        }
        
        if (!mapt.load("/home/sanaa/Documents/abouobaydphenix/res/tilemap.png", sf::Vector2u(32, 32), t_terre, 10, 10))
        cout << "Erreur chargement texture terre" << endl;
        // ---------------------------------------------------------------------------------------------------
        
        
        // ----------------------------------------------------------
        /*engine::Engine engine;
        state::State currentState = engine.getState();
        state::ElementTab grid(10,10);
        currentState.setGrid(grid);*/
        
        
        
        
        
        while (window.isOpen()){
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(mapt);
        window.display();
    }
        
        
        
        
        
        
        
        
    }



TestAI::~TestAI() {
}
}
