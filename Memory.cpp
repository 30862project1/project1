//
// Created by Ari on 10/30/2019.
//

#include "Memory.h"
#include "RunStack.h"
#include "FrameStack.h"
#include "MemoryObject.h"
#include <iostream>
using namespace std;

Memory::Memory(char * memory, int passed_pc) : mem(memory), pc(passed_pc) {}

void Memory::parse(){
    RunStack * RStack = new RunStack();
    FrameStack * FStack = new FrameStack();
    MemoryObject * first_object;
    MemoryObject * second_object;
    MemoryObject * object;
    while(int(mem[pc]) != 0){
        switch(int(mem[pc])){
            case 132:{
                first_object = (RStack->stack)[RStack->stackPointer];
                second_object = (RStack->stack)[(RStack->stackPointer) - 1];
                int equals = ((first_object->intValue) == (second_object->intValue)) ? 1 : 0;
                object = new MemoryObject("INT", equals);
                RStack->remove(RStack->stackPointer);
                RStack->remove((RStack->stackPointer) - 1);
                (RStack->stackPointer)--;
                RStack->push(object, RStack->stackPointer);
                pc++;
                break;}
            case 136:{
                first_object = (RStack->stack)[RStack->stackPointer];
                second_object = (RStack->stack)[(RStack->stackPointer) - 1];
                int lessthan = ((first_object->intValue) >= (second_object->intValue)) ? 1 : 0;
                object = new MemoryObject("INT", lessthan);
                RStack->remove(RStack->stackPointer);
                RStack->remove((RStack->stackPointer) - 1);
                (RStack->stackPointer)--;
                RStack->push(object, RStack->stackPointer);
                pc++;
                break;
            }
            case 140:{
                first_object = (RStack->stack)[RStack->stackPointer];
                second_object = (RStack->stack)[(RStack->stackPointer) - 1];
                int greaterthan = ((first_object->intValue) < (second_object->intValue)) ? 1 : 0;
                object = new MemoryObject("INT", greaterthan);
                RStack->remove(RStack->stackPointer);
                RStack->remove((RStack->stackPointer) - 1);
                (RStack->stackPointer)--;
                RStack->push(object, RStack->stackPointer);
                pc++;
                break;
            }
            case 36: {
                first_object = (RStack->stack)[RStack->stackPointer];
                pc = first_object->intValue;
                RStack->remove(RStack->stackPointer);
                (RStack->stackPointer)--;
                break;
            }
            case 40: {
                first_object = (RStack->stack)[RStack->stackPointer];
                //first_object = RStack.remove(runStack.getSP());
                second_object = (RStack->stack)[RStack->stackPointer - 1];
                RStack->remove(RStack->stackPointer);
                RStack->remove((RStack->stackPointer) - 1);
                (RStack->stackPointer)--;
                (RStack->stackPointer)--;
                if (second_object->intValue == 1) {
                    pc = first_object->intValue;
                }
                else {
                    pc++;
                }
                break;
            }
            case 44:{
                FStack->stackPointer++;
                first_object = (RStack->stack)[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                (RStack->stackPointer)--;
                object = new MemoryObject("INT", RStack->stackPointer - first_object->intValue - 1);
                FStack->push(object, FStack->stackPointer);
                second_object = (RStack->stack)[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                (RStack->stackPointer)--;
                pc = second_object->intValue;
                break;
            }
            case 48:{
                first_object = FStack->stack[FStack->stackPointer];
                FStack->remove(FStack->stackPointer);
                RStack->stackPointer = first_object->intValue;
                (FStack->stackPointer)--;
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                pc = first_object->intValue;
                RStack->stackPointer--;
                break;
            }
            case 68:{
                RStack->stackPointer++;
                first_object = new MemoryObject("CHAR", mem[pc+1]);
                RStack->push(first_object, RStack->stackPointer);
                pc += 2;
                break;
            }
            case 69:{
                (RStack->stackPointer)++;
                object = new MemoryObject("INT", RStack->convertShort(mem, pc + 1));
                RStack->push(object, RStack->stackPointer);
                pc += 3;
                break;
            }
            case 70: {
                (RStack->stackPointer)++;
                object = new MemoryObject("INT", RStack->convertInt(mem, pc + 1));
                RStack->push(object, RStack->stackPointer);
                pc += 5;
                break;
            }
            default: {
                pc++;
             }

        }
        //printAll(RStack, FStack, mem, pc);
    }
}

#include "Memory.h"
