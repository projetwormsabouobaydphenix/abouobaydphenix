
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
        l.resize(0);
    }
    
    size_t ElementTab::add(Element* e) {
        l.push_back(std::unique_ptr<Element>(e));  
        cout << "Ajout d'un élement à la grille" << endl;
        return l.size();
    }

    void ElementTab::get(int i, int j) const {
        //Element* e ;
        cout << "Obtenir l'élement se trouvant à la position (i, j)" << endl;
        //return e;
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
        cout << "Redimensionne en " << width << " par " << height << endl;
        l.resize(width*height);

    }

    void ElementTab::set(int i, int j, Element* e) {
        
    }



}

