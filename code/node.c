/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include "node.h"

node createNode() {

    node node;
    node.length = 0;
    return node;
}

node createNodeWithVariables(char* variables[], int size) {

    node node;
    node.length = 0;

    for (int i = 0; i < size; i++) {
        node.variables[i] = variables[i];
        node.length++;
    }
    return node;
}

void addVariableToNode(char* identifier, node* node) {

    int length = node->length;

    node->variables[length] = identifier;
    node->length++;
}

void printNode(node node) {

    printf("********************************\nUzol:\n | ");
    for (int i = 0; i < node.length; i++) {
        printf("%s",node.variables[i]);
        if (node.length - i > 1) {
            printf(" & ");
        }
        // printf("\n");
    }
    printf("\n");

    // printf("Pocet premennych: %d\n", node.length);
    printf("********************************\n");
}
