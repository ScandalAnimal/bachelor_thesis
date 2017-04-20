/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "anf.h"
// #include "hashmap.h"
// #include "node.h"
#include "utils.h"
// #include "variable.h"

int main(int argc, char* argv[]) {
    
    tANFBundle* bundle = createANFBundle(10, 0.7);
    if (bundle == NULL) {
        return ERROR;
    }

    // tVar var1 = createVarInBundle(bundle, "Celtics", true);
    // tVar var2 = createVarInBundle(bundle, "Raptors", true);
    // tVar var3 = createTrueVarInBundle(bundle, "Knicks");
    // tVar var4 = createFalseVarInBundle(bundle, "76ers");
    // tVar var5 = createVarInBundle(bundle, "Nets", true);

    // tVar SE[] = { 
    //     createVar("Wizards", true), 
    //     createTrueVar("Hawks"), 
    //     createVar("Heat", true), 
    //     createFalseVar("Hornets"), 
    //     createVar("Magic", true) 
    // };
    // tVar CE[] = { 
    //     createVar("Cavs", true), 
    //     createVar("Pacers", true), 
    //     createVar("Bucks", true), 
    //     createVar("Pistons", false), 
    //     createVar("Bulls", true) 
    // };
    // tVar NW[] = { 
    //     createVar("Jazz", false), 
    //     createVar("Thunder", true), 
    //     createVar("Nuggets", true), 
    //     createVar("Blazers", true), 
    //     createVar("Timberwolves", true) 
    // };
    // tVar PA[] = { 
    //     createVar("Warriors", true), 
    //     createVar("Clippers", true), 
    //     createVar("Kings", false), 
    //     createVar("Suns", true), 
    //     createVar("Lakers", true) 
    // };
    // tVar SW[] = { 
    //     createVar("Spurs", true), 
    //     createVar("Rockets", true), 
    //     createVar("Rockets", true), 
    //     createVar("Rockets", true), 
    //     createVar("Rockets", true), 
    //     createVar("Grizzlies", true), 
    //     createVar("Mavericks", true), 
    //     createVar("Suns", false), 
    //     createVar("Mavericks", true), 
    //     createVar("Pelicans", true) 
    // };

    // createVarsInBundle(bundle, SE, ARRAY_SIZE(SE));
     
    // tNode* node1 = createNodeInBundle(bundle);
    // if (node1 == NULL) {
    //     return ERROR;
    // }
    // tNode* node2 = createNodeWithVarsInBundle(bundle, SE, ARRAY_SIZE(SE));
    // if (node2 == NULL) {
    //     return ERROR;
    // }
    // tNode* node3 = createNodeWithVarsInBundle(bundle, CE, ARRAY_SIZE(CE));
    // if (node3 == NULL) {
    //     return ERROR;
    // }
    // tNode* node4 = createNodeWithVarsInBundle(bundle, NW, ARRAY_SIZE(NW));
    // if (node4 == NULL) {
    //     return ERROR;
    // }
    // tNode* node5 = createNodeWithVarsInBundle(bundle, PA, ARRAY_SIZE(PA));
    // if (node5 == NULL) {
    //     return ERROR;
    // }
    // tNode* node6 = createNodeWithVarsInBundle(bundle, SW, ARRAY_SIZE(SW));
    // if (node6 == NULL) {
    //     return ERROR;
    // }

    // tNode* nodeX = createNode();

    // addVariableToNode(var1, node1);
    // addVariableToNode(var2, node1);
    // addVariableToNode(var3, node1);
    // addVariableToNode(var4, node1);
    // addVariableToNode(var5, node1);

    // addVariablesToNode(NW, ARRAY_SIZE(NW), node2);

    // // printNode(node1);
    // // printNode(node2);
    // // printNode(node3);
    // // printNode(node4);
    // // printNode(node5);
    // // printNode(node6);

    // tNode* nodes[] = {
    //     node2,
    //     node3
    // };

    // tNode* nodes2[] = {
    //     node4,
    //     node5,
    //     node6
    // };

    // tAnf* anf2 = createAnfWithNodesInBundle(bundle, nodes, ARRAY_SIZE(nodes));
    // // tAnf* anf3 = createAnfWithNodesInBundle(bundle, nodes2, ARRAY_SIZE(nodes2));

    // // addNodeToAnf(node3, anf2);

    // printBundle(bundle);
    // // printAnf(anf2);

    // iterateOverBundle(bundle);

    // // deleteAnfFromBundle(bundle, anf3);
    // deleteNodeFromBundle(bundle, node3);
    // printBundle(bundle);

    // // printBundleMap(bundle);

    // freeNode(node1);
    // freeNode(node2); 
    // freeNode(node3);
    // freeNode(node4);
    // freeNode(node5);
    // freeNode(node6);

    // freeNode(nodeX);

    // freeAnf(anf2);
    // // freeAnf(anf3);

    freeANFBundle(bundle);
    return 0;
}
