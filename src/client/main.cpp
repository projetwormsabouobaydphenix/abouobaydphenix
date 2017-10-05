#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include <stdio.h>
#include <string.h>
#include "state/TestState.h"


using namespace std;


int main(int argc,char* argv[]) 
{
    const char *str1 = "hello";
    const char *str2="state";
    if (argc==2){
        if (strcmp(argv[1], str1)==0){
            cout << "Hello World !" << endl;
        }
        
        else if (strcmp(argv[1], str2)==0){
            using namespace state;
            TestState();
        }
    }
    
    
    
    
    

    return 0;
}
