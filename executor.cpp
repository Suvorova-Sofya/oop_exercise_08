#include <iostream>

#include "executor.h"

void exec::worker(exec *one){
    while(!one->working) {
        std::unique_lock<std::mutex> lock(one->mut);
        one->con.wait(lock);
        if(one->doing) {
            std::cout << "\n";
            for (size_t i = 0; i < one->processors.size(); ++i) {
                one->processors[i]->process(one->data);
            }
        }
    }
}

void exec::exec_set(std::vector<std::unique_ptr<figure>> data1){
    data=std::move(data1);
}