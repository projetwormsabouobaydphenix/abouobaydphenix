// Generated by dia2code
#ifndef AI__POINT__H
#define AI__POINT__H


namespace ai {
  class Point;
}

#include "state/Direction.h"

namespace ai {

  /// class Point - 
  class Point {
    // Attributes
  protected:
    int x;
    int y;
    int weight;
    // Operations
  public:
    Point (int x = 0, int y = 0, int w = 0);
    Point transform (state::Direction d);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getWeight() const;
    void setWeight(int weight);
  };

};

#endif
