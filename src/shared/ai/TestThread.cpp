/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestThread.cpp
 * Author: clara
 * 
 * Created on December 11, 2017, 4:01 PM
 */

#include "TestThread.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include "HeuristicAI.h"
#include <thread>



#include <iostream>
using namespace std;
using namespace engine;
using namespace state;
using namespace sf;
using namespace render;


#define LIMITE_FRAME 60

namespace ai {
 
  void TestThread::thread_secondaire(engine::Engine& moteur, int color){
    State& state = moteur.getState();
    HeuristicAI heuristicnoir(state, 2);
    HeuristicAI heuristicvert(state,1);
    
    if (color==1){
        heuristicvert.run(moteur,1);
        sleep(milliseconds(1000));
        color =2;
      }
      else if (color==2){
        heuristicnoir.run(moteur, 2);
        sleep(milliseconds(1000));
        color=1;
      }
      else {
        cout<<"erreur la couleur n'est pas bonne"<<endl;
      }
  }
   
TestThread::TestThread() {
       cout << "debut test hai" << endl;
        Engine moteur;
        State& state = moteur.getState();

        Command* init = new LoadCommand("res/heuristic_ai.txt");
        moteur.addCommand(0, init);
        moteur.update();
        //init->execute(state);

        Layer* layer1 = new ElementTabLayer(state.getGrid());
        Layer* layer2 = new ElementTabLayer(state.getChars());

        sf::RenderWindow window;
        window.setFramerateLimit(LIMITE_FRAME);
        window.create(sf::VideoMode(800, 384), "Test Worms");
        cout << "Bienvenue sur le jeu worms" << endl;
        cout << "Le personnage vert n'a qu'une seule vie. Normalement, il doit en récupérer s'il ne veut pas mourir" << endl;
        cout << "Appuyez sur Espace pour faire défiler" << endl;
        //cout << "Pour choisir l'équipe verte, appuyez sur la touche V; sinon appuyez sur la touche N" << endl;

        //int i = 0;
        //int k = 0;
        int color =1;
        while (window.isOpen()) {
            
            thread th_second(&thread_secondaire,std::ref(moteur), std::ref(color));
            
            layer1->initSurface();
            window.draw(*(layer1->getSurface()));

            layer2->initSurface();
            window.draw(*(layer2->getSurface()));

            window.display();
            window.clear();

        }
}


TestThread::~TestThread() {
}

}