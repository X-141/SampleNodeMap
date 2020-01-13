#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template<typename T>
class Node {
public:
    using node = Node<T>;
	Node()
        : m_value(T()), m_abs_max(0), m_next_index(4), m_prev_index(0), m_debug(false)
	{
        m_prev_arr = new node*[4];
        m_next_arr = new node*[4];
	}

	explicit Node(T t_val, std::size_t max_links, bool t_debug = false)
        : m_value(t_val), m_abs_max(max_links), m_next_index(0), m_prev_index(0), m_debug(t_debug)
	{
        m_prev_arr = new node*[max_links];
        m_next_arr = new node*[max_links];
    }

	~Node() {
	    if (m_debug)
	        std::cout << "Destroying node" << std::endl;
	    delete [] m_prev_arr;
	    delete [] m_next_arr;
	};

public:
	bool addNextPointer(node* t_val)
	{
        if (m_debug)
        {
            std::cout << "Storing new node of value " << t_val->m_value << std::endl;
            if (m_next_index < m_abs_max) {
                m_next_arr[m_next_index] = t_val;
                ++m_next_index;
                return true;
            }
            else std::cout << "m_next_arr is full!" << std::endl;
            return false;
        }
        if(m_next_index < m_abs_max) {
            m_next_arr[m_next_index++] = t_val;
            return true;
        }
        return false;
	}

	bool addPrevPointer(node* t_val)
	{
        if (m_debug)
        {
            std::cout << "Storing new node of value " << t_val->m_value << std::endl;
            if (m_prev_index < m_abs_max) {
                m_prev_arr[m_prev_index] = t_val;
                ++m_prev_index;
                return true;
            }
            else std::cout << "m_next_arr is full!" << std::endl;
            return false;
        }
        if (m_prev_index < m_abs_max) {
            m_prev_arr[m_prev_index++] = t_val;
            return true;
        }
        return false;
	}

    std::size_t getNextSize() const { return m_next_index; }

	std::size_t getPrevSize() const { return m_prev_index; }

	Node* getNext(std::size_t t_index) {
	    if (m_next_index <= t_index || m_next_index == 0)
	        return nullptr;
	    return m_next_arr[t_index];
	}

	Node* getPrev(std::size_t t_index) {
	    if (m_prev_index <= t_index || m_prev_index == 0)
	        return nullptr;
	    return m_prev_arr[t_index];
	}

	int getValue() const { return m_value; }

private:
    Node<T>** m_next_arr;
	Node<T>** m_prev_arr;
	std::size_t m_abs_max;
	std::size_t m_next_index;
	std::size_t m_prev_index;
	T m_value;

    bool m_debug;
};