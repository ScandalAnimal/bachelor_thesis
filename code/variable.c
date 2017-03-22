/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"
#include "variable.h"

tVar createVar(char* name, bool value) {
    
    tVar var;
    var.name = name;
    var.value = value;
    return var;    
}

tVar* createVariable(unsigned int maxVarLength, char* name, bool value) {

    tVar* var = (tVar*) malloc(sizeof(tVar));

    var->name = malloc(sizeof(char) * maxVarLength);
    sprintf((char *) var->name, "%s", name);
    var->value = value;

    return var;
}

// void createVariables(void* m, char* names[], int size, bool values[]) {

//     tHashMap* map = (tHashMap*) m;

//     for (int i = 0; i < size; i++) {

//         // TODO: is this needed?

//         // variable* variable = malloc(sizeof(variable));

//         // sprintf((char *) variable->name, "%s", name);
//         // variable->value = value;

//         insertToHashMap(map, names[i], values[i]);
//     }
// }