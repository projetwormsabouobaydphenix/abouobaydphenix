// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementTab;
  class Observable;
}

#include "ElementTab.h"
#include "Observable.h"

namespace state {

  /// class State - 
  class State : public state::Observable {
    // Associations
    // Attributes
  private:
    ElementTab grid;
    ElementTab chars;
  protected:
    int joueur     = 2;
    int epoch     = 0;
    int epochrate     = 12;
    // Operations
  public:
    ElementTab& getGrid ();
    ElementTab& getChars ();
    void setGrid (ElementTab& grid);
    void setChars (ElementTab& chars);
    // Setters and Getters
    int getJoueur() const;
    void setJoueur(int joueur);
    int getEpoch() const;
    void setEpoch(int epoch);
    int getEpochrate() const;
    void setEpochrate(int epochrate);
  };

};

#endif
