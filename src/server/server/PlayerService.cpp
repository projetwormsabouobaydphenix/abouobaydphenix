
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PlayerService.h"
#include "Player.h"
#include "server.h"
#include <iostream>

using namespace std;
int nbJoueurs = 0;

namespace server {
    PlayerService::PlayerService (Game& game) : AbstractService("/player"),
        game(game) {

    }

    HttpStatus PlayerService::get (Json::Value& out, int id) const {
        //cout << "test get" << endl;
        size_t sizePlayers = game.getPlayers().size();
        //cout << "nombre de joueurs : " << sizePlayers << endl;
        if (id == -1){
            for (int i = 1; i<=(int)sizePlayers; i++){
                Json::Value outInter;
                const Player* player = game.getPlayer(i);
                if (!player)
                    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
                outInter["color"] = player->color;
                out.append(outInter);
            }
            return HttpStatus::OK;
        }
        else {
            const Player* player = game.getPlayer(id);
            Json::Value outInter;
            if (!player)
                throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
            out["color"] = player->color;
            return HttpStatus::OK;
        }
        
        
    }

    Game& PlayerService::getGame() const {
        return this->game;
    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND, "Invalid player id");
        unique_ptr<Player> usermod(new Player(*player));
        if (in.isMember("color")) {
            usermod->color = in["color"].asString();
        }
        game.setPlayer(id,std::move(usermod));
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
     
        if (nbJoueurs <2){
            string color = in["color"].asString();
            //bool free = in["id"].asInt();
            Player* player = new Player(color);
            out["id"] = game.addPlayer((unique_ptr<Player>)player);
            nbJoueurs++;
            //cout << "nbJoueurs = " << nbJoueurs << endl;
            return HttpStatus::CREATED;
        }
        
        //cout << "Le nombre de joueurs max est atteint" << endl;
        else{
            cout << "Le nombre de joueurs max est atteint, aucun joueur n'a été rajouté !" << endl;
            return HttpStatus::NOT_IMPLEMENTED;
        }
    }
    

    HttpStatus PlayerService::remove(int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    }


}
