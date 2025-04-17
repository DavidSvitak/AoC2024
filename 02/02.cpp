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

void pop(std::vector<int> &vector, int index) {
    if(index < 0 || index > vector.size()) { throw std::runtime_error{"Chceme odstranit element ktery neexistuje"}; }
    vector.erase(vector.begin() + index);
}

std::vector<int> pop_sm(std::vector<int> &vector, int index) {
    std::vector<int> vv{vector};
    if(index < 0 || index > vv.size()) { throw std::runtime_error{"Chceme odstranit element ktery neexistuje"}; }
    vv.erase(vv.begin() + index);
    return vv;
}

bool is_safe_advanced(std::vector<int> &vector) {
    bool positive;
    if ((vector[0] - vector[1]) < 0) { positive = false; } 
    else { positive = true; }
    if ((vector[0] - vector[1]) == 0) {
        pop(vector, 0);
        return is_safe(vector);
    } else if (vector[0] - vector[1] > 3) {
        std::vector<int> tmp0;
        std::vector<int> tmp1;
        tmp0 = pop_sm(vector, 0);
        tmp1 = pop_sm(vector, 1);
        return is_safe(tmp0) || is_safe(tmp1);
    }
    for(int i = 0; i<(vector.size()-1); i++) {
        if( (vector[i] - vector[i+1] < 0) && positive ) { 
            pop(vector, i+1);
            return is_safe(vector); 
        }
        if( (vector[i] - vector[i+1] > 0) && !positive ) { 
            pop(vector, i+1);
            return is_safe(vector); 
        }
        if( abs(vector[i] - vector[i+1]) < 1) {
            pop(vector, i+1);
            return is_safe(vector);
        }
        if( abs(vector[i] - vector[i+1]) > 3) {
        std::vector<int> tmp0;
        std::vector<int> tmp1;
        tmp0 = pop_sm(vector, 0);
        tmp1 = pop_sm(vector, 1);
        return is_safe(tmp0) || is_safe(tmp1);
        }
    }
    return true;
}


int main() {
    Loader l{"02/02.txt"};
    std::vector<std::string> content{ l.ret() };
    int result{0};
    for(int i = 0; i < content.size(); i++) {
        std::vector<int> line = get_vector(content[i]);
        bool res{ is_safe_advanced(line) };
        if(res) {
            result++; 
        }
    }
    printf("Result: %d.\n", result);
}