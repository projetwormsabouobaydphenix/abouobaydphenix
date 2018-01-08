/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "VersionService.h"

using namespace std;

namespace server {

    VersionService::VersionService () : AbstractService("/version") {

    }

    HttpStatus VersionService::get (Json::Value& out, int id) const {
        out["major"] = 1;
        out["minor"] = 0;
        return HttpStatus::OK;
    }
}