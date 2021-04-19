#include "Graph.h"

Graph::Graph(string name){
    gName = name;
}

string Graph::addNode(string name){
    if(nodeExists(name)){
        return "ERROR1";
    }else{
        Node node;
        node.name = name;
        node.degree=0;
        nodes.push_back(node);
        numOfNodes++;
        return "OK";
    }
}

string Graph::addEdge(string name1,string name2,int cost){
    if(!nodeExists(name1) && !nodeExists(name2)){
        return "ERROR2";
    }else{
        Node node1 = nodes.at(getNode(name1));
        int index2 = getNode(name2);
        if(connectionExists(node1,name2)){
            return "ERROR3";
        }else{
            addConnection(node1,nodes.at(index2),cost);
            return "OK";
        }
    }
}

bool Graph::nodeExists(string name){
    for(int i=0; i< numOfNodes;i++){
        if(nodes.at(i).name.compare(name)==0){
            return true;
        }
    }
    return false;
}

bool Graph::connectionExists(Node node1,string name2){
    for(unsigned int i=0; i< node1.connections.size(); i++){
        if(node1.connections.at(i).node->name.compare(name2)==0){
            return true;
        }
    }
    return false;
}

int Graph::getNode(string name){
    for(int i=0; i< numOfNodes;i++){
        if(nodes.at(i).name.compare(name)==0){
            return i;
        }
    }
    return -1;  //This will be never touched
}

void Graph::addConnection(Node node1, Node node2, int cost){
    Connection conFor1;
    conFor1.node = &node2;
    conFor1.cost = cost;
    Connection conFor2;
    conFor2.node = &node1;
    conFor2.cost = cost;
    node1.connections.push_back(conFor1);
    node2.connections.push_back(conFor2);
}