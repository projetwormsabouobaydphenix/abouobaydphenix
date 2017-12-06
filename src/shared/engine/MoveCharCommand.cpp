/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharCommand.h"
#include "state.h"
#include "state/Personnage.h"
#include <iostream>
#include <unistd.h>

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

    void engine::MoveCharCommand::execute(state::State& state) {

        //cout<<"Le personnage s'est déplacé"<<endl;
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();

        size_t width = chars.getWidth();
        size_t height = chars.getHeight();
        //cout << width << endl;
        //cout << height << endl;

        for (int i = 0; i < (int) height; i++) {
            for (int j = 0; j < (int) width; j++) {
                if (chars.list[i * width + j].get() != NULL) {
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* p = (Personnage*) chars.list[i * width + j].get();
                        if (p->getColor() == color) {
                            int xFrom = p->getI();
                            int yFrom = p->getJ();
                            //cout << "x = " << xFrom << ", y = " << yFrom << endl;
                            //cout << "Le personnage a " << p->getLifecount() << " vies" << endl;
                            if (direction == Direction::RIGHT) {
                                if (grid.get(xFrom + 1, yFrom)->getTypeId() == TypeId::SPACE) {
                                    if (grid.get(xFrom + 1, yFrom + 1)->getTypeId() == TypeId::FLOOR) {
                                        Personnage* p1 = new Personnage(color, RIGHT);
                                        p1->setI(xFrom + 1);
                                        p1->setJ(yFrom);
                                        p1->setLifecount(p->getLifecount());
                                        cout << "life" << p1->getLifecount() << endl;
                                        chars.changePosition(xFrom, yFrom, xFrom + 1, yFrom, p1);
                                        if (grid.get(xFrom + 1, yFrom)->getTypeId() == state::TypeId::SPACE) {
                                            Space* s = (Space*) grid.get(xFrom + 1, yFrom);
                                            if (s->getNature() == SpaceTypeId::LIFE) {
                                                if (p1->getLifecount() < 3) {
                                                    p1->setLifecount(p1->getLifecount() + 1);
                                                    cout << "Super, le personnage a récupéré une vie" << endl;
                                                    cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                                } else {
                                                    cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                                }
                                            }
                                        }
                                        return;
                                    }
                                    
                                    else if (grid.get(xFrom + 1, yFrom + 1)->getTypeId() == TypeId::SPACE) {
                                        if (grid.get(xFrom + 1, yFrom + 2)->getTypeId() == TypeId::SPACE) {
                                            chars.list[xFrom + yFrom * width].reset();
                                            cout << "Le personnage est tombé dans l'eau. Il est mort." << endl;
                                            return;
                                        } else {
                                            Personnage* p1 = new Personnage(color, RIGHT);
                                            p1->setI(xFrom + 1);
                                            p1->setJ(yFrom + 1);
                                            p1->setLifecount(p->getLifecount());
                                            cout << "life" << p1->getLifecount() << endl;
                                            chars.changePosition(xFrom, yFrom, xFrom + 1, yFrom + 1, p1);
                                            if (grid.get(xFrom + 1, yFrom + 1)->getTypeId() == state::TypeId::SPACE) {
                                                Space* s = (Space*) grid.get(xFrom + 1, yFrom + 1);
                                                if (s->getNature() == SpaceTypeId::LIFE) {
                                                    if (p1->getLifecount() < 3) {
                                                        p1->setLifecount(p1->getLifecount() + 1);
                                                        cout << "Super, le personnage a récupéré une vie" << endl;
                                                        cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                                    } else {
                                                        cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                                    }
                                                }
                                                return;
                                            }
                                        }
                                    } else { //if(grid.get(xFrom+1, yFrom)->getTypeId() == TypeId::FLOOR){
                                        Personnage* p1 = new Personnage(color, RIGHT);
                                        p1->setI(xFrom + 1);
                                        p1->setJ(yFrom - 1);
                                        p1->setLifecount(p->getLifecount());
                                        chars.changePosition(xFrom, yFrom, xFrom + 1, yFrom - 1, p1);
                                        if (grid.get(xFrom + 1, yFrom - 1)->getTypeId() == state::TypeId::SPACE) {
                                            Space* s = (Space*) grid.get(xFrom + 1, yFrom - 1);
                                            if (s->getNature() == SpaceTypeId::LIFE) {
                                                if (p1->getLifecount() < 3) {
                                                    p1->setLifecount(p1->getLifecount() + 1);
                                                    cout << "Super, le personnage a récupéré une vie" << endl;
                                                    cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                                } else {
                                                    cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                                }
                                            }
                                            return;
                                        }

                                    }
                                }
                            }//fin if direction = right

                            else if (direction == Direction::LEFT) {
                                cout << "direction = left" << endl;
                                if (grid.get(xFrom - 1, yFrom)->getTypeId() == TypeId::SPACE) {
                                    if (grid.get(xFrom - 1, yFrom + 1)->getTypeId() == TypeId::FLOOR) {
                                        Personnage* p1 = new Personnage(color, LEFT);
                                        p1->setI(xFrom - 1);
                                        p1->setJ(yFrom);
                                        p1->setLifecount(p->getLifecount());
                                        cout << "life" << p1->getLifecount() << endl;
                                        chars.changePosition(xFrom, yFrom, xFrom - 1, yFrom, p1);
                                        if (grid.get(xFrom - 1, yFrom)->getTypeId() == state::TypeId::SPACE) {
                                            Space* s = (Space*) grid.get(xFrom - 1, yFrom);
                                            if (s->getNature() == SpaceTypeId::LIFE) {
                                                if (p1->getLifecount() < 3) {
                                                    p1->setLifecount(p1->getLifecount() + 1);
                                                    cout << "Super, le personnage a récupéré une vie" << endl;
                                                    cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                                } else {
                                                    cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                                }
                                            }
                                            return;
                                        }
                                    }
                                        else if (grid.get(xFrom - 1, yFrom + 1)->getTypeId() == TypeId::SPACE) {
                                            if (grid.get(xFrom - 1, yFrom + 2)->getTypeId() == TypeId::SPACE) {
                                                chars.list[xFrom + yFrom * width].reset();
                                                cout << "Le personnage est tombé dans l'eau. Il est mort." << endl;
                                                return;
                                            } else {
                                                Personnage* p1 = new Personnage(color, LEFT);
                                                p1->setI(xFrom - 1);
                                                p1->setJ(yFrom + 1);
                                                p1->setLifecount(p->getLifecount());
                                                cout << "life" << p1->getLifecount() << endl;
                                                chars.changePosition(xFrom, yFrom, xFrom - 1, yFrom + 1, p1);
                                                if (grid.get(xFrom - 1, yFrom + 1)->getTypeId() == state::TypeId::SPACE) {
                                                    Space* s = (Space*) grid.get(xFrom - 1, yFrom + 1);
                                                    if (s->getNature() == SpaceTypeId::LIFE) {
                                                        if (p1->getLifecount() < 3) {
                                                            p1->setLifecount(p1->getLifecount() + 1);
                                                            cout << "Super, le personnage a récupéré une vie" << endl;
                                                            cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                                        } else {
                                                            cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                                        }
                                                    }
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                 else if (grid.get(xFrom - 1, yFrom)->getTypeId() == TypeId::FLOOR) {
                                    Personnage* p1 = new Personnage(color, LEFT);
                                    p1->setI(xFrom - 1);
                                    p1->setJ(yFrom - 1);
                                    p1->setLifecount(p->getLifecount());
                                    chars.changePosition(xFrom, yFrom, xFrom - 1, yFrom - 1, p1);
                                    if (grid.get(xFrom - 1, yFrom - 1)->getTypeId() == state::TypeId::SPACE) {
                                        Space* s = (Space*) grid.get(xFrom - 1, yFrom - 1);
                                        if (s->getNature() == SpaceTypeId::LIFE) {
                                            if (p1->getLifecount() < 3) {
                                                p1->setLifecount(p1->getLifecount() + 1);
                                                cout << "Super, le personnage a récupéré une vie" << endl;
                                                cout << "Il en a maintenant " << p1->getLifecount() << endl;
                                            } else {
                                                cout << "Le personnage a déjà 3 vies. Il ne peut pas en avoir plus." << endl;
                                            }
                                        }
                                        return;
                                    }
                                } //fin direction == LEFT

                            }
                        }
                    }
                }
                
            }
        }
    }
}
