// Generated by dia2code
#ifndef ENGINE__MOVECHARCOMMAND__H
#define ENGINE__MOVECHARCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/Direction.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class MoveCharCommand - 
  class MoveCharCommand : public engine::Command {
    // Associations
    // Attributes
  protected:
    int color;
    state::Direction direction;
    // Operations
  public:
    MoveCharCommand (int color, state::Direction direction);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
    state::Direction getDirection() const;
    void setDirection(state::Direction direction);
  };

};

#endif
