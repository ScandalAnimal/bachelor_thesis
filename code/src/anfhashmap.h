/** 
 * @file
 * @brief functions for manipulating with hash map
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#include <stdbool.h>
#include "anferror.h"
#include "anfgraph.h"
#include "anfutils.h"
#include "uthash.h"
#include "anfvariable.h"
/**
 * tMap is a pointer to an internally maintained data structure.
 * Clients of this package do not need to know how hashmaps are
 * represented.  They see and manipulate only tMaps.
 */
typedef void*  tMap;

/**
 * creates new hash map
 * @return pointer to created hash map
 */
tMap createHashMap();

/**
 * inserts new record to hash map
 * @param map map to which inserting
 * @param key key of record
 * @param value value of record
 * @param origin origin of record
 * @return return code from <code>error.h</code>
 */
int insertToHashMap(tMap map, char* key, bool value, char* origin);

/**
 * gets variable with key from map
 * @param map map from which selecting
 * @param key key of selected record
 * @return pointer to selected variable
 */
tVar* selectFromHashMap(tMap map, const char* key);

/**
 * checks if hash map is empty or not
 * @param map map tested
 * @return true if map is empty, false if is not
 */
bool isHashMapEmpty(tMap map);

/**
 * frees map from memory
 * @param map map to free
 */
void freeHashMap(tMap map);

/**
 * checks if key is present in map
 * @param map map to check
 * @param key key to check
 * @return true if key is in map, false if is not
 */
bool isKeyInHashMap(tMap map, const char* key);

/**
 * deletes record from hash map
 * @param map map where to delete record
 * @param key key of record to delete
 * @return return code from <code>error.h</code>
 */
int removeFromHashMap(tMap map, char* key);

/**
 * deletes all variables from map
 * @param map map where deleting
 */
void clearHashMap(tMap map);

/**
 * prints contents of map to console
 * @param map map to print
 */
void printHashMap(tMap map);

/**
 * generates graph of hash map
 * @param map map to create graph from
 * @param filename file to write graph to
 * @return return code from <code>error.h</code>
 */
int generateHashMapGraph(tMap map, char* filename);

#endif //CODE_HASHMAP_H
