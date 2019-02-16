#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Node {
private:
	std::vector<Node*> m_prevLinkSet;
	std::vector<Node*> m_nextLinkSet;
	int value;

public:
	Node();
	Node(int value);
	~Node() { std::cout << "Destroying node" << std::endl; };
public:
	void addNextPointer(Node *node);
	void addPrevPointer(Node *node);
	Node* getNextPointer();
	Node* getPrevPointer();
	std::vector<Node *>& getNextPointerSet();
	std::vector<Node *>& getPrevPointerSet();
	int getValue();
};