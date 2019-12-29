#ifndef D_EXECUTOR_H_
#define D_EXECUTOR_H_

#include <iostream>
#include <vector>
#include <memory>
#include "figure.h"

struct exec{

    static void worker(exec* one);

    void exec_set(std::vector<std::unique_ptr<figure>> one){
        data=std::move(one);
        std::thread work{worker,this};
        while(!flag){
            std::cout << ".";
        }
        flag= false;
        work.join();
    }

private:
    mutable bool flag=false;
    std::vector<std::unique_ptr<figure>> data;
    screen_writer screen;
    file_writer file;
};

void exec::worker(exec *one) {
    one->flag=true;
    std::cout <<"\n";
    one->screen.process(one->data);
    one->file.process(one->data);
}

#endif