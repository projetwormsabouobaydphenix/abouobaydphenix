
#include "ElementTab.h"
#include "Element.h"

namespace state{

    ElementTab::ElementTab(size_t width, size_t height) {
        this->width=width;
        this->height=height;
        list.resize(width*height);
    }
    
    size_t ElementTab::add(Element* e) {
        int i = e->getX();
        int j = e->getY();
        
    }

    Element* ElementTab::get(int i, int j) const {
        Element* e;
        e->x=i;
        e->y=j;
        return e;
    }

    size_t ElementTab::getHeight() const {
        return this->height;
    }

    size_t ElementTab::getWidth() const {
        return this->width;
    }

    
    void ElementTab::resize(size_t width, size_t height) {
        this->height=height;
        this->width= width;
        

    }

    void ElementTab::set(int i, int j, Element* e) {

    }



}

