/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_VARIABLE_H
#define CODE_VARIABLE_H

#include <stdbool.h>

typedef struct variable {
    char name[50]; // TODO: change to macro
    bool value;
} variable;

extern variable* createVariable(void*, char*, bool);
extern void 	 createVariables(void*, char**, bool[]);

#endif //CODE_VARIABLE_H
