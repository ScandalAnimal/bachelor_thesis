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

int main(int argc, char *argv[]) {

    tANFBundle* bundle = createANFBundle(10, 0.7, 50);

    tVar var1 = createVarInBundle(bundle, "Celtics", true);
    tVar var2 = createVarInBundle(bundle, "Raptors", true);
    tVar var3 = createVarInBundle(bundle, "Knicks", true);
    tVar var4 = createVarInBundle(bundle, "76ers", true);
    tVar var5 = createVarInBundle(bundle, "Nets", true);

    tVar SE[] = { 
        createVar("Wizards", true), 
        createVar("Hawks", true), 
        createVar("Heat", true), 
        createVar("Hornets", true), 
        createVar("Magic", true) 
    };
    tVar CE[] = { 
        createVar("Cavs", true), 
        createVar("Pacers", true), 
        createVar("Bucks", true), 
        createVar("Pistons", true), 
        createVar("Bulls", true) 
    };
    tVar NW[] = { 
        createVar("Jazz", true), 
        createVar("Thunder", true), 
        createVar("Nuggets", true), 
        createVar("Blazers", true), 
        createVar("Timberwolves", true) 
    };
    tVar PA[] = { 
        createVar("Warriors", true), 
        createVar("Clippers", true), 
        createVar("Kings", true), 
        createVar("Suns", true), 
        createVar("Lakers", true) 
    };
    tVar SW[] = { 
        createVar("Spurs", true), 
        createVar("Rockets", true), 
        createVar("Grizzlies", true), 
        createVar("Mavericks", true), 
        createVar("Pelicans", true) 
    };

    int SE_size = sizeof(SE) / sizeof(*SE);
    int CE_size = sizeof(CE) / sizeof(*CE); 
    int NW_size = sizeof(NW) / sizeof(*NW);
    int PA_size = sizeof(PA) / sizeof(*PA);
    int SW_size = sizeof(SW) / sizeof(*SW);

    addVarsToBundle(bundle, SE, SE_size);
     
    tNode* node1 = createNodeInBundle(bundle);
    tNode* node2 = createNodeWithVarsInBundle(bundle, SE, SE_size);
    tNode* node3 = createNodeWithVarsInBundle(bundle, CE, CE_size);
    tNode* node4 = createNodeWithVarsInBundle(bundle, NW, NW_size);
    tNode* node5 = createNodeWithVarsInBundle(bundle, PA, PA_size);
    tNode* node6 = createNodeWithVarsInBundle(bundle, SW, SW_size);

    addVariableToNode(var1.name, node1);
    addVariableToNode(var2.name, node1);
    addVariableToNode(var3.name, node1);
    addVariableToNode(var4.name, node1);
    addVariableToNode(var5.name, node1);

    addVariablesToNode(NW, NW_size, node2);

    printNode(node1);
    printNode(node2);

    tNode* nodes[] = {
        node2,
        node3,
        node4,
        node5,
        node6
    };

    int nodes_size = sizeof(nodes) / sizeof(*nodes);

    // anf anf1 = createAnf();
    tAnf* anf2 = createAnfWithNodesInBundle(bundle, nodes, nodes_size);

    //     // // // TODO addNodeToAnf();

    //     // printAnf(anf2);


    printBundle(bundle);
    printBundleMap(bundle);
    printAnf(anf2);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    freeNode(node4);
    freeNode(node5);
    freeNode(node6);

    freeAnf(anf2);

    freeANFBundle(bundle);
    return 0;
}
