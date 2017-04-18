/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anf.h"

// void setAnfValue(tAnf* anf, bool value) {
//     if (anf->length == 0) {
//         anf->value = value;
//     }
//     else {
//         anf->value ^= value;
//     }
// }

void freeANFBundle(tANFBundle* bundle) {
    freeHashMap(bundle->hashmap);
    free(bundle->anfs);
    free(bundle->nodes);
    free(bundle);
}

void* createANFBundle(unsigned int mapInitCapacity, double mapLoadFactor) {

    tANFBundle* bundle;
    if (!(bundle = (tANFBundle*) malloc(sizeof(tANFBundle)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    bundle->hashmap = createHashMap(mapInitCapacity, mapLoadFactor);    
    if (bundle->hashmap == NULL) {
        return NULL;
    }

    if (!(bundle->nodes = malloc(sizeof(tNode *)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    };

    if (!(bundle->anfs = malloc(sizeof(tAnf *)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    };    

    bundle->nodeCount = 0;
    bundle->anfsCount = 0;

    return bundle;
}

void freeAnf(tAnf* anf) {
    free(anf->nodes);
    free(anf);
}

// void* createNodeInBundle(tANFBundle* bundle) {

//     tNode* node = createNode();

//     if (!(bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     }

//     bundle->nodes[bundle->nodeCount] = node;
//     bundle->nodeCount++;    

//     return node;
// }

// void* createNodeWithVarsInBundle(tANFBundle* bundle, tVar variables[], int length) {

//     tNode* node = createNode();

//     if (node == NULL) {
//         return NULL;
//     }

//     tVar* varsWithoutDuplicity;
//     if (!(varsWithoutDuplicity = (tVar*) malloc(sizeof(tVar) * length))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     }

//     bool found = false;
//     int insertedVars = 0;
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < insertedVars; j++) {
//             if (strcmp(variables[i].name, varsWithoutDuplicity[j].name) == 0) {
//                 found = true;
//             }
//         }
//         if (found) {
//             found = false;
//         }
//         else {
//             varsWithoutDuplicity[insertedVars] = variables[i];
//             insertedVars++;
//         }
//     }

//     addVariablesToNode(varsWithoutDuplicity, insertedVars, node);
//     createVarsInBundle(bundle, varsWithoutDuplicity, insertedVars);

//     if (!(bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     }

//     bundle->nodes[bundle->nodeCount] = node;
//     bundle->nodeCount++;    

//     free(varsWithoutDuplicity);
//     return node;
// }

// tVar createVarInBundle(tANFBundle* bundle, char* name, bool value) {

//     tVar var = createVar(name, value);

//     if (!isKeyInHashMap(bundle->hashmap, name)) {
//         if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
//            fprintf(stderr, "%d\n", ERR_INSERT);        
//         }
//     }
//     else {
//        fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
//     }

//     return var;
// }

// tVar createTrueVarInBundle(tANFBundle* bundle, char* name) {

//     tVar var = createTrueVar(name);

//     if (!isKeyInHashMap(bundle->hashmap, name)) {
//         if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
//            fprintf(stderr, "%d\n", ERR_INSERT);        
//         }
//     }
//     else {
//        fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
//     }

//     return var;
// }

// tVar createFalseVarInBundle(tANFBundle* bundle, char* name) {

//     tVar var = createFalseVar(name);

//     if (!isKeyInHashMap(bundle->hashmap, name)) {
//         if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
//            fprintf(stderr, "%d\n", ERR_INSERT);        
//         }
//     }
//     else {
//        fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
//     }

//     return var;
// }

// void createVarsInBundle(tANFBundle* bundle, tVar variables[], int length) {

//     for (int i = 0; i < length; i++) {
//         tVar var = variables[i];
//         if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
//             fprintf(stderr, "%d\n", ERR_INSERT);        
//         }
//     } 
// }

void* createEmptyAnf() {

    tAnf* anf;
    if (!(anf = (tAnf*) malloc(sizeof(tAnf)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);        
        return NULL;
    }

    anf->length = 0;
    if (!(anf->nodes = malloc(sizeof(anf->nodes)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        free(anf);
        return NULL;        
    }
    anf->value = false;
    return anf;
}

int addAnfToBundle(tANFBundle* bundle, tAnf* anf) {

    if (!(bundle->anfs = realloc(bundle->anfs, sizeof(tAnf*) * (bundle->anfsCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return ERR_MALLOC;
    }

    bundle->anfs[bundle->anfsCount] = anf;
    bundle->anfsCount++; 
    return OK;   
}

void* createEmptyAnfInBundle(tANFBundle* bundle) {

    tAnf* anf = createEmptyAnf();
    if (anf == NULL) {
        return NULL;
    }

    if (addAnfToBundle(bundle, anf) == OK) {
        return anf;
    }
    else {
        freeAnf(anf);
        return NULL;
    }
}


// void addNodeToAnf(tNode* node, tAnf* anf) {

//     int length = anf->length;    

//     anf->nodes = realloc(anf->nodes, sizeof(tNode*) * (length + 1));

//     anf->nodes[anf->length] = node;
//     anf->length++;
//     setAnfValue(anf, node->value);
// }

// void addNodesToAnf(tNode* nodes[], int size, tAnf* anf) {

//     for (int i = 0; i < size; i++) {
//         addNodeToAnf(nodes[i], anf);
//     }

// }

// void* createAnfWithNodesInBundle(tANFBundle* bundle, tNode* nodes[], int size) {

//     tAnf* anf = createAnf();

//     if (anf == NULL) {
//         return NULL;
//     }

//     addNodesToAnf(nodes, size, anf);

//     if (!(bundle->anfs = realloc(bundle->anfs, sizeof(tAnf *) * (bundle->anfsCount + 1)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     }

//     bundle->anfs[bundle->anfsCount] = anf;
//     bundle->anfsCount++;    

//     return anf;
// }

// void deleteAnfFromBundle(tANFBundle* bundle, tAnf* anf) {

//     bool found = false;
//     for (int i = 0; i < bundle->anfsCount; i++) {
//         if (anf == bundle->anfs[i]) {
//             found = true;

//             for (int p = i; p < bundle->anfsCount; p++) {
//                 bundle->anfs[p] = bundle->anfs[p+1];
//             }
//             bundle->anfsCount--;
//         }
//     }
//     if (!found) {
//         fprintf(stderr, "%d\n", ERR_DELETE);
//     }
// }

// void deleteNodeFromBundle(tANFBundle* bundle, tNode* node) {

//     bool isInAnf = false;
//     for (int i = 0; i < bundle->anfsCount; i++) {
//         for (int j = 0; j < bundle->anfs[i]->length; j++) {
//             if (node == bundle->anfs[i]->nodes[j]) {
//                 isInAnf = true;
//             }
//         }
//     }

//     if (isInAnf) {
//         fprintf(stderr, "%d\n", ERR_INANF);
//         return;
//     }

//     bool found = false;
//     for (int i = 0; i < bundle->nodeCount; i++) {
//         if (node == bundle->nodes[i]) {
//             found = true;

//             for (int p = i; p < bundle->nodeCount; p++) {
//                 bundle->nodes[p] = bundle->nodes[p+1];
//             }
//             bundle->nodeCount--;
//         }
//     }
//     if (!found) {
//         fprintf(stderr, "%d\n", ERR_DELETE);
//     }
// }


// void iterateOverBundle(tANFBundle* bundle) {

//     for (int i = 0; i < bundle->anfsCount; i++) {
//         tAnf* anf = bundle->anfs[i];
//         printf("********************************\nANF No: %d\n", i);
//         for (int j = 0; j < anf->length; j++) {
//             printf(" @ Node No: %d\n -- ", j);
//             for (int k = 0; k < anf->nodes[j]->length; k++) {
//                 char* varName = anf->nodes[j]->variables[k].name;
//                 printf("%s:%d ", varName, selectFromHashMap(bundle->hashmap, varName)->value);
//             }
//             printf("\n");
//         }
//         printf("********************************\n");
//     }
// }

void printAnf(tAnf* anf) {

    printf("********************************\nANF:\n @ ");
    for (int i = 0; i < anf->length; i++) {
        for (int j = 0; j < anf->nodes[i]->length; j++) {
        
            printf("%s",anf->nodes[i]->variables[j].name);
            if (anf->nodes[i]->length - j > 1) {
                printf(" & ");
            }
        }
        if (anf->length - i > 1) {
            printf(" XOR \n @ ");
        }
    }
    printf("\n * Anf value: ");
    fputs(anf->value ? "true\n" : "false\n", stdout);
    printf("********************************\n");
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
    