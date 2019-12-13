#include "Node.hpp"

template<typename T>
void print(T t_arg)
{
    std::cout << t_arg << std::endl;
}

int main() {
    Node<int> m_sample{45, 4, true};
    print(m_sample.addNextPointer(new Node<int>(45, 4)));
    print(m_sample.addNextPointer(new Node<int>(55, 4)));
    print(m_sample.addNextPointer(new Node<int>(55, 4)));
    print(m_sample.addNextPointer(new Node<int>(55, 4)));
    print(m_sample.addNextPointer(new Node<int>(55, 4)));
    print(m_sample.addPrevPointer(new Node<int>(65, 4)));
    print(m_sample.addPrevPointer(new Node<int>(75, 4)));
    print(m_sample.addPrevPointer(new Node<int>(75, 4)));
    print(m_sample.addPrevPointer(new Node<int>(75, 4)));
    print(m_sample.addPrevPointer(new Node<int>(75, 4)));

    for(std::size_t index = 0 ; index < m_sample.getNextSize(); ++index)
        print(m_sample.getNext(index)->getValue());

    for(std::size_t index = 0 ; index < m_sample.getPrevSize(); ++index)
        print(m_sample.getPrev(index)->getValue());

    print(m_sample.getNextSize());
    print(m_sample.getPrevSize());
}


