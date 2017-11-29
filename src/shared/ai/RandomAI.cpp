
#include "RandomAI.h"
#include "engine/Engine.h"
#include "ai.h"
#include "../state.h"
#include "../engine.h"
#include <random>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>


using namespace state;
using namespace engine;
using namespace std;

namespace ai{

    RandomAI::RandomAI() {
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        randgen = rng;
    }

    void RandomAI::run(engine::Engine& engine) {
        vector<Command*> listCommands;
        State& state = engine.getState();
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        std::mt19937 rng(seed);
        int color = engine.getState().getJoueur();
        if (color == 1){
            cout << "Joueur vert" << endl;
        }
        else if (color == 2){
            cout << "Joueur noir" << endl;
        }
        
        //Command* = 
        
        
        
        
        
    }
    
    
  
    
    RandomAI::~RandomAI(){}
    
}