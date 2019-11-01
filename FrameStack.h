//
// Created by Ari on 10/30/2019.
//

#ifndef PROJECT1_FRAMESTACK_H
#define PROJECT1_FRAMESTACK_H


#include "MemoryObject.h"
#include <vector>

class FrameStack {
public:
    std::vector<MemoryObject*> stack;
    int stackPointer;
    FrameStack();
    void push(MemoryObject*, int);
    void remove(int sp);
};


#endif //PROJECT1_FRAMESTACK_H
