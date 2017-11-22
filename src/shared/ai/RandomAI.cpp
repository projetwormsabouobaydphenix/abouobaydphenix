
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
        
    }

    void RandomAI::run(engine::Engine& engine, int i, int j) {
        //cout<<"test random ai 1"<<endl;
        std::vector<engine::Command*> list;
        //srand(time(NULL));
        AI::listCommands(list, engine.getState(), i, j );

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 randgen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(0, 1);
        int pos = dis(randgen);
        //randgen =mt_rand([0,1]);
        for (int k =0; k<10; k++){
            //int pos = rand()%2;
            engine.addCommand(k, list[pos]);
           
        }
       
        engine.update();
    }
    
    RandomAI::~RandomAI(){
        
    }
}