/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ServiceException.h"
#include "HttpStatus.h"

using namespace std;

namespace server {
    ServiceException::ServiceException(HttpStatus status, std::string msg): httpStatus(status),msg(msg) { 
       
    }   
 
    const string& ServiceException::getMsg() const {
        return msg;
    }
    
    HttpStatus ServiceException::status () const {
        return httpStatus;
    }

    const char* ServiceException::what () const {
        return msg.c_str();
    }
}