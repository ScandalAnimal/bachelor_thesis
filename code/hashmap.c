/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"

unsigned int generateIndex(void* m, char* key) {

    tHashMap* map = (tHashMap*) m;
    int mask;
    int range = 0xFFFFFFFF;
    int character;

    for (unsigned int i = 0; i < strlen((const char *) key); i++) {
        character = key[i];
        range ^= character;
        for (int j = 7; j >= 0; j--) {
            mask = -(range & 1);
            range = (range >> 1) ^ (0xEDB88320 & mask);
        }
    }
    return (~range) % map->capacity;

}

bool rehash(void *m) {

    tHashMap* map = (tHashMap*) m;

    tHashMapRecord* newRecords;
    if (!(newRecords = calloc((size_t) 2 * map->capacity, sizeof(tHashMapRecord)))) {
        fprintf(stderr, "%s\n", ERR_MALLOC);
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
        fprintf(stderr, "%s\n", ERR_MALLOC);
        return NULL;
    }

    if (!(map->records = calloc((size_t) initialCapacity, sizeof(tHashMapRecord)))) {
        freeHashMap(map);
        fprintf(stderr, "%s\n", ERR_MALLOC);
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

unsigned int getHashMapCapacity(void* m) {
    tHashMap* map = (tHashMap*) m;
    return (map != NULL) ? map->capacity : 0;
}

int insertToHashMap(void* m, char *key, bool value) {
    tHashMap* map = (tHashMap*) m;

    int indexToInsert = generateIndex(m,key);

    if (map->records[indexToInsert].used) {
        if (strcmp((const char *) key, (const char *) map->records[indexToInsert].key) == 0) {
            map->records[indexToInsert].value = value;
        }
        else {
            if (!rehash(map)) {
                return ERROR;
            };
            insertToHashMap(map,key,value);
        }
    }
    else {
        sprintf((char *) map->records[indexToInsert].key, "%s", (const char *) key);
        map->records[indexToInsert].value = value;
        map->records[indexToInsert].used = true;
        map->usedCapacity++;
    }

    if ((map->usedCapacity / map->capacity) > map->loadFactor) {
        if (!rehash(map)) {
            return ERROR;
        };
    }
    return OK;
}

tHashMapRecord* selectFromHashMap(void* m, char* key) {
    tHashMap* map = (tHashMap*) m;

    int index = generateIndex(m,key);
    return &(map->records[index]);
}

bool isHashMapEmpty(void* m) {
    tHashMap* map = (tHashMap*) m;
    return (map->usedCapacity == 0);
}

bool isKeyInHashMap(void* m, char* key) {

    tHashMap* map = (tHashMap*) m;

    unsigned int index = generateIndex(map,key);
    if (strcmp(key, map->records[index].key) == 0) {
        return (map->records[index].used);        
    }
    else {
        return false;
    }
}

void removeFromHashMap(void* m, char* key) {

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
            printf("%4u |  %15s ----- ",i,record.key);
            fputs(record.value ? "true #\n" : "false #\n", stdout);
        }

    }
    printf("Pocet zaznamov: %d/%d\n", map->usedCapacity, map->capacity);
    if (zeroRecords) {
        printf("Mapa neobsahuje ziadne zaznamy.\n");
    }
    printf("********************************\n");
}