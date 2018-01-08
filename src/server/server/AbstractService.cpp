
#include "AbstractService.h"
#include "ServiceException.h"


namespace server {

    AbstractService::AbstractService(const std::string& pattern) : pattern(pattern) {
        
    }

    AbstractService::~AbstractService() {

    }

    HttpStatus AbstractService::get(Json::Value& out, int id) const {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED, "Non implanté");
    }

    HttpStatus AbstractService::post(const Json::Value& in, int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED, "Non implanté");
    }

    HttpStatus AbstractService::put(Json::Value& out, const Json::Value& in) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED, "Non implanté");
    }

    HttpStatus AbstractService::remove(int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED, "Non implanté");
    }




}