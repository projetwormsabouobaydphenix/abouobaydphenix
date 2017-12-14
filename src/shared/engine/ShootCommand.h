// Generated by dia2code
#ifndef ENGINE__SHOOTCOMMAND__H
#define ENGINE__SHOOTCOMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class ShootCommand;
  class Command;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"

namespace engine {

  /// class ShootCommand - 
  class ShootCommand : public engine::Command {
    // Attributes
  protected:
    int color;
    // Operations
  public:
    ShootCommand (int color);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    void serialize (Json::Value& out) const;
    ShootCommand* deserialize (const Json::Value& in);
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
  };

};

#endif
