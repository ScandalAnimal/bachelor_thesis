/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "anf.h"
#include "utils.h"

int emptyAnfs() {

    tAnf* anf1 = createEmptyAnf();
    if (anf1 == NULL) {
        return ERROR;
    }

    printAnf(anf1);

    tANFBundle* bundle = createANFBundle(10, 0.7);
    if (bundle == NULL) {
        freeAnf(anf1);
        return ERROR;
    }

    tAnf* anf2 = createEmptyAnfInBundle(bundle);
    if (anf2 == NULL) {
        freeAnf(anf1);
        freeANFBundle(bundle);
        return ERROR;
    }

    printAnf(anf2);

    printBundle(bundle);

    if (addAnfToBundle(bundle, anf1) != OK) {
        freeAnf(anf1);
        freeAnf(anf2);
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundle(bundle);

    if (deleteAnfFromBundle(bundle, anf1) != OK) {
        freeAnf(anf1);
        freeAnf(anf2);
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundle(bundle);

    freeAnf(anf1);
    freeAnf(anf2);

    freeANFBundle(bundle);
    return OK;
}

int standaloneNodes() {

    tNode* node1 = createNode();
    if (node1 == NULL) {
        return ERROR;
    }

    printNode(node1);

    tVar var1 = createVar("var1", true);
    tVar var2 = createFalseVar("var2");
    tVar var3 = createTrueVar("var3");

    tVar varArray[] = {
        createVar("var4", true),
        createVar("var5", true),
        createVar("var6", true),
        createVar("var7", true),
        createVar("var8", true)
    };

    if (addVariableToNode(var1, node1) != OK) {
        freeNode(node1);
        return ERROR;
    }

    printNode(node1);

    if (addVariablesToNode(varArray, ARRAY_SIZE(varArray), node1) != OK) {
        freeNode(node1);
        return ERROR;
    } 

    printNode(node1);

    if (addVariableToNode(var2, node1) != OK) {
        freeNode(node1);
        return ERROR;
    }

    if (addVariableToNode(var3, node1) != OK) {
        freeNode(node1);
        return ERROR;
    }

    printNode(node1);

    if (deleteVariableFromNode("var8", node1) != OK) {
        freeNode(node1);
        return ERROR;
    }    

    printNode(node1);
    freeNode(node1);

    tNode* node2 = createNodeWithVariables(varArray, ARRAY_SIZE(varArray));
    if (node2 == NULL) {
        return ERROR;
    }

    printNode(node2);
    freeNode(node2);

    return OK;
}

int nodesInBundle() {

    tANFBundle* bundle = createANFBundle(10, 0.7);
    if (bundle == NULL) {
        return ERROR;
    }

    tNode* node1 = createNodeInBundle(bundle);
    if (node1 == NULL) {
        freeANFBundle(bundle);
        return ERROR;
    }

    tVar var1 = createVarInBundle(bundle, "var1", true);
    tVar var2 = createFalseVarInBundle(bundle, "var2");
    tVar var3 = createTrueVarInBundle(bundle, "var3");

    tVar varArray[] = {
        createVar("var4", true),
        createVar("var5", true),
        createVar("var6", true),
        createVar("var7", true),
        createVar("var8", true)
    };

    if (createVarsInBundle(bundle, varArray, ARRAY_SIZE(varArray)) != OK) {
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundleMap(bundle);


    if (addVariablesToNode(varArray, ARRAY_SIZE(varArray), node1) != OK) {
        freeNode(node1);
        freeANFBundle(bundle);
        return ERROR;
    } 

    if (addVariableToNode(var2, node1) != OK) {
        freeNode(node1);
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundle(bundle);

    tVar varArray2[] = {
        createVar("var10", true),
        createVar("var11", true),
        createVar("var12", true),
        createVar("var13", true),
        createVar("var14", true)
    };    

    tNode* node2 = createNodeWithVarsInBundle(bundle, varArray2, ARRAY_SIZE(varArray2));
    if (node2 == NULL) {
        freeNode(node1);
        freeANFBundle(bundle);
        return ERROR;
    }

    printNode(node2);
    printBundle(bundle);

    if (deleteNodeFromBundle(bundle, node2) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeANFBundle(bundle);
        return ERROR;
    }

    printBundle(bundle);

    freeNode(node1);
    freeNode(node2);
    freeANFBundle(bundle);
    return OK;
}

int main(int argc, char* argv[]) {

    printf("TEST 01: %d\n", emptyAnfs());
    printf("TEST 02: %d\n", standaloneNodes());
    printf("TEST 03: %d\n", nodesInBundle());

}