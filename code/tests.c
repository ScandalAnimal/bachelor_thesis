/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "anf.h"
#include "utils.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("key")
#define KEY_COUNT (100)


int hashMapTest(char* graphOutput) {

    tMap map = createHashMap();

    if (!isHashMapEmpty(&map)) {
        freeHashMap(&map);
        return ERROR;
    }

    char* key1 = "Key1";
    if (insertToHashMap(&map, key1, true) != OK) {
        freeHashMap(&map);
        return ERROR;
    }

    tVar* mapRecord = selectFromHashMap(&map, key1);

    if (strcmp(mapRecord->name,key1) != 0) {
        freeHashMap(&map);
        return ERROR;
    }

    if (!isKeyInHashMap(&map, key1)) {
        freeHashMap(&map);
        return ERROR;   
    }

    char* key2 = "Key2";
    if (isKeyInHashMap(&map, key2)) {
        freeHashMap(&map);
        return ERROR;   
    }

    if (insertToHashMap(&map, key2, true) != OK) {
        freeHashMap(&map);
        return ERROR;
    }

    char* key3 = "Key3";
    if (insertToHashMap(&map, key3, true) != OK) {
        freeHashMap(&map);
        return ERROR;
    }

    printHashMap(&map);
    if (generateHashMapGraph(&map, graphOutput) != OK) {
        freeHashMap(&map);
        return ERROR;   
    }

    if (removeFromHashMap(&map, key1) != OK) {
        freeHashMap(&map);
        return ERROR;
    }

    printHashMap(&map);

    clearHashMap(&map);

    printHashMap(&map);

    freeHashMap(&map);

    return OK;

}

int singleFunctionTest(char* graphOutput) {

    tAnf* anf = newAnf();
    if (anf == NULL) {
        return ERROR;
    }

    printAnf(anf);

    tNode* node1 = newNodeInAnf(anf);
    if (node1 == NULL) {
        freeAnf(anf);
        return ERROR;
    }

    printAnf(anf);

    tVar varArray[] = {
        createVar("var1", true),
        createVar("var2", true),
        createVar("var3", false),
        createVar("var4", true)
    };

    tNode* node2 = newNodeWithVarsInAnf(anf, varArray, ARRAY_SIZE(varArray));
    if (node2 == NULL) {
        freeNode(node1);
        freeAnf(anf);
        return ERROR;
    }

    printNode(node2);
    printAnf(anf);

    // if (deleteNodeFromAnf(anf, node1) != OK) {
    //     freeNode(node1);
    //     freeNode(node2);
    //     freeAnf(anf);
    //     return ERROR;
    // }

    // printAnf(anf);
    // printHashMap(anf->hashMap);

    if (deleteVarFromAnf(anf, "var3", true) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf);
        return ERROR;   
    }

    printNode(node2);
    printAnf(anf);
    printHashMap(&(anf->hashMap));

    if (addVarToNodeInAnf(anf, node1, createVar("var5", true)) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf);
        return ERROR;    
    }

    printNode(node1);
    printAnf(anf);
    printHashMap(&(anf->hashMap));

    if (switchVarValueInAnf("var5", anf)) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf);
        return ERROR;    
    }

    printNode(node1);
    printNode(node2);
    printAnf(anf);
    printHashMap(&(anf->hashMap));

    if (generateAnfGraph(anf, graphOutput) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf);
        return ERROR;  
    }

    if (deleteAllNodesFromAnf(anf, true) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf);
        return ERROR;    
    }

    printAnf(anf);
    printHashMap(&(anf->hashMap));

    freeNode(node1);
    freeNode(node2);
    freeAnf(anf);

    return OK;
}


int multipleFunctionsTest(char* graphOutput) {

    tVar varArray[] = {
        createVar("var1", true),
        createVar("var2", true),
        createVar("var3", true)
    };

    tVar varArray2[] = {
        createVar("var4", true),
        createVar("var5", true),
        createVar("var6", true)
    };

    tVar varArray3[] = {
        createVar("var3", false),
        createVar("var8", true),
        createVar("var9", true),
        createVar("var10", true)
    };

    tVar varArray4[] = {
        createVar("var11", true),
        createVar("var12", true),
        createVar("var13", true)
    };

    tAnf* anf1 = newAnf();
    if (anf1 == NULL) {
        return ERROR;
    }

    tNode* node1 = newNodeWithVarsInAnf(anf1, varArray, ARRAY_SIZE(varArray));
    if (node1 == NULL) {
        freeAnf(anf1);
        return ERROR;
    }

    tNode* node2 = newNodeWithVarsInAnf(anf1, varArray2, ARRAY_SIZE(varArray2));
    if (node2 == NULL) {
        freeNode(node1);
        freeAnf(anf1);
        return ERROR;
    }

    printAnf(anf1);
    printHashMap(&(anf1->hashMap));

    tAnf* anf2 = newAnf();
    if (anf2 == NULL) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf1);
        return ERROR;
    }

    tNode* node3 = newNodeWithVarsInAnf(anf2, varArray3, ARRAY_SIZE(varArray3));
    if (node3 == NULL) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    tNode* node4 = newNodeWithVarsInAnf(anf2, varArray4, ARRAY_SIZE(varArray4));
    if (node4 == NULL) {
        freeNode(node1);
        freeNode(node2);
        freeNode(node3);
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    printAnf(anf2);
    printHashMap(&(anf2->hashMap));

    tAnf* anf3 = newAnfFrom2Anfs(anf1, anf2, true);
    if (anf3 == NULL) {
        freeNode(node1);
        freeNode(node2);
        freeNode(node3);
        freeNode(node4);
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    printAnf(anf3);
    printHashMap(&(anf3->hashMap));

    if (generateAnfGraph(anf3, graphOutput) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeNode(node3);
        freeNode(node4);
        freeAnf(anf1);
        freeAnf(anf2);
        freeAnf(anf3);
        return ERROR;  
    }

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);
    freeNode(node4);

    freeAnf(anf1);
    freeAnf(anf2);

    freeAnf(anf3);

    return OK;   
}

