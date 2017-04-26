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
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    node->length = 0;
    if (!(node->variables = malloc(sizeof(node->variables)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        free(node);
        return NULL;
    }
    node->value = false;
    return node;
}


int addVariableToNode(tVar variable, tNode* node) {

    int length = node->length;

    for (int i = 0; i < length; i++) {
        if (strcmp(node->variables[i].name, variable.name) == 0) {
            printf("%s %s\n", node->variables[i].name, variable.name);
            return ERR_DUPLICATE;
        }
    }

    if (!(node->variables = realloc(node->variables, sizeof(tVar) * (length+1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return ERR_MALLOC;
    }

    node->variables[length] = variable;

    if ((length != 0) && node->value == false) {
        node->length++;
        return OK;
    }
    setNodeValue(node, variable.value);
    node->length++;
    return OK;
}

int addVariablesToNode(tVar variables[], int size, tNode* node) {

    for (int i = 0; i < size; i++) {
        int addResult = addVariableToNode(variables[i], node);
        if (addResult != OK) {
            printf("%d %d\n", i, addResult);
            return addResult;
        }
    }
    return OK;
}


void* createNodeWithVariables(tVar variables[], int size) {

    tNode* node = createNode();
    if (node == NULL) {
        return NULL;
    }

    if (addVariablesToNode(variables, size, node) != OK) {
        freeNode(node);
        return NULL;
    }    
    return node;
}

int deleteVariableFromNode(char* varName, tNode* node) {

    bool found = false;
    for (int i = 0; i < node->length; i++) {
        if (strcmp(node->variables[i].name, varName) == 0) {
            found = true;

            for (int p = i; p < node->length - 1; p++) {
                node->variables[p] = node->variables[p+1];
            }
            node->length--;
        }
    }
    if (!found) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    }
    else {
        for (int i = 0; i < node->length; i++) {
            bool value = node->variables[i].value;
            if (i == 0) {
                node->value = value;
            }
            else {
                if (node->value == false) {
                    break;
                }
                node->value &= value;
            }
        }
    }
    return OK;
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
