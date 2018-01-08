
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PlayerService.h"
#include "Player.h"
#include "server.h"

using namespace std;

namespace server {
    PlayerService::PlayerService (Game& game) : AbstractService("/player"),
        game(game) {

    }

    HttpStatus PlayerService::get (Json::Value& out, int id) const {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        out["name"] = player->name;
        out["free"] = player->free;
        return HttpStatus::OK;
    }

    Game& PlayerService::getGame() const {
        return this->game;
    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND, "Invalid player id");
        unique_ptr<Player> usermod(new Player(*player));
        if (in.isMember("name")) {
            usermod->name = in["name"].asString();
        }
        if (in.isMember("free")) {
            usermod->free = in["free"].asBool();
        }
        game.setPlayer(id,std::move(usermod));
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
        string name = in["name"].asString();
        bool free = in["free"].asBool();
        Player* player = new Player(name, free);
        out["id"] = game.addPlayer((unique_ptr<Player>)player);
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove(int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    }


}
