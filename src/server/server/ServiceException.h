// Generated by dia2code
#ifndef SERVER__SERVICEEXCEPTION__H
#define SERVER__SERVICEEXCEPTION__H

#include <string>

namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class ServiceException - 
  class ServiceException {
    // Associations
    server::HttpStatus httpStatus;
    // Attributes
  protected:
    std::string msg;
    // Operations
  public:
    ServiceException (HttpStatus status, std::string msg);
    HttpStatus status () const;
    const char* what () const;
    // Setters and Getters
    HttpStatus getHttpStatus() const;
    void setHttpStatus(HttpStatus httpStatus);
    const std::string& getMsg() const;
    void setMsg(const std::string& msg);
  };

};

#endif
