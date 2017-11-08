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
#include "state/TestState.h"
#include "render/TestRender.h"
#include "engine/TestEngine.h"


using namespace std;


int main(int argc,char* argv[]) 
{
    /*const char *str1 = "hello";
    const char *str2 = "state";
    const char *str3 = "render";*/
    string mode(argv[1]); 
    if (argc==2){
        if (mode == "hello"){
            cout << "Hello World !" << endl;
        }
        
        else if (mode == "state"){
            using namespace state;
            TestState();
        }
        
        else if (mode == "render"){
            cout << "Test render" << endl;
            render::TestRender();
            
        }
        
        else if (mode == "engine"){
            cout << "Test engine" << endl;
            engine::TestEngine();
        }
    }
    
    
    
    
    

    return 0;
}
