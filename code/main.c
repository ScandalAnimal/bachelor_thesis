
#include <stdio.h>
#include <assert.h>
#include "evaluator.h"
#include "hashmap.h"

int main(int argc, char *argv[]) {

    tEvaluator evaluator = initEvaluator();

    addVariable(&evaluator, (unsigned char *) "A", 10);
    addVariable(&evaluator, (unsigned char *) "B", 20);
    addVariable(&evaluator, (unsigned char *) "C", 30);
    addVariable(&evaluator, (unsigned char *) "D", 40);
    addVariable(&evaluator, (unsigned char *) "E", 50);
    addVariable(&evaluator, (unsigned char *) "F", 60);
    addVariable(&evaluator, (unsigned char *) "GHI", 70);
    printHashMap(evaluator.variables);

    destroyEvaluator(&evaluator);

    return 0;
}
