
#include "CommandService.h"
#include "engine/Engine.h"
#include "engine/MoveCharAction.h"
#include "engine/MoveCharCommand.h"

using namespace engine;

namespace server{

    CommandService::CommandService(engine::Engine& engine): AbstractService("/command"),
        engine(engine) {

    }
    
    HttpStatus CommandService::get(Json::Value& out, int id) const {
        return HttpStatus::OK;
    }

    engine::Engine& CommandService::getEngine() const {
        return this->engine;
    }

    HttpStatus CommandService::put(Json::Value& out, const Json::Value& in) {
        //if (in.isMember("commande")){
            //for (int i = 0; i<(int)in.size(); i++){
               /* if (in.isMember("commande")){
                    if (in["commande"].asString() == "MoveCharCommand"){
                        Command* move = new MoveCharCommand(1, state::Direction::LEFT);
                        engine.addCommand(1, move->deserialize(in));    
                       // engine.addCommand(1,  engine::MoveCharCommand)
                        
                    }
                    else if (uneCommande["Type de commande"].asString() == "ShootCommand"){
                        Command* shoot = new ShootCommand(1);
                        engine.addCommand(1, shoot->deserialize(in));   */ 
                    
                
            //}
                
                //out["test"] = 1;
                
                return HttpStatus::CREATED;
        
    }
    
    
     
}