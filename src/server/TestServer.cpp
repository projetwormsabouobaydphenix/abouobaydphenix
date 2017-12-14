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
#include <random>


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
    
    vector<Command*> list;

    
    Command* move1 = new MoveCharCommand(1, Direction::RIGHT);
    list.push_back(move1);
    
    move1 = new MoveCharCommand(1, Direction::RIGHT);
    list.push_back(move1);
    
    move1 = new MoveCharCommand(1, Direction::RIGHT);
    list.push_back(move1);
    
    ShootCommand* shoot1 = new ShootCommand(1);
    list.push_back(shoot1);

    Command* move3 = new MoveCharCommand(2, Direction::RIGHT);
    list.push_back(move3);

    Command* move4 = new MoveCharCommand(2, Direction::RIGHT);
    list.push_back(move4);
    
    move4 = new MoveCharCommand(2, Direction::LEFT);
    list.push_back(move4);

    Command* shoot2 = new ShootCommand(2);
    list.push_back(shoot2);

    Command* move5 = new MoveCharCommand(1, Direction::LEFT);
    list.push_back(move5);
    
    move5 = new MoveCharCommand(1, Direction::RIGHT);
    list.push_back(move5);
        
    
    
    //std::vector<Command*> listCommand = moteur.currentCommands;
    Json::Value listJson;
    std::mt19937 randgen;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 rng(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, list.size()-1);
    randgen = rng;
    int pos = dis(randgen);
    
    
    moteur.addCommand(0, list[pos]);
    moteur.update();
    
    
    //cout << listCommand.size() << endl;
    for (int i = 0; i<(int)list.size(); i++){
        //int p = rand()%6;
        //cout << "i = " << i << " p = " << p << endl;
        list[i]->serialize(out);
        listJson.append(out);
        out.clear();
    }
    
    
    
    string const nomFichier("res/replay.txt");
    ofstream monFlux(nomFichier.c_str());
    monFlux.clear();
    if (monFlux){
        monFlux << listJson.toStyledString() << endl;
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    cout << "Les commandes ont été ajoutées au fichier replay.txt" << endl;
   
}

TestServer::~TestServer() {
}

