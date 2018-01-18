// Generated by dia2code
#ifndef SERVER__COMMANDSERVICE__H
#define SERVER__COMMANDSERVICE__H

#include <json/json.h>

namespace engine {
  class Engine;
};
namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class CommandService - 
  class CommandService : public server::AbstractService {
    // Attributes
  protected:
    engine::Engine& engine;
    // Operations
  public:
    CommandService (engine::Engine& engine);
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus put (Json::Value& out, const Json::Value& in);
    // Setters and Getters
    engine::Engine& getEngine() const;
    void setEngine(const engine::Engine&& engine);
  };

};

#endif