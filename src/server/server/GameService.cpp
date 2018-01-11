
#include "GameService.h"
#include "Game.h"

using namespace std;

namespace server {
      GameService::GameService (Game& game) : AbstractService("/game"),
        game(game) {
    }
   
    HttpStatus GameService::get(Json::Value& out, int id) const {
        const std::map<int, std::unique_ptr<Player>>& players = game.getPlayers();
        if((players.size()) != 2){
            out["startGame"] = false;
        }
        else {
            out["startGame"] = true;
        }
        return HttpStatus::OK;
    }
   
}
