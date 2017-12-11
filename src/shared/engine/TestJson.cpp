
#include "TestJson.h"
#include <json/json.h>
#include <json/json-forwards.h>

using namespace std;

namespace engine{

    TestJson::TestJson(std::string nom, int age) : nom(nom), age(age) {

    }

    void TestJson::serialize(Json::Value& out) const {
        out["nom"] = nom;
        out["age"] = age;
        
    }

    TestJson* TestJson::deserialize(const Json::Value& in) {
        /*unique_ptr<TestJson> u (new TestJson (*testJson));
        if  (in.isMember("nom")){
            
        }*/
    }
    
    
    
}