#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

using namespace std;
const int NOT_EXIST = -1;

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
    int getNodeIndex(string name);
    Connection createConnection(Node* otherNode, int cost);
    void addNeighbor(int nodeIdx1, int nodeIdx2, int cost);
    bool connectionExists(Node node1, string name2);
    Connection getConnection(Node node1, string name2);
    int getNeigborIndex(Node node1, string name2);
    int getConnectionIndex(Node node1, string name2);
public:
    vector<Node> nodes;
    string gName;
    Graph(string name);
    string addNode(string name);
    string addEdge(string name1,string name2,int cost);
    string getDegree(string name);
    string getCost(string name1, string name2);
};

#endif