/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_VARIABLE_H
#define CODE_VARIABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/uthash.h"


typedef struct variable {
    char* name;
    bool value;
   	UT_hash_handle hh;
} tVar;

tVar createVar(char*, bool);
tVar createTrueVar(char*);
tVar createFalseVar(char*);

#endif //CODE_VARIABLE_H
