/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anf.h"

void setAnfValue(tAnf* anf, bool value) {
    if (anf->nodeCount == 0) {
        anf->value = value;
    }
    else {
        anf->value ^= value;
    }
}

// void freeANFBundle(tANFBundle* bundle) {
//     freeHashMap(bundle->hashmap);
//     free(bundle->anfs);
//     free(bundle->nodes);
//     free(bundle);
// }

// void* createANFBundle(unsigned int mapInitCapacity, double mapLoadFactor) {

//     tANFBundle* bundle;
//     if (!(bundle = (tANFBundle*) malloc(sizeof(tANFBundle)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     }

//     bundle->hashmap = createHashMap(mapInitCapacity, mapLoadFactor);    
//     if (bundle->hashmap == NULL) {
//         return NULL;
//     }

//     if (!(bundle->nodes = malloc(sizeof(tNode *)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     };

//     if (!(bundle->anfs = malloc(sizeof(tAnf *)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return NULL;
//     };    

//     bundle->nodeCount = 0;
//     bundle->anfsCount = 0;

//     return bundle;
// }

void freeAnf(tAnf* anf) {
    free(anf->nodeList);
    freeHashMap(anf->hashMap);
    free(anf);
}

void* newNodeInAnf(tAnf* anf) {

    tNode* node = newNode();
    if (node == NULL) {
        return NULL;
    }

    if (!(anf->nodeList = realloc(anf->nodeList, sizeof(tNode *) * (anf->nodeCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    anf->nodeList[anf->nodeCount] = node;
    setAnfValue(anf, node->value); 

    anf->nodeCount++;   

    return node;
}

void* newNodeWithVarsInAnf(tAnf* anf, tVar variables[], int varCount) {

    tNode* node = newNode();
    if (node == NULL) {
        return NULL;
    }

    tVar* varsWithoutDuplicity;
    if (!(varsWithoutDuplicity = (tVar*) malloc(sizeof(tVar) * varCount))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    bool found = false;
    int insertedVars = 0;
    for (int i = 0; i < varCount; i++) {
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

    if (addVariablesToNode(varsWithoutDuplicity, insertedVars, node) != OK) {
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    if (createVarsInAnf(anf, varsWithoutDuplicity, insertedVars) != OK) {
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    if (!(anf->nodeList = realloc(anf->nodeList, sizeof(tNode *) * (anf->nodeCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    anf->nodeList[anf->nodeCount] = node;
    setAnfValue(anf, node->value);

    anf->nodeCount++;    
    free(varsWithoutDuplicity);
    return node;
}

tVar createVarInAnf(tAnf* anf, char* name, bool value) {

    tVar var = createVar(name, value);

    if (!isKeyInHashMap(anf->hashMap, name)) {
        if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

tVar createTrueVarInAnf(tAnf* anf, char* name) {

    tVar var = createTrueVar(name);

    if (!isKeyInHashMap(anf->hashMap, name)) {
        if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

tVar createFalseVarInAnf(tAnf* anf, char* name) {

    tVar var = createFalseVar(name);

    if (!isKeyInHashMap(anf->hashMap, name)) {
        if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

int createVarsInAnf(tAnf* anf, tVar variables[], int length) {

    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        if (!isKeyInHashMap(anf->hashMap, var.name)) {
            if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
               fprintf(stderr, "%d\n", ERR_INSERT);        
            }
        }
        else {
           fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, var.name);        
        }
    } 
    return OK;
}

void* newAnf(int mapInitCapacity, double mapLoadFactor) {

    tAnf* anf;
    if (!(anf = (tAnf*) malloc(sizeof(tAnf)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);        
        return NULL;
    }

    anf->hashMap = createHashMap(mapInitCapacity, mapLoadFactor);    
    if (anf->hashMap == NULL) {
        return NULL;
    }

    anf->nodeCount = 0;
    if (!(anf->nodeList = malloc(sizeof(anf->nodeList)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        free(anf);
        return NULL;        
    }
    anf->value = false;
    return anf;
}

// int addAnfToBundle(tANFBundle* bundle, tAnf* anf) {

//     if (!(bundle->anfs = realloc(bundle->anfs, sizeof(tAnf*) * (bundle->anfsCount + 1)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         return ERR_MALLOC;
//     }

//     bundle->anfs[bundle->anfsCount] = anf;
//     bundle->anfsCount++; 
//     return OK;   
// }

// void* createEmptyAnfInBundle(tANFBundle* bundle) {

//     tAnf* anf = createEmptyAnf();
//     if (anf == NULL) {
//         return NULL;
//     }

//     if (addAnfToBundle(bundle, anf) == OK) {
//         return anf;
//     }
//     else {
//         freeAnf(anf);
//         return NULL;
//     }
// }


// int addNodeToAnf(tANFBundle* bundle, tNode* node, tAnf* anf) {

//     int length = anf->length;    

//     anf->nodes = realloc(anf->nodes, sizeof(tNode*) * (length + 1));
//     if (anf->nodes == NULL) {
//         return ERROR;
//     }

//     for (int i = 0; i < node->length; i++) {
//         if (!isKeyInHashMap(bundle->hashmap, node->variables[i].name)) {
//             if (ERROR == insertToHashMap(bundle->hashmap, node->variables[i].name, node->variables[i].value)) {
//                 fprintf(stderr, "%d\n", ERR_INSERT);        
//             }
//         }
//     }

//     anf->nodes[anf->length] = node;
//     anf->length++;
//     setAnfValue(anf, node->value);
//     return OK;
// }

// int addNodesToAnf(tANFBundle* bundle, tNode* nodes[], int size, tAnf* anf) {

//     for (int i = 0; i < size; i++) {
//         int addResult = addNodeToAnf(bundle, nodes[i], anf);
//         if (addResult != OK) {
//             return addResult;
//         }
//     }

//     return OK;
// }

// void* createAnfWithNodesInBundle(tANFBundle* bundle, tNode* nodes[], int size) {

//     tAnf* anf = createEmptyAnf();

//     if (anf == NULL) {
//         return NULL;
//     }

//     if (addNodesToAnf(bundle, nodes, size, anf) != OK) {
//         freeAnf(anf);
//         return NULL;
//     }

//     for (int i = 0; i < size; i++) {
//         if (createVarsInBundle(bundle, nodes[i]->variables, nodes[i]->length) != OK) {
//             freeAnf(anf);
//             return NULL;
//         }
//     }

//     if (!(bundle->anfs = realloc(bundle->anfs, sizeof(tAnf *) * (bundle->anfsCount + 1)))) {
//         fprintf(stderr, "%d\n", ERR_MALLOC);
//         freeAnf(anf);
//         return NULL;
//     }

//     bundle->anfs[bundle->anfsCount] = anf;
//     bundle->anfsCount++;    

//     return anf;
// }

// int deleteAnfFromBundle(tANFBundle* bundle, tAnf* anf) {

//     bool found = false;
//     for (int i = 0; i < bundle->anfsCount; i++) {
//         if (anf == bundle->anfs[i]) {
//             found = true;

//             for (int p = i; p < bundle->anfsCount - 1; p++) {
//                 bundle->anfs[p] = bundle->anfs[p+1];
//             }
//             bundle->anfsCount--;
//         }
//     }
//     if (!found) {
//         fprintf(stderr, "%d\n", ERR_DELETE);
//         return ERR_DELETE;
//     }
//     return OK;
// }

int deleteNodeFromAnf(tAnf* anf, tNode* node) {

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
//         return ERR_INANF;
//     }

    bool found = false;
    for (int i = 0; i < anf->nodeCount; i++) {
        if (node == anf->nodeList[i]) {
            found = true;

            for (int p = i; p < anf->nodeCount - 1; p++) {
                anf->nodeList[p] = anf->nodeList[p+1];
            }
            anf->nodeCount--;
        }
    }
    if (!found) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    }

    anf->value = false;
    int originalNodeCount = anf->nodeCount;
    anf->nodeCount = 0;
    for (int i = 0; i < originalNodeCount; i++) {
        setAnfValue(anf, anf->nodeList[i]->value);
        anf->nodeCount++;
    }
    return OK;
}


// // void iterateOverBundle(tANFBundle* bundle) {

// //     for (int i = 0; i < bundle->anfsCount; i++) {
// //         tAnf* anf = bundle->anfs[i];
// //         printf("********************************\nANF No: %d\n", i);
// //         for (int j = 0; j < anf->length; j++) {
// //             printf(" @ Node No: %d\n -- ", j);
// //             for (int k = 0; k < anf->nodes[j]->length; k++) {
// //                 char* varName = anf->nodes[j]->variables[k].name;
// //                 printf("%s:%d ", varName, selectFromHashMap(bundle->hashmap, varName)->value);
// //             }
// //             printf("\n");
// //         }
// //         printf("********************************\n");
// //     }
// // }

void printAnf(tAnf* anf) {

    printf("********************************\nANF:\n @ ");
    for (int i = 0; i < anf->nodeCount; i++) {
        for (int j = 0; j < anf->nodeList[i]->varCount; j++) {
        
            tHashMapRecord* record = selectFromHashMap(anf->hashMap, anf->nodeList[i]->variables[j]);
            printf("%s:%s", record->key, record->value ? "true" : "false");
            if (anf->nodeList[i]->varCount - j > 1) {
                printf(" & ");
            }
        }
        if (anf->nodeList[i]->varCount == 0) {
            printf("0");
        }
        if (anf->nodeCount - i > 1) {
            printf(" XOR \n @ ");
        }
    }
    printf("\n * Node Count: %d", anf->nodeCount);
    printf("\n * Anf value: ");
    fputs(anf->value ? "true\n" : "false\n", stdout);
    printf("********************************\n");
}

// int getNodeCountFromAnfs(tAnf* anfs[], int length) {

//     int nodeCount = 0;
//     for (int i = 0; i < length; i++) {
//         nodeCount += anfs[i]->length;
//     }
//     return nodeCount;
// }

// int getVarCountFromAnfs(tAnf* anfs[], int length) {

//     int varCount = 0;
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < anfs[i]->length; j++) {
//             varCount += anfs[i]->nodes[j]->length;
//         }
//     }
//     return varCount;   
// }

// int getVarCountFromNodes(tNode* nodes[], int length) {

//     int varCount = 0;
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < nodes[i]->length; j++) {
//             varCount += 1;
//         }
//     }
//     return varCount;   
// }
// void printBundle(tANFBundle* bundle) {

//     printf("*******************\n");
//     printf("Anfs Count               : %d\n", bundle->anfsCount);
//     printf("     with %d nodes.\n", getNodeCountFromAnfs(bundle->anfs, bundle->anfsCount));
//     printf("     with %d vars.\n", getVarCountFromAnfs(bundle->anfs, bundle->anfsCount));
//     printf("Nodes created without Anf: %d\n", bundle->nodeCount);
//     printf("     with %d vars.\n", getVarCountFromNodes(bundle->nodes, bundle->nodeCount));
//     printf("Variables                : %d\n", bundle->hashmap->usedCapacity);
//     // printf("Max Var Length: %d\n", bundle->maxVarLength);
//     printf("*******************\n");
// }

// void printBundleMap(tANFBundle* bundle) {
//     printHashMap(bundle->hashmap);
// }
    
// int generateAnfGraph(tAnf* anf, char* filename) {

//     FILE *file = openAndClearFile(filename);

//     if (file == NULL) {
//         return ERR_OPEN;
//     }

//     printInitGraphSequence(file);
//     printSingleRootNode(file, "anf");

//     int nodeCounter = 1;
//     nodeCounter = printAnonymousNodes(file, anf->length, nodeCounter, "node", 0);

//     for (int i = 0; i < anf->length; i++) {
        
//         for (int j = 0; j < anf->nodes[i]->length; j++) {

//             tVar var = anf->nodes[i]->variables[j];
//             printNodeWithValue(file, nodeCounter, var.name, var.value);
//             printArrow(file, i+1, NO_PORT, nodeCounter);
//             nodeCounter++;        
//         }
//     }

//     printEndGraphSequence(file);

//     fclose(file);
//     return OK;

// }

// int generateBundleGraph(tANFBundle* bundle, char* filename) {

//     FILE *file = openAndClearFile(filename);

//     if (file == NULL) {
//         return ERR_OPEN;
//     }

//     printInitGraphSequence(file);
//     printSingleRootNode(file, "bundle");

//     int nodeCounter = 1;
//     nodeCounter = printAnonymousNodes(file, bundle->anfsCount, nodeCounter, "anf", 0);
        
//     int currentNodeIndex = 0;
//     int nodeIndex = 1;

//     for (int i = 0; i < bundle->anfsCount; i++) {
        
//         for (int j = 0; j < bundle->anfs[i]->length; j++) {

//             int nodeNameSize = 6 + getDigitCount(nodeCounter); 
//             char nodeName[nodeNameSize];
//             snprintf(nodeName, nodeNameSize, "node %d", nodeIndex);
//             printNodeWithoutValue(file, nodeCounter, nodeName);
//             printArrow(file, i+1, NO_PORT, nodeCounter);
//             currentNodeIndex = nodeCounter;

//             nodeCounter++;
//             nodeIndex++;
        
//             for (int k = 0; k < bundle->anfs[i]->nodes[j]->length; k++) {
                
//                 tVar var = bundle->anfs[i]->nodes[j]->variables[k];
//                 printNodeWithValue(file, nodeCounter, var.name, var.value);
//                 printArrow(file, currentNodeIndex, NO_PORT, nodeCounter);

//                 nodeCounter++;        
//             }
    
//         }
//     }
//     printEndGraphSequence(file);
    
//     fclose(file);
//     return OK;

// }
