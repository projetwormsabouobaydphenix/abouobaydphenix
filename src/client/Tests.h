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

#ifndef TESTS_H
#define TESTS_H

class Tests {
public:
    Tests();
    void test_render();
    void test_engine();
    void test_heuristic_ai();
    void test_random_ai();
    void test_state();
    void test_rollback();
    void test_record();
    virtual ~Tests();
private:

};

#endif /* TESTS_H */
