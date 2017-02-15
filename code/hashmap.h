/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>

#define DEFAULT_HASHMAP_CAPACITY 256

typedef struct hashMapRecord {
    unsigned char *key;
    bool value;
    bool used;
} tHashMapRecord;

typedef struct hashMap {
    tHashMapRecord *records;
    unsigned int capacity;
    long usedCapacity;
    double loadFactor;
} tHashMap;

extern void*        createHashMap(unsigned int, double);

// TODO think about return enum
extern bool         insertToHashMap(void*, unsigned char *, bool);
extern bool          selectFromHashMap(void*, unsigned char*);

extern bool         isHashMapEmpty(void*);
extern void         freeHashMap(void*);
extern unsigned int getHashMapCapacity(void*);

extern bool         isKeyInHashMap(void*, unsigned char*);
extern void         removeFromHashMap(void*, unsigned char*);
extern void         clearHashMap(void*);

extern void         printHashMap(void*);

#endif //CODE_HASHMAP_H
