//
// Created by Ari on 10/30/2019.
//

#include "RunStack.h"
#include <vector>

RunStack::RunStack() : stackPointer(-1){}

void RunStack::remove(int sp) {
    stack.erase(stack.begin()+sp);
}

void RunStack::push(MemoryObject* object, int sp) {
    stack.insert(stack.begin() + sp, object);
}

int RunStack::convertInt(char * mem, int pc){
    return ((mem[pc] & 0xFF) << 0) | ((mem[pc+1] & 0xFF) << 8) | ((mem[pc+2] & 0xFF) << 16) | ((mem[pc+3] & 0xFF) << 24);
}

short RunStack::convertShort(char * mem, int pc){
    int r = mem[pc] & 0xFF;
    r = (r << 8) | (mem[pc+1] & 0xFF);
    short s = (short)r;
    return s;
}

