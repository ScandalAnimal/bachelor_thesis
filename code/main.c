/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "evaluator.h"
#include "hashmap.h"
#include "utils.h"

int main(int argc, char *argv[]) {

    tEvaluator evaluator = initEvaluator();

    int INPUT_LENGTH = 3;
    bool input[INPUT_LENGTH];

    for (int i = 0; i < INPUT_LENGTH; i++) {
        input[i] = getRandomBooleanValue();
    }

    tHashMapRecord* value;

    int keyLength = getDigitCount(INPUT_LENGTH) + 2; // letter I + end of string character

    for (int i = 0; i < INPUT_LENGTH; i++) {
        value = malloc(sizeof(tHashMapRecord));
        snprintf((char *) value->key, (size_t) keyLength, "I%d", i);
        value->value = input[i];

        addVariable(&evaluator, value->key, value->value);
        free(value);
    }

    printHashMap(evaluator.variables);

    destroyEvaluator(&evaluator);

    return 0;
}
