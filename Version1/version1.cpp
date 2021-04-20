#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <cstring>      // for strerror()
#include <vector>
#include <thread>
#include <fstream>
#include <iterator>
#include <unistd.h>     // for usleep()
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "Graph.h"
using namespace std;
const string NODE = "NODE";
const string EDGE = "EDGE";
const string DEGREE = "DEGREE";
const string COST = "COST";

int main(int argc,const char* argv[]){
    if(argc != 2){
        cout << "usage: ./version1 <filePath>" << endl;
    }
    ifstream fileRead;
    fileRead.open(argv[1]);
    string gName;
    fileRead >> gName;
    Graph graph = Graph(gName);
    while (!fileRead.eof())
    {
        string cmd;
        fileRead >> cmd;
        if(cmd.compare(NODE) == 0){
            string name, out;
            fileRead >> name;
            out = graph.addNode(name);
            cout << out << endl;
        }else if(cmd.compare(EDGE) == 0){
            string node1,node2,out;
            int cost;
            fileRead >> node1 >> node2 >> cost;
            out = graph.addEdge(node1,node2,cost);
            cout << out << endl;
        }else if(cmd.compare(DEGREE)==0){
            string name,out;
            fileRead >> name;
            out = graph.getDegree(name);
            cout << out << endl;
        }else if(cmd.compare(COST)==0){
            string name1,name2,out;
            fileRead >> name1 >> name2;
            out = graph.getCost(name1,name2);
            cout << out << endl;
        }
        else{
            cout << "INVALID COMMAND" << endl;
        }
    }
    
    return 0;
}