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
    free(bundle->anfs);
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

    bundle->anfs = malloc(sizeof(tAnf *));
    bundle->anfsCount = 0;

    // bundle->maxVarLength = maxVarLength;

    return bundle;
}

void* createNodeInBundle(tANFBundle* bundle) {

    tNode* node = createNode();

    bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1));

    bundle->nodes[bundle->nodeCount] = node;
    // bundle->nodes[bundle->nodeCount]->variables = node->variables;
    bundle->nodeCount++;    

    return node;
}

void* createNodeWithVarsInBundle(tANFBundle* bundle, tVar variables[], int length) {

    tNode* node = createNode();

    tVar* varsWithoutDuplicity;
    if (!(varsWithoutDuplicity = (tVar*) malloc(sizeof(tVar) * length))) {
        return NULL;
    }

    bool found = false;
    int insertedVars = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < insertedVars; j++) {
            if (strcmp(variables[i].name, varsWithoutDuplicity[j].name) == 0) {
                found = true;
            }
        }
        if (found) {
            found = false;
        }
        else {
            varsWithoutDuplicity[insertedVars] = variables[i];
            insertedVars++;
        }
    }

    addVariablesToNode(varsWithoutDuplicity, insertedVars, node);
    addVarsToBundle(bundle, varsWithoutDuplicity, insertedVars);

    bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1));

    bundle->nodes[bundle->nodeCount] = node;
    bundle->nodeCount++;    

    free(varsWithoutDuplicity);
    return node;
}


tVar createVarInBundle(tANFBundle* bundle, char* name, bool value) {

    tVar var = createVar(name, value);

    insertToHashMap(bundle->hashmap, var.name, var.value);
    return var;
}

void addVarsToBundle(tANFBundle* bundle, tVar variables[], int length) {

    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        insertToHashMap(bundle->hashmap, var.name, var.value);
    } 
}

void* createAnf() {

    tAnf* anf;
    if (!(anf = (tAnf*) malloc(sizeof(tAnf)))) {
        return NULL;
    }

    anf->length = 0;
    anf->nodes = malloc(sizeof(anf->nodes));
    return anf;
}

void addNodesToAnf(tNode* nodes[], int size, tAnf* anf) {

    int length = anf->length;    

    anf->nodes = realloc(anf->nodes, sizeof(tNode*) * (length + size));

    for (int i = 0; i < size; i++) {
        anf->nodes[length + i] = nodes[i];
        anf->nodes[length + i]->length = nodes[i]->length;
        anf->length++;
    }

}

void* createAnfWithNodesInBundle(tANFBundle* bundle, tNode* nodes[], int size) {

    tAnf* anf = createAnf();

    addNodesToAnf(nodes, size, anf);

    bundle->anfs = realloc(bundle->anfs, sizeof(tAnf *) * (bundle->anfsCount + 1));

    bundle->anfs[bundle->anfsCount] = anf;
    bundle->anfsCount++;    

    return anf;
}

// void addNodeToAnf(node node, anf* anf) {

//     int length = anf->length;

//     anf->nodes[length] = node;
//     anf->length++;
// }

void freeAnf(tAnf* anf) {
    free(anf->nodes);
    free(anf);
}

void iterateOverBundle(tANFBundle* bundle) {

    for (int i = 0; i < bundle->anfsCount; i++) {
        tAnf* anf = bundle->anfs[i];
        printf("********************************\nANF No: %d\n", i);
        for (int j = 0; j < anf->length; j++) {
            printf(" @ Node No: %d\n -- ", j);
            for (int k = 0; k < anf->nodes[j]->length; k++) {
                char* varName = anf->nodes[j]->variables[k];
                printf("%s:%d ", varName, getVarValue(bundle->hashmap, varName));
            }
            printf("\n");
        }
        printf("********************************\n");
    }
}

void printAnf(tAnf* anf) {

    printf("********************************\nANF:\n @ ");
    for (int i = 0; i < anf->length; i++) {
        for (int j = 0; j < anf->nodes[i]->length; j++) {
        
            printf("%s",anf->nodes[i]->variables[j]);
            if (anf->nodes[i]->length - j > 1) {
                printf(" & ");
            }
        }
        if (anf->length - i > 1) {
            printf(" XOR \n @ ");
        }
    }

    printf("\n********************************\n");
}

void printBundle(tANFBundle* bundle) {

    printf("*******************\n");
    printf("Node Count:     %d\n", bundle->nodeCount);
    printf("Anfs Count:     %d\n", bundle->anfsCount);
    printf("Variable Count: %d\n", bundle->hashmap->usedCapacity);
    // printf("Max Var Length: %d\n", bundle->maxVarLength);
    printf("*******************\n");
}

void printBundleMap(tANFBundle* bundle) {
    printHashMap(bundle->hashmap);
}

