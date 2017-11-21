

#include <SFML/Window/Keyboard.hpp>

#include "TestEngine.h"
#include "state.h"
#include "engine.h"
#include "render.h"

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;



using namespace state;
using namespace render;

namespace engine{
    TestEngine::TestEngine() {
        
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
        
        if (!mapt.load("res/tilemap.png", sf::Vector2u(32, 32), t_terre, 10, 10))
        cout << "Erreur chargement texture terre" << endl;
        
        cout << "Map terre créée" << endl;
        // ------------------------------------------------------------------------------------------
        
        
        
        //-------------------------------------------------------------------------------------------
        render::TileMap mapp;
        CharsTileSet tileset;
        Personnage p;
        p.setColor(0);
        p.setD(Direction::LEFT);
        p.setStatus(Status::ALIVE);
        Tile tilep = tileset.getTile(p);
        std::vector<int> t_perso;
        int n = tilep.getX();
        t_perso.push_back(n);
        cout << t_perso.size() << endl;
        cout << "Création personnage" << endl;
        if (!mapt.load("res/soldat13.png", sf::Vector2u(32, 36), t_perso, 1, 1))
        cout << "Erreur chargement texture personnage" << endl;
        
        
        
        
        
        
        
        //------------------------------------------------------------------------------------------
        
        
        //------------------------------------------------------------------------------------------
        engine::Engine engine;
        state::State& currentState = engine.getState();
        state::ElementTab grid(10,10);
        state::ElementTab chars(1,1);
        state::Element* personnage = new state::Personnage();
        chars.add(personnage);
        for (size_t it = 0; it<t_terre.size(); it++){
            if (t_terre[it] == 164){
                grid.add( new state::Floor(state::FloorTypeId::GROUND) );
            }
            else if (t_terre[it] == 132){
                grid.add(new state::Floor(state::FloorTypeId::GRASS));
            }
            else if (t_terre[it] == 0){
                grid.add(new state::Space(state::SpaceTypeId::EMPTY));
            }
        }
        cout << "tous les élements sont chargés dans la grille" << endl;
        currentState.setGrid(grid);
        currentState.setChars(chars);
        
        
        
        // ------------------------------------------------------------------------------------------
        Command* commande;
        //commande = new MoveCharCommand();
        
        
        
        
        
        
        // ------------------------------------------------------------------------------------------
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
        window.draw(mapp);
        window.display();
    
    
    
    }
    }



    TestEngine::~TestEngine() {
    }

}

