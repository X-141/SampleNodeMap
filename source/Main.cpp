#include <iostream>
#include <map>

#include "Parser.hpp"

using namespace std;

int main(int argc, char** argv) {

    cout << "Please Enter the name of your file: ";
    std::string file_path{};
    std::getline(std::cin, file_path);
    Parser parse_instance{file_path};
    std::cout << "File status: " << static_cast<int>(parse_instance.get_status()) << std::endl;
}