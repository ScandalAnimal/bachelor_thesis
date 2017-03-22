/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void* createNode() {

    tNode* node;

    if (!(node = (tNode*) malloc(sizeof(tNode)))) {
        return NULL;
    }

    node->length = 0;
    node->variables = malloc(sizeof(node->variables));
    return node;
}

// node createNodeWithVariables(char* variables[], int size, bool values[], void* m) {

//     tHashMap* map = (tHashMap*) m;

//     node node;
//     node.variables = malloc(sizeof(char *) * size);

//     node.length = 0;

//     for (int i = 0; i < size; i++) {
//         node.variables[i] = variables[i];
//         insertToHashMap(map, variables[i], values[i]);
//         node.length++;
//     }
//     return node;
// }

void addVariableToNode(char* identifier, tNode* node) {

    int length = node->length;

    node->variables = realloc(node->variables, sizeof(char *) * (length+1));

    node->variables[length] = identifier;
    node->length++;
}

void addVariablesToNode(tVar variables[], int size, tNode* node) {

    int length = node->length;

    node->variables = realloc(node->variables, sizeof(char *) * (length + size));

    for (int i = 0; i < size; i++) {
        node->variables[length + i] = variables[i].name;
        node->length++;
    }
}

void freeNode(tNode* node) {
    free(node->variables);
    free(node);
}

void printNode(tNode* node) {

    printf("********************************\nUzol:\n | ");
    for (int i = 0; i < node->length; i++) {
        printf("%s",node->variables[i]);
        if (node->length - i > 1) {
            printf(" & ");
        }
    }
    printf("\n");

    printf("********************************\n");
}
