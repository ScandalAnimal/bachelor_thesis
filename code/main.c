/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "utils.h"

int main(int argc, char *argv[]) {

    tHashMap* map = createHashMap(10,0.7);

    int INPUT_LENGTH = 3;
    int OUTPUT_LENGTH = 3;
    bool input[INPUT_LENGTH];

    for (int i = 0; i < INPUT_LENGTH; i++) {
//        input[i] = getRandomBooleanValue();
        input[i] = true; // for tests
    }

    tHashMapRecord* value;

    int keyLength = getDigitCount(INPUT_LENGTH) + 2; // letter I + end of string character

    // saving inputs to map
//    for (int i = 0; i < INPUT_LENGTH; i++) {
//        printf("In main for cycle: value: %d\n", i);
//
//        value = malloc(sizeof(tHashMapRecord));
//        snprintf((char *) value->key, (size_t) keyLength, "I%d", i);
//        value->value = input[i];
//
//        insertToHashMap(map, value->key, value->value);
//        free(value);
//    }

    // saving init outputs to map
    for (int i = 0; i < OUTPUT_LENGTH; i++) {
        value = malloc(sizeof(tHashMapRecord));
        snprintf((char *) value->key, (size_t) keyLength, "X%d", i);
        value->value = false;

        insertToHashMap(map, value->key, value->value);
        free(value);
    }

    // selecting from map
//    for (int i = 0; i < OUTPUT_LENGTH; i++) {
//        tHashMapRecord* expected = malloc(sizeof(tHashMapRecord));
//        value = malloc(sizeof(tHashMapRecord));
//        snprintf((char *) expected->key, (size_t) keyLength, "X%d", i);
//
//        selectFromHashMap(map, expected->key, value);
//        free(value);
//        free(expected);
//    }
    printHashMap(map);

    // x0 xor x1*x2

    for (int i = 0; i < INPUT_LENGTH; i++) {
        tHashMapRecord* x0 = malloc(sizeof(tHashMapRecord));
        tHashMapRecord* x1 = malloc(sizeof(tHashMapRecord));
        tHashMapRecord* x2 = malloc(sizeof(tHashMapRecord));

        selectFromHashMap(map, "X0", x0);
        selectFromHashMap(map, "X1", x1);
        selectFromHashMap(map, "X2", x2);

        bool newX0 = input[1] ^ (x1->value & x2->value);

        printf("s\n");
        insertToHashMap(map, "X2", x1->value);
        printf("1\n");
        insertToHashMap(map, "X1", x0->value);
        insertToHashMap(map, "X0", newX0);
        printf("EOC\n");

        free(x0);
        free(x1);
        free(x2);
    }

    printHashMap(map);

    freeHashMap(map);
    return 0;
}
