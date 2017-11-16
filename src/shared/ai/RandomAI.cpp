
#include "RandomAI.h"
#include "engine/Engine.h"
#include "ai.h"
#include "state.h"
#include <random>
#include <iostream>


using namespace state;
using namespace engine;
using namespace std;

namespace ai{

    RandomAI::RandomAI() {
        
    }

    void RandomAI::run(engine::Engine& engine, int i, int j) {
        cout<<"test random ai 1"<<endl;
        std::vector<engine::Command*> list;
        //State currentState;
        //currentState = engine.getState();
        AI::listCommands(list, engine.getState(), i, j );
        int pos = rand()%3;
        cout<<"test random ai 4"<<endl;
        //std::random_device rd;  //Will be used to obtain a seed for the random number engine
        //std::mt19937 randgen(rd()); //Standard mersenne_twister_engine seeded with rd()
        //std::uniform_int_distribution<> dis(0, 1);
        //int pos = dis(randgen);
       // randgen =mt_rand([0,1]);
        for (int k =0; k<4; k++){
           cout<<"test random ai"<<k<<endl;
           engine.addCommand(k, list[k]);
           cout<<"test random ai"<<k<<endl;
        }
        
        engine.update();
    }
}