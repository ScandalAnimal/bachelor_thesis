/** 
 * @file
 * @brief functions for manipulating with anf
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anf.h"

/**
 * function for changing value of anf
 * @param anf anf where change happens
 * @param value value to add to anf
 */
void setAnfValue(tAnf* anf, bool value) {
    if (anf->nodeCount == 0) {
        anf->value = value;
    }
    else {
        anf->value ^= value;
    }
}

/**
 * function for fixing value of node
 * @param node node where change happens
 * @param hashMap hash map of all variables
 */
void fixNodeValue(tNode* node, tVar** hashMap) {

    if (node->varCount == 0) {
        node->value = false;
        return;
    }

    if (node->value == true) {
        return;
    }

    for (int i = 0; i < node->varCount; i++) {
        bool value = selectFromHashMap(&hashMap, node->variables[i])->value;
        
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

/**
 * function for fixing value of anf
 * @param anf anf where to fix value
 */
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
            value ^= anf->nodeList[i]->value;
        }
    }
    anf->value = value; 
}

void freeAnf(tAnf* anf) {
    for (int i = 0; i < anf->nodeCount; i++) {
        freeNode(anf->nodeList[i]);
    }
    free(anf->nodeList);
    clearHashMap(&(anf->hashMap));
    freeHashMap(&(anf->hashMap));
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

    // memcpy(anf->nodeList[anf->nodeCount], node, sizeof(tNode));
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

    return var;
}

