#include "Node.h"

Node::Node() {
	m_nextLinkSet.reserve(4);
	m_prevLinkSet.reserve(4);
}

Node::Node(int value) : value(value) {
	m_nextLinkSet.reserve(4);
	m_prevLinkSet.reserve(4);
}

int Node::getValue() { return this->value; }


void Node::addNextPointer(Node *node) {
	m_nextLinkSet.push_back(node);
}

void Node::addPrevPointer(Node *node) {
	m_prevLinkSet.push_back(node);
}

std::vector<Node*>& Node::getNextPointerSet() {
	return m_nextLinkSet;
}

std::vector<Node*>& Node::getPrevPointerSet() {
	return m_prevLinkSet;
}

