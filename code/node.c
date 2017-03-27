/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void setNodeValue(tNode* node, bool value) {
    if (node->length == 0) {
        node->value = value;
    }
    else {
        if (node->value == false) {
           return;
        }
        node->value &= value;
    }
}

void* createNode() {

    tNode* node;

    if (!(node = (tNode*) malloc(sizeof(tNode)))) {
        fprintf(stderr, "%s\n", ERR_MALLOC);
        return NULL;
    }

    node->length = 0;
    if (!(node->variables = malloc(sizeof(node->variables)))) {
        fprintf(stderr, "%s\n", ERR_MALLOC);
        free(node);
        return NULL;
    }
    node->value = false;
    return node;
}

// // node createNodeWithVariables(char* variables[], int size, bool values[], void* m) {

// //     tHashMap* map = (tHashMap*) m;

// //     node node;
// //     node.variables = malloc(sizeof(char *) * size);

// //     node.length = 0;

// //     for (int i = 0; i < size; i++) {
// //         node.variables[i] = variables[i];
// //         insertToHashMap(map, variables[i], values[i]);
// //         node.length++;
// //     }
// //     return node;
// // }

void addVariableToNode(tVar variable, tNode* node) {

    int length = node->length;

    for (int i = 0; i < length; i++) {
        if (strcmp(node->variables[i].name, variable.name) == 0) {
            return;
        }
    }

    node->variables = realloc(node->variables, sizeof(tVar) * (length+1));

    node->variables[length] = variable;

    setNodeValue(node, variable.value);
    node->length++;
}

void addVariablesToNode(tVar variables[], int size, tNode* node) {

    for (int i = 0; i < size; i++) {
        if ((node->length != 0) && node->value == false) {
            break;
        }
        addVariableToNode(variables[i], node);
    }
}

void freeNode(tNode* node) {
    free(node->variables);
    free(node);
}

void printNode(tNode* node) {

    printf("********************************\nUzol:\n | ");
    for (int i = 0; i < node->length; i++) {
        tVar variable = node->variables[i];
        printf("%s:%d", variable.name, variable.value);
        if (node->length - i > 1) {
            printf(" & ");
        }
    }
    printf("\n * Node value: ");
    fputs(node->value ? "true\n" : "false\n", stdout);
    printf("********************************\n");
}
