#pragma once
#include <vector>
#include <numeric>
#include <cmath>
#include <assert.h>

// Source : https://en.wikipedia.org/wiki/Cuban_prime
static int calc_cuban_prime(int t_factor) {
    return 3*pow(t_factor, 2) + 3*t_factor + 1;
}

class x_map {
public:
    x_map(int t_factor=2)
    {
        assert(t_factor > 0);
        m_var_list = std::vector<std::string>(calc_cuban_prime(t_factor), "");
    }

    ~x_map() = default;

    // To do: abstract for loops in insert and get to "std::string* search(&t_element)
    bool insert(const std::string& t_element)
    {
        if(m_num_elements < m_var_list.size()) {
            int key_1 = gen_key(t_element);
            for(int x = 0,  double_key = double_hash(key_1, x);; 
                ++x,  double_key = double_hash(key_1, x))
            {
                if (m_var_list[double_key] == "") {
                    m_var_list[double_key] = t_element;
                    ++m_num_elements;
                    return true;
                }
            }
        }
        return false;
    }
    // To do: abstract for loops in insert and get to "std::string* search(&t_element)
    const std::string& get(const std::string& t_element)
    {
        int key_1 = gen_key(t_element);
        for(int x = 0,  double_key = double_hash(key_1, x);; 
            ++x,  double_key = double_hash(key_1, x))
            {
                if (m_var_list[double_key] == t_element) {
                    return t_element;
                }
            }
    }


protected:
    int double_hash(int& t_key_1, int t_step) {
        return (t_key_1 + t_step * (5 - (t_key_1 % 5))) % m_var_list.size();
    }
    
    int gen_key(const std::string& t_element) {
        return std::accumulate(t_element.begin(), t_element.end(), 0) % m_var_list.size();
    }
    
private:
    std::vector<std::string>     m_var_list;
    int                          m_num_elements{0};
};