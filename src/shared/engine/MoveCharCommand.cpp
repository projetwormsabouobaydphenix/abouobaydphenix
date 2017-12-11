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

    void engine::MoveCharCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>& actions) {

        //cout << "Début movecharcommand" << endl;
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();

        size_t width = chars.getWidth();
        size_t height = chars.getHeight();
        //cout << width << endl;
        //cout << height << endl;

        
        for (int i = 0; i < (int)height; i++) {
            for (int j = 0; j < (int)width; j++) {
                if (chars.list[i * width + j].get() != NULL){
                    //cout << "Test 1" << endl;
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        //cout << "Test 2" << endl;
                        Personnage* persoAction = (Personnage*) chars.list[i * width + j].get();
                        if (persoAction->getColor() == color) {
                            int xFrom = persoAction->getI();
                            int yFrom = persoAction->getJ();
                            int lifeCountPersoAction = persoAction->getLifecount();
                            state::Direction precDir = persoAction->getDirection();
                            //cout << "x = " << xFrom << ", y = " << yFrom << endl;
                            //cout << "Le personnage a " << p->getLifecount() << " vies" << endl;
                            if (direction == Direction::RIGHT){
                                if (grid.get(xFrom+1, yFrom)->getTypeId() == TypeId::SPACE){
                                    if (grid.get(xFrom+1, yFrom+1)->getTypeId() == TypeId::FLOOR){
                                        Personnage* persoApAction = new Personnage(color, RIGHT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom+1, yFrom, persoApAction, precDir, nextDir);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                            Space* s = (Space*)grid.get(xFrom+1, yFrom);
                                            if (s->getNature() == SpaceTypeId::LIFE){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
                                            }
                                        return;
                                    }

                                    else if(grid.get(xFrom+1, yFrom+1)->getTypeId() == TypeId::SPACE){
                                        if (grid.get(xFrom+1, yFrom+2)->getTypeId() == TypeId::SPACE){
                                            engine::Action* die = new KillCharAction(color, xFrom, yFrom, persoAction);
                                            actions.push(shared_ptr<Action>(die));
                                            die->apply(state);
                                            return;
                                        } 
                                        else{
                                        Personnage* persoApAction = new Personnage(color, RIGHT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom+1, yFrom+1, persoApAction, precDir, nextDir);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                        cout << "test " << endl;
                                        Space* s = (Space*)grid.get(xFrom+1, yFrom+1);
                                        if (s->getNature() == SpaceTypeId::LIFE && persoApAction->getLifecount()< 3){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
                                            }
                                        
                                        return;
                                        }

                                    }
                                

                                else { 
                                    Personnage* persoApAction = new Personnage(color, RIGHT);
                                    persoApAction->setLifecount(lifeCountPersoAction);
                                    state::Direction nextDir = persoApAction->getDirection();
                                    engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom+1, yFrom-1, persoApAction, precDir, nextDir);
                                    move->apply(state);
                                    actions.push(shared_ptr<Action>(move));
                                    Space* s = (Space*)grid.get(xFrom+1, yFrom-1);
                                    if (s->getNature() == SpaceTypeId::LIFE && persoApAction->getLifecount()< 3){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
                                            }
                                    return;
                                }
                                }

                            }  //fin if direction = right

                            else if (direction == Direction::LEFT){
                                if (grid.get(xFrom-1, yFrom)->getTypeId() == TypeId::SPACE){
                                    if (grid.get(xFrom-1, yFrom+1)->getTypeId() == TypeId::FLOOR){
                                        Personnage* persoApAction = new Personnage(color, LEFT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom-1, yFrom, persoApAction, precDir, nextDir);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                            Space* s = (Space*)grid.get(xFrom-1, yFrom);
                                            if (s->getNature() == SpaceTypeId::LIFE && persoApAction->getLifecount()< 3){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
                                            }
                                        
                                        return;
                                    }

                                    else if(grid.get(xFrom-1, yFrom+1)->getTypeId() == TypeId::SPACE){
                                        if (grid.get(xFrom-1, yFrom+2)->getTypeId() == TypeId::SPACE){
                                            engine::Action* die = new KillCharAction(color, xFrom, yFrom, persoAction);
                                            actions.push(shared_ptr<Action>(die));
                                            die->apply(state);
                                            return;
                                        }
                                        else{
                                        Personnage* persoApAction = new Personnage(color, LEFT);
                                        persoApAction->setLifecount(lifeCountPersoAction);
                                        state::Direction nextDir = persoApAction->getDirection();
                                        engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom-1, yFrom+1, persoApAction, precDir, nextDir);
                                        move->apply(state);
                                        actions.push(shared_ptr<Action>(move));
                                            Space* s = (Space*)grid.get(xFrom-1, yFrom+1);
                                            if (s->getNature() == SpaceTypeId::LIFE && persoApAction->getLifecount()< 3){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
                                            }
                                        
                                        return;
                                        }
                                    }
                                }
                                else if(grid.get(xFrom-1, yFrom)->getTypeId() == TypeId::FLOOR){
                                    Personnage* persoApAction = new Personnage(color, LEFT);
                                    persoApAction->setLifecount(lifeCountPersoAction);
                                    state::Direction nextDir = persoApAction->getDirection();
                                    engine::Action* move = new MoveCharAction(color, xFrom, yFrom, xFrom-1, yFrom-1, persoApAction, precDir, nextDir);
                                    move->apply(state);
                                    actions.push(shared_ptr<Action>(move));
                                            Space* s = (Space*)grid.get(xFrom-1, yFrom-1);
                                            if (s->getNature() == SpaceTypeId::LIFE && persoApAction->getLifecount()< 3){
                                                persoApAction->setLifecount(persoApAction->getLifecount()+1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << persoApAction->getLifecount() << endl;
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

    MoveCharCommand* MoveCharCommand::deserialize(const Json::Value& in) {

    }

    void MoveCharCommand::serialize(Json::Value& out) const {

    }
    
    
    
}
