#include <fstream>
#include <string_view>
#include <regex>
#include "Node.hpp"

template <typename T>
class NodeGraph {
public:
    NodeGraph()
        : m_head(nullptr), m_tail(nullptr)
    {}

    explicit NodeGraph(const std::string& t_file_path)
        : m_head(nullptr), m_tail(nullptr)
    {

    }

private:
    Node<T>* m_head;
    Node<T>* m_tail;
//public:
//	NodeGraph(Node *node);
//    NodeGraph(const std::string &filename);
//	~NodeGraph();
//public:
//	void addNode(Node *node);
//    void linkNode(Node *node_0, Node *node_1);
//	void printNodeGraph();
//
//	//Temporary traveling implementation //delete after done
//	Node * getHeadNode() { return m_headNode; }
//	Node * getTailNode() { return m_tailNode; }
//	Node * getCurrentNode() { return m_currentNode; }
//	bool& getGameStatus() { return m_GameEnd; }
//	void chooseNextMove();
//	void printPossibleMovements(Node *node);
//
//private:
//	Node *m_headNode;
//	Node *m_tailNode;
//	std::vector<Node *> m_VertexSet;
//
//	//Temporary traveling implementation //delete after done
//	Node *m_currentNode;
//	bool m_GameEnd;
};

