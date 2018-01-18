/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tests.h
 * Author: sanaa
 *
 * Created on 11 décembre 2017, 17:09
 */
#include <json/json.h>
#ifndef TESTS_H
#define TESTS_H

namespace engine {
    class Engine;    
    class MoveCharCommand;
};

class Tests {
public:
    Tests();
    void test_render();
    void test_engine();
    void test_heuristic_ai();
    void test_random_ai();
    void test_state();
    void test_rollback();
    void thread_secondaire(engine::Engine& moteur, int color);
    void test_thread();
    void test_play();
    void thread_command(engine::Engine& moteur, int currentEpoch);
    void test_network();
    ~Tests();
private:

};

#endif /* TESTS_H */

