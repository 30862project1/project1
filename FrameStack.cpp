//
// Created by Ari on 10/30/2019.
//

#include "FrameStack.h"

FrameStack::FrameStack() : stackPointer(-1){}

void FrameStack::push(MemoryObject* object, int sp) {
    stack.insert(stack.begin() + sp, object);
}

void FrameStack::remove(int sp) {
    stack.erase(stack.begin()+sp);
}