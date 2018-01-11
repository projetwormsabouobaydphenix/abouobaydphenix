// Generated by dia2code
#ifndef SERVER__GAMESERVICE__H
#define SERVER__GAMESERVICE__H

#include <json/json.h>

namespace server {
  class Game;
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"
#include "Game.h"

namespace server {

  /// class GameService - 
  class GameService : public server::AbstractService {
    // Associations
    // Attributes
  protected:
    Game& game;
    // Operations
  public:
    GameService (Game& game);
    HttpStatus get (Json::Value& out, int id) const;
    // Setters and Getters
    Game& getGame() const;
    void setGame(const Game&& game);
  };

};

#endif
