// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <stdlib.h>
#include <vector>
#include <memory>
#include <string>

namespace state {
  class Element;
  class Observable;
}

#include "Observable.h"
#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab : public state::Observable {
    // Associations
    // Attributes
  private:
    /// 	
    size_t width ;
    size_t height;
    std::vector<std::shared_ptr<Element>> list;
    // Operations
  public:
    explicit ElementTab (size_t width = 0, size_t height = 1);
    size_t getWidth () const;
    size_t getHeight () const;
    size_t add (Element* e);
    void resize (size_t width, size_t height);
    Element* get (int i, int j) const;
    void set (int i, Element* e);
    std::vector<int> load (const std::string& file);
    // Setters and Getters
  };

};

#endif
