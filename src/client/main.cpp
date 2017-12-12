#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "../shared/state.h"
#include "render.h"
#include "state.h"
#include "engine.h"
#include <stdio.h>
#include <string.h>
#include "Tests.h"

using namespace std;


int main(int argc,char* argv[]) 
{
    /*const char *str1 = "hello";
    const char *str2 = "state";
    const char *str3 = "render";*/
    string mode(argv[1]); 
    Tests test;
    if (argc==2){
        if (mode == "hello"){
            cout << "Hello World !" << endl;
        }
        
        else if (mode == "state"){
            test.test_state();
            
        }
        
        else if (mode == "render"){
            cout << "Test render" << endl;
            test.test_render();
            
        }
        
        else if (mode == "engine"){
            cout << "Test engine" << endl;
            test.test_engine();
        }
        
        else if (mode == "random_ai"){
            cout << "Test AI" << endl;
            test.test_random_ai();
        }
        
        else if (mode == "heuristic_ai"){
            cout << "Test Heuristic  AI" << endl;
            test.test_heuristic_ai();
        }
        
        else if (mode == "rollback"){
            cout << "Test RollBack" << endl;
            test.test_rollback();
        }
        /*else if (mode == "record"){
            cout << "Test Record" << endl;
            test.test_record();
        }*/
        
        else if (mode == "thread"){
            cout << "Test Thread" << endl;
            test.test_thread();
        }
        
        else{
            cout << "Mode invalide" << endl;
        }
    }
    
    
    
    
    

    return 0;
}
