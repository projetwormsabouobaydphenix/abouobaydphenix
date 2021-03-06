// Generated by dia2code
#ifndef ENGINE__HANDLELIFESCOMMAND__H
#define ENGINE__HANDLELIFESCOMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class Command;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"
#include "state/SpaceTypeId.h"

namespace engine {

  /// class HandleLifesCommand - 
  class HandleLifesCommand : public engine::Command {
    // Attributes
  protected:
    int color;
    // Operations
  public:
    void addLife (int color, state::State& state);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    void serialize (Json::Value& out) const;
    void deserialize (const Json::Value& in);
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
  };

};

#endif
