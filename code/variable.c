/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"
#include "variable.h"

variable* createVariable(void* m, char* name, bool value) {

    tHashMap* map = (tHashMap*) m;

    variable* var = (variable*) malloc(sizeof(variable));

    sprintf((char *) var->name, "%s", name);
    var->value = value;

    insertToHashMap(map, name, value);

    return var;
}

void createVariables(void* m, char* names[], int size, bool values[]) {

    tHashMap* map = (tHashMap*) m;

    for (int i = 0; i < size; i++) {

        // TODO: is this needed?

        // variable* variable = malloc(sizeof(variable));

        // sprintf((char *) variable->name, "%s", name);
        // variable->value = value;

        insertToHashMap(map, names[i], values[i]);
    }
}