/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ShootCommand.h"
#include "state.h"
#include "KillCharAction.h"
#include "ShootAction.h"
#include <iostream>
#include <cmath>
#include <stack>
#include <fstream>
#include <string>

using namespace std;
using namespace state;

namespace engine{

    ShootCommand::ShootCommand(int color) : color(color) {}
    
   
    CommandTypeId ShootCommand::getTypeId() const{
        //cout << "ShootCommand";
        return CommandTypeId::SHOOT;
    }
    

    void ShootCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>& actions){
        //cout << "debut shoot" << endl;

        ElementTab& tabchars = state.getChars();
        
        size_t width = tabchars.getWidth();
        size_t height = tabchars.getHeight();
        int xperso, yperso, xennemy, yennemy;
        
        
        for (int i = 0; i < (int)height; i++) {
            //cout << "test" << endl;
            for (int j = 0; j < (int)width; j++) {
                //cout << "test2" << endl;
                if (tabchars.list[i * width + j].get() != NULL){
                    //cout << "Test 1" << endl;
                    if (tabchars.list[i * width + j].get()->getTypeId() == TypeId::PERSONNAGE) {
                        Personnage* persoAction = (Personnage*) tabchars.list[i * width + j].get();
                        if (persoAction->getColor() == color) {
                            xperso = persoAction->getI();
                            yperso = persoAction->getJ();
                            //cout << "xperso = " << xperso << ", yperso = " << yperso << endl;
                        }
                        else{
                            xennemy = persoAction->getI();
                            yennemy = persoAction->getJ();
                            //cout << "xe = " << xennemy << ", ye = " << yennemy << endl;

                        }
                    }
                }
            }
        }
        
        int distance = sqrt((xperso-xennemy)*(xperso-xennemy)+(yperso-yennemy)*(yperso-yennemy));
        //cout << "distance = " << distance << endl;

        
        if (this->color == 1){
            cout << "Le personnage vert va tirer" << endl;
        }
        else if (this->color == 2){
            cout << "Le personnage noir va tirer" << endl;
        }
        if (distance < 20){
            cout << "L'ennemi a été touché." << endl;
            Personnage* ennemy = (Personnage*) tabchars.get(xennemy, yennemy);
            int life = ennemy->getLifecount();
            
            if (life > 1){
                engine::Action* shoot = new ShootAction(color,ennemy, life);
                actions.push(shared_ptr<Action>(shoot));
                shoot->apply(state);
                return;
            }
            else if (life == 1){
                engine::Action* shoot = new ShootAction(color,ennemy, life);
                actions.push(shared_ptr<Action>(shoot));
                shoot->apply(state);
                engine::Action* die = new KillCharAction(color, xennemy, yennemy,ennemy);
                actions.push(shared_ptr<Action>(die));
                die->apply(state);
                cout << "Il n'avait qu'une vie restante. Il est mort" << endl;
                return;
            }
            
        }
        else{
            cout << "L'ennemi est trop loin, il n'a pas été touché" << endl;
        }
    }
    



   /* ShootCommand* ShootCommand::deserialize(const Json::Value& in) {
        ShootCommand* shoot = new ShootCommand(2); //constructeur choisi au hasard
        if (in.isMember("color")){
            shoot->color = in["color"].asInt();
        }
         else {
            cout << "Erreur Deserialize ShootCommand" << endl;
        }
        return shoot;
    }*/


    void ShootCommand::deserialize(const Json::Value& in) {
        if (in.isMember("commande")){
            if (in["commande"].asString() == "ShootCommand"){ 
                //ShootCommand* shoot = new ShootCommand(2); //constructeur choisi au hasard
                if (in.isMember("color")){
                    this->color = in["color"].asInt();
                }
            
            }
            
    }
        
}
 
   void ShootCommand::serialize(Json::Value& out) const {
        out["commande"] = "ShootCommand";
        out["color"] = color;
   }

}
    

   