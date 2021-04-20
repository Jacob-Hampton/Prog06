#include "Graph.h"

Graph::Graph(string name){
    gName = name;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string Graph::addNode(string name){
    int nodeIdx = getNodeIndex(name);
    if(nodeIdx == NOT_EXIST){
        Node node;
        node.name = name;
        node.degree=0;
        nodes.push_back(node);
        numOfNodes++;
        return "OK";
    }else{
        return "ERROR1";
    }
}

string Graph::addEdge(string name1,string name2,int cost){
    int nodeIdx1 = getNodeIndex(name1);
    int nodeIdx2 = getNodeIndex(name2);
    if( nodeIdx1 == NOT_EXIST || nodeIdx2 == NOT_EXIST ){
        return "ERROR2";
    }else{
        if(getNeigborIndex(nodes.at(nodeIdx1),name2) != NOT_EXIST ){
            return "ERROR3";
        }else{
            int conIndx = getConnectionIndex(nodes.at(nodeIdx1),name2);
            if(conIndx != NOT_EXIST){
                nodes.at(nodeIdx1).connections.erase(nodes.at(nodeIdx1).connections.begin()+conIndx);
            }
            addNeighbor(nodeIdx1,nodeIdx2,cost);
            return "OK";
        }
    }
}

Graph::Connection Graph::createConnection(Node* otherNode, int cost){
    Connection connect;
    connect.node = otherNode;
    connect.cost = cost;
    return connect;
}

void Graph::addNeighbor(int nodeIdx1, int nodeIdx2, int cost){
    nodes.at(nodeIdx1).neighbors.push_back(createConnection(&nodes.at(nodeIdx2),cost));
    nodes.at(nodeIdx2).neighbors.push_back(createConnection(&nodes.at(nodeIdx1),cost));
    nodes.at(nodeIdx2).degree++;
    nodes.at(nodeIdx1).degree++;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string Graph::getDegree(string name){
    int nodeIdx = getNodeIndex(name);
    if(nodeIdx == NOT_EXIST){
        return "ERROR2";
    }else{
        return (to_string(nodes.at(nodeIdx).degree) + "OK");
    }
}

string Graph::getCost(string name1, string name2){
    int nodeIdx1 = getNodeIndex(name1);
    int nodeIdx2 = getNodeIndex(name2);
    if( nodeIdx1 == -1 || nodeIdx2 == -1 ){
        return "ERROR2";
    }else{
        int conIndex = getConnectionIndex(nodes.at(nodeIdx1),name2);
        int cost;
        if(conIndex == NOT_EXIST){
            conIndex = getNeigborIndex(nodes.at(nodeIdx1),name2);
            if(conIndex == NOT_EXIST){
                return "ERROR4";
            }else{
                cost = nodes.at(nodeIdx1).neighbors.at(conIndex).cost;
            }
        }else{
            cost = nodes.at(nodeIdx1).connections.at(conIndex).cost;
        }
        string out = "OK";
        return out.append(to_string(cost));
    }
}

int Graph::getNodeIndex(string name){
    for(int i=0; i< numOfNodes;i++){
        if(nodes.at(i).name.compare(name)==0){
            return i;
        }
    }
    return -1;
}


int Graph::getNeigborIndex(Node node1, string name2){
    for(unsigned int i=0; i< node1.neighbors.size(); i++){
        if(node1.neighbors.at(i).node->name.compare(name2)==0){
            return node1.neighbors.at(i).cost;
        }
    }
    return -1;
}
int Graph::getConnectionIndex(Node node1, string name2){
    for(unsigned int i=0; i< node1.connections.size(); i++){
        if(node1.connections.at(i).node->name.compare(name2)==0){
            return i;
        }
    }
    return -1;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<