
#include "EngineServer.h"
#include "json/json.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../../shared/engine/MoveCharCommand.h"
#include "../../shared/engine/ShootCommand.h"
#include "../../shared/engine/LoadCommand.h"

using namespace engine;
using namespace std;

namespace client{
    
    EngineServer::EngineServer(int port, std::string url) : port(port), url(url) {

    }
    
    void EngineServer::addCommand(int priority, engine::Command* cmd) {
        currentCommands.push_back(cmd);
        
        Json::Value out;
        Json::Value out2;
        /*if (!command)
            throw ServiceException(HttpStatus::NOT_FOUND, "Invalid command id");*/
        engine::CommandTypeId commandTypeId = cmd->getTypeId();
        if (commandTypeId == CommandTypeId::MOVE_CHAR){
            MoveCharCommand* move = (MoveCharCommand*)cmd;
            move->serialize(out);
            //outInter["commande"] = "MoveCharCommand";
        }
        else if (commandTypeId == CommandTypeId::SHOOT){
            ShootCommand* shoot = (ShootCommand*)cmd;
            shoot->serialize(out);
            //outInter["commande"] = "ShootCommand";
        }
        else if (commandTypeId == CommandTypeId::LOAD){
            LoadCommand* load = (LoadCommand*)cmd;
            load->serialize(out);
            //outInter["commande"] = "LoadCommand";
        }
        out2.append(out);
        sf::Http connection("http://localhost", 8080);
        sf::Http::Request* request_put_command = new sf::Http::Request;
        sf::Http::Request* request_get_command = new sf::Http::Request;
        request_put_command->setHttpVersion(1, 1);
        request_put_command->setField("Content-Type", "application/x-www-form-urlencoded");
        request_get_command->setHttpVersion(1, 1);
        request_get_command->setField("Content-Type", "application/x-www-form-urlencoded");
        
        sf::Http::Response response_put_command;
        sf::Http::Response response_get_command;
    
        Json::Value jsonResponse;
        Json::Reader jsonReader;
        
        request_put_command->setUri("/command");
        request_put_command->setMethod(sf::Http::Request::Put);
        request_put_command->setBody(out2.toStyledString());
        
        response_put_command = connection.sendRequest(*request_put_command);  
        if (response_put_command.getStatus() == sf::Http::Response::Created) {
            cout << "Created" << endl;
        }
        else {
            cout << "erreur" << endl;
        }
        
        if (!(jsonReader.parse(response_put_command.getBody(), jsonResponse, false))) {
            cout << jsonReader.getFormattedErrorMessages() << endl;
        }
        
        
        response_get_command = connection.sendRequest(*request_get_command);
        if (!(jsonReader.parse(response_put_command.getBody(), jsonResponse, false))) {
            cout << jsonReader.getFormattedErrorMessages() << endl;
        }
        
        cout << "Liste des commandes : " << endl;
        cout << response_get_command.getBody() << endl;
        
    }
    
}