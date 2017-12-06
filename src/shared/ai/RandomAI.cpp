
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
    
    void RandomAI::run(engine::Engine& engine, int color){
        //cout << "debut run" << endl;
        vector<Command*> list;
        
        listCommands(list, engine.getState(), color);
       
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 rng(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(0, list.size()-1);
        randgen = rng;
        int pos = dis(randgen);
        cout << "pos = " << pos << endl;
        cout << "execution de la commande : " << list[pos]->getTypeId() << endl;
        engine.addCommand(0, list[pos]);
        
       
        engine.update();
        //sleep(1);
        
    }
  
    
    RandomAI::~RandomAI(){}
    
}