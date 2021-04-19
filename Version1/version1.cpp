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
        if(cmd.compare("NODE") == 0){
            string name, out;
            fileRead >> name;
            out = graph.addNode(name);
            cout << out << endl;
        }
    }
    
    return 0;
}