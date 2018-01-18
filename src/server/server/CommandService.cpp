
#include "CommandService.h"
#include "engine/Engine.h"
#include "engine/MoveCharAction.h"
#include "engine/MoveCharCommand.h"
#include "engine/ShootCommand.h"
#include "engine/ShootAction.h"
#include "engine/LoadCommand.h"
#include "ServiceException.h"
#include "ServicesManager.h"

#include <iostream>

using namespace engine;
using namespace std;
int nbCommands = 0;

namespace server{

    CommandService::CommandService(engine::Engine& engine): AbstractService("/command"),
        engine(engine) {

    }
    
    HttpStatus CommandService::get(Json::Value& out, int id) const {
        
        std::vector<Command*> currentCommand = engine.currentCommands;
        size_t sizeCommands = currentCommand.size();
        cout << "nombre de commandes : " << sizeCommands << endl;
        
        if (id == -1) {
            for (int i = 0; i <(int)sizeCommands; i++) {
                Json::Value outInter;
                const Command* command = currentCommand[i];
                if (!command)
                    throw ServiceException(HttpStatus::NOT_FOUND, "Invalid command id");
                engine::CommandTypeId commandTypeId = currentCommand[i]->getTypeId();
                if (commandTypeId == CommandTypeId::MOVE_CHAR){
                    MoveCharCommand* move = (MoveCharCommand*)currentCommand[i];
                    move->serialize(outInter);
                    //outInter["commande"] = "MoveCharCommand";
                }
                else if (commandTypeId == CommandTypeId::SHOOT){
                    ShootCommand* shoot = (ShootCommand*)currentCommand[i];
                    shoot->serialize(outInter);
                    //outInter["commande"] = "ShootCommand";
                }
                else if (commandTypeId == CommandTypeId::LOAD){
                    LoadCommand* load = (LoadCommand*)currentCommand[i];
                    load->serialize(outInter);
                    //outInter["commande"] = "LoadCommand";
                }
                out.append(outInter);
            }
            return HttpStatus::OK;
        } else {
            if (currentCommand.size()<=id)
                throw ServiceException(HttpStatus::NOT_FOUND, "Invalid command id");
            const Command* command = currentCommand[id];
            if (!command)
                throw ServiceException(HttpStatus::NOT_FOUND, "Invalid command id");
            engine::CommandTypeId commandTypeId = command->getTypeId();
            if (commandTypeId == CommandTypeId::MOVE_CHAR) {
                MoveCharCommand* move = (MoveCharCommand*)command;
                move->serialize(out);
            } else if (commandTypeId == CommandTypeId::SHOOT) {
                ShootCommand* shoot = (ShootCommand*)command;
                shoot->serialize(out);
                //out["commande"] = "ShootCommand";
            } else if (commandTypeId == CommandTypeId::LOAD) {
                LoadCommand* load = (LoadCommand*)command;
                load->serialize(out);
                //out["commande"] = "LoadCommand";
            } 
            return HttpStatus::OK;
        }

    }

    engine::Engine& CommandService::getEngine() const {
        return this->engine;
    }

    HttpStatus CommandService::put(Json::Value& out, const Json::Value& in) {
        
            for (int i = 0; i<(int)in.size(); i++){
                Json::Value uneCommande = in[i];
                //cout << "in[i] = " << uneCommande.toStyledString() << endl;
                if (uneCommande.isMember("commande")){
                    if (uneCommande["commande"].asString() == "MoveCharCommand"){
                        Command* move = new MoveCharCommand(1, state::Direction::LEFT);
                        move->deserialize(uneCommande);
                        engine.addCommand(i, move);
                        cout << "size currentCommands : " << engine.currentCommands.size() << endl;
                        nbCommands++;
                    }
                    else if (uneCommande["commande"].asString() == "ShootCommand"){
                        Command* shoot = new ShootCommand(1);
                        shoot->deserialize(uneCommande);
                        engine.addCommand(i, shoot);
                        cout << "size currentCommands : " << engine.currentCommands.size() << endl;
                        nbCommands++;
                    }
                    else if (uneCommande["commande"].asString() == "LoadCommand"){
                        Command* load = new LoadCommand("res/heuristic_ai.txt");
                        load->deserialize(uneCommande);
                        engine.addCommand(i, load);
                        cout << "size currentCommands : " << engine.currentCommands.size() << endl;
                        nbCommands++;
                    }
                }
                out["id"] = i;
            }
            
            
            //out["id"] = 1;
                
            return HttpStatus::CREATED;
        
    }
    
    
     
}