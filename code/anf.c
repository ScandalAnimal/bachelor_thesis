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

void fixNodeValue(tNode* node, tHashMap* hashMap) {

    if (node->value == true) {
        return;
    }

    for (int i = 0; i < node->varCount; i++) {
        bool value = selectFromHashMap(hashMap, node->variables[i])->value;
        
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

void fixAnfValue(tAnf* anf) {

    bool value = false;
    for (int i = 0; i < anf->nodeCount; i++) {
        
        if (i == 0) {
            value = anf->nodeList[i]->value;
        }
        else {
            if (anf->nodeList[i]->value == false) {
                value = false;
                break;
            }
            value &= anf->nodeList[i]->value;
        }
    }
    anf->value = value; 
}

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

int deleteNodeFromAnf(tAnf* anf, tNode* node) {

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
    if (!(anf->nodeList = realloc(anf->nodeList, sizeof(tNode *) * anf->nodeCount))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return ERR_MALLOC;
    }

    return OK;
}

int deleteAllNodesFromAnf(tAnf* anf, bool deleteVariables) {

    if (deleteVariables) {
        for (int i = 0; i < anf->nodeCount; i++) {
            for (int j = 0; j < anf->nodeList[i]->varCount; j++) {
                char* varName = anf->nodeList[i]->variables[j];

                if (isKeyInHashMap(anf->hashMap, varName)) {
                    if (removeFromHashMap(anf->hashMap, varName) != OK) {
                        return ERR_DELETE;
                    }
                }
            }
        }
    }

    if (!(anf->nodeList = realloc(anf->nodeList, sizeof(tNode *) * 1))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return ERR_MALLOC;
    }

    anf->nodeCount = 0;
    anf->value = false;

    return OK;
}


int deleteVarFromAnf(tAnf* anf, char* varName, bool deleteFromNodes) {

    bool isInNode = false;
    for (int i = 0; i < anf->nodeCount; i++) {
        if (isInNode) {
            break;
        }
        for (int j = 0; j < anf->nodeList[i]->varCount; j++) {
            if (strcmp(varName, anf->nodeList[i]->variables[j]) == 0) {
                isInNode = true;
                break;
            }
        }
    }

    if (isInNode && !deleteFromNodes) {
        fprintf(stderr, "%d\n", ERR_INNODE);
        return ERR_INNODE;
    }

    if (isInNode && deleteFromNodes) {
        for (int i = 0; i < anf->nodeCount; i++) {
            for (int j = 0; j < anf->nodeList[i]->varCount; j++) {
                if (strcmp(varName, anf->nodeList[i]->variables[j]) == 0) {
                    if (deleteVariableFromNode(varName, anf->nodeList[i]) != OK) {
                        return ERR_DELETE;
                    }
                }
            }
            fixNodeValue(anf->nodeList[i], anf->hashMap);
        }        
        fixAnfValue(anf);
    }

    if (removeFromHashMap(anf->hashMap, varName) != OK) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    } 

    return OK;
}

bool isNodeInAnf(tAnf* anf, tNode* node) {

    for (int i = 0; i < anf->nodeCount; i++) {
        if (anf->nodeList[i] == node) {
            return true;
        }
    } 
    return false;
}

int addVarToNodeInAnf(tAnf* anf, tNode* node, tVar var) {
    
    if (!isNodeInAnf(anf, node)) {
        return ERR_INANF;
    }
    if (!isKeyInHashMap(anf->hashMap, var.name)) {
        if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
            fprintf(stderr, "%d\n", ERR_INSERT);        
            return ERR_INSERT;
        }
    }
    if (addVariableToNode(var, node) != OK) {
        return ERROR;
    }
    return OK;
}

int addVarsToNodeInAnf(tAnf* anf, tNode* node, tVar variables[], int length) {

    if (!isNodeInAnf(anf, node)) {
        return ERR_INANF;
    }
    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        if (!isKeyInHashMap(anf->hashMap, var.name)) {
            if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
                fprintf(stderr, "%d\n", ERR_INSERT);        
                return ERR_INSERT;
            }
        }
    } 
    if (addVariablesToNode(variables, length, node) != OK) {
        return ERROR;
    }
    return OK;
}

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

void printBundleMap(tAnf* anf) {
    printHashMap(anf->hashMap);
}
    
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
