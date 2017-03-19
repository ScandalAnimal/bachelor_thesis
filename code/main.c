/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "anf.h"
#include "hashmap.h"
#include "node.h"
#include "utils.h"
#include "variable.h"

int main(int argc, char *argv[]) {

    tHashMap* map = createHashMap(10,0.7);    

        variable* var1 = createVariable(map, "Celtics", true);
        variable* var2 = createVariable(map, "Raptors", true);
        variable* var3 = createVariable(map, "Knicks", true);
        variable* var4 = createVariable(map, "76ers", true);
        variable* var5 = createVariable(map, "Nets", true);

        char* SE[] = { "Wizards", "Hawks", "Heat", "Hornets", "Magic" };
        char* CE[] = { "Cavs", "Pacers", "Bucks", "Pistons", "Bulls" };
        char* NW[] = { "Jazz", "Thunder", "Nuggets", "Blazers", "Timberwolves" };
        char* PA[] = { "Warriors", "Clippers", "Kings", "Suns", "Lakers" };
        char* SW[] = { "Spurs", "Rockets", "Grizzlies", "Mavericks", "Pelicans" };
        bool values[] = { true, true, true, true, true };

        int SE_size = sizeof(SE) / sizeof(*SE);
        int CE_size = sizeof(CE) / sizeof(*CE);
        int NW_size = sizeof(NW) / sizeof(*NW);
        int PA_size = sizeof(PA) / sizeof(*PA);
        int SW_size = sizeof(SW) / sizeof(*SW);

        createVariables(map, SE, SE_size, values);
        createVariables(map, CE, CE_size, values);
        createVariables(map, NW, NW_size, values);
        createVariables(map, PA, PA_size, values);
        createVariables(map, SW, SW_size, values);
     
        node node1 = createNode();
        node node2 = createNodeWithVariables(SE, SE_size);
        node node3 = createNodeWithVariables(CE, CE_size);
        node node4 = createNodeWithVariables(NW, NW_size);
        node node5 = createNodeWithVariables(PA, PA_size);
        node node6 = createNodeWithVariables(SW, SW_size);

        addVariableToNode(var1->name, &node1);
        addVariableToNode(var2->name, &node1);
        addVariableToNode(var3->name, &node1);
        addVariableToNode(var4->name, &node1);
        addVariableToNode(var5->name, &node1);

        // printNode(node1);
        // printNode(node2);

        node nodes[] = {
            node1,
            node2,
            node3,
            node4,
            node5,
            node6
        };

        int nodes_size = sizeof(nodes) / sizeof(*nodes);

        anf anf1 = createAnf();
        anf anf2 = createAnfWithNodes(nodes, nodes_size);

        // // TODO addNodeToAnf();

        printAnf(anf2);

    free(var1);
    free(var2);
    free(var3);
    free(var4);
    free(var5);

    printHashMap(map);
    freeHashMap(map);
    
    return 0;
}
