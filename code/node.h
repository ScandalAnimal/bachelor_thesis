/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <stdbool.h>
#include <string.h>
#include "hashmap.h"
#include "variable.h"

typedef struct node {
    int length;
    tVar* variables;
    bool value;
    // TODO pridat info v ktorom bundli je, pre kontrolu duplicit
} tNode;

extern void* 	createNode();
extern void* 	createNodeWithVariables(tVar[], int);
extern int	 	addVariableToNode(tVar, tNode*);
extern int 		addVariablesToNode(tVar[], int, tNode*);
extern int		deleteVariableFromNode(char*, tNode*);
extern void 	printNode(tNode*);
extern void 	freeNode(tNode*);

#endif //CODE_NODE_H