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
	const char** variables;
    int varCount;
    bool value;
} tNode;

void* 	newNode();
int	 	addVariableToNode(tVar, tNode*);
int 	addVariablesToNode(tVar[], int, tNode*);
int		deleteVariableFromNode(const char*, tNode*);
void 	printNode(tNode*);
void 	freeNode(tNode*);

#endif //CODE_NODE_H