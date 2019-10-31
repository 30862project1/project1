//
// Created by Ari and Tika on 10/21/2019. Hi ari!
//
#include "MemoryObject.h"

MemoryObject::MemoryObject(char * type, int intValue) : data_type(type), intValue(intValue) {}

MemoryObject::MemoryObject(char * type, short shortValue) : data_type(type), shortValue(shortValue) {}

MemoryObject::MemoryObject(char * type, char charValue) : data_type(type), charValue(charValue) {}

MemoryObject::MemoryObject(char * type, float floatValue) : data_type(type), floatValue(floatValue) {}

MemoryObject::MemoryObject(){}
