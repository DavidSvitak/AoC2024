#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>
#include <algorithm>

std::regex pattern(R"(\d+)");
std::vector<int> row_1;
std::vector<int> row_2;

int diff(int a, int b) {
    return abs(a - b);
}

int main() {
    // Load the input file
    std::ifstream input("01.txt");
    // Allocate the data from the input file to the vectors row_1 and row_2
    int k = 0;
    if (input.is_open()) {
        std::string line;
        while(std::getline(input, line)) {
            auto int_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
            auto int_end = std::sregex_iterator();
            if (std::distance(int_begin, int_end) == 2) {
                int numbers[2] = {0,0};
                int index = 0;
                for (auto it = int_begin; it != int_end; ++it) {
                    numbers[index++] = std::stoi(it->str());
                }
                //std::cout << numbers[0] << "   " << numbers[1] << std::endl;
                row_1.push_back(numbers[0]);
                row_2.push_back(numbers[1]);
            } else {
                throw std::runtime_error{"Regex nasel vice intu"};
            }
        }
        input.close();
    }
    // Sort both of the vecotrs
    std::sort(row_1.begin(), row_1.end(), std::greater<>());

    int result = 0;
    for (int i = 0; i < row_1.size(); ++i) {
        result += diff(row_1[i], row_2[i]);
    }
    printf("result: %d", result);
}