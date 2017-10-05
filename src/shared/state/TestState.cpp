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


using namespace std;

namespace state {
    
    void TestState::testsUnitaires(){
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
     
        //cout << "Crée un sol" << endl;
    
    
    
        //cout << "Ajoute le sol " << endl;
        //grille.add(f);
    
    
        //cout << "Crée un personnage vert" << endl;
        //Personnage personnage_vert(1);
    
        //cout << "Ajoute le personnage " << endl;
        //grille.add(personnage_vert);
    
        cout << "Vérifie que la largeur est 1" << endl;
        size_t l2 = grille.getWidth();
        if (l2 == 1){
            cout << "Largeur = 1" << endl;
        }
        else {
          cout << "Largeur différente de 1" << endl;
        } 
        //StaticElement * floor = new Floor();
        Element* floor;
        //floor = new Floor();
        //Element* personnage;
        //Personnage p(1); 
        //Floor f;
        //Space s;

        size_t add = grille.add(floor);
        cout << "Tests sur la grille" << endl;
        cout << "Redimmensionne en 5 par 7" << endl;
           grille.resize(5,7);
        cout << "Vérifie que la largeur est correcte : ";
        if (grille.getWidth()==5){
         cout << "OK" << endl;
         }
        else{
            cout << "Not OK" << endl;
        }
    
    cout << "Vérifie que la hauteur est correcte : ";
    if (grille.getHeight()== 7){
        cout << "OK" << endl;
    }
    else{
        cout << "Not OK" << endl;
    }
    
    cout << "Vérifie que toutes les cases sont nulles ";
    
    
    
    
    
    
    
}

}