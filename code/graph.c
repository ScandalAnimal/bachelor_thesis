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

    fprintf(file, "node0 [label = \"<f0> %s\",height=2.5];\n", rootName);
}

void printMultipleRootNodes(FILE* file, int nodeCount) {

    fprintf(file, "node0 [label = \"");

    int size = 7 * (nodeCount + 1) * getDigitCount(nodeCount); 
    char rootNode[size];
    strcpy(rootNode, "");
    
    for (int i = 0; i < nodeCount; i++) {

        char buffer[10];
        snprintf(buffer, 10, "%d", i);
        
        strcat(rootNode, "<f");
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