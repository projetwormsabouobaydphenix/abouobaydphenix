/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LoadCSV.h"
#include <fstream>
#include <sstream>

std::vector<int> loadCSV(std::string nom_fichier) {
        std::vector<int> layer;
    	std::ifstream fichier;
        fichier.open(nom_fichier,std::ios::in);
        std:: string valeur, ligne;
       
        //int i = 0;
		
        while(!fichier.eof()){
            std::getline(fichier,ligne);
            std::stringstream stream(ligne);
            std::cout << ligne << std::endl;

		
            while(getline(stream, valeur,',')){
			
                layer.push_back(atoi(valeur.c_str()));
			
            }
        }
        std::cout << "OK" << std::endl;
        
        return layer;
}