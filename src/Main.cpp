#include "NodeGraph.h"

int main() {
    NodeGraph *nodeGraph = new NodeGraph("../map/NodeMap2.txt");
	while(!nodeGraph->getGameStatus()){
		nodeGraph->chooseNextMove();
	}
	delete nodeGraph;
	std::cin.get();
	return 0;
}


