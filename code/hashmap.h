/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>
#include "error.h"
#include "graph.h"
#include "utils.h"
#include "lib/uthash.h"
#include "variable.h"

// max hashmap tested - 15000 records


/*
 * tMap is a pointer to an internally maintained data structure.
 * Clients of this package do not need to know how hashmaps are
 * represented.  They see and manipulate only tMaps.
 */
typedef void*  tMap;

tMap	createHashMap();
int     insertToHashMap(tMap, const char*, bool);
tVar*	selectFromHashMap(tMap, const char*);
bool    isHashMapEmpty(tMap);
void    freeHashMap(tMap);

bool    isKeyInHashMap(tMap, const char*);
int 	removeFromHashMap(tMap, const char*);
void    clearHashMap(tMap);

void    printHashMap(tMap);
int 	generateHashMapGraph(tMap, char*);

#endif //CODE_HASHMAP_H
