/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include "hashmap.h"

// TODO implement
int generateIndex(void* map, char* key) {
    return 0;
}

// TODO implement
int findIndex(void* map, char* key) {
    return 0;
}

void* createHashMap(long initialCapacity, int loadFactor) {
    if (initialCapacity <= 0L) {
        initialCapacity = DEFAULT_HASHMAP_CAPACITY;
    }
    tHashMap* map = (tHashMap*) malloc(sizeof(tHashMap));
    if (!map) {
        return NULL;
    }

    map->records = calloc((size_t) initialCapacity, sizeof(tHashMapRecord));
    if (!map->records) {
        freeHashMap(map);
        return NULL;
    }

    map->capacity = initialCapacity;
    map->usedCapacity = 0;
    map->loadFactor = loadFactor;

    return map;
}

void freeHashMap(void* m) {
    tHashMap* map = (tHashMap*) m;
    free(map->records);
    free(map);
}

long getHashMapCapacity(void* m) {
    tHashMap* map = (tHashMap*) m;
    return (map != NULL) ? map->capacity : 0;
}

void insertToHashMap(void* m, char* key, int value) {
    tHashMap* map = (tHashMap*) m;

    // TODO check for overflow etc.
    int indexToInsert = generateIndex(m,key);

    map->records[indexToInsert].key = key;
    map->records[indexToInsert].value = value;
    map->usedCapacity++;

    if (map->usedCapacity > map->loadFactor) {
        // TODO add more memory
    }

}

int selectFromHashMap(void* m, char* key) {
    tHashMap* map = (tHashMap*) m;

    int index = findIndex(m,key);
    return map->records[index].value;
}

bool isHashMapEmpty(void* m) {
    tHashMap* map = (tHashMap*) m;

    return (map->usedCapacity == 0);
}

// TODO implement
bool isKeyInHashMap(void* m, char* key) {
    return false;
}

// TODO implement
void removeFromHashMap(void* m, char* key) {

}

// TODO implement
void clearHashMap(void* m) {

}

// TODO implement
char* printHashMap(void* m) {
    return "Here will be formatted hashMap\n";
}



