#include "../Loader.hpp"
#include <vector>
#include <string>

int main() {
    Loader l{"02/02_test.txt"};
    std::vector<std::string> content{ l.ret() };
    for(int i = 0; i < content.size(); i++) {
        std::cout << content[i] << std::endl;
    }

}