/** 
 * @file
 * @brief functions for manipulating with node
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anfnode.h"

/**
 * fix node value
 * @param node node to fix value
 * @param value value to set
 */
void setNodeValue(tNode* node, bool value) {
    if (node->varCount == 0) {
        node->value = value;
    }
    else {
        if (node->value == false) {
           return;
        }
        node->value &= value;
    }
}

void* newNode() {

    tNode* node;

    if (!(node = (tNode*) malloc(sizeof(tNode)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    if (!(node->variables = malloc(sizeof(char*)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    node->varCount = 0;
    node->value = false;
    return node;
}


int addVariableToNode(tVar variable, tNode* node) {

    for (int i = 0; i < node->varCount; i++) {
        if (strcmp(node->variables[i], variable.name) == 0) {
            return ERR_DUPLICATE;
        }
    }

    if (!(node->variables = realloc(node->variables, sizeof(char *) * (node->varCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return ERR_MALLOC;
    }

    node->variables[node->varCount] = variable.name;
    setNodeValue(node, variable.value);

    node->varCount++;
    return OK;
}

int addVariablesToNode(tVar variables[], int size, tNode* node) {

    for (int i = 0; i < size; i++) {
        int addResult = addVariableToNode(variables[i], node);
        if (addResult != OK) {
            return addResult;
        }
    }
    return OK;
}

int deleteVariableFromNode(const char* varName, tNode* node) {

    bool found = false;
    for (int i = 0; i < node->varCount; i++) {
        if (strcmp(node->variables[i], varName) == 0) {
            found = true;

            for (int p = i; p < node->varCount - 1; p++) {
                node->variables[p] = node->variables[p+1];
            }
            node->varCount--;
        }
    }
    if (!found) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    }

    return OK;
}

void freeNode(tNode* node) {
    free(node->variables);
    free(node);
}

void printNode(tNode* node) {

    printf("********************************\nNode:\n | ");
    for (int i = 0; i < node->varCount; i++) {
        const char* variable = node->variables[i];
        printf("%s", variable);
        if (node->varCount - i > 1) {
            printf(" & ");
        }
    }
    printf("\n * Node value: ");
    fputs(node->value ? "true\n" : "false\n", stdout);
    printf("********************************\n");
}
