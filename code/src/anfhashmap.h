/*
	Copyright 1992-2017 Maroš Vasilišin. All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
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
tVar* selectFromHashMap(tMap map, char* key);

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
