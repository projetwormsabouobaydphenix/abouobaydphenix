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

TestState::TestState() {
    cout<< "Tests des états" <<endl;
    cout<<"Création d'une grille"<<endl;
    ElementTab grille = new ElementTab(3, 5);
    
    
}

TestState::~TestState() {
}

