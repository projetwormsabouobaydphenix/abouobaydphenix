
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


using namespace std;

namespace state{
    


    ElementTab::ElementTab(size_t width, size_t height) {
        
        this->width=width;
        this->height=height;
        list.resize(width*height);
        for (int i=0;i<(int)(height*width);i++){
          list.push_back(NULL);
        }
    }
    
    size_t ElementTab::add(Element* e) {
        /*list.push_back(e);  
        //cout << "Ajout d'un élement à la grille" << endl;
        notifierObserver();*/
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
        //cout << "Redimensionnement en " << width << " par " << height << endl;
        list.resize(width*height);

    }

    void ElementTab::set(int i, int j, Element* e) {
        int position = j*width +i;
        //if (list[position] == NULL){
               list[position]= std::shared_ptr<Element>(e);
                //cout << "set elementTab ok" << endl;
                
        //}
//        list[position]= e;
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
    
    
    void ElementTab::changePosition(int x1, int y1, int x2, int y2, Element* e) {
        if (list[x2+y2*width].get() == NULL){
            //cout<<"changeposition"<<endl;
            list[x2 + y2 *width] = std::shared_ptr<Element>(e);
            list[x1 + y1 * width].reset();
        }
        
        else{
            cout << "Le personnage ne peut pas se déplacer, il y a quelqu'un devant lui." << endl;
        }
    }
    
    



}

