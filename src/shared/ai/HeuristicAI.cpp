

#include "HeuristicAI.h"
#include "engine/Engine.h"
#include "state/Personnage.h"
#include "engine/MoveCharCommand.h"
#include "engine/ShootCommand.h"
#include "state/Space.h"
#include "engine/HandleLifesCommand.h"
#include "engine/Command.h"
#include "state/Floor.h"
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;
using namespace state;
using namespace engine;

namespace ai {

    HeuristicAI::HeuristicAI(const state::State& state, int color) {

    }

    const PathMap& HeuristicAI::getEnnemyMap() const {
        return HeuristicAI::ennemyMap;
    }

    const PathMap& HeuristicAI::getLifeMap() const {
        return HeuristicAI::lifeMap;
    }

    bool HeuristicAI::dijkstra() {
        return true;
    }

    void HeuristicAI::run(engine::Engine& engine, int color) {
        //cout << "debut heuristic" << endl;
        State& state = engine.getState();
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();

        size_t width = grid.getWidth();
        size_t height = grid.getHeight();
        int xperso;
        int yperso;
        int xennemy;
        int yennemy;
        int lifeCount;
        Personnage* player;

        //Point* ennemy = new Point();

        lifeMap.init(grid);
        lifeMap.setWeights(4 * grid.getWidth() + 7, 0);
        lifeMap.setWeights(3 * grid.getWidth() + 20, 0);
        std::vector<int> weightslifeAv = lifeMap.getWeights();
        ennemyMap.init(grid);

        for (int i = 0; i < (int) height; i++) {
            for (int j = 0; j < (int) width; j++) {
                if (weightslifeAv[i * grid.getWidth() + j] == (std::numeric_limits<int>::max())) {
                    //cout << "test 2" << endl;
                    int dist1 = sqrt((20 - j)*(20 - j)+(3 - i)*(3 - i));
                    int dist2 = sqrt((7 - j)*(7 - j)+(4 - i)*(4 - i));
                    //cout << "calcul" << endl;
                    lifeMap.setWeights(i * grid.getWidth() + j, min(dist1, dist2));
                    //cout << "dist1 = " << dist1 << "dist2 = " << dist2 << "min = " << min(dist1, dist2) << endl;
                }
            }
        }
        
        std::vector<int> weightslife = lifeMap.getWeights();

        for (int i = 0; i < (int) height; i++) {
            for (int j = 0; j < (int) width; j++) {
                if (chars.list[i * width + j].get() != NULL) {
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* perso = (Personnage*) chars.list[i * width + j].get();
                        if (perso->getColor() == color) {
                            xperso = perso->getI();
                            yperso = perso->getJ();
                            lifeCount = perso->getLifecount();
                            if (perso->getLifecount() < 3) {
                                //cout << "test 5" << endl;
                                if (weightslife[yperso * grid.getWidth() + xperso + 1] < 0) {
                                    if (lifeMap.compare(weightslife[yperso * width + xperso - 1], weightslife[(yperso - 1) * grid.getWidth() + xperso + 1])) {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        return;
                                    } else {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        return;
                                    }
                                }
                                else {
                                    if (lifeMap.compare(weightslife[yperso * grid.getWidth() + xperso + 1], weightslife[(yperso) * grid.getWidth() + xperso - 1])) {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        return;
                                    }
                                    else {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        //cout << "test 7" << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        return;
                                    }
                                }
                            }
                            else {
                                cout << "Le personnage a trois vies" << endl;
                            }
                            //cout << "x = " << xperso << "y =" << yperso << endl;
                        } else if (perso->getColor() != color) {
                            xennemy = perso->getI();
                            yennemy = perso->getJ();
                        }
                    }
                }
            }

            /*cout << "x 2 = " << xperso << "y =" << yperso << endl;
            if (chars.list[yperso * width + xperso].get() != NULL) {
                player = (Personnage*) chars.list[yperso * width + xperso].get();
                player->setLifecount(lifeCount);
            } else {
                cout << "il y a une erreur" << endl;
            }*/



        }


    }



}
