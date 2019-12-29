#ifndef D_PROCESSOR_H_
#define D_PROCESSOR_H_

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>


struct processor {
    virtual void process(const std::vector<std::unique_ptr<figure>> &data) const = 0;

};

struct screen_writer : processor {
    void process(const std::vector<std::unique_ptr<figure>> &data) const {
        for (size_t i=0;i<data.size();++i) {
            data[i]->print(std::cout);
        }
    }
};

struct file_writer : processor {
    void process(const std::vector<std::unique_ptr<figure>> &data) const {
        std::ofstream os(std::to_string(file_id)+".txt");
        file_id += 1;
        for (size_t i=0;i<data.size();++i) {
            data[i]->help_print(os);
        }
    }
    mutable int file_id = 0;
};

#endif