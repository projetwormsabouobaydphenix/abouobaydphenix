/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharCommand.h"
#include "state.h"
#include "state/Personnage.h"
#include "MoveCharAction.h"
#include "KillCharAction.h"
#include <iostream>
#include <unistd.h>
#include <stack>
#include <fstream>
#include <string>

using namespace std;
using namespace state;

namespace engine {

    MoveCharCommand::MoveCharCommand(int color, state::Direction direction) : color(color),
    direction(direction) {
    }

    state::Direction MoveCharCommand::getDirection() const {
        return this->direction;
    }

    void MoveCharCommand::setDirection(state::Direction direction) {
        this->direction = direction;
    }

    int MoveCharCommand::getColor() const {
        return this->color;
    }

    void MoveCharCommand::setColor(int color) {
        this->color = color;
    }

    CommandTypeId engine::MoveCharCommand::getTypeId() const {
        //cout << "MoveCharCommand";
        return CommandTypeId::MOVE_CHAR;
    }

    void engine::MoveCharCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>&actions) {

        //cout << "Début movecharcommand" << endl;
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();

        size_t width = chars.getWidth();
        size_t height = chars.getHeight();
        
        int lifeCountPersoAction;
        int xFrom, yFrom;
        state::Direction precDir;

        for (int i = 0; i < (int) height; i++) {
            for (int j = 0; j < (int) width; j++) {
                if (chars.list[i * width + j].get() != NULL) {
                    //cout << "Test 1" << endl;
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        //cout << "Test 2" << endl;
                        Personnage* persoAction = (Personnage*) chars.list[i * width + j].get();
                        if (persoAction->getColor() == color) {
                            xFrom = persoAction->getI();
                            yFrom = persoAction->getJ();
                            lifeCountPersoAction = persoAction->getLifecount();
                            precDir = persoAction->getDirection();
                            //cout << "x = " << xFrom << ", y = " << yFrom << endl;
                            //cout << "Le personnage a " << p->getLifecount() << " vies" << endl;
                            if (direction == Direction::RIGHT) {
                                if (grid.get(xFrom + 1, yFrom)->getTypeId() == TypeId::SPACE) {
                                    if (grid.get(xFrom + 1, yFrom + 1)->getTypeId() == TypeId::FLOOR) {
                                        Personnage* persoApAction = new Personnage(color, RIGHT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom + 1, yFrom, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                        Space* s = (Space*) grid.get(xFrom + 1, yFrom);
                                        if (s->getNature() == SpaceTypeId::LIFE ) {
                                            if (persoApAction->getLifecount()<3){
                                                persoApAction->setLifecount(lifeCountPersoAction + 1);
                                                cout << "Super, le personnage " << color <<" a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() <<endl;
                                            }
                                            else {
                                                cout << "Le personnage a déjà 3 vies." << endl;
                                            }
                                                        
                                        }
                                        return;
                                    }
                                    else if (grid.get(xFrom + 1, yFrom + 1)->getTypeId() == TypeId::SPACE) {
                                        if (grid.get(xFrom + 1, yFrom + 2)->getTypeId() == TypeId::SPACE) {
                                            engine::Action* die = new KillCharAction(color, xFrom, yFrom, persoAction);
                                            actions.push(shared_ptr<Action>(die));
                                            die->apply(state);
                                            return;
                                        }
                                        else {
                                            Personnage* persoApAction = new Personnage(color, RIGHT);
                                            persoApAction->setLifecount(lifeCountPersoAction);
                                            state::Direction nextDir = persoApAction->getDirection();
                                            engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom + 1, yFrom + 1, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                            move->apply(state);
                                            actions.push(shared_ptr<Action>(move));
                                            //cout << "test " << endl;
                                            Space* s = (Space*) grid.get(xFrom + 1, yFrom + 1);
                                            if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction <3) {
                                                persoApAction->setLifecount(lifeCountPersoAction );
                                                cout << "Super, le personnage " << color <<" a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << lifeCountPersoAction + 1 << endl;
                                            }
                                            else if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction==3) {
                                        cout << "Le personnage a déjà trois vies, il ne peut pas en récupérer" << endl;
                                    }

                                            return;
                                        }

                                    }
                                }

                                    else {
                                        Personnage* persoApAction = new Personnage(color, RIGHT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom + 1, yFrom - 1, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                        Space* s = (Space*) grid.get(xFrom + 1, yFrom - 1);
                                        if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction <3) {
                                            persoApAction->setLifecount(persoApAction->getLifecount() + 1);
                                            cout << "Super, le personnage " << color << " a récupéré une vie" << endl;
                                            cout << "Il en a maintenant " << lifeCountPersoAction + 1 << endl;
                                        }
                                        return;
                                    }
                                

                            }//fin if direction = right

                            else if (direction == Direction::LEFT) {
                                if (grid.get(xFrom - 1, yFrom)->getTypeId() == TypeId::SPACE) {
                                    if (grid.get(xFrom - 1, yFrom + 1)->getTypeId() == TypeId::FLOOR) {
                                        Personnage* persoApAction = new Personnage(color, LEFT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom - 1, yFrom, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                        Space* s = (Space*) grid.get(xFrom - 1, yFrom);
                                        if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction <3) {
                                            persoApAction->setLifecount(lifeCountPersoAction + 1);
                                            cout << "Super, le personnage "<<color << " a récupéré une vie" << endl;
                                            cout << "Il en a maintenant " << lifeCountPersoAction + 1 << endl;
                                        }

                                        return;
                                    }
                                    else if (grid.get(xFrom - 1, yFrom + 1)->getTypeId() == TypeId::SPACE) {
                                        if (grid.get(xFrom - 1, yFrom + 2)->getTypeId() == TypeId::SPACE) {
                                            engine::Action* die = new KillCharAction(color, xFrom, yFrom, persoAction);
                                            actions.push(shared_ptr<Action>(die));
                                            die->apply(state);
                                            return;
                                        } else {
                                            Personnage* persoApAction = new Personnage(color, LEFT);
                                            persoApAction->setLifecount(lifeCountPersoAction);
                                            state::Direction nextDir = persoApAction->getDirection();
                                            engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom - 1, yFrom + 1, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                            move->apply(state);
                                            actions.push(shared_ptr<Action>(move));
                                            Space* s = (Space*) grid.get(xFrom - 1, yFrom + 1);
                                            if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction <3) {
                                                persoApAction->setLifecount(persoApAction->getLifecount() + 1);
                                                cout << "Super, le personnage " << color <<" a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << lifeCountPersoAction + 1 << endl;
                                            }
                                           

                                            return;
                                        }
                                    }
                                } else if (grid.get(xFrom - 1, yFrom)->getTypeId() == TypeId::FLOOR) {
                                    Personnage* persoApAction = new Personnage(color, LEFT);
                                    persoApAction->setLifecount(lifeCountPersoAction);
                                    state::Direction nextDir = persoApAction->getDirection();
                                    engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom - 1, yFrom - 1, persoApAction, precDir, nextDir, lifeCountPersoAction);
                                    move->apply(state);
                                    actions.push(shared_ptr<Action>(move));
                                    Space* s = (Space*) grid.get(xFrom - 1, yFrom - 1);
                                    if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction <3) {
                                        persoApAction->setLifecount(persoApAction->getLifecount() + 1);
                                        cout << "Super, le personnage " << color <<" a récupéré une vie" << endl;
                                        cout << "Il en a maintenant " << lifeCountPersoAction + 1 << endl;
                                    }
                                    else if (s->getNature() == SpaceTypeId::LIFE && lifeCountPersoAction==3) {
                                        cout << "Le personnage a déjà trois vies, il ne peut pas en récupérer" << endl;
                                    }
                                    return;
                                }
                            } //fin direction == LEFT
                        } //fin color
                    }
                }
            }
        }
    }

    void MoveCharCommand::deserialize(const Json::Value& in) {

        //cout << "debut deserialize move" << endl;
        if (in.isMember("commande")){
            if (in["commande"].asString() == "MoveCharCommand"){
                //cout << "commande move" << endl;
                //MoveCharCommand* move = new MoveCharCommand(2, Direction::RIGHT); //constructeur choisi au hasard
                if (in.isMember("color")) {
                    this->color = in["color"].asInt();
                }
                if (in.isMember("direction")) {
                    if (in["direction"].asString() == "Left") {
                        this->direction = Direction::LEFT;
                    } else if (in["direction"].asString() == "Right") {
                        this->direction = Direction::RIGHT;
                    }
                }
                

            }
        }


    }

    void MoveCharCommand::serialize(Json::Value& out) const {
  
        out["commande"] = "MoveCharCommand";
        out["color"] = color;
        if (direction == Direction::LEFT) {
            out["direction"] = "Left";
        } else if (direction == Direction::RIGHT) {
            out["direction"] = "Right";
        }
       
       
    }
}
