//
// Created by Ari on 10/21/2019.
//

#ifndef PROJECT1_MEMORYOBJECT_H
#define PROJECT1_MEMORYOBJECT_H


class MemoryObject {
public:
    const char * data_type;
    float floatValue;
    int intValue;
    char charValue;
    short shortValue;

    MemoryObject(const char * type, int intValue);
    MemoryObject(const char * type, short shortValue);
    MemoryObject(const char * type, char charValue);
    MemoryObject(const char * type, float floatValue);
    MemoryObject();
};


#endif //PROJECT1_MEMORYOBJECT_H
