/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>
#include "error.h"
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


extern tMap        		createHashMap(unsigned int, double);
extern int              insertToHashMap(tMap, char *, bool);
extern tHashMapRecord*  selectFromHashMap(tMap, char*);

extern bool             isHashMapEmpty(tMap);
extern void             freeHashMap(tMap);
extern unsigned int     getHashMapCapacity(tMap);

extern bool             isKeyInHashMap(tMap, char*);
extern int 	            removeFromHashMap(tMap, char*);
extern void             clearHashMap(tMap);

extern void             printHashMap(tMap);
extern int 				generateHashMapGraph(tMap, char*);

#endif //CODE_HASHMAP_H
