
#include "LoadCommand.h"
#include "state/SpaceTypeId.h"
#include "state/Floor.h"
#include "state/Space.h"
#include "state/ElementTab.h"
#include "state/Personnage.h"

#include <iostream>
using namespace std;
using namespace state;

namespace engine{

    LoadCommand::LoadCommand(const char* f) {
        this->file_name = f;

    }

    const std::string& LoadCommand::getFile_name() const {
        return this->file_name;
    }

    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }

    void LoadCommand::setFile_name(const std::string& file_name) {
        this->file_name = file_name;
    }
    
    void LoadCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>& actions) {
        ElementTab& grid = state.getGrid();
        ElementTab& chars = state.getChars();
        grid.resize(25, 12);
        chars.resize(25, 12);
        std::vector<int> vcarte = state.getGrid().load("res/heuristic_ai.txt");
        std::vector<int> pcarte = state.getChars().load("res/heuristic_perso.txt");
        //cout << vcarte.size() << endl;
       // cout << pcarte.size() << endl;
        
        
        for (int i = 0; i<(int)vcarte.size(); i++){
            //cout << vcarte[i] << endl;
            if (vcarte[i] == 0){
                //cout << "vcarte[i] = 0" << endl;
                Element* empty = new Space(SpaceTypeId::EMPTY);
                empty->setI(i%25);
                empty->setJ(i/25);
                grid.set(i%25, i/25, empty);
            }
            else if (vcarte[i] == 1){
                //cout << "vcarte[i] = 1" << endl;
                Element* ground = new Floor(state::FloorTypeId::GROUND);
                ground->setI(i%25);
                ground->setJ(i/25);
                grid.set(i%25, i/25, ground);
            }
            else if (vcarte[i] == 2){
                //cout << "vcarte[i] = 2" << endl;
                Element* grass = new Floor(state::FloorTypeId::GRASS);
                grass->setI(i%25);
                grass->setJ(i/25);
                grid.set(i%25, i/25, grass);
            }
            else if (vcarte[i] == 3){
                //cout << "vcarte[i] = 3" << endl;
                Element* water = new Space(state::SpaceTypeId::WATER);
                water->setI(i%25);
                water->setJ(i/25);
                grid.set(i%25, i/25, water);
            }
            else if (vcarte[i] == 4){
                Element* life = new Space(state::SpaceTypeId::LIFE);
                life->setI(i%25);
                life->setJ(i/25);
                grid.set(i%25, i/25, life);
            }
            
            }
        
    
        for (int i = 0; i<(int)pcarte.size(); i++){
            //cout << vcarte[i] << endl;
            
            if (pcarte[i] == 1){ //vert gauche
                //cout << "vcarte[i] = 1" << endl;
                Element* vg = new Personnage(1, Direction::LEFT);
                vg->setI(i%25);
                vg->setJ(i/25);
                chars.set(i%25, i/25, vg);
            }
            else if (pcarte[i] == 2){ //vert droite
                //cout << "vcarte[i] = 2" << endl;
                Element* vd = new Personnage(1, Direction::RIGHT);
                vd->setI(i%25);
                vd->setJ(i/25);
                chars.set(i%25, i/25, vd);
            }
            else if (pcarte[i] == 3){ //noir gauche
                //cout << "vcarte[i] = 3" << endl;
                Element* ng = new Personnage(2, Direction::LEFT);
                ng->setI(i%25);
                ng->setJ(i/25);
                chars.set(i%25, i/25, ng);
            }
            else if (pcarte[i] == 4){ //noir droite
                Element* nd = new Personnage(2, Direction::RIGHT);
                nd->setI(i%25);
                nd->setJ(i/25);
                chars.set(i%25, i/25, nd);
            }
            //else{
              //  chars.set(i%25, i/25, NULL);
            //}
            }
            
            
            }
        }

        
    
    
    
 
