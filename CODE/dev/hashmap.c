/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include "hashmap.h"

typedef struct hashMapRecord {
    char key;
    int value;
} hashMapRecord;

typedef struct hashMap {
    hashMapRecord *records;
    int size;
} hashMap;

anyType createHashMap() {
    hashMap* map = (hashMap*) malloc(sizeof(hashMap));
    if (!map) {
        return NULL;
    }

    map->records = calloc(100, sizeof(hashMapRecord));
    if (!map->records) {
        freeHashMap(map);
        return NULL;
    }

    map->size = 100;

    return map;
}

void freeHashMap(anyType m) {
    hashMap* map = (hashMap*) m;
    free(map->records);
    free(map);
}

int getHashMapSize(anyType m) {
    hashMap* map = (hashMap*) m;
    return (map != NULL) ? map->size : 0;
}