// Generated by dia2code
#ifndef ENGINE__HANDLELIFESCOMMAND__H
#define ENGINE__HANDLELIFESCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"
#include "state/SpaceTypeId.h"

namespace engine {

  /// class HandleLifesCommand - 
  class HandleLifesCommand : public engine::Command {
    // Attributes
  protected:
    int i;
    int j;
    // Operations
  public:
    void addLife (int i, int j, state::State& state);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    HandleLifesCommand (int i, int j);
    // Setters and Getters
    int getI() const;
    void setI(int i);
    int getJ() const;
    void setJ(int j);
  };

};

#endif
