/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestState.cpp
 * Author: sanaa
 * 
 * Created on 3 octobre 2017, 11:21
 */

#include "TestState.h"
#include "state.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

namespace state {
TestState::TestState() {
    cout<< "Tests des états" <<endl;
    cout<<"Création d'une grille"<<endl;
    ElementTab grille(0,1);
    cout << "Vérifie que la largeur est nulle" << endl;
    // vérification de la largeur
    size_t largeur = grille.getWidth();
    if (largeur == 0){
        cout << "La largeur est nulle" << endl;
    }
    else {
        cout << "La largeur n'est pas nulle" << endl;
    }
     
    cout << "Crée un sol" << endl;
    
    
    
    cout << "Ajoute le sol " << endl;
    //grille.add(f);
    
    
    cout << "Crée un personnage vert" << endl;
    //Personnage personnage_vert(1);
    
    cout << "Ajoute le personnage " << endl;
    //grille.add(personnage_vert);
    
    cout << "Vérifie que la largeur est 1" << endl;
    size_t l2 = grille.getWidth();
    if (l2 == 1){
       cout << "Largeur = 1" << endl;
    }
    else {
       cout << "Largeur différente de 1" << endl;
    } 
    
    Element* floor = new Floor();
    Element * personnage = new Personnage();
    
    
    
}

TestState::~TestState() {
}

}