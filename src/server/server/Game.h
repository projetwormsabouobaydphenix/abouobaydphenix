// Generated by dia2code
#ifndef SERVER__GAME__H
#define SERVER__GAME__H

#include <map>
#include <memory>

namespace engine {
  class Engine;
};
namespace server {
  class Player;
}

#include "engine/Engine.h"
#include "Player.h"
#include "GameStatus.h"

namespace server {

  /// class Game - 
  class Game {
    // Associations
    // Attributes
  public:
    engine::Engine engine;
  protected:
    int idseq;
    std::map<int,std::unique_ptr<Player>> players;
    // Operations
  public:
    Game ();
    const Player* getPlayer (int id) const;
    int addPlayer (std::unique_ptr<Player> player);
    void setPlayer (int id, std::unique_ptr<Player> player);
    void removePlayer (int id);
    engine::Engine& getEngine ();
    void run ();
    // Setters and Getters
    int getIdseq() const;
    void setIdseq(int idseq);
    const std::map<int,std::unique_ptr<Player>>& getPlayers() const;
    void setPlayers(const std::map<int,std::unique_ptr<Player>>& players);
  };

};

#endif
