
#include "AI.h"
#include "../state.h"
#include "../engine.h"
#include <iostream>
#include <vector>

using namespace state;
using namespace engine;
using namespace std;

namespace ai {

    void AI::listCommands(std::vector<engine::Command*>& list, state::State& state, int color) {

        //ElementTab& chars = state.getChars();

        //size_t width = chars.getWidth();
        //size_t height = chars.getHeight();

        Command* move1 = new MoveCharCommand(1, Direction::RIGHT);
        list.push_back(move1);

        Command* shoot1 = new ShootCommand(1);
        list.push_back(shoot1);

        Command* move3 = new MoveCharCommand(1, Direction::LEFT);
        list.push_back(move3);

        Command* move4 = new MoveCharCommand(2, Direction::RIGHT);
        list.push_back(move4);

        Command* shoot2 = new ShootCommand(2);
        list.push_back(shoot2);

        Command* move5 = new MoveCharCommand(2, Direction::LEFT);
        list.push_back(move5);

    }


}
