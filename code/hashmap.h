/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>
#include "error.h"
#include "graph.h"
#include "utils.h"

#define DEFAULT_HASHMAP_CAPACITY 256
#define MAX_KEY_LENGTH 256
// max hashmap tested - 1300 records

typedef struct hashMapRecord {
    char key[MAX_KEY_LENGTH];
    bool value;
    bool used;
} tHashMapRecord;

typedef struct hashMap {
    tHashMapRecord *records;
    unsigned int capacity;
    unsigned int usedCapacity;
    double loadFactor;
} tHashMap;


/*
 * tMap is a pointer to an internally maintained data structure.
 * Clients of this package do not need to know how hashmaps are
 * represented.  They see and manipulate only tMaps.
 */
typedef void*  tMap;


tMap			createHashMap(unsigned int, double);
int             insertToHashMap(tMap, char*, bool);
tHashMapRecord* selectFromHashMap(tMap, char*);
bool            isHashMapEmpty(tMap);
void           	freeHashMap(tMap);
unsigned int   	getHashMapCapacity(tMap);

bool            isKeyInHashMap(tMap, char*);
int 	        removeFromHashMap(tMap, char*);
void            clearHashMap(tMap);

void            printHashMap(tMap);
int 			generateHashMapGraph(tMap, char*);

#endif //CODE_HASHMAP_H
