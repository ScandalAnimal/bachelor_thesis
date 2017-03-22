/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <stdbool.h>
#include "hashmap.h"
#include "variable.h"

typedef struct node {
    int length;
    char** variables;
    // TODO pridat info v ktorom bundli je, pre kontrolu duplicit
} tNode;

extern void* createNode();
// extern node createNodeWithVariables(char**, int, bool[], void*);
extern void addVariableToNode(char*, tNode*);
extern void addVariablesToNode(tVar[], int, tNode*);
extern void printNode(tNode*);
extern void freeNode(tNode*);

#endif //CODE_NODE_H