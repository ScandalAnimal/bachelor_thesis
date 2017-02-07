/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>

#define DEFAULT_HASHMAP_CAPACITY 256

typedef struct hashMapRecord {
    char* key;
    int value;
} tHashMapRecord;

typedef struct hashMap {
    tHashMapRecord *records;
    long capacity;
    long usedCapacity;
    int loadFactor;
} tHashMap;

extern void*    createHashMap(long, int);

// TODO think about return type
extern void     insertToHashMap(void*, char*, int);
extern int      selectFromHashMap(void*, char*);

extern bool     isHashMapEmpty(void*);
extern void     freeHashMap(void*);
extern long     getHashMapCapacity(void*);

extern bool     isKeyInHashMap(void*, char*);
extern void     removeFromHashMap(void*, char*);
extern void     clearHashMap(void*);

extern char*    printHashMap(void*);

#endif //CODE_HASHMAP_H
