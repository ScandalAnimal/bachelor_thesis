/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_UTILS_H
#define CODE_UTILS_H

#include <stdbool.h>
#include "variable.h"

#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

bool 	getRandomBooleanValue();
int 	getDigitCount(int);
FILE*	openAndClearFile(char*);

#endif //CODE_UTILS_H
