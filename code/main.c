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

    //     char* SE[] = { "Wizards", "Hawks", "Heat", "Hornets", "Magic" };
    //     char* CE[] = { "Cavs", "Pacers", "Bucks", "Pistons", "Bulls" };
    //     char* NW[] = { "Jazz", "Thunder", "Nuggets", "Blazers", "Timberwolves" };
    //     char* PA[] = { "Warriors", "Clippers", "Kings", "Suns", "Lakers" };
    //     char* SW[] = { "Spurs", "Rockets", "Grizzlies", "Mavericks", "Pelicans" };
    //     bool values[] = { true, true, true, true, true };

    //     int SE_size = sizeof(SE) / sizeof(*SE);
    //     int CE_size = sizeof(CE) / sizeof(*CE);
    //     int NW_size = sizeof(NW) / sizeof(*NW);
    //     int PA_size = sizeof(PA) / sizeof(*PA);
    //     int SW_size = sizeof(SW) / sizeof(*SW);

    //     // createVariables(map, SE, SE_size, values);
    //     // createVariables(map, CE, CE_size, values);
    //     // createVariables(map, NW, NW_size, values);
    //     // createVariables(map, PA, PA_size, values);
    //     // createVariables(map, SW, SW_size, values);
     
    tNode* node1 = createNodeInBundle(bundle);
    // tNode* node2 = createNodeInBundle(bundle);
    //     node node2 = createNodeWithVariables(SE, SE_size, values, map);
    //     node node3 = createNodeWithVariables(CE, CE_size, values, map);
    //     node node4 = createNodeWithVariables(NW, NW_size, values, map);
    //     node node5 = createNodeWithVariables(PA, PA_size, values, map);
    //     node node6 = createNodeWithVariables(SW, SW_size, values, map);

    addVariableToNode(var1.name, node1);
    addVariableToNode(var2.name, node1);
    addVariableToNode(var3.name, node1);
    addVariableToNode(var4.name, node1);
    addVariableToNode(var5.name, node1);

    // tVar* vars[] = {
        // var1, var2, var3
    // };
    // int vars_size = sizeof(vars) / sizeof(*vars);

    // printf("%d\n", vars_size);
    // addVariablesToNode(vars, vars_size, node2);

    printNode(node1);
    // printNode(node2);

    //     node nodes[] = {
    //         node1,
    //         node2,
    //         node3,
    //         node4,
    //         node5,
    //         node6
    //     };

    //     // int nodes_size = sizeof(nodes) / sizeof(*nodes);

    //     // anf anf1 = createAnf();
    //     // anf anf2 = createAnfWithNodes(nodes, nodes_size);

    //     // // // TODO addNodeToAnf();

    //     // printAnf(anf2);

    // free(var1->name);
    // free(var1);
    // free(var2);
    // free(var3);
    // free(var4);
    // free(var5);

    free(node1->variables);
    // free(node1->variables.name);
    free(node1);
    // free(node2->variables);
    // free(node2);

    printBundle(bundle);
    printBundleMap(bundle);
    
    freeANFBundle(bundle);
    return 0;
}
