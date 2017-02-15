
#include <stdio.h>
#include <assert.h>
#include "evaluator.h"
#include "hashmap.h"

int main(int argc, char *argv[]) {

    tEvaluator evaluator = initEvaluator();

    addVariable(&evaluator, (unsigned char *) "A", true);
    addVariable(&evaluator, (unsigned char *) "B", true);
    addVariable(&evaluator, (unsigned char *) "C", false);
    addVariable(&evaluator, (unsigned char *) "D", false);
    addVariable(&evaluator, (unsigned char *) "E", true);
    addVariable(&evaluator, (unsigned char *) "F", true);
    addVariable(&evaluator, (unsigned char *) "GHI", false);
    printHashMap(evaluator.variables);

    destroyEvaluator(&evaluator);

    return 0;
}
