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
using namespace std;

int main(int argc,const char* argv[]){
    if(argc != 2){
        cout << "usage: ./version1 <filePath>";
    }     
    return 0;
}