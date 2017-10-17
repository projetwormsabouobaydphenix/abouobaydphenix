// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <stdlib.h>
#include <vector>
#include <memory>

namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  private:
    /// 	
    size_t width ;
    size_t height;
    std::vector<std::unique_ptr<Element>> l;
    // Operations
  public:
    ElementTab (size_t width = 0, size_t height = 1);
    size_t getWidth () const;
    size_t getHeight () const;
    size_t add (Element* e);
    void resize (size_t width, size_t height);
    void get (int i, int j) const;
    void set (int i, int j, Element* e);
    // Setters and Getters
  };

};

#endif
