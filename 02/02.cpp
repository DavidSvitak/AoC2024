#include "../Loader.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <regex>

std::vector<int> get_vector(std::string &line) {
    std::regex pattern(R"(\d+)");
    std::sregex_iterator begin(line.begin(), line.end(), pattern);
    std::sregex_iterator end = std::sregex_iterator();

    std::vector<int> result;

    for (std::sregex_iterator i = begin; i != end; ++i) {
        result.push_back(std::stoi(i->str()));   
    }
    return result;
}

bool is_safe(std::vector<int> &vector) {
    std::vector<int> diff;
    for(int i = 0; i < (vector.size() - 1); i++) { diff.push_back(vector[i] - vector[i+1]); }
    bool positive;
    if (diff[0] > 0) { positive = true; } else { positive = false; }
    for(int num : diff) {
        if( (num < 0) && positive ) { return false; }
        if( (num > 0) && !positive ) { return false; }
        if( abs(num) < 1 || abs(num) > 3) { return false; }
    }
    return true;
}

int main() {
    Loader l{"02/02.txt"};
    std::vector<std::string> content{ l.ret() };
    int result{0};
    for(int i = 0; i < content.size(); i++) {
        std::vector<int> line = get_vector(content[i]);
        bool res{ is_safe(line) };
        if(res) {
            result++; 
        }
    }
    printf("Result: %d.\n", result);
}