int variableValueChangeTest(char* graphOutput) {

    tVar varArray[] = {
        createVar("var1", true),
        createVar("var2", true),
        createVar("var3", true)
    };

    tVar varArray2[] = {
        createVar("var4", true),
        createVar("var5", true),
        createVar("var6", true)
    };

    tAnf* anf1 = newAnf();
    if (anf1 == NULL) {
        return ERROR;
    }

    tNode* node1 = newNodeWithVarsInAnf(anf1, varArray, ARRAY_SIZE(varArray));
    if (node1 == NULL) {
        freeAnf(anf1);
        return ERROR;
    }

    tNode* node2 = newNodeWithVarsInAnf(anf1, varArray2, ARRAY_SIZE(varArray2));
    if (node2 == NULL) {
        freeNode(node1);
        freeAnf(anf1);
        return ERROR;
    }

    printAnf(anf1);
    printNode(node1);
    printNode(node2);
    printHashMap(&(anf1->hashMap));

    if (switchVarValueInAnf("var2", anf1) != OK) {
        freeNode(node1);
        freeNode(node2);
        freeAnf(anf1);
        return ERROR;    
    }

    printAnf(anf1);
    printNode(node1);
    printNode(node2);
    printHashMap(&(anf1->hashMap));

    freeNode(node1);
    freeNode(node2);

    freeAnf(anf1);

    return OK;   
}

int bigDataInputTest(char* graphOutput) {

    tMap map = createHashMap();

    char key_string[KEY_MAX_LENGTH];
    tVar* value;
    

    for (int i = 0; i < KEY_COUNT; i++) {
        value = GC_MALLOC(sizeof(tVar));
        value->name = GC_MALLOC(sizeof(char) * KEY_MAX_LENGTH);
        snprintf(value->name, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, i);
        value->value = getRandomBooleanValue();

        if (insertToHashMap(&map, value->name, value->value) != OK) {
            free(value->name);
            free(value);
            freeHashMap(&map);
            return ERROR;
        }
        free(value->name);
        free(value);
    }

    printHashMap(&map);

    if (generateHashMapGraph(&map, graphOutput) != OK) {
        freeHashMap(&map);
        return ERROR;   
    }

    for (int i = 0; i < KEY_COUNT; i++) {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, i);

        if (selectFromHashMap(&map, key_string) == NULL) {
            free(value->name);
            free(value);
            freeHashMap(&map);
            return ERROR;    
        }
        if (removeFromHashMap(&map, key_string) != OK) {
            free(value->name);
            free(value);
            freeHashMap(&map);
            return ERROR;    
        }
    }

    printHashMap(&map);
    freeHashMap(&map);

    return OK;
}

int main(int argc, char* argv[]) {

    struct stat st = {0};

    if (stat("./testOutput", &st) == -1) {
        mkdir("./testOutput", 0700);
    }

    freopen ("./testOutput/test1-output", "a+", stdout);
    int test1Result = hashMapTest("./testOutput/test1-graph.gv");
    freopen ("./testOutput/test2-output", "a+", stdout);
    int test2Result = singleFunctionTest("./testOutput/test2-graph.gv");
    freopen ("./testOutput/test3-output", "a+", stdout);    
    int test3Result = multipleFunctionsTest("./testOutput/test3-graph.gv");
    freopen ("./testOutput/test4-output", "a+", stdout);
    int test4Result = variableValueChangeTest("./testOutput/test4-graph.gv");
    freopen ("./testOutput/test5-output", "a+", stdout);
    int test5Result = bigDataInputTest("./testOutput/test5-graph.gv");

    freopen("/dev/tty", "w", stdout);
    printf("TEST 01: HashMap Test                ..... Result: %s %d\n", (test1Result == OK) ? "SUCCESS" : "FAILURE", test1Result);
    printf("TEST 02: Single Function Test        ..... Result: %s %d\n", (test2Result == OK) ? "SUCCESS" : "FAILURE", test2Result);
    printf("TEST 03: Multiple Functions Test     ..... Result: %s %d\n", (test3Result == OK) ? "SUCCESS" : "FAILURE", test3Result);
    printf("TEST 04: Variable Value Change Test  ..... Result: %s %d\n", (test4Result == OK) ? "SUCCESS" : "FAILURE", test4Result);
    printf("TEST 05: Big Data HashMap Input Test ..... Result: %s %d\n", (test5Result == OK) ? "SUCCESS" : "FAILURE", test5Result);


}