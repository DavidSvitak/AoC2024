#include "Loader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <stdexcept>

Loader::Loader(std::string file_name) : file_name{ file_name } {
    std::ifstream input(file_name);
    if (input.is_open()) {
        std::string line;
        while(std::getline(input, line)) {
            content.push_back(line);
        }
        input.close();
    } else {
        throw std::runtime_error{"No such file directory"};
    }
}

std::vector<std::string> Loader::ret() {
    return content;
}