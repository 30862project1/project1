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
    int x = 0;
    while(int(mem[pc] & 0xFF) != 0){
        cout << "PC value: " << pc << endl;
        cout << "Op value: " << int(mem[pc] & 0xFF) << endl;
        switch(int(mem[pc] & 0xFF)){
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
                object = new MemoryObject("SHORT", RStack->convertShort(mem, pc + 1));
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
            case 71:{
                (RStack->stackPointer)++;
                object = new MemoryObject("FLOAT", RStack->convertFloat(mem, pc + 1));
                RStack->push(object, RStack->stackPointer);
                pc += 5;
                break;
            }
            case 72:{
                int index = (FStack->stack[FStack->stackPointer])->intValue + 1 + (RStack->stack[RStack->stackPointer])->intValue;
                char value = RStack->stack[index]->charValue;
                object = new MemoryObject("CHAR", value);
                RStack->stack[RStack->stackPointer] = object;
                pc++;
                break;
            }
            case 73:{
                int index = (FStack->stack[FStack->stackPointer])->intValue + 1 + (RStack->stack[RStack->stackPointer])->intValue;
                short value = RStack->stack[index]->shortValue;
                object = new MemoryObject("SHORT", value);
                RStack->stack[RStack->stackPointer] = object;
                pc++;
                break;
            }
            case 74:{
                int index = (FStack->stack[FStack->stackPointer])->intValue + 1 + (RStack->stack[RStack->stackPointer])->intValue;
                int value = RStack->stack[index]->intValue;
                object = new MemoryObject("INT", value);
                RStack->stack[RStack->stackPointer] = object;
                pc++;
                break;
            }
            case 75:{
                int index = (FStack->stack[FStack->stackPointer])->intValue + 1 + (RStack->stack[RStack->stackPointer])->intValue;
                float value = RStack->stack[index]->floatValue;
                object = new MemoryObject("FLOAT", value);
                RStack->stack[RStack->stackPointer] = object;
                pc++;
                break;
            }
            case 76:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int num_remove = first_object->intValue;
                for (int i = 0; i < num_remove; i++) {
                    RStack->remove(RStack->stackPointer);
                    RStack->stackPointer--;
                }
                pc++;
                break;
            }
            case 80:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int val1 = (FStack->stack[FStack->stackPointer])->intValue;
                int val2 = first_object->intValue;
                RStack->stack[val1+val2+1] = second_object;
                pc++;
                break;
            }
            case 77:{
                int num_to_keep = RStack->stack[RStack->stackPointer]->intValue;
                int frameValue = FStack->stack[FStack->stackPointer]->intValue;
                for (int i = 1; i <= num_to_keep; i++) {
                    int index = RStack->stackPointer - RStack->stack[RStack->stackPointer]->intValue + i - 1;
                    int set = (RStack->stack[index])->intValue;
                    object = new MemoryObject("INT", set);
                    RStack->stack[frameValue + i] = object;
                }
                for (int j = RStack->stackPointer; j > num_to_keep + frameValue; j--) {
                    RStack->remove(j);
                    RStack->stackPointer--;
                }
                pc++;
                break;
            }
            case 84:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int get = first_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                int set = second_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                object = new MemoryObject("CHAR", RStack->stack[get]->charValue);
                RStack->stack[set] = object;
                pc++;
                break;
            }
            case 85:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int get = first_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                int set = second_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                object = new MemoryObject("SHORT", RStack->stack[get]->shortValue);
                RStack->stack[set] = object;
                pc++;
                break;
            }
            case 86:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int get = first_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                int set = second_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                object = new MemoryObject("INT", RStack->stack[get]->intValue);
                RStack->stack[set] = object;
                pc++;
                break;
            }
            case 87:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                int get = first_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                int set = second_object->intValue + (FStack->stack[FStack->stackPointer])->intValue + 1;
                object = new MemoryObject("FLOAT", RStack->stack[get]->floatValue);
                RStack->stack[set] = object;
                pc++;
                break;
            }
            case 88:{
                int get = RStack->stack[RStack->stackPointer]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                int set = RStack->stack[RStack->stackPointer - 1]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                object = new MemoryObject("CHAR", RStack->stack[set]->charValue);
                RStack->stack[get] = object;
                pc++;
                break;
            }
            case 89:{
                int get = RStack->stack[RStack->stackPointer]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                int set = RStack->stack[RStack->stackPointer - 1]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                object = new MemoryObject("SHORT", RStack->stack[set]->shortValue);
                RStack->stack[get] = object;
                pc++;
                break;
            }
            case 90:{
                int get = RStack->stack[RStack->stackPointer]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                int set = RStack->stack[RStack->stackPointer - 1]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                object = new MemoryObject("INT", RStack->stack[set]->intValue);
                RStack->stack[get] = object;
                pc++;
                break;
            }
            case 91:{
                int get = RStack->stack[RStack->stackPointer]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                int set = RStack->stack[RStack->stackPointer - 1]->intValue + FStack->stack[FStack->stackPointer]->intValue + 1;
                object = new MemoryObject("FLOAT", RStack->stack[set]->floatValue);
                RStack->stack[get] = object;
                pc++;
                break;
            }
            case 94:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                RStack->push(first_object, RStack->stackPointer);
                RStack->stackPointer++;
                RStack->push(second_object, RStack->stackPointer);
                RStack->stackPointer++;
                pc++;
                break;
            }
            case 100:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                object = new MemoryObject("INT", (first_object->intValue + second_object->intValue));
                RStack->push(object, RStack->stackPointer);
                RStack->stackPointer++;
                pc++;
                break;
            }
            case 104:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                object = new MemoryObject("INT", (second_object->intValue - first_object->intValue));
                RStack->push(object, RStack->stackPointer);
                RStack->stackPointer++;
                pc++;
                break;
            }
            case 108:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                object = new MemoryObject("INT", (first_object->intValue * second_object->intValue));
                RStack->push(object, RStack->stackPointer);
                RStack->stackPointer++;
                pc++;
                break;
            }
            case 112:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                second_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                object = new MemoryObject("INT", (second_object->intValue / first_object->intValue));
                RStack->push(object, RStack->stackPointer);
                RStack->stackPointer++;
                pc++;
                break;
            }
            case 144:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                cout << int(first_object->charValue) << endl;
                pc++;
                break;
            }
            case 145:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                cout << first_object->shortValue << endl;
                pc++;
                break;
            }
            case 146:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                cout << first_object->intValue << endl;
                pc++;
                break;
            }
            case 147:{
                first_object = RStack->stack[RStack->stackPointer];
                RStack->remove(RStack->stackPointer);
                RStack->stackPointer--;
                cout << first_object->floatValue << endl;
                pc++;
                break;
            }
            default: {
                //none
             }

        }
        //printAll(RStack, FStack, mem, pc);
        x++;
    }
    cout << "end" << endl;
}

#include "Memory.h"
