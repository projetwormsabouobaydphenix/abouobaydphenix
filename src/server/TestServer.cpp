/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestServer.cpp
 * Author: sanaa
 * 
 * Created on 12 décembre 2017, 10:36
 */

#include "TestServer.h"
#include "state/ElementTab.h"
#include "../shared/state.h"
#include <vector>
#include "../shared/ai.h"
#include "../shared/engine.h"
#include "render.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
using namespace state;
using namespace render;
using namespace ai;
using namespace engine;

TestServer::TestServer() {
}

void TestServer::test_record() {
    Engine moteur;
    Json::Value out;
    
    Command* move = new MoveCharCommand(2, Direction::LEFT);
    moteur.addCommand(0, move);
    
    
    Command* shoot = new ShootCommand(1);
    moteur.addCommand(1, shoot);
    
    std::vector<Command*> listCommand = moteur.currentCommands;
    Json::Value listJson;
    
    
    cout << listCommand.size() << endl;
    for (int i = 0; i<(int)listCommand.size(); i++){
        cout << "i = " << i << endl;
        listCommand[i]->serialize(out);
        listJson.append(out);
        out.clear();
    }
    
    cout << listJson.toStyledString() << endl;
    
    string const nomFichier("res/replay.txt");
    ofstream monFlux(nomFichier.c_str());
    monFlux.clear();
    if (monFlux){
        monFlux << listJson.toStyledString() << endl;
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
   
}

TestServer::~TestServer() {
}

