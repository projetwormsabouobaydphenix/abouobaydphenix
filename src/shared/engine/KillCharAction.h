// Generated by dia2code
#ifndef ENGINE__KILLCHARACTION__H
#define ENGINE__KILLCHARACTION__H


namespace state {
  class Personnage;
  class State;
};
namespace engine {
  class Action;
}

#include "ActionTypeId.h"
#include "Action.h"
#include "state/Personnage.h"

namespace engine {

  /// class KillCharAction - 
  class KillCharAction : public engine::Action {
    // Associations
    // Attributes
  protected:
    int color;
    int xFrom;
    /// 	
    int yFrom;
    state::Personnage* persoAvAction;
    // Operations
  public:
    KillCharAction (int color, int xFrom, int yFrom, state::Personnage* persoAvAction);
    void apply (state::State& state);
    void undo (state::State& state);
    ActionTypeId getActionTypeId () const;
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
    int getXFrom() const;
    void setXFrom(int xFrom);
    int getYFrom() const;
    void setYFrom(int yFrom);
    const state::Personnage*& getPersoAvAction() const;
    void setPersoAvAction(const state::Personnage*& persoAvAction);
  };

};

#endif