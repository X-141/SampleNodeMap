//#include "NodeGraph.h"
//NodeGraph::NodeGraph(Node *node) : m_headNode(node) , m_tailNode(node) {
//    m_VertexSet.push_back(node);
//
//    //Delete after temporary implementation
//    m_currentNode = node;
//    m_GameEnd = false;
//}
//
//NodeGraph::NodeGraph(const std::string &filename) {
//    m_tailNode, m_currentNode, m_headNode = nullptr;
//    std::ifstream nodefile;
//    std::string line;
//    nodefile.open(filename);
//    if(nodefile.is_open()) {
//        getLine(nodefile, line);
//        int size = std::stoi(line);
//        m_VertexSet.resize(size);
//        while(getLine(nodefile, line)){
//            try {
//                auto pos_1 = line.find_first_of(':');
//                auto pos_2 = line.find_last_of(':');
//                int value_1 = std::stoi(line.substr(0, pos_1));
//                int value_2 = std::stoi(line.substr(pos_2+1, line.size()));
//                std::string command = line.substr(pos_1+1, (pos_2 - (1 + pos_1)));
//                if(command == CREATE_NODE){
//                    if(m_VertexSet.at(value_1) == NULL){
//                        m_VertexSet[value_1] = new Node(value_2);
//                    }
//                    else{
//                        log("Node already exists at this index. No Node created");
//                    }
//                } else if(command == LINK_NODE) {
//                    if ((m_VertexSet.at(value_1) == NULL) || (m_VertexSet.at(value_2) == NULL)) {
//                            log("No node exists at this index!");
//                            //catches segmentation error
//                    } else {
//                        linkNode(m_VertexSet.at(value_1) , m_VertexSet.at(value_2));
//                    }
//                } else {
//                    log(line + " - No action performed");
//                }
//            } catch (std::out_of_range ex) {
//                log(line + " - Invalid index! Out of Bounds");
//            }
//        }
//    }else {
//        log("Unable to open file");
//    }
//    /*
//    NOTE: if for any reason a node is created and it is not placed within the array
//    It will lead to that index to equal a NULL value. This wont be an issue if this is
//    Intentional as the printArray() method will still function. HOWEVER, it will lead
//    to a segmentation fault if the program tries to link that NULL index with any other
//    index in the program. A special case has been placed to prevent this. But BE WARNED!
//    */
//   Node *temp_tail;
//   for(Node *node : m_VertexSet) {
//       if(node != NULL) {
//           temp_tail = node;
//           if(m_headNode == nullptr) {
//                m_headNode = node;
//                m_currentNode = m_headNode;
//           }
//       }
//   }
//   m_tailNode = temp_tail;
//   nodefile.close();
//
//   //Delete this after finishing temporary implementation
//   m_GameEnd = false;
//}
//
//NodeGraph::~NodeGraph() {
//    for(Node *node : m_VertexSet)
//        delete node;
//	std::cout << "Finalized destructor" << std::endl;
//}
//
//void NodeGraph::addNode(Node *node) {
//	if (m_headNode->getNextPointerSet().empty()) {
//        m_headNode->addNextPointer(node);
//        node->addPrevPointer(m_headNode);
//        m_tailNode = node;
//        m_VertexSet.push_back(node);
//	}
//	else {
//        m_tailNode->addNextPointer(node);
//        node->addPrevPointer(m_tailNode);
//        m_tailNode = node;
//        m_tailNode = node;
//        m_VertexSet.push_back(node);
//	}
//}
//
//void NodeGraph::linkNode(Node *node_0, Node *node_1) {
//    //node_0 is the parent node
//    //node_1 is the child node
//    node_0->addNextPointer(node_1);
//    node_1->addPrevPointer(node_0);
//}
//
//void NodeGraph::printNodeGraph() {
//    for(Node *node : m_VertexSet) {
//        if(node != NULL) {
//            int primary_node_value = node->getValue();
//            log("Prev pointer set");
//            if(node->getPrevPointerSet().empty()) {
//                    std::cout << "NULL <- " << primary_node_value<< std::endl;
//            } else {
//                for(Node *pre_pointer : node->getPrevPointerSet()) {
//                    std::cout << pre_pointer->getValue() << " <- " << primary_node_value<< std::endl;
//                }
//            }
//            log("next pointer set");
//            if(node->getNextPointerSet().empty()) {
//                std::cout << primary_node_value << " -> NULL" << std::endl;
//            } else {
//                for(Node *next_pointer : node->getNextPointerSet()){
//                    std::cout << primary_node_value << " -> " << next_pointer->getValue() << std::endl;
//                }
//            }
//        }
//    }
//}
//
//void NodeGraph::chooseNextMove() {
//    bool valid_choice = false;
//    printPossibleMovements(m_currentNode);
//    log("Which node would you like to move to?");
//    while(!valid_choice) {
//        int choice;
//        std::cin >> choice;
//        //See if you can implement this as one for loop that iterates
//        //through both vectors
//        for(Node *node : m_currentNode->getNextPointerSet()) {
//            if(node->getValue() == choice){
//                m_currentNode = node;
//                valid_choice = true;
//                break;
//            }
//        }
//        if(!valid_choice) {
//            for(Node *node : m_currentNode->getPrevPointerSet()) {
//                if(node->getValue() == choice){
//                    m_currentNode = node;
//                    valid_choice = true;
//                    break;
//                }
//            }
//        }
//        std::cin.clear();
//        std::cin.ignore();
//    }
//    if(m_currentNode == m_tailNode) {
//        m_GameEnd = true;
//    }
//}
//
//void NodeGraph::printPossibleMovements(Node *node) {
//    if(node->getPrevPointerSet().empty()){
//        std::cout << "NULL <- " << node->getValue() << std::endl;
//    } else {
//        for(Node *prevPlaces : node->getPrevPointerSet()){
//            std::cout << prevPlaces->getValue() <<  " <- " << node->getValue() << std::endl;
//        }
//    }
//    if(node->getNextPointerSet().empty()) {
//        std::cout << node->getValue() << " -> NULL" << std::endl;
//    } else {
//        for(Node *nextPlaces : node->getNextPointerSet()) {
//            std::cout << node->getValue() << " -> " << nextPlaces->getValue() << std::endl;
//        }
//    }
//}
