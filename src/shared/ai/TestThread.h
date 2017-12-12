/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestThread.h
 * Author: clara
 *
 * Created on December 11, 2017, 4:01 PM
 */

#ifndef TESTTHREAD_H
#define TESTTHREAD_H

namespace engine{
    class Engine;
}
namespace ai {
    class TestThread {
    public:
        void thread_secondaire(engine::Engine& moteur, int color);
        TestThread();

        virtual ~TestThread();
    private:

    };
};

#endif /* TESTTHREAD_H */

