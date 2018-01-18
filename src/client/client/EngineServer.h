// Generated by dia2code
#ifndef CLIENT__ENGINESERVER__H
#define CLIENT__ENGINESERVER__H

#include <string>

namespace engine {
  class Engine;
}

#include "engine/Engine.h"

namespace client {

  /// class EngineServer - 
  class EngineServer : public engine::Engine {
    // Attributes
  public:
    int port;
    std::string url;
    // Operations
  public:
    EngineServer (int port, std::string url);
    void addCommand (int priority, engine::Command* cmd);
    // Setters and Getters
  };

};

#endif