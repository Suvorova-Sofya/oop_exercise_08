#include <iostream>
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include "processor.h"
#include <vector>
#include <string>
#include <thread>
#include <fstream>
#include <memory>
#include "executor.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR" << "\n";
        return 1;
    }
    size_t buffer_size = (size_t)std::stoi(argv[1]);
    std::vector<std::unique_ptr<figure>> buffer;
    buffer.reserve(buffer_size);
    exec make;
    std::unique_ptr<figure> value;
    std::string figures;
    while (std::cin >> figures) {
        if(figures == "five_angles"){
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<five_angles>(five_angles(std::cin));
            buffer.push_back(std::move(new_figure));
        }else if(figures == "six_angles"){
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<six_angles>( six_angles(std::cin));
            buffer.push_back(std::move(new_figure));
        }else if(figures == "eight_angles"){
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<eight_angles>( eight_angles(std::cin));
            buffer.push_back(std::move(new_figure));
        }
        if (buffer.size() != buffer_size) {
            continue;
        }else {
            make.exec_set(std::move(buffer));
            buffer.clear();
        }
    }
    return 0;
}