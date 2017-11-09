// Generated by dia2code
#ifndef ENGINE__HANDLEIMPACTCOMMAND__H
#define ENGINE__HANDLEIMPACTCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/Status.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class HandleImpactCommand - 
  class HandleImpactCommand : public engine::Command {
    // Operations
  public:
    void lostLife (state::State& state, state::Status statusPerso);
    void destruct (state::State& state, int pos);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, int position);
    // Setters and Getters
  };

};

#endif