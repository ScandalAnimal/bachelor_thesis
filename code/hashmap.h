/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>

#define DEFAULT_HASHMAP_CAPACITY 256

typedef struct hashMapRecord {
    char key[50]; // TODO: change to macro
    bool value;
    bool used;
} tHashMapRecord;

typedef struct hashMap {
    tHashMapRecord *records;
    unsigned int capacity;
    unsigned int usedCapacity;
    double loadFactor;
} tHashMap;

extern void*        	createHashMap(unsigned int, double);

// TODO think about return enum
extern bool             insertToHashMap(void*, char *, bool);
extern tHashMapRecord*  selectFromHashMap(void*, char*);

extern bool             isHashMapEmpty(void*);
extern void             freeHashMap(void*);
extern unsigned int     getHashMapCapacity(void*);

extern bool             isKeyInHashMap(void*, char*);
extern void             removeFromHashMap(void*, char*);
extern void             clearHashMap(void*);

extern void             printHashMap(void*);

#endif //CODE_HASHMAP_H
