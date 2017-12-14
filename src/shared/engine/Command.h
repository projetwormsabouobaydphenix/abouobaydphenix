// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace engine {
  class Action;
};
namespace state {
  class State;
};
namespace engine {
  class Engine;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "state/State.h"
#include "Engine.h"

namespace engine {

  /// class Command - 
  class Command {
    // Associations
    // Operations
  public:
    Command ();
    virtual ~Command ();
    virtual CommandTypeId getTypeId () const = 0;
    virtual void execute (state:: State& state, std::stack<std::shared_ptr<Action>>& actions) = 0;
    virtual void serialize (Json::Value& out) const = 0;
    virtual void deserialize (const Json::Value& in);
    void addToReplay ();
    // Setters and Getters
  };

};

#endif
