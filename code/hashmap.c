/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"

unsigned int generateIndex(void* m, unsigned char* key) {

    tHashMap* map = (tHashMap*) m;
    unsigned int mask;
    unsigned int range = 0xFFFFFFFF;
    unsigned int character;

    for (unsigned int i = 0; i < strlen((const char *) key); i++) {
        character = key[i];
        range ^= character;
        for (int j = 7; j >= 0; j--) {
            mask = (unsigned int) -(range & 1);
            range = (range >> 1) ^ (0xEDB88320 & mask);
        }
    }
    return (~range) % map->capacity;

}

bool rehash(void *m) {

    printf("---------REHASHING\n");
    tHashMap* map = (tHashMap*) m;

    tHashMapRecord* newRecords;
    if (!(newRecords = calloc((size_t) 2 * map->capacity, sizeof(tHashMapRecord)))) {
        return false;
    }

    tHashMapRecord* oldRecords = map->records;
    map->records = newRecords;

    int oldMapCapacity = map->capacity;
    map->capacity *= 2;
    map->usedCapacity = 0;

    for (int i = 0; i < oldMapCapacity; i++) {
        tHashMapRecord record = oldRecords[i];
        if (record.used) {
            insertToHashMap(map,record.key,record.value);
        }
    }
    free(oldRecords);
    return true;
}

void* createHashMap(unsigned int initialCapacity, double loadFactor) {
    if (initialCapacity <= 0L) {
        initialCapacity = DEFAULT_HASHMAP_CAPACITY;
    }
    tHashMap* map;
    if (!(map = (tHashMap*) malloc(sizeof(tHashMap)))) {
        return NULL;
    }

    if (!(map->records = calloc((size_t) initialCapacity, sizeof(tHashMapRecord)))) {
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

bool insertToHashMap(void* m, unsigned char *key, int value) {
    tHashMap* map = (tHashMap*) m;

    int indexToInsert = generateIndex(m,key);
    printf("Inserting: %s on index %d\n", key, indexToInsert);

    if (map->records[indexToInsert].used) {
        if (strcmp((const char *) key, (const char *) map->records[indexToInsert].key) == 0) {
            map->records[indexToInsert].value = value;
        }
        else {
            if (!rehash(map)) {
                return false;
            };
            printf("Return from rehash\n");
            printf("New size: %d\n",map->capacity);
            insertToHashMap(map,key,value);
            map->usedCapacity++;
        }
    }
    else {
        map->records[indexToInsert].key = key;
        map->records[indexToInsert].value = value;
        map->records[indexToInsert].used = true;
        map->usedCapacity++;
    }

    if ((map->usedCapacity / map->capacity) > map->loadFactor) {
        if (!rehash(map)) {
            return false;
        };
    }
    return true;
}

int selectFromHashMap(void* m, unsigned char* key) {
    tHashMap* map = (tHashMap*) m;

    int index = generateIndex(m,key);
    return map->records[index].value;
}

bool isHashMapEmpty(void* m) {
    tHashMap* map = (tHashMap*) m;
    return (map->usedCapacity == 0);
}

bool isKeyInHashMap(void* m, unsigned char* key) {

    tHashMap* map = (tHashMap*) m;

    unsigned int index = generateIndex(map,key);
    return (map->records[index].used);
}

void removeFromHashMap(void* m, unsigned char* key) {

    tHashMap* map = (tHashMap*) m;

    unsigned int index = generateIndex(map,key);
    if (map->records[index].used) {
        map->records[index].used = false;
        map->usedCapacity--;
    }
}

void clearHashMap(void* m) {
    tHashMap* map = (tHashMap*) m;

    for (int i = 0; i < map->capacity; i++) {
        map->records[i].used = false;
    }
    map->usedCapacity = 0;
}

void printHashMap(void* m) {
    tHashMap* map = (tHashMap*) m;
    bool zeroRecords = true;

    printf("********************************\nObsah hash mapy:\n");
    for (int i = 0; i < map->capacity; i++) {
        tHashMapRecord record = map->records[i];
        if (record.used) {
            zeroRecords = false;
            printf("%u |  %s ----- %d\n",i,record.key, record.value);
        }
//        printf("%u |  %s ----- %d\n",i,record.key, record.value);

    }
    printf("Pocet zaznamov: %ld\n", map->usedCapacity);
    if (zeroRecords) {
        printf("Mapa neobsahuje ziadne zaznamy.\n");
    }
    printf("********************************\n");
}



