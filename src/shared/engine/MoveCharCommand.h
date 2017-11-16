// Generated by dia2code
#ifndef ENGINE__MOVECHARCOMMAND__H
#define ENGINE__MOVECHARCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class MoveCharCommand - 
  class MoveCharCommand : public engine::Command {
    // Attributes
  protected:
    int character;
    int i;
    int j;
    // Operations
  public:
    MoveCharCommand (int i, int j);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    int getCharacter() const;
    void setCharacter(int character);
    int getI() const;
    void setI(int i);
    int getJ() const;
    void setJ(int j);
  };

};

#endif
