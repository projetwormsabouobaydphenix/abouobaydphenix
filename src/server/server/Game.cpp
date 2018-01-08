/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Game.h"
#include "Player.h"

using namespace std;

namespace server {
    Game::Game() : idseq(1) {

   }

   const Player* Game::getPlayer (int i) const {
       auto ite = players.find(i);
       if (ite == players.cend())
           return nullptr;
       return ite->second.get();
   }

   int Game::addPlayer (std::unique_ptr<Player> player) {
       int id = idseq++;
       players.insert(std::make_pair(id,std::move(player)));
       return id;
   }

   void Game::setPlayer (int id, std::unique_ptr<Player> player) {
       players[id] = std::move(player);
       if (id > idseq) {
           idseq = id;
       }
   }

   void Game::removePlayer (int id) {
       auto ite = players.find(id);
       if (ite == players.end())
           return;
       players.erase(ite);
   }
}