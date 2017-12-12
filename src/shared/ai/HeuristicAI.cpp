

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
        int distennemy;
        static std::stack<std::shared_ptr<Action>> actions;

        lifeMap.init(grid);
        lifeMap.setWeights(4 * grid.getWidth() + 7, 0);
        lifeMap.setWeights(3 * grid.getWidth() + 20, 0);
        std::vector<int> weightslifeAv = lifeMap.getWeights();
        ennemyMap.init(grid);
        std::vector<int> weightsEnnemyAv = ennemyMap.getWeights();
        
        Personnage* ennemy;

        // instanciation de lifeMap
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
                if (weightslifeAv[i * grid.getWidth() + j] == (std::numeric_limits<int>::max())) {
                    if (chars.list[i * width + j].get() != NULL) {
                        if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                            Personnage* perso = (Personnage*) chars.list[i * width + j].get();
                            if ((perso->getColor() == color)) {
                               // cout<<"c'est le joueur"<<endl;
                            }
                            else {
                                xennemy = perso->getI();
                                yennemy = perso->getJ(); 
                                ennemy=perso;
                                //cout<<"distance dans if "<<distennemy<<endl;
                            }
                            
                        }
                    }
                    distennemy = sqrt((xennemy - j)*(xennemy - j)+(yennemy - i)*(yennemy - i));
                    //cout<<"la distance avec l'ennemi est :"<<distennemy<<endl;
                    ennemyMap.setWeights(i * grid.getWidth() + j, distennemy);
                }

            }
        }
        
        std::vector<int> weightslife = lifeMap.getWeights();
        std::vector<int> weightsennemy = ennemyMap.getWeights();

        //heuristic life
        for (int i = 0; i < (int) height; i++) {
            for (int j = 0; j < (int) width; j++) {
                if (chars.list[i * width + j].get() != NULL) {
                    if (chars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* perso = (Personnage*) chars.list[i * width + j].get();
                        if (perso->getColor() == color) {
                            xperso = perso->getI();
                            yperso = perso->getJ();
//                            int lifeCount = perso->getLifecount();
                            if (perso->getLifecount() < 2) {
                                //cout << "test 5" << endl;
                                if (weightslife[yperso * grid.getWidth() + xperso + 1] < 0) {
                                    if (lifeMap.compare(weightslife[yperso * width + xperso - 1], weightslife[(yperso - 1) * grid.getWidth() + xperso + 1])) {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[yperso * width + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        
                                        return;
                                    } else {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[(yperso - 1) * grid.getWidth() + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                                else if (weightslife[yperso * grid.getWidth() + xperso - 1] < 0) {
                                    if (lifeMap.compare(weightslife[yperso * width + xperso + 1], weightslife[(yperso - 1) * grid.getWidth() + xperso - 1])) {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[yperso * width + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    } else {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[(yperso - 1) * grid.getWidth() + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                                else {
                                    if (lifeMap.compare(weightslife[yperso * grid.getWidth() + xperso + 1], weightslife[(yperso) * grid.getWidth() + xperso - 1])) {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[yperso * grid.getWidth() + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                    else {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        //cout << "test 7" << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[(yperso) * grid.getWidth() + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                            }
                            else {
                                //cout << "Le personnage a trois vies" << endl;
                                if (weightsennemy[yperso * grid.getWidth() + xperso + 1] < 0) {
                                    if (ennemyMap.compare(weightsennemy[yperso * width + xperso - 1], weightsennemy[(yperso - 1) * grid.getWidth() + xperso + 1])) {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightsennemy[yperso * width + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    } else {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightsennemy[(yperso - 1) * grid.getWidth() + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                                
                                else if (weightsennemy[yperso * grid.getWidth() + xperso - 1] < 0) {
                                    if (ennemyMap.compare(weightsennemy[yperso * width + xperso + 1], weightsennemy[(yperso - 1) * grid.getWidth() + xperso - 1])) {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightsennemy[yperso * width + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    } else {
                                        //cout << "poid gauche " <<  weightslife[yperso * width + xperso - 1] << "poid droite " << weightslife[(yperso - 1) * grid.getWidth() + xperso + 1] << endl;
                                        
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[yperso * width + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                                
                                else {
                                    if (ennemyMap.compare(weightsennemy[yperso * grid.getWidth() + xperso + 1], weightsennemy[(yperso) * grid.getWidth() + xperso - 1])) {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::RIGHT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[yperso * width + xperso + 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);
                                            engine.update();
                                        }  
                                        return;
                                    }
                                    else {
                                        //cout << "poid droite " <<  weightslife[yperso * width + xperso + 1] << "poid gauche " << weightslife[(yperso) * grid.getWidth() + xperso - 1] << endl;
                                        //cout << "test 7" << endl;
                                        Command* move = new MoveCharCommand(color, state::Direction::LEFT);
                                        engine.addCommand(0, move);
                                        engine.update();
                                        if(weightslife[(yperso) * grid.getWidth() + xperso - 1]<5){
                                            Command* shoot = new ShootCommand(color);
                                            engine.addCommand(0,shoot);  
                                            engine.update();
                                        }
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }        
        
    }
}
