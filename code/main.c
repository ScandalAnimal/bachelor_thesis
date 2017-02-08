
#include <stdio.h>
#include <assert.h>
#include "hashmap.h"

int main(int argc, char *argv[]) {

    unsigned int requestedCapacity = 2;
    double loadFactor = 0.5;

    tHashMap* map = createHashMap(requestedCapacity, loadFactor);
//    long cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
//
//    printf(isHashMapEmpty(map) ? "Map is empty\n" : "Map is not empty\n");
//
//    int insertedValue = 5;
//
//    insertToHashMap(map, (unsigned char *) "A", insertedValue);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "B", 10);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "C", 20);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "D", 20);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "E", 20);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "F", 20);
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);
    insertToHashMap(map, (unsigned char *) "G", 20);

//    int x = selectFromHashMap(map, (unsigned char *) "A");
//    printf("Value: %d\n", x);
//
//    assert(x == insertedValue);
//
//    bool isKeyTest = isKeyInHashMap(map, (unsigned char *) "D");
//    assert(false == isKeyTest);
//
//    isKeyTest = isKeyInHashMap(map, (unsigned char *) "A");
//    assert(true == isKeyTest);
//
//    printf(isHashMapEmpty(map) ? "Map is empty\n" : "Map is not empty\n");
//
//    printf("Assert OK\n");
//
    printHashMap(map);
//    cap = getHashMapCapacity(map);
//    printf("Size : %ld\n",cap);

//
//    removeFromHashMap(map, (unsigned char *) "B");
//    printHashMap(map);
//
//    clearHashMap(map);
//    printHashMap(map);
    freeHashMap(map);
    return 0;
}
