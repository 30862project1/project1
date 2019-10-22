//
// Created by Ari on 10/21/2019.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "MemoryObject.h"

using namespace std;

int main(int argc, char * argv[]) {
    vector <MemoryObject*> memory;
    FILE * fp = fopen("interpreter_input.smp", "r");
    char * buffer;
    fread(buffer, sizeof(char), 8, fp);
    cout << buffer << endl;
    return 0;
}
