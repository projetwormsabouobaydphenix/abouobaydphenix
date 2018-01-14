
#include "GameService.h"
#include "Game.h"
#include <iostream>

using namespace std;

extern int nbJoueurs;

namespace server {
      GameService::GameService (Game& game) : AbstractService("/game"),
        game(game) {
    }
   
    HttpStatus GameService::get(Json::Value& out, int id) const {
        const std::map<int, std::unique_ptr<Player>>& players = game.getPlayers();
        /*if((players.size()) != 2){
            out["startGame"] = false;
        }
        else {
            out["startGame"] = true;
        }*/
        
        if (nbJoueurs<2){
            out["Game status"] = "CREATING";
            return HttpStatus::CREATED;
        }
        else {
            out["Game Status"] = "RUNNING";
            return HttpStatus::OK;
        }
        
        //cout << "nbJoueurs dans game = " << nbJoueurs << endl;
        
        
    }
    
    Game& GameService::getGame() const {
        return this->game;
    }
    

   
}
