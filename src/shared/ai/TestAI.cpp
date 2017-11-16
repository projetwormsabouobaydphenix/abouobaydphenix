

#include "TestAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>


#include <iostream>
using namespace std;

namespace ai{
    
    TestAI::TestAI() {
        
        sf::RenderWindow window(sf::VideoMode(320, 320), "Test Worms");
         
        // ----------------------------------------------------------------------------------
        render::TileMap mapt; //création d'une mini map
        std::vector<int> t_terre = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,132,132, -1,-1,-1,-1,-1,-1,-1,132,164,164,
            132,132,-1,-1,-1,-1,132,164,164,164, 164,164,132,132,132,132,164,164,164,164,
            164,164,164,164,164,164,164,164,164,164, 164,164,164,164,164,164,164,164,164,164,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        
        //cout << t_terre.size() << endl; /test
        
        for (size_t i = 0; i<t_terre.size(); i++){
            if (t_terre[i] == -1){
               t_terre[i] = 0;
            }
        }
        
        if (!mapt.load("/home/sanaa/Documents/abouobaydphenix/res/tilemap.png", sf::Vector2u(32, 32), t_terre, 10, 10))
        cout << "Erreur chargement texture terre" << endl;
        // ---------------------------------------------------------------------------------------------------
        
        
        
        //------------------------------------------------------------------------------------
        render::TileMap tileperso;
        std::vector<int> t_perso = {2}; //a modifier en fonction du personnage + chemin vers personnage
        if (!tileperso.load("/home/sanaa/Documents/abouobaydphenix/res/tilemap.png", sf::Vector2u(32, 32), t_perso, 1, 1))
        cout << "Erreur chargement texture personnage" << endl;
        //-------------------------------------------------------------------------------------
        
        
        // ----------------------------------------------------------
        engine::Engine enginet;
        state::State currentState = enginet.getState();
        state::ElementTab grid(10,10);
        state::ElementTab chars(1,1);
        currentState.setGrid(grid);
        currentState.setChars(chars);
        state::Element* floor = new state::Floor(state::FloorTypeId::FULL);
        state::Element* space = new state::Space(state::SpaceTypeId::EMPTY);
        state::Element* personnage = new state::Personnage();
        chars.add(personnage);
        for (size_t it = 0; it<t_terre.size(); it++){
            if (t_terre[it] != 0){
                grid.add(floor);
            }
            else if (t_terre[it] == 0){
                grid.add(space);
            }
        }
        cout << "tous les élements sont chargés dans la grille" << endl;
        engine::Command* commande;
        //commande = new engine::OrientationCommand(1, 2, state::Direction::LEFT);
        //enginet.addCommand(1,commande);
        //cout << "test" << endl;
        //commande->execute(currentState);
        cout << " test" << endl;
        commande = new engine::MoveCharCommand(1,2);
        enginet.addCommand(2,commande);
        cout << "test2" << endl;
        commande->execute(currentState);
        cout << " fin test" << endl;
        commande = new engine::MoveCharCommand(1,2);
        enginet.addCommand(3,commande);
        commande->execute(currentState);
        commande = new engine::MoveCharCommand(1,2);
        enginet.addCommand(4,commande);
        commande->execute(currentState);
        
        
        
        
        
        
        
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
