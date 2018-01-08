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
/*Engine moteur;
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
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 rng(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, list.size()-1);
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
    for (int i = 0; i<4; i++){
        int p = rand()%4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }
   
    shoot1->serialize(commande);
    out.append(commande);
    commande.clear();
   
    for (int i = 0; i<6; i++){
        int p = rand()%4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }
   
    shoot2->serialize(commande);
    out.append(commande);
    commande.clear();
   
   
   
    for (int i = 0; i<3; i++){
        int p = rand()%4;
        //cout << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }
   
    shoot2->serialize(commande);
    out.append(commande);
    commande.clear();
   
    for (int i = 0; i<3; i++){
        int p = rand()%4;
        //cout << "i = " << i << " p = " << p << endl;
        list[p]->serialize(commande);
        out.append(commande);
        commande.clear();
    }
   
    listJson.append(out);
   
   
   
    string const nomFichier("res/replay.txt");
    ofstream monFlunomFichier.c_str());
    monFlux.clear();
    if (monFlux){
        monFlux << listJson.toStyledString() << endl;
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    cout << "Des commandes random ont été ajoutées au fichier replay.txt" << endl;*/
   
}

/*class Request {
public:
    struct MHD_PostProcessor *pp = nullptr;
    string data;
    ~Request() {
        if (pp) MHD_destroy_post_processor (pp);
    }
};

// Fonction pour gérer les données imporantes en upload (non implanté ici)
static int
post_iterator(void *cls,
        enum MHD_ValueKind kind,
        const char *key,
        const char *filename,
        const char *content_type,
        const char *transfer_encoding,
        const char *data, uint64_t off, size_t size) 
{
    return MHD_NO;
}

// Détruit les données d'une requête
static void
request_completed (void *cls, struct MHD_Connection *connection,
                   void **con_cls, enum MHD_RequestTerminationCode toe)
{
  Request *request = (Request*)*con_cls;
  if (request) {
      delete request;
      *con_cls = nullptr;
  }
}

// Gestionnaire principal
static int
main_handler (void *cls,      
          struct MHD_Connection *connection,
          const char *url, // 
          const char *method,
          const char *version,
          const char *upload_data, size_t *upload_data_size, void **ptr) 
{
    // Données pour une requête (en plusieurs appels à cette fonction)
    Request *request = (Request*)*ptr;

    // Premier appel pour cette requête
    if (!request) { 
        request = new Request();
        if (!request) {
            return MHD_NO;
        }
        *ptr = request;
        if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
         || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
            request->pp = MHD_create_post_processor(connection,1024,&post_iterator,request);
            if (!request->pp) {
                cerr << "Failed to setup post processor for " << url << endl;
                return MHD_NO;
            }
        }
        return MHD_YES;
    }    
    
    // Cas où il faut récupérer les données envoyés par l'utilisateur
    if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
     || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
        MHD_post_process(request->pp,upload_data,*upload_data_size);
        if (*upload_data_size != 0) {
            request->data = upload_data;
            *upload_data_size = 0;
            return MHD_YES;
        }    
    }

    HttpStatus status;
    string response;
    try {

        ServicesManager *manager = (ServicesManager*) cls;
        status = manager->queryService(response,request->data,url,method);
    }
    catch(ServiceException& e) {
        status = e.status();
        response = e.what();
        response += "\n";
    }
    catch(exception& e) {
        status = HttpStatus::SERVER_ERROR;
        response = e.what();
        response += "\n";
    }
    catch(...) {
        status = HttpStatus::SERVER_ERROR;
        response = "Unknown exception\n";
    }

    struct MHD_Response *mhd_response;
    mhd_response = MHD_create_response_from_buffer(response.size(),(void *)response.c_str(),MHD_RESPMEM_MUST_COPY);
    if (strcmp(method,MHD_HTTP_METHOD_GET) == 0) {
        MHD_add_response_header(mhd_response,"Content-Type","application/json; charset=utf-8");
    }
    int ret = MHD_queue_response(connection, status, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret;
}

void TestServer::test_listen(){
    
    try {
        ServicesManager servicesManager;
        VersionService* VS = new VersionService;
        servicesManager.registerService((unique_ptr<VersionService>)VS);

        Game game;
        Player player = new Player("Paul");
        game.addPlayer((unique_ptr<Player>)player);
        PlayerService PlServ = new PlayerService;
        servicesManager.registerService((unique_ptr<PlayerService>)PlServ);

        struct MHD_Daemon *d;
        if (argc != 2) {
            printf("%s PORT\n", argv[0]);
            return 1;
        }
        d = MHD_start_daemon(// MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG | MHD_USE_POLL,
                MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG | MHD_USE_POLL,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG,
                atoi(argv[1]),
                NULL, NULL, 
                &main_handler, (void*) &servicesManager,
                MHD_OPTION_NOTIFY_COMPLETED, request_completed, NULL,
                MHD_OPTION_END);
        if (d == NULL)
            return 1;
        cout << "Pressez <entrée> pour arrêter le serveur" << endl;
        (void) getc(stdin);
        MHD_stop_daemon(d);
    }
    catch(exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}*/

TestServer::~TestServer() {
}

