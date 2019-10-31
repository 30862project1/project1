//
// Created by Ari and Tika on 10/21/2019. Hi ari!
//
#include "MemoryObject.h"

MemoryObject::MemoryObject(const char * type, int intValue) : data_type(type), intValue(intValue) {}

MemoryObject::MemoryObject(const char * type, short shortValue) : data_type(type), shortValue(shortValue) {}

MemoryObject::MemoryObject(const char * type, char charValue) : data_type(type), charValue(charValue) {}

MemoryObject::MemoryObject(const char * type, float floatValue) : data_type(type), floatValue(floatValue) {}

MemoryObject::MemoryObject(){}
