//
// Created by Ari on 10/21/2019.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "MemoryObject.h"
#include "Memory.h"

using namespace std;


int main(int argc, char * argv[]) {
    if(argc != 2){
        cout << "Usage: project1 <filename>" << endl;
        return 0;
    }
    char * file = argv[1];
    std::ifstream fp(file);
    fp.seekg(0, std::ios::end);
    int length = fp.tellg();
    char memory[length];
    fp.seekg(0, std::ios::beg);
    fp.read(memory, length);
    Memory * full_mem = new Memory(memory, 0);
    full_mem->parse();
    return 0;
}