tVar createTrueVarInAnf(tAnf* anf, char* name) {

    tVar var = createTrueVar(name);

    if (!isKeyInHashMap(anf->hashMap, name)) {
        if (ERROR == insertToHashMap(anf->hashMap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
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

    return var;
}

int createVarsInAnf(tAnf* anf, tVar variables[], int length) {

    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        if (!isKeyInHashMap(&(anf->hashMap), var.name)) {
            if (ERROR == insertToHashMap(&(anf->hashMap), var.name, var.value)) {
               fprintf(stderr, "%d\n", ERR_INSERT);        
            }
        }
    } 
    return OK;
}

void* newAnf() {

    tAnf* anf;
    if (!(anf = (tAnf*) malloc(sizeof(tAnf)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);        
        return NULL;
    }

    anf->hashMap = createHashMap();    

    anf->nodeCount = 0;
    if (!(anf->nodeList = malloc(sizeof(anf->nodeList)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        free(anf);
        return NULL;        
    }

    anf->value = false;
    return anf;
}

/**
 * function creates new map from existing map
 * @param sourceMap map to copy from
 * @param targetMap map to create
 * @return return code from <code>error.h</code>
 */
int duplicateVars(tMap sourceMap, tMap targetMap) {
    
    tVar** source = (tVar**) sourceMap;

    tVar* s = NULL;
    for (s = *source; s != NULL; s = (tVar*)(s->hh.next)) {
        if (!isKeyInHashMap(targetMap, s->name)) {
            if (insertToHashMap(targetMap, s->name, s->value) != OK) {
                return ERR_INSERT;
            }    
        }
    }
    return OK;
}

void* newAnfFrom2Anfs(tAnf* anf1, tAnf* anf2, bool valuesFromAnf1) {

    tAnf* anf = newAnf();

    if (valuesFromAnf1) {

        if ((duplicateVars(&(anf2->hashMap), &(anf->hashMap)) != OK) || 
            (duplicateVars(&(anf1->hashMap), &(anf->hashMap)) != OK)) {
            freeAnf(anf);
            return NULL;
        }
    }
    else {
        
        if ((duplicateVars(&(anf1->hashMap), &(anf->hashMap)) != OK) || 
            (duplicateVars(&(anf2->hashMap), &(anf->hashMap)) != OK)) {
            freeAnf(anf);
            return NULL;
        }        
    }

    tNode* node;

    for (int i = 0; i < anf1->nodeCount; i++) {

        tVar varArray[anf1->nodeList[i]->varCount];

        for (int j = 0; j < anf1->nodeList[i]->varCount; j++) {
            char* varName = anf1->nodeList[i]->variables[j];
            bool varValue = selectFromHashMap(&(anf->hashMap), varName)->value;
            varArray[j] = createVar(varName, varValue);
        }

        node = newNodeWithVarsInAnf(anf, varArray, ARRAY_SIZE(varArray));
        if (node == NULL) {
            freeAnf(anf);
            return NULL;
        }
    }

    for (int i = 0; i < anf2->nodeCount; i++) {

        tVar varArray[anf2->nodeList[i]->varCount];

        for (int j = 0; j < anf2->nodeList[i]->varCount; j++) {
            char* varName = anf2->nodeList[i]->variables[j];
            bool varValue = selectFromHashMap(&(anf->hashMap), varName)->value;
            varArray[j] = createVar(varName, varValue);
        }

        node = newNodeWithVarsInAnf(anf, varArray, ARRAY_SIZE(varArray));
        if (node == NULL) {
            freeAnf(anf);
            return NULL;
        }
    }
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

                if (isKeyInHashMap(&(anf->hashMap), varName)) {
                    if (removeFromHashMap(&(anf->hashMap), varName) != OK) {
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

    if (removeFromHashMap(&(anf->hashMap), varName) != OK) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    } 

    return OK;
}

/**
 * function checks if node is in anf specified
 * @param anf anf where node should be
 * @param node node to check
 * @return true if node is in anf, false if is not
 */
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
    if (!isKeyInHashMap(&(anf->hashMap), var.name)) {
        if (ERROR == insertToHashMap(&(anf->hashMap), var.name, var.value)) {
            fprintf(stderr, "%d\n", ERR_INSERT);        
            return ERR_INSERT;
        }
    }
    if (addVariableToNode(var, node) != OK) {
        return ERROR;
    }
    fixNodeValue(node, anf->hashMap);
    fixAnfValue(anf);
    return OK;
}

int addVarsToNodeInAnf(tAnf* anf, tNode* node, tVar variables[], int length) {

    if (!isNodeInAnf(anf, node)) {
        return ERR_INANF;
    }
    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        if (!isKeyInHashMap(&(anf->hashMap), var.name)) {
            if (ERROR == insertToHashMap(&(anf->hashMap), var.name, var.value)) {
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

/**
 * function recount counter in node
 * @param node node where counting happens
 * @param anf anf where counting happens
 */
void recountNodeValueInAnf(tNode* node, tAnf* anf) {

    for (int i = 0; i < node->varCount; i++) {

        bool value = selectFromHashMap(&(anf->hashMap), node->variables[i])->value;
        
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

/**
 * function for recounting counters in anf after change
 * @param anf anf where recount happens
 */
void recountValuesInAnf(tAnf* anf) {

    for (int i = 0; i < anf->nodeCount; i++) {
        recountNodeValueInAnf(anf->nodeList[i], anf);
    }
    fixAnfValue(anf);
}

int switchVarValueInAnf(char* varName, tAnf* anf) {
    
    tVar* record = selectFromHashMap(&(anf->hashMap), varName);
    if (record == NULL) {
        return ERR_NOTEXIST;
    }

    bool newValue = !(record->value);

    if (ERROR == insertToHashMap(&(anf->hashMap), varName, newValue)) {
        return ERR_INSERT;
    }

    recountValuesInAnf(anf);

    return OK;
}


void printAnf(tAnf* anf) {

    int varCount = 0;
    printf("********************************\nANF:\n @ ");
    for (int i = 0; i < anf->nodeCount; i++) {
        varCount += anf->nodeList[i]->varCount;
            
        for (int j = 0; j < anf->nodeList[i]->varCount; j++) {
            tVar* record = selectFromHashMap(&(anf->hashMap), anf->nodeList[i]->variables[j]);
            printf("%s:%s", record->name, record->value ? "true" : "false");
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
    printf("\n * Var Count: %d", varCount);
    printf("\n * Anf value: ");
    fputs(anf->value ? "true\n" : "false\n", stdout);
    printf("********************************\n");
}

int generateAnfGraph(tAnf* anf, char* filename) {

    FILE *file = openAndClearFile(filename);

    if (file == NULL) {
        return ERR_OPEN;
    }

    printInitGraphSequence(file);
    printSingleRootNode(file, "anf", false, anf->value);

    int nodeCounter = 1;
    nodeCounter = printAnonymousNodes(file, anf->nodeCount, nodeCounter, "node", 0);

    for (int i = 0; i < anf->nodeCount; i++) {
        
        for (int j = 0; j < anf->nodeList[i]->varCount; j++) {

            const char* varName = anf->nodeList[i]->variables[j];
            bool varValue = selectFromHashMap(&(anf->hashMap), varName);
            printNodeWithValue(file, nodeCounter, varName, varValue);
            printArrow(file, i+1, NO_PORT, nodeCounter);
            nodeCounter++;        
        }
    }

    printEndGraphSequence(file);

    fclose(file);
    return OK;

}