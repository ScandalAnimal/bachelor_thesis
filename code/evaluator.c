/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */
#include <stdio.h>
#include "evaluator.h"
#include "hashmap.h"

tEvaluator initEvaluator() {

    tEvaluator evaluator;
    // TODO change variables
    tHashMap* map = createHashMap(2,0.5);
    evaluator.variables = map;
    return evaluator;
}

void addVariable(void* e, unsigned char *key, bool value) {
    tEvaluator *evaluator = (tEvaluator *) e;
    insertToHashMap(evaluator->variables,key,value);
}

void destroyEvaluator(void* e) {
    tEvaluator *evaluator = (tEvaluator *) e;
    freeHashMap(evaluator->variables);

}