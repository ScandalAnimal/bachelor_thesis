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
#include <anf.h>

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("key")
#define HELPER_PREFIX ("help")
#define KEY_COUNT (100)


int hashMapTest(char* graphOutput) {

    tMap map = createHashMap();

    if (!isHashMapEmpty(&map)) {
        freeHashMap(&map);
        return ERROR;
    }

    char* key1 = "Key1";
    if (insertToHashMap(&map, key1, true, "") != OK) {
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

    if (insertToHashMap(&map, key2, true, "") != OK) {
        freeHashMap(&map);
        return ERROR;
    }

    char* key3 = "Key3";
    if (insertToHashMap(&map, key3, true, "") != OK) {
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
        freeAnf(anf1);
        return ERROR;
    }

    printAnf(anf1);
    printHashMap(&(anf1->hashMap));

    tAnf* anf2 = newAnf();
    if (anf2 == NULL) {
        freeAnf(anf1);
        return ERROR;
    }

    tNode* node3 = newNodeWithVarsInAnf(anf2, varArray3, ARRAY_SIZE(varArray3));
    if (node3 == NULL) {
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    tNode* node4 = newNodeWithVarsInAnf(anf2, varArray4, ARRAY_SIZE(varArray4));
    if (node4 == NULL) {
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    printAnf(anf2);
    printHashMap(&(anf2->hashMap));

    tAnf* anf3 = newAnfFrom2Anfs(anf1, anf2, true);
    if (anf3 == NULL) {
        freeAnf(anf1);
        freeAnf(anf2);
        return ERROR;
    }

    printAnf(anf3);
    printHashMap(&(anf3->hashMap));

    if (generateAnfGraph(anf3, graphOutput) != OK) {
        freeAnf(anf1);
        freeAnf(anf2);
        freeAnf(anf3);
        return ERROR;  
    }

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
        freeAnf(anf1);
        return ERROR;
    }

    printAnf(anf1);
    printNode(node1);
    printNode(node2);
    printHashMap(&(anf1->hashMap));

    if (switchVarValueInAnf("var2", anf1) != OK) {
        freeAnf(anf1);
        return ERROR;    
    }

    printAnf(anf1);
    printNode(node1);
    printNode(node2);
    printHashMap(&(anf1->hashMap));


    freeAnf(anf1);

    return OK;   
}

int bigDataInputTest(char* graphOutput) {

    tMap map = createHashMap();

    char key_string[KEY_MAX_LENGTH];
    tVar* value;
    

    for (int i = 0; i < KEY_COUNT; i++) {
        value = malloc(sizeof(tVar));
        value->name = malloc(sizeof(char) * KEY_MAX_LENGTH);
        snprintf(value->name, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, i);
        value->value = getRandomBooleanValue();

        if (insertToHashMap(&map, value->name, value->value, "") != OK) {
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

tAnf* evaluateBooleanFunction(tAnf* indexes[], int testNumber, int *helperFunctionsCounter) {

    if (testNumber == 6) {
        // A0 = A1 xor A2 xor A3;

        tAnf* newA0temp = newAnfFrom2Anfs(indexes[1], indexes[2], true);
        if (newA0temp == NULL) {
            return NULL;
        }
        tAnf* newA0 = newAnfFrom2Anfs(newA0temp, indexes[3], true);
        if (newA0 == NULL) {
            freeAnf(newA0temp);
            return NULL;
        }
        freeAnf(newA0temp);
        return newA0;
    }
    else if (testNumber == 8) {
        // result = A0 xor A1 xor A2;

        tAnf* resultTemp = newAnfFrom2Anfs(indexes[0], indexes[1], true);
        if (resultTemp == NULL) {
            return NULL;
        }
        tAnf* result = newAnfFrom2Anfs(resultTemp, indexes[2], true);
        if (result == NULL) {
            freeAnf(resultTemp);
            return NULL;
        }
        freeAnf(resultTemp);
        return result;
    }
    else if (testNumber == 7) {
        
        // A0 = (A0 xor A1 and A2) xor A3;

        char *x;
        x = malloc(sizeof(char) * KEY_MAX_LENGTH);
        snprintf(x, KEY_MAX_LENGTH, "%s%d", HELPER_PREFIX, 5);
        // printf("X: %s\n", x);

        tVar test;
        test.name = "test";
        test.value = false;
        test.origin = malloc(sizeof(x) * (strlen(x) + 1));
        strcpy(test.origin, x);

        free(x);

        // printf("Var: %s, %d, %s\n", test.name, test.value, test.origin);

        free(test.origin);


        char *help1, *help2;
        help1 = malloc(sizeof(char) * KEY_MAX_LENGTH);
        help2 = malloc(sizeof(char) * KEY_MAX_LENGTH);
        snprintf(help1, KEY_MAX_LENGTH, "%s%d", HELPER_PREFIX, *helperFunctionsCounter);
        *helperFunctionsCounter = *helperFunctionsCounter + 1;
        snprintf(help2, KEY_MAX_LENGTH, "%s%d", HELPER_PREFIX, *helperFunctionsCounter);
        *helperFunctionsCounter = *helperFunctionsCounter + 1;
        
        tAnf* newA0temp = newAnf();
        if (newA0temp == NULL) {
            return NULL;
        }

        char* origin1 = createOriginFromAnf(indexes[1]);
        char* origin2 = createOriginFromAnf(indexes[2]);

        tVar varArray[] = {
            createVarWithOrigin(help1, indexes[1]->value, origin1),
            createVarWithOrigin(help2, indexes[2]->value, origin2)
        };

        free(help1);
        free(help2);
        // printf("Var: %s, %d, %s\n", varArray[0].name, varArray[0].value, varArray[0].origin);
     
        newNodeWithVarsInAnf(newA0temp, varArray, ARRAY_SIZE(varArray));

        tAnf* newA0temp2 = newAnfFrom2Anfs(indexes[0], newA0temp, true);
        if (newA0temp2 == NULL) {
            return NULL;
        }
        tAnf* newA0 = newAnfFrom2Anfs(newA0temp2, indexes[3], true);
        if (newA0 == NULL) {
            freeAnf(newA0temp);
            return NULL;
        }

        // printHashMap(&(newA0->hashMap));

        // free(varArray[0].name);

        freeAnf(newA0temp);

        free(origin1);
        free(origin2);
        freeAnf(newA0temp2);

        return newA0;
    }
    return NULL;
}

int shiftRegisterTest(char* graphOutput) {
    
    int registerLength = 4;
    tVar originalValues[] = {
        createVar("A0", true),
        createVar("A1", false),
        createVar("A2", false),
        createVar("A3", false)
    };
    tAnf* reg[registerLength];
    tAnf* newA0;

    for (int i = 0; i < registerLength; i++) {
        reg[i] = newAnf();
        if (reg[i] == NULL) {
            return ERROR;
        }
        newNodeWithOneVarInAnf(reg[i], originalValues[i]);
    }

    for (int count = 0; count < 20; count++) {

        int x = 0;
        newA0 = evaluateBooleanFunction(reg, 6, &x);

        freeAnf(reg[3]);
        for (int i = (registerLength - 1); i > 0; i--) {
            reg[i] = reg[i-1];
        }

        reg[0] = newA0;

        if ((reg[0]->value == false) && 
            (reg[1]->value == false) && 
            (reg[2]->value == false) && 
            (reg[3]->value == false)) {
            printf("ALL FALSE STATE, END OF TEST.\n");
            break;
        } 

    }

    // printAnf(reg[0]);
    // printAnf(reg[1]);
    // printAnf(reg[2]);
    // printAnf(reg[3]);    
    // printHashMap(&(reg[0]->hashMap));

    for (int i = 0; i < registerLength; i++) {
        freeAnf(reg[i]);
    }

    return OK;
}

int andInBooleanFunctionTest(char* graphOutput) {
    
    int registerLength = 4;
    tVar originalValues[] = {
        createVar("A0", true),
        createVar("A1", false),
        createVar("A2", false),
        createVar("A3", false)
    };
    tAnf* reg[registerLength];
    tAnf* newA0;

    for (int i = 0; i < registerLength; i++) {
        reg[i] = newAnf();
        if (reg[i] == NULL) {
            return ERROR;
        }
        newNodeWithOneVarInAnf(reg[i], originalValues[i]);
    }

    // printAnf(reg[0]);
    // printAnf(reg[1]);
    // printAnf(reg[2]);
    // printAnf(reg[3]);

    int helperFunctionsCounter = 1;
    // for (int count = 0; count < 3; count++) {

        newA0 = evaluateBooleanFunction(reg, 7, &helperFunctionsCounter);

        freeAnf(reg[3]);
        for (int i = (registerLength - 1); i > 0; i--) {
            reg[i] = reg[i-1];
        }

        reg[0] = newA0;

        if ((reg[0]->value == false) && 
            (reg[1]->value == false) && 
            (reg[2]->value == false) && 
            (reg[3]->value == false)) {
            printf("ALL FALSE STATE, END OF TEST.\n");
            // break;
        } 

    // }

    printAnf(reg[0]);
    printAnf(reg[1]);
    printAnf(reg[2]);
    printAnf(reg[3]);    
    printHashMap(&(reg[0]->hashMap));
    printHashMap(&(reg[1]->hashMap));
    printHashMap(&(reg[2]->hashMap));
    printHashMap(&(reg[3]->hashMap));

    for (int i = 0; i < registerLength; i++) {
        freeAnf(reg[i]);
    }

    // freeAnf(newA0);
    return OK;
}

int threeXoredVariablesTest() {
    
    bool x1[] = {true, true, true, true, false, false, false, false};
    bool x2[] = {true, true, false, false, true, true, false, false};
    bool x3[] = {true, false, true, false, true, false, true, false};
    char* outputs[] = {"./testOutput/test8-0.gv", "./testOutput/test8-1.gv", "./testOutput/test8-2.gv",
     "./testOutput/test8-3.gv", "./testOutput/test8-4.gv", "./testOutput/test8-5.gv",
      "./testOutput/test8-6.gv", "./testOutput/test8-7.gv"};

    for (int i = 0; i < 8; i++) {

        tVar variables[] = {
            createVar("X1", x1[i]),
            createVar("X2", x2[i]),
            createVar("X3", x3[i])
        };
        int arrayLength = ARRAY_SIZE(variables);

        tAnf* function[arrayLength];
        tAnf* result;

        for (int j = 0; j < arrayLength; j++) {
            function[j] = newAnf();
            if (function[j] == NULL) {
                return ERROR;
            }
            newNodeWithOneVarInAnf(function[j], variables[j]);
        }

        int x = 0;
        result = evaluateBooleanFunction(function, 8, &x);

        printAnf(result);

        freopen (outputs[i], "a+", stdout);
        generateAnfGraph(result, outputs[i]);
        freopen("/dev/tty", "w", stdout);

        for (int i = 0; i < arrayLength; i++) {
            freeAnf(function[i]);
        }
        freeAnf(result);

    }

    return OK;
}

int main(int argc, char* argv[]) {

    struct stat st = {0};

    if (stat("./testOutput", &st) == -1) {
        mkdir("./testOutput", 0700);
    }

    // freopen ("./testOutput/test1-output", "a+", stdout);
    // int test1Result = hashMapTest("./testOutput/test1-graph.gv");
    // freopen ("./testOutput/test2-output", "a+", stdout);
    // int test2Result = singleFunctionTest("./testOutput/test2-graph.gv");
    // freopen ("./testOutput/test3-output", "a+", stdout);    
    // int test3Result = multipleFunctionsTest("./testOutput/test3-graph.gv");
    // freopen ("./testOutput/test4-output", "a+", stdout);
    // int test4Result = variableValueChangeTest("./testOutput/test4-graph.gv");
    // freopen ("./testOutput/test5-output", "a+", stdout);
    // int test5Result = bigDataInputTest("./testOutput/test5-graph.gv");
    // freopen ("./testOutput/test6-output", "a+", stdout);
    // int test6Result = shiftRegisterTest("./testOutput/test6-graph.gv");

    // freopen("/dev/tty", "w", stdout);

    // freopen ("./testOutput/test7-output", "a+", stdout);
    // int test7Result = andInBooleanFunctionTest("./testOutput/test7-graph.gv");
    int test8Result = threeXoredVariablesTest();

    // freopen("/dev/tty", "w", stdout);
    // printf("TEST 01: HashMap Test                 ..... Result: %s %d\n", (test1Result == OK) ? "SUCCESS" : "FAILURE", test1Result);
    // printf("TEST 02: Single Function Test         ..... Result: %s %d\n", (test2Result == OK) ? "SUCCESS" : "FAILURE", test2Result);
    // printf("TEST 03: Multiple Functions Test      ..... Result: %s %d\n", (test3Result == OK) ? "SUCCESS" : "FAILURE", test3Result);
    // printf("TEST 04: Variable Value Change Test   ..... Result: %s %d\n", (test4Result == OK) ? "SUCCESS" : "FAILURE", test4Result);
    // printf("TEST 05: Big Data HashMap Input Test  ..... Result: %s %d\n", (test5Result == OK) ? "SUCCESS" : "FAILURE", test5Result);
    // printf("TEST 06: Shift Register Test          ..... Result: %s %d\n", (test6Result == OK) ? "SUCCESS" : "FAILURE", test6Result);
    // printf("TEST 07: And In Boolean Function Test ..... Result: %s %d\n", (test7Result == OK) ? "SUCCESS" : "FAILURE", test7Result);
    printf("TEST 08: Three XORed Variables Test ..... Result: %s %d\n", (test8Result == OK) ? "SUCCESS" : "FAILURE", test8Result);


}