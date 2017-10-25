
#include "ElementTab.h"
#include "Element.h"
#include <vector>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;

namespace state{
    


    ElementTab::ElementTab(size_t width, size_t height) {
        this->width=width;
        this->height=height;
        list.resize(width*height);
    }
    
    size_t ElementTab::add(Element* e) {
        list.push_back(std::unique_ptr<Element>(e));  
        cout << "Ajout d'un élement à la grille" << endl;
        return list.size();
    }

    Element* ElementTab::get(int i, int j) const {
        //return list[j*width + i];
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
        cout << "Redimensionnement en " << width << " par " << height << endl;
        list.resize(width*height);

    }

    void ElementTab::set(int i, int j, Element* e) {
       // l.insert(i,e);
        //l[j*width + i] = e;
    }



}

