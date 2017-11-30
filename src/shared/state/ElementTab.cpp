
#include "ElementTab.h"
#include "state.h"
#include "Element.h"
#include <vector>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>




namespace state{
    
using namespace std;

    ElementTab::ElementTab(size_t width, size_t height) {
        this->width=width;
        this->height=height;
        list.resize(width*height);
        for (int i=0;i<(int)(height*width);i++){
          list.push_back(NULL);
        }
    }
    
    size_t ElementTab::add(Element* e) {
        list.push_back(std::shared_ptr<Element>(e));  
        //cout << "Ajout d'un élement à la grille" << endl;
        //notifierObserver();
        return list.size();
    }


    Element* ElementTab::get(int i, int j) const {
        //if (0<=i and i<(int)width and 0<=j and j<(int)height){
            return list[j*width + i].get();
        /*}
        else {
            return nullptr;
        }*/
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
        int position = j*width +i;
        //if (list[position] == NULL){
                list[position]= std::shared_ptr<Element>(e);
                //cout << "set elementTab ok" << endl;
                
        //}
    }
    
    std::vector<int> ElementTab::load(const std::string& file) {
        std::vector<int> vcarte;
        string n;
	std::ifstream fichier(file);
        //fichier.open("terre.csv", std::ios::in);
        if (!fichier.is_open()) std::cout << "Erreur open file" << endl;
        while(fichier.good()){
            getline(fichier, n, ',');
            vcarte.push_back(std::stoi(n));
        }
        return vcarte;
    }
    
    void ElementTab::changePosition(int x1, int y1, int x2, int y2) {
        if (get(x1, y1) != NULL){
            if (get(x2, y2) == NULL){
                list[x2 + y2 * width].swap(list[x1 + y1 * width]);
                //list[x2 + y2 * width].get();
            }
        }
        else{
            cout << "Erreur : on ne peut pas déplacer l'élement" << endl;
        }
    }

    void ElementTab::swap(Element* e1, Element* e2) {
        Element* tmp = e1;
        e1 = NULL;
        e2 = tmp;
        cout << "Swap OK" << endl;
        return;

    }

    
    Element* ElementTab::alloc(int type){
        Element* e;
        if (type == -1){
            e = new Space(SpaceTypeId::EMPTY);
            return e;
        }
        else if (type == 280){
            e = new Floor(FloorTypeId::GROUND);
            return e;
        }
        else if (type == 119){
            e = new Floor(FloorTypeId::GRASS);
            return e;
        }
        else if (type == 32){
            e = new Floor(FloorTypeId::WATER);
            return e;
        }
        
        
    }

}

