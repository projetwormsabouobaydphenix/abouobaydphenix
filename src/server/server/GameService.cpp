
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
       
        switch (nbJoueurs){
            case 0 : 
                out["Game status"] = "CREATING";
                return HttpStatus::CREATED;
                break;
            case 1 :
                out["Game status"] = "CREATING";
                return HttpStatus::CREATED;
                break;
            case 2 :
                out["Game Status"] = "RUNNING";
                return HttpStatus::OK;
        }
        
    }
    
    Game& GameService::getGame() const {
        return this->game;
    }
    

   
}
