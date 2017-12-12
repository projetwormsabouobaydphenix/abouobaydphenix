#include <iostream>
#include "TestServer.h"

using namespace std;

int main(int argc,char* argv[]) 
{
    
    string mode(argv[1]); 
    TestServer test;
    if (argc==2){
        if (mode == "record"){
            cout << "Test Record!" << endl;
            test.test_record();
        }
        
        else{
            cout << "Mode incorrect" << endl;;
        }
    }
}

