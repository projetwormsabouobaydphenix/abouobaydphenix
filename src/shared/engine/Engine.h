// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <vector>
#include <stack>
#include <memory>

namespace state {
  class State;
};
namespace engine {
  class Command;
  class Action;
}

#include "state/State.h"
#include "Action.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Attributes
  public:
    state::State currentState;
    std::vector<Command*> currentCommands;
    // Operations
  public:
    Engine ();
    ~Engine ();
     state::State& getState ();
    void addPassiveCommand ();
    virtual void addCommand (int priority, Command* cmd);
    std::stack<std::shared_ptr<Action>>& update ();
    void moteur ();
    void undoe (std::stack<std::shared_ptr<Action>>& actions);
    // Setters and Getters
  };

};

#endif
