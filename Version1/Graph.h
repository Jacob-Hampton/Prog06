#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

using namespace std;

class Graph
{
private:
    struct Node;
    struct Connection{
        Node* node;
        int cost;
    };
    struct Node{
        string name;
        int degree;
        vector<Connection> neighbors;
        vector<Connection> connections;
    };
    int numOfNodes;
    bool nodeExists(string name);
    int getNode(string name);
    void addConnection(Node node1, Node node2, int cost);
    bool connectionExists(Node node1, string name2);
public:
    vector<Node> nodes;
    string gName;
    Graph(string name);
    string addNode(string name);
    string addEdge(string name1,string name2,int cost);
};

#endif