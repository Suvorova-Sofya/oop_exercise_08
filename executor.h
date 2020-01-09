#ifndef D_EXECUTOR_H_
#define D_EXECUTOR_H_

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "figure.h"
#include "processor.h"

struct exec{

    exec(){
        screen_writer pp1;
        file_writer pp2;
        std::unique_ptr<screen_writer> p1=std::make_unique<screen_writer>(pp1);
        std::unique_ptr<file_writer> p2=std::make_unique<file_writer>(pp2);
        processors.push_back(std::move(p1));
        processors.push_back(std::move(p2));
    }

    void exec_set(std::vector<std::unique_ptr<figure>> data);

    static void worker(exec* one);

    std::thread work{worker,this};

    bool working=false;
    bool doing=false;
    std::mutex mut;
    std::condition_variable con;
private:
    std::vector<std::unique_ptr<figure>> data;
    std::vector<std::unique_ptr<processor>> processors;
};

#endif