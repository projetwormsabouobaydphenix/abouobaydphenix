// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <vector>

namespace engine {
  class Engine;
  class Command;
};
namespace state {
  class State;
}

namespace ai {

  /// class AI - 
  class AI {
    // Operations
  public:
    virtual void run (engine::Engine& engine) = 0;
  protected:
    void listCommands (std::vector<engine::Command*> list, state::State& state, int i, int j);
    // Setters and Getters
  };

};

#endif
