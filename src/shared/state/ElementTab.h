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
    ElementTab (size_t width = 25, size_t height = 12);
    size_t getWidth () const;
    size_t getHeight () const;
    size_t add (Element* e);
    void resize (size_t width, size_t height);
    Element* get (int i, int j) const;
    void set (int i, int j, Element* e);
    std::vector<int> load (const std::string& file);
    Element* alloc (int type);
    /// 	
    /// @param x1		(???) 
    /// @param y1		(???) 
    /// @param x2		(???) 
    /// @param y2		(???) 
    void changePosition (int x1, int y1, int x2, int y2);
    // Setters and Getters
  };

};

#endif
