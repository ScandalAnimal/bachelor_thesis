/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "anf.h"

void setAnfValue(tAnf* anf, bool value) {
    if (anf->length == 0) {
        anf->value = value;
    }
    else {
        anf->value ^= value;
    }
}

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

void* createNodeInBundle(tANFBundle* bundle) {

    tNode* node = createNode();
    if (node == NULL) {
        return NULL;
    }

    if (!(bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        return NULL;
    }

    bundle->nodes[bundle->nodeCount] = node;
    bundle->nodeCount++;    

    return node;
}

void* createNodeWithVarsInBundle(tANFBundle* bundle, tVar variables[], int length) {

    tNode* node = createNode();

    if (node == NULL) {
        return NULL;
    }

    tVar* varsWithoutDuplicity;
    if (!(varsWithoutDuplicity = (tVar*) malloc(sizeof(tVar) * length))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
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

    if (addVariablesToNode(varsWithoutDuplicity, insertedVars, node) != OK) {
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    if (createVarsInBundle(bundle, varsWithoutDuplicity, insertedVars) != OK) {
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    if (!(bundle->nodes = realloc(bundle->nodes, sizeof(tNode *) * (bundle->nodeCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        freeNode(node);
        free(varsWithoutDuplicity);
        return NULL;
    }

    bundle->nodes[bundle->nodeCount] = node;
    bundle->nodeCount++;    

    free(varsWithoutDuplicity);
    return node;
}

tVar createVarInBundle(tANFBundle* bundle, char* name, bool value) {

    tVar var = createVar(name, value);

    if (!isKeyInHashMap(bundle->hashmap, name)) {
        if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

tVar createTrueVarInBundle(tANFBundle* bundle, char* name) {

    tVar var = createTrueVar(name);

    if (!isKeyInHashMap(bundle->hashmap, name)) {
        if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

tVar createFalseVarInBundle(tANFBundle* bundle, char* name) {

    tVar var = createFalseVar(name);

    if (!isKeyInHashMap(bundle->hashmap, name)) {
        if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
           fprintf(stderr, "%d\n", ERR_INSERT);        
        }
    }
    else {
       fprintf(stderr, "%d Key: %s\n", ERR_DUPLICATE, name);        
    }

    return var;
}

int createVarsInBundle(tANFBundle* bundle, tVar variables[], int length) {

    for (int i = 0; i < length; i++) {
        tVar var = variables[i];
        if (ERROR == insertToHashMap(bundle->hashmap, var.name, var.value)) {
            fprintf(stderr, "%d\n", ERR_INSERT);        
            return ERR_INSERT;
        }
    } 
    return OK;
}

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


int addNodeToAnf(tANFBundle* bundle, tNode* node, tAnf* anf) {

    int length = anf->length;    

    anf->nodes = realloc(anf->nodes, sizeof(tNode*) * (length + 1));
    if (anf->nodes == NULL) {
        return ERROR;
    }

    for (int i = 0; i < node->length; i++) {
        if (!isKeyInHashMap(bundle->hashmap, node->variables[i].name)) {
            if (ERROR == insertToHashMap(bundle->hashmap, node->variables[i].name, node->variables[i].value)) {
                fprintf(stderr, "%d\n", ERR_INSERT);        
            }
        }
    }

    anf->nodes[anf->length] = node;
    anf->length++;
    setAnfValue(anf, node->value);
    return OK;
}

int addNodesToAnf(tANFBundle* bundle, tNode* nodes[], int size, tAnf* anf) {

    for (int i = 0; i < size; i++) {
        int addResult = addNodeToAnf(bundle, nodes[i], anf);
        if (addResult != OK) {
            return addResult;
        }
    }

    return OK;
}

void* createAnfWithNodesInBundle(tANFBundle* bundle, tNode* nodes[], int size) {

    tAnf* anf = createEmptyAnf();

    if (anf == NULL) {
        return NULL;
    }

    if (addNodesToAnf(bundle, nodes, size, anf) != OK) {
        freeAnf(anf);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        if (createVarsInBundle(bundle, nodes[i]->variables, nodes[i]->length) != OK) {
            freeAnf(anf);
            return NULL;
        }
    }

    if (!(bundle->anfs = realloc(bundle->anfs, sizeof(tAnf *) * (bundle->anfsCount + 1)))) {
        fprintf(stderr, "%d\n", ERR_MALLOC);
        freeAnf(anf);
        return NULL;
    }

    bundle->anfs[bundle->anfsCount] = anf;
    bundle->anfsCount++;    

    return anf;
}

int deleteAnfFromBundle(tANFBundle* bundle, tAnf* anf) {

    bool found = false;
    for (int i = 0; i < bundle->anfsCount; i++) {
        if (anf == bundle->anfs[i]) {
            found = true;

            for (int p = i; p < bundle->anfsCount - 1; p++) {
                bundle->anfs[p] = bundle->anfs[p+1];
            }
            bundle->anfsCount--;
        }
    }
    if (!found) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    }
    return OK;
}

int deleteNodeFromBundle(tANFBundle* bundle, tNode* node) {

    bool isInAnf = false;
    for (int i = 0; i < bundle->anfsCount; i++) {
        for (int j = 0; j < bundle->anfs[i]->length; j++) {
            if (node == bundle->anfs[i]->nodes[j]) {
                isInAnf = true;
            }
        }
    }

    if (isInAnf) {
        fprintf(stderr, "%d\n", ERR_INANF);
        return ERR_INANF;
    }

    bool found = false;
    for (int i = 0; i < bundle->nodeCount; i++) {
        if (node == bundle->nodes[i]) {
            found = true;

            for (int p = i; p < bundle->nodeCount - 1; p++) {
                bundle->nodes[p] = bundle->nodes[p+1];
            }
            bundle->nodeCount--;
        }
    }
    if (!found) {
        fprintf(stderr, "%d\n", ERR_DELETE);
        return ERR_DELETE;
    }

    return OK;
}


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

int getNodeCountFromAnfs(tAnf* anfs[], int length) {

    int nodeCount = 0;
    for (int i = 0; i < length; i++) {
        nodeCount += anfs[i]->length;
    }
    return nodeCount;
}

int getVarCountFromAnfs(tAnf* anfs[], int length) {

    int varCount = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < anfs[i]->length; j++) {
            varCount += anfs[i]->nodes[j]->length;
        }
    }
    return varCount;   
}

void printBundle(tANFBundle* bundle) {

    printf("*******************\n");
    printf("Anfs Count               : %d\n", bundle->anfsCount);
    printf("     with %d nodes.\n", getNodeCountFromAnfs(bundle->anfs, bundle->anfsCount));
    printf("     with %d vars.\n", getVarCountFromAnfs(bundle->anfs, bundle->anfsCount));
    printf("Nodes created without Anf: %d\n", bundle->nodeCount);
    printf("Variables                : %d\n", bundle->hashmap->usedCapacity);
    // printf("Max Var Length: %d\n", bundle->maxVarLength);
    printf("*******************\n");
}

void printBundleMap(tANFBundle* bundle) {
    printHashMap(bundle->hashmap);
}
    
int generateAnfGraph(tAnf* anf, char* filename) {

    FILE *file;
    file = fopen(filename, "w");
  
    if (file == NULL) {
        return ERR_OPEN;
    }
    fclose(file);

    file = fopen(filename, "a");
  
    if (file == NULL) {
        return ERR_OPEN;
    }

    fprintf(file, "digraph G {\nnodesep=.05;\nrankdir=LR;\nnode [shape=record,width=.1,height=.1];\nnode0 [label = \"<f0> anf\",height=2.5];\nnode [width = 1.5];\n");

    int size = (50 + (3 * getDigitCount(anf->length))) * anf->length + 1; 
    char nodeList[size];
    int nodeCounter = 1;
    strcpy(nodeList, "");
    for (int i = 0; i < anf->length; i++) {

        char buffer[10];
        snprintf(buffer, 10, "%d", nodeCounter);

        strcat(nodeList, "node");
        strcat(nodeList, buffer);
        strcat(nodeList, "[label = \"{ <n> node ");
        strcat(nodeList, buffer);
        strcat(nodeList, " }\"];\nnode0:f0 -> node");
        snprintf(buffer, 10, "%d", nodeCounter);
        strcat(nodeList, buffer);
        strcat(nodeList, ":n;\n");

        nodeCounter++;
    }
    fprintf(file, "%s", nodeList);
    fprintf(file, "node [width = 1.5];\n");

    size = 0;
    for (int i = 0; i < anf->length; i++) {
        size += anf->nodes[i]->length;            
    }

    size *= 100 + 1; 
    char varList[size];
    for (int i = 0; i < anf->length; i++) {
        
        for (int j = 0; j < anf->nodes[i]->length; j++) {
            
            char buffer[10];
            snprintf(buffer, 10, "%d", nodeCounter);

            strcat(varList, "node");
            strcat(varList, buffer);
            strcat(varList, "[label = \"{ <v> ");
            
            strcat(varList, anf->nodes[i]->variables[j].name);
            strcat(varList, " | ");
            anf->nodes[i]->variables[j].value ? strcat(varList, "true") : strcat(varList, "false");
            strcat(varList, "}\"];\nnode");

            snprintf(buffer, 10, "%d", i+1);
            strcat(varList, buffer);
            strcat(varList, ":n -> node");
            snprintf(buffer, 10, "%d", nodeCounter);
            strcat(varList, buffer);
            strcat(varList, ":v;\n");

            nodeCounter++;        
        }
    }

    fprintf(file, "%s", varList);
    fprintf(file, "}\n");


//    node0:f0 -> node1:n;
//    node0:f0 -> node2:n;
//    node0:f0 -> node3:n;
//    node0:f0 -> node4:n;
//    node0:f0 -> node5:n;
//    node2:p -> node6:n;
//    node4:p -> node7:n;

    fclose(file);
    return OK;

}

int generateBundleGraph(tANFBundle* bundle, char* filename) {

    FILE *file;
    file = fopen(filename, "w");
  
    if (file == NULL) {
        return ERR_OPEN;
    }
    fclose(file);

    file = fopen(filename, "a");
  
    if (file == NULL) {
        return ERR_OPEN;
    }

    fprintf(file, "digraph G {\nnodesep=.05;\nrankdir=LR;\nnode [shape=record,width=.1,height=.1];\nnode0 [label = \"<f0> bundle\",height=2.5];\nnode [width = 1.5];\n");

//     int size = (50 + (3 * getDigitCount(anf->length))) * anf->length + 1; 
//     char nodeList[size];
//     int nodeCounter = 1;
//     strcpy(nodeList, "");
//     for (int i = 0; i < anf->length; i++) {

//         char buffer[10];
//         snprintf(buffer, 10, "%d", nodeCounter);

//         strcat(nodeList, "node");
//         strcat(nodeList, buffer);
//         strcat(nodeList, "[label = \"{ <n> node ");
//         strcat(nodeList, buffer);
//         strcat(nodeList, " }\"];\nnode0:f0 -> node");
//         snprintf(buffer, 10, "%d", nodeCounter);
//         strcat(nodeList, buffer);
//         strcat(nodeList, ":n;\n");

//         nodeCounter++;
//     }
//     fprintf(file, "%s", nodeList);
//     fprintf(file, "node [width = 1.5];\n");

//     size = 0;
//     for (int i = 0; i < anf->length; i++) {
//         size += anf->nodes[i]->length;            
//     }

//     size *= 100 + 1; 
//     char varList[size];
//     for (int i = 0; i < anf->length; i++) {
        
//         for (int j = 0; j < anf->nodes[i]->length; j++) {
            
//             char buffer[10];
//             snprintf(buffer, 10, "%d", nodeCounter);

//             strcat(varList, "node");
//             strcat(varList, buffer);
//             strcat(varList, "[label = \"{ <v> ");
            
//             strcat(varList, anf->nodes[i]->variables[j].name);
//             strcat(varList, " | ");
//             anf->nodes[i]->variables[j].value ? strcat(varList, "true") : strcat(varList, "false");
//             strcat(varList, "}\"];\nnode");

//             snprintf(buffer, 10, "%d", i+1);
//             strcat(varList, buffer);
//             strcat(varList, ":n -> node");
//             snprintf(buffer, 10, "%d", nodeCounter);
//             strcat(varList, buffer);
//             strcat(varList, ":v;\n");

//             nodeCounter++;        
//         }
//     }

//     fprintf(file, "%s", varList);
    fprintf(file, "}\n");

// digraph G {
// nodesep=.05;
// rankdir=LR;
// node [shape=record,width=.1,height=.1];
// node0 [label = "<f0> bundle", height=2.5];
// node [width = 1.5];

// node1 [label = "<a> anf 1"];
// node0:f0 -> node1:a;
// node2 [label = "<a> anf 2"];
// node0:f0 -> node2:a;

// node3[label = "{ <n> node 1 }"];
// node1:a -> node3:n;
// node4[label = "{ <n> node 2 }"];
// node1:a -> node4:n;

// node5[label = "{ <n> node 3 }"];
// node2:a -> node5:n;
// node6[label = "{ <n> node 4 }"];
// node2:a -> node6:n;

// node7[label = "{ <v> var1 | true}"];
// node3:n -> node7:v;
// node8[label = "{ <v> var2 | true}"];
// node4:n -> node8:v;
// node9[label = "{ <v> var3 | true}"];
// node5:n -> node9:v;
// node10[label = "{ <v> var4 | true}"];
// node6:n -> node10:v;
// }

    fclose(file);
    return OK;

}
