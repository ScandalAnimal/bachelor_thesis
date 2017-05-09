/**
 * @file
 * @brief util functions
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_UTILS_H
#define CODE_UTILS_H

#include <stdbool.h>
#include "variable.h"

/**
 * computes array size
 */
#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

/**
 * return pseudo randomly true or false
 * @return random bool
 */
bool 	getRandomBooleanValue();

/**
 * computes digit count from number
 * @param number number to compute
 * @return digit count of number
 */
int 	getDigitCount(int number);

/**
 * creates or opens file and erases contents
 * @param filename file to open
 * @return cleared file
 */
FILE*	openAndClearFile(char* filename);

#endif //CODE_UTILS_H
