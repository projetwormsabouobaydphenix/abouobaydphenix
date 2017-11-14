
#include "ElementTab.h"
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
    }
    
    size_t ElementTab::add(Element* e) {
        list.push_back(std::shared_ptr<Element>(e));  
        cout << "Ajout d'un élement à la grille" << endl;
        notifierObserver();
        return list.size();
    }


    Element* ElementTab::get(int i, int j) const {
        return list[j*width + i].get();
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
        list[position]= std::shared_ptr<Element>(e);
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



}

