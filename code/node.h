/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <stdbool.h>

typedef struct node {
    int length;
    char* variables[10];
} node;

extern node createNode();
extern node createNodeWithVariables(char**, int);
extern void addVariableToNode(char*, node*);
extern void printNode(node);

#endif //CODE_NODE_H