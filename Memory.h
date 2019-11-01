//
// Created by Ari on 10/30/2019.
//

#ifndef PROJECT1_MEMORY_H
#define PROJECT1_MEMORY_H

#include "RunStack.h"
#include "FrameStack.h"

class Memory {
public:
    char * mem;

    int pc;

    void parse();

    Memory(char *, int);

    //void printAll(RunStack * RStack, FrameStack * FStack, char * mem, int pc);
};


#endif //PROJECT1_MEMORY_H
