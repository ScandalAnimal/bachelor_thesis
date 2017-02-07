
#include <stdio.h>
#include <assert.h>
#include "hashmap.h"

int main(int argc, char *argv[]) {

    long requestedCapacity = 256L;
    int loadFactor = 10;

    tHashMap* map = createHashMap(requestedCapacity, loadFactor);
    long cap = getHashMapCapacity(map);
    printf("Size : %ld\n",cap);

    printf(isHashMapEmpty(map) ? "Map is empty\n" : "Map is not empty\n");

    int insertedValue = 5;

    insertToHashMap(map,"A",insertedValue);
    int x = selectFromHashMap(map,"A");
    printf("Value: %d\n", x);

    assert(x == insertedValue);

    printf(isHashMapEmpty(map) ? "Map is empty\n" : "Map is not empty\n");

    printf("Assert OK\n");
    freeHashMap(map);
    return 0;
}
