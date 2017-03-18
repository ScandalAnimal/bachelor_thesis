/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashmap.h"
#include "node.h"
#include "utils.h"
#include "variable.h"

int main(int argc, char *argv[]) {

    tHashMap* map = createHashMap(10,0.7);    

    variable* var1 = createVariable(map, "Rockets", true);
    variable* var2 = createVariable(map, "Warriors", true);
    variable* var3 = createVariable(map, "Spurs", true);
    variable* var4 = createVariable(map, "Jazz", true);

    char* array[] = {
        "Thunder",
        "Clippers", 
        "Grizzlies"
    };
    bool values[] = {
        true, 
        true, 
        true
    };

    createVariables(map, array, values);
 
    node node1 = createNode();
    node node2 = createNodeWithVariables(array);

    addVariableToNode(var1->name, &node1);
    addVariableToNode(var2->name, &node1);
    addVariableToNode(var3->name, &node1);
    addVariableToNode(var4->name, &node1);

    printNode(node1);
    printNode(node2);



//--create ANF;
//--add node to ANF;

//--repeat after done;

//--save ANF;
//--print;

    free(var1);
    free(var2);
    free(var3);
    free(var4);

    printHashMap(map);
    freeHashMap(map);
    
    return 0;
}
