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

    anyType map = createHashMap();
    int size = getHashMapSize(map);
    printf("%d\n",size);
    freeHashMap(map);
    return 0;
}
