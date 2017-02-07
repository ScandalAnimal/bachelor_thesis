#include <stdio.h>
#include "inputs.h"
#include "hashmap.h"

int main(int argc, char *argv[]) {
    myStructure s[10];
    addVar(s,'A');
    addVar(s,'B');
    addVar(s,'C');
    for (int i = 0; i < 10; i++) {
        printf("%c\n",s[i].name);
    }

    int requestedCapacity = 256;

    void* map = createHashMap(requestedCapacity);
    long cap = getHashMapCapacity(map);
    printf("%ld\n",cap);
    freeHashMap(map);
    return 0;
}
