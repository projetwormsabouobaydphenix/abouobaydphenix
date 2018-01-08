
#include "ServiceException.h"

namespace server{

    ServiceException::ServiceException(HttpStatus status, std::string msg): httpStatus(status), msg(msg) {

    }

    HttpStatus ServiceException::getHttpStatus() const {
        return this->httpStatus;
    }

    const std::string& ServiceException::getMsg() const {
        return this->msg;
    }

    void ServiceException::setHttpStatus(HttpStatus httpStatus) {
        this->httpStatus = httpStatus;
    }

    void ServiceException::setMsg(const std::string& msg) {
        this->msg = msg;
    }

    HttpStatus ServiceException::status() const {
        return httpStatus;
    }

    const char* ServiceException::what() const {
        return msg.c_str();
    }
    

    
    
    
    
}