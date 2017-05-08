/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"

tMap createHashMap() {

    tVar* map = NULL;
    return map;
}

void freeHashMap(tMap m) {
    
    tVar** map = (tVar**) m;
    tVar *s, *tmp = NULL;

    /* free the hash table contents */
    HASH_ITER(hh, *map, s, tmp) {
        HASH_DEL(*map, s);
        free(s);
    }
}

int insertToHashMap(tMap m, const char *name, bool value) {

    tVar** map = (tVar**) m;

    tVar* s = NULL;
    s = (tVar*) malloc(sizeof(tVar));
    s->name = name;
    s->value = value;
    HASH_ADD_KEYPTR(hh, *map, s->name, strlen(s->name), s);    

    return OK;
}

tVar* selectFromHashMap(tMap m, const char* name) {
    
    tVar** map = (tVar**) m;

    tVar* s = NULL;
    HASH_FIND_STR(*map, name, s);
    return s;
}

bool isHashMapEmpty(tMap m) {
    
    tVar** map = (tVar**) m;
    
    unsigned int count = HASH_COUNT(*map);

    return (count == 0);
}

bool isKeyInHashMap(tMap m, const char* name) {

    tVar** map = (tVar**) m;

    tVar* s = NULL;
    HASH_FIND_STR(*map, name, s);
    return (s == NULL) ? false : true;
}

int removeFromHashMap(tMap m, const char* name) {

    tVar** map = (tVar**) m;

    tVar* s = NULL;
    HASH_FIND_STR(*map, name, s);
    if (s == NULL) {
        return ERROR;
    }

    HASH_DEL(*map, s);
    free(s);
    return OK;
}

void clearHashMap(tMap m) {

    tVar** map = (tVar**) m;

    tVar *current_record, *tmp = NULL;

    HASH_ITER(hh, *map, current_record, tmp) {
        HASH_DEL(*map, current_record);
        free(current_record);
    }
}

void printHashMap(tMap m) {

    tVar** map = (tVar**) m;

    tVar *s = NULL;

    int i = 0;
    printf("********************************\nHash Map Contents:\n");
    for(s = *map; s != NULL; s = (tVar*)(s->hh.next)) {
        
        printf("%4u |  %15s ----- ",i,s->name);
        fputs(s->value ? "true #\n" : "false #\n", stdout);

        i++;
    }
    printf("Record Count: %d\n", HASH_COUNT(*map));
    if (isHashMapEmpty(m)) {
        printf("No records in map.\n");
    }
    printf("********************************\n");
}

int generateHashMapGraph(tMap m, char* filename) {

    tVar** map = (tVar**) m;

    FILE *file = openAndClearFile(filename);

    if (file == NULL) {
        return ERR_OPEN;
    }

    printInitGraphSequence(file);
    int capacity = HASH_COUNT(*map);
    printMultipleRootNodes(file, capacity);

    int subNodeCounter = 1;
    tVar* s = NULL;

    int i = 0;
    for (s = *map; s != NULL; s = (tVar*)(s->hh.next)) {

        printNodeWithValue(file, subNodeCounter, s->name, s->value);
        printArrow(file, 0, i, subNodeCounter);
        subNodeCounter++;
        i++;
    }

    printEndGraphSequence(file);

    fclose(file);
    return OK;

}
