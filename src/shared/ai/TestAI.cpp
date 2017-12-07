

#include "TestAI.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include "../engine/Action.h"


#include <iostream>
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;

namespace ai {

    TestAI::TestAI() {
        RandomAI* rai = new RandomAI();
        Engine moteur;
        State& state = moteur.getState();
        
        //std::stack<std::shared_ptr<Action> >& actions   ;
                
        // initialisation de l'état
        Command* init = new LoadCommand("res/heuristic_ai.txt");
        moteur.addCommand(0, init);
        moteur.update();
        //init->execute(state);

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());

        sf::RenderWindow window;
        window.create(sf::VideoMode(800, 384), "Jeu Worms");

        //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;
        //cout << "Appuyez sur la touche T pour tirer" << endl;
        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                
            }
            rai->run(moteur, 1);
            

            moteur.update();
            

            layer1->initSurface();
            window.draw(*(layer1->getSurface()));

            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();
        }
    }

    TestAI::~TestAI() {

    }
}












