// Generated by dia2code
#ifndef ENGINE__SHOOTACTION__H
#define ENGINE__SHOOTACTION__H


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

  /// class ShootAction - 
  class ShootAction : public engine::Action {
    // Associations
    // Attributes
  protected:
    int color;
    state::Personnage* ennemy;
    int life;
    // Operations
  public:
    ShootAction (int color, state::Personnage* ennemy, int life);
    void apply (state::State& state);
    void undo (state::State& state);
    ActionTypeId getActionTypeId () const;
    // Setters and Getters
    int getColor() const;
    void setColor(int color);
    const state::Personnage*& getEnnemy() const;
    void setEnnemy(const state::Personnage*& ennemy);
    int getLife() const;
    void setLife(int life);
  };

};

#endif
