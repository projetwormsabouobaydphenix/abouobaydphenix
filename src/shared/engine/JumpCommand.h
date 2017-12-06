// Generated by dia2code
#ifndef ENGINE__JUMPCOMMAND__H
#define ENGINE__JUMPCOMMAND__H

#include <stack>
#include <memory>

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

namespace engine {

  /// class JumpCommand - 
  class JumpCommand : public engine::Command {
    // Attributes
  protected:
    int i;
    int j;
    // Operations
  public:
    JumpCommand (int i, int j);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    // Setters and Getters
    int getI() const;
    void setI(int i);
    int getJ() const;
    void setJ(int j);
  };

};

#endif
