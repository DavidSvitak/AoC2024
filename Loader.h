#include <vector>
#include <string>

struct Loader {
    Loader(std::string file_name);
    std::vector<std::string> ret();
    private:
        std::string file_name;
        std::vector<std::string> content;
};