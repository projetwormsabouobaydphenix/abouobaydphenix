/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestServer.cpp
 * Author: sanaa
 * 
 * Created on 12 décembre 2017, 10:36
 */

#include "TestServer.h"
#include "state/ElementTab.h"
#include "../shared/state.h"
#include <vector>
#include "../shared/ai.h"
#include "../shared/engine.h"
#include "render.h"
#include <iostream>


using namespace std;
using namespace state;
using namespace render;
using namespace ai;
using namespace engine;

TestServer::TestServer() {
}

void TestServer::test_record() {
        MoveCharCommand test(1, Direction::LEFT);
        Json::Value out;
        MoveCharCommand* t;
        test.serialize(out);
        t = test.deserialize(out);
        cout << out.toStyledString() << endl;
        cout << "direction : " << t->getDirection() << " color : " << t->getColor() << endl;
}

TestServer::~TestServer() {
}

