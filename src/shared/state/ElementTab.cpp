
#include "ElementTab.h"
#include "Element.h"
#include <vector>
#include <memory>


namespace state{

    ElementTab::ElementTab(size_t width, size_t height) {
        this->width=width;
        this->height=height;
        l.resize(width*height);
    }
    
    size_t ElementTab::add(Element* e) {
        l.push_back(std::unique_ptr<Element>(e));  
        cout << "Ajout d'un élement à la grille" << endl;
        return l.size();
    }

    Element* ElementTab::get(int i, int j) const {
        Element* e ;
        cout << "Obtenir l'élement se trouvant à la position (i, j)" << endl;
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
        //l[i][j].push_back(e);
    }



}

