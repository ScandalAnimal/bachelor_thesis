/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_UTILS_H
#define CODE_UTILS_H

#include <stdbool.h>
#include "variable.h"

#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

extern bool 	getRandomBooleanValue();
extern int 		getDigitCount(int);

extern bool		getTrue();
extern bool		getFalse();

#endif //CODE_UTILS_H
