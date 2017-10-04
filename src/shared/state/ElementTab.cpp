
#include "ElementTab.h"
#include "Element.h"

namespace state{

    ElementTab::ElementTab(size_t width, size_t height) {
        this->width=width;
        this->height=height;
        list.resize(width*height);
    }
    
    size_t ElementTab::add(Element* e) {
        list.push_back(e);
        
    }

    Element* ElementTab::get(int i, int j) const {
        Element* e = list[i,j];
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
        list[i,j].push_back(e);
    }



}

