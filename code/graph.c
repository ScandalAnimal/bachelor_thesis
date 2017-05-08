/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <string.h>
#include "graph.h"

void printInitGraphSequence(FILE* file) {
    
    fprintf(file, "digraph G {\nnodesep=.05;\nrankdir=LR;\nnode [shape=record,width=.1,height=.1];\nnode [width = 1.5];\n");
}

void printEndGraphSequence(FILE* file) {

    fprintf(file, "}\n");
}

void printSingleRootNode(FILE* file, char* rootName) {

    fprintf(file, "node0 [label = \"<n0> %s\",height=2.5];\n", rootName);
}

void printMultipleRootNodes(FILE* file, int nodeCount) {

    fprintf(file, "node0 [label = \"");

    int size = 7 * (nodeCount + 1) * getDigitCount(nodeCount); 
    char rootNode[size];
    strcpy(rootNode, "");
    
    for (int i = 0; i < nodeCount; i++) {

        char buffer[10];
        snprintf(buffer, 10, "%d", i);
        
        strcat(rootNode, "<n");
        strcat(rootNode, buffer);
        strcat(rootNode, "> ");
        strcat(rootNode, buffer);
        if (i != nodeCount - 1) {
            strcat(rootNode, " | ");
        }
    }
    fprintf(file, "%s", rootNode);
    fprintf(file, "\",height=2.5];\n");

}

void printArrow(FILE* file, int leftSideNodeNumber, int leftSideNodePort, int rightSideNodeNumber) {
    
    int bufferSize = getDigitCount(leftSideNodeNumber) + 2;
    if (getDigitCount(leftSideNodePort) > bufferSize) {
        bufferSize = getDigitCount(leftSideNodePort) + 2;
    }

    int size = 20 + getDigitCount(leftSideNodeNumber) + 
                    getDigitCount(leftSideNodePort) + 
                    getDigitCount(rightSideNodeNumber) + 2;
    char output[size];
    strcpy(output, "");

    char buffer[bufferSize];
    strcpy(buffer, "");

    strcat(output, "node");
    snprintf(buffer, bufferSize, "%d", leftSideNodeNumber);
    strcat(output, buffer);    
    strcat(output, ":n");
    if (leftSideNodePort >= 0) {
        snprintf(buffer, bufferSize, "%d", leftSideNodePort);
        strcat(output, buffer);
    }
    strcat(output, " -> node");
    snprintf(buffer, bufferSize, "%d", rightSideNodeNumber);
    strcat(output, buffer);
    strcat(output, ":n;\n");

    fprintf(file, "%s", output);
}

void printNodeWithValue(FILE* file, int nodeNumber, const char* key, bool value) {

    int bufferSize = getDigitCount(nodeNumber) + 2;

    int size = 37 + getDigitCount(nodeNumber) + 2;

    char output[size];
    strcpy(output, "");

    char buffer[bufferSize];
    strcpy(buffer, "");

    snprintf(buffer, bufferSize, "%d", nodeNumber);
    strcat(output, "node");
    strcat(output, buffer);
    strcat(output, "[label = \"{ <n> ");
    strcat(output, key);
    strcat(output, " | ");
    value ? strcat(output, "true") : strcat(output, "false");
    strcat(output, "}\"];");

    fprintf(file, "%s\n", output);
}

void printNodeWithoutValue(FILE* file, int nodeNumber, char* key) {

    int bufferSize = getDigitCount(nodeNumber) + 2;

    int size = 29 + getDigitCount(nodeNumber) + 2;

    char output[size];
    strcpy(output, "");

    char buffer[bufferSize];
    strcpy(buffer, "");

    snprintf(buffer, bufferSize, "%d", nodeNumber);
    strcat(output, "node");
    strcat(output, buffer);
    strcat(output, "[label = \"{ <n> ");
    strcat(output, key);
    strcat(output, "}\"];");

    fprintf(file, "%s\n", output);
}

int printAnonymousNodes(FILE* file, int nodeCount, int nodeInitNumber, char* prefix, int arrowLeftSidePort) {

    int count = nodeInitNumber;
    for (int i = 0; i < nodeCount; i++) {

        int nodeNameSize = 6 + getDigitCount(count); 
        char nodeName[nodeNameSize];
        snprintf(nodeName, nodeNameSize, "%s %d", prefix, count);

        printNodeWithoutValue(file, count, nodeName);
        printArrow(file, 0, arrowLeftSidePort, count);

        count++;
    }
    return count;
}