//
// Created by Ari on 10/21/2019.
//

#ifndef PROJECT1_MEMORYOBJECT_H
#define PROJECT1_MEMORYOBJECT_H


class MemoryObject {
public:
    char * data_type;
    float floatValue;
    int intValue;
    char charValue;
    short shortValue;

    MemoryObject(char * type, int intValue);
    MemoryObject(char * type, short shortValue);
    MemoryObject(char * type, char charValue);
    MemoryObject(char * type, float floatValue);
    MemoryObject();
};


#endif //PROJECT1_MEMORYOBJECT_H
