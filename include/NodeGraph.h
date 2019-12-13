//#include "Node.h"
//#include <fstream>
//
//#define getLine(x, y) std::getline(x , y)
//#define log(x) std::cout << x << std::endl;
//#define CREATE_NODE "create_node"
//#define LINK_NODE "link_node"
//
//class NodeGraph {
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
//};