
#include "RandomAI.h"
#include "engine/Engine.h"
#include "ai.h"
#include "../state.h"
#include "../engine.h"
#include <random>
#include <iostream>
#include <stdlib.h>


using namespace state;
using namespace engine;
using namespace std;

namespace ai{

    RandomAI::RandomAI() {
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        randgen = rng;
    }

    void RandomAI::run(engine::Engine& engine, int i, int j) {
        
        
    }
    
    
  
    
    RandomAI::~RandomAI(){}
    
}