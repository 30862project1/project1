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
    //vector <char> memory;
    //FILE * fp = fopen("interpreter_input.smp", "r");
    //std::ifstream fp("interpreter_input.smp");
    std::ifstream fp("Math.bin");

//get length of file
    fp.seekg(0, std::ios::end);
    int length = fp.tellg();
    char memory[length];
    fp.seekg(0, std::ios::beg);
/*
    if (length > sizeof (buffer))
    {
        length = sizeof (buffer);
    }*/
    fp.read(memory, length);
    //fread(buffer, sizeof(char), 8, fp);
    Memory * full_mem = new Memory(memory, 0);
    full_mem->parse();
    return 0;
}
