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

#include "server/ServicesManager.h"
#include "server/ServiceException.h"
#include "server/VersionService.h"
#include "server/PlayerService.h"
#include "server/HttpStatus.h"

#include <sstream>
#include <microhttpd.h>
#include <stdio.h>
#include <cstring> 

using namespace std;
using namespace state;
using namespace render;
using namespace ai;
using namespace engine;
using namespace server;

TestServer::TestServer() {
}

void TestServer::test_record() {
    Engine moteur;
    vector<Command*> list;

    Command* move1 = new MoveCharCommand(1, Direction::RIGHT);
    list.push_back(move1);



    Command* move3 = new MoveCharCommand(1, Direction::LEFT);
    list.push_back(move3);

    Command* move4 = new MoveCharCommand(2, Direction::RIGHT);
    list.push_back(move4);



    Command* move5 = new MoveCharCommand(2, Direction::LEFT);
    list.push_back(move5);

    Command* load = new LoadCommand("res/heuristic_ai.txt");

    Json::Value listJson;
    Json::Value out;
    Json::Value commande;
    std::mt19937 randgen;
    std::random_device rd; //Will be used to obtain a seed for the random number engine
    std::mt19937 rng(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, list.size() - 1);
    randgen = rng;
    //int pos = dis(randgen);

    srand(time(0));

    load->serialize(commande);
    out.append(commande);
    //cout << out.toStyledString() << endl;
    listJson.append(out);
    //cout << listJson.toStyledString() << endl;
    out.clear();
    commande.clear();

    Command* shoot2 = new ShootCommand(2);
    Command* shoot1 = new ShootCommand(1);




    //cout << listCommand.size() << endl;
    for (int i = 0; i < 4; i++) {
        int p = rand() % 4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }

    shoot1->serialize(commande);
    out.append(commande);
    commande.clear();

    for (int i = 0; i < 6; i++) {
        int p = rand() % 4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }

    shoot2->serialize(commande);
    out.append(commande);
    commande.clear();



    for (int i = 0; i < 3; i++) {
        int p = rand() % 4;
        //cout << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }

    shoot2->serialize(commande);
    out.append(commande);
    commande.clear();

    for (int i = 0; i < 3; i++) {
        int p = rand() % 4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }

    listJson.append(out);



    /*string const nomFichier("res/replay.txt");
    ofstream monFlunomFichier.c_str();
    monFlux.clear();
    if (monFlux) {
        monFlux << listJson.toStyledString() << endl;
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }*/
    cout << "Des commandes random ont été ajoutées au fichier replay.txt" << endl;
}

TestServer::~TestServer() {
}

