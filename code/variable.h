/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_VARIABLE_H
#define CODE_VARIABLE_H

#include <stdbool.h>

typedef struct variable {
    char* name;
    bool value;
} tVar;

extern tVar  createVar(char*, bool);
extern tVar* createVariable(unsigned int, char*, bool);
// extern void 	 createVariables(void*, char**, int, bool[]);

#endif //CODE_VARIABLE_H
