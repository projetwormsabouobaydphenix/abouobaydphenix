
#include "Game.h"
#include "Player.h"
#include "engine/LoadCommand.h"

using namespace std;

namespace server {

    Game::Game() : idseq(1) {

    }

    const Player* Game::getPlayer(int i) const {
        auto ite = players.find(i);
        if (ite == players.cend())
            return nullptr;
        return ite->second.get();
    }

    int Game::addPlayer(std::unique_ptr<Player> player) {
        int id = idseq++;
        players.insert(std::make_pair(id, std::move(player)));
        return id;
    }

    void Game::setPlayer(int id, std::unique_ptr<Player> player) {
        players[id] = std::move(player);
        if (id > idseq) {
            idseq = id;
        }
    }

    void Game::removePlayer(int id) {
        auto ite = players.find(id);
        if (ite == players.end())
            return;
        players.erase(ite);
    }

    const std::map<int, std::unique_ptr<Player> >& Game::getPlayers() const {
        return this->players;
    }

    engine::Engine& Game::getEngine() {
        return this->engine;
    }
    
    void Game::run() {
        engine.addCommand(1, new engine::LoadCommand("res/heuristic_ai.txt"));
    }


}