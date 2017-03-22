/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anf.h"

void freeANFBundle(tANFBundle* bundle) {
    freeHashMap(bundle->hashmap);
    // printf("Node Count: %d\n", bundle->nodeCount);
    // for (int i = 0; i < bundle->nodeCount; i++) {
        // for (int j = 0; j < bundle->nodes[i]->length; j++) {
            // printf("--- %s\n", bundle->nodes[i]->variables[j]);
        // }
        // free(bundle->nodes[i]->variables);
    // }
    // printf("Vars Count: %d\n", bundle->varsCount);
    // for (int i = 0; i < bundle->varsCount; i++) {
        // printf("%s\n", bundle->vars[i]->name);
        // free(bundle->vars[i]->name);
    // }
    // free(bundle->vars);
    free(bundle->nodes);
    free(bundle);
}

void* createANFBundle(unsigned int mapInitCapacity, double mapLoadFactor, unsigned int maxVarLength) {

    tANFBundle* bundle;
    if (!(bundle = (tANFBundle*) malloc(sizeof(tANFBundle)))) {
        return NULL;
    }

    bundle->hashmap = createHashMap(mapInitCapacity, mapLoadFactor);    

    bundle->nodes = malloc(sizeof(tNode *));
    bundle->nodeCount = 0;

    // bundle->vars = malloc(sizeof(tVar *));
    // bundle->varsCount = 0;

    // bundle->maxVarLength = maxVarLength;

    return bundle;
}

void* createNodeInBundle(tANFBundle* bundle) {

    tNode* node = createNode();

    bundle->nodes[bundle->nodeCount] = node;
    // bundle->nodes[bundle->nodeCount]->variables = node->variables;
    bundle->nodeCount++;    

    return node;
}

tVar createVarInBundle(tANFBundle* bundle, char* name, bool value) {

    tVar var = createVar(name, value);

    insertToHashMap(bundle->hashmap, var.name, var.value);
    return var;
}


// anf createAnf() {

//     anf anf;
//     anf.length = 0;
//     return anf;
// }

// anf createAnfWithNodes(node nodes[], int size) {

//     anf anf;
//     anf.length = 0;

//     for (int i = 0; i < size; i++) {
//         anf.nodes[i] = nodes[i];
//         anf.length++;
//     }
//     return anf;
// }

// void addNodeToAnf(node node, anf* anf) {

//     int length = anf->length;

//     anf->nodes[length] = node;
//     anf->length++;
// }

// void printAnf(anf anf) {

//     printf("********************************\nANF:\n @ ");
//     for (int i = 0; i < anf.length; i++) {
//         for (int j = 0; j < anf.nodes[i].length; j++) {
        
//             printf("%s",anf.nodes[i].variables[j]);
//             if (anf.nodes[i].length - j > 1) {
//                 printf(" & ");
//             }
//             // printf("\n");
//         }
//         if (anf.length - i > 1) {
//             printf(" XOR \n @ ");
//         }
//     }
//     // printf("\n");

//     printf("\nPocet uzlov: %d\n", anf.length);
//     printf("********************************\n");
// }

void printBundle(tANFBundle* bundle) {

    printf("*******************\n");
    printf("Node Count:     %d\n", bundle->nodeCount);
    printf("Variable Count: %d\n", bundle->hashmap->usedCapacity);
    printf("Max Var Length: %d\n", bundle->maxVarLength);
    printf("*******************\n");
}

void printBundleMap(tANFBundle* bundle) {
    printHashMap(bundle->hashmap);
}

