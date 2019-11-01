//
// Created by Ari on 10/30/2019.
//

#ifndef PROJECT1_RUNSTACK_H
#define PROJECT1_RUNSTACK_H


#include "MemoryObject.h"
#include <vector>

class RunStack {
public:
    std::vector<MemoryObject*> stack;
    int stackPointer;
    RunStack();
    void push(MemoryObject*, int);
    void remove(int sp);
    int convertInt(char * mem, int pc);
    short convertShort(char * mem, int pc);
};


#endif //PROJECT1_RUNSTACK_H
