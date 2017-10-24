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

namespace state {
    
    TestState::TestState(){
        cout<< "Tests des états" <<endl;
        cout<<"Création d'une grille"<<endl;
        ElementTab grille(0,1);
        //Personnage* perso;
        //perso = new Personnage; 
        cout << "Vérifie que la largeur est nulle" << endl;
        // vérification de la largeur
        size_t largeur = grille.getWidth();
        if (largeur == 0){
            cout << "La largeur est nulle" << endl;
        }
        else {
            cout << "La largeur n'est pas nulle" << endl;
        }
    
        cout << "Vérifie que la largeur est 1" << endl;
        size_t l2 = grille.getWidth();
        if (l2 == 1){
            cout << "Largeur = 1" << endl;
        }
        else {
          cout << "Largeur différente de 1" << endl;
        } 
<<<<<<< HEAD
        //StaticElement * floor = new Floor();
        Element* fl;
        fl = new Floor(FULL);
=======
        Element* floor = new Floor();
        //Element* floor;
        //floor = new Floor();
>>>>>>> 354a9cd21019c6cacb51d82aa3781ccb62ff8e6b
        //Element* personnage;
        Personnage* ptt; 
        //Floor floor;
        //Space s;
        cout << "Ajout d'un élement dans la grille" << endl;

        size_t add = grille.add(fl);
        
        cout << "On vérifie que la largeur a changé :" ;
        if (add == 1){
            cout << "OK" << endl;
        }
        else{
            cout << "not ok" << endl;
        }
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
    
        //cout << "Vérifie que toutes les cases sont nulles ";
    
    
    
    
    
    
    
}

}