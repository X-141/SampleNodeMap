#include <iostream>
#include <map>

using namespace std;

//#define debug_Parser
#define debug_x_map

#ifdef debug_Parser
        
    #include "Parser.hpp"

    int main(int argc, char** argv) {
        std::cout << "Hello world!" << std::endl;
        cout << "Please Enter the name of your file: ";
        std::string file_path{};
        std::getline(std::cin, file_path);
        Parser parse_instance{file_path};
        std::cout << "File status: " << static_cast<int>(parse_instance.get_status()) << std::endl;
    }

#endif

#ifdef debug_x_map

    #include "x_map.hpp"
    
    template<typename T>
    void print(T&& t_arg)
    {
        std::cout << t_arg << std::endl;
    }

    int main(int argc, char** argv)
    {
        x_map sample_map{3};
        sample_map.insert("Sean");
        sample_map.insert("naeS");
        sample_map.insert("Alexis");
        sample_map.insert("sixelA");
        sample_map.insert("Alissia");
        sample_map.insert("aissilA");
        sample_map.insert("Luis");
        sample_map.insert("siuL");
        print(sample_map.get("Sean"));
        print(sample_map.get("naeS"));
        print(sample_map.get("Alexis"));
        print(sample_map.get("sixelA"));
        print(sample_map.get("Alissia"));
        print(sample_map.get("aissilA"));
        print(sample_map.get("Luis"));
        print(sample_map.get("siuL"));
    }

#endif