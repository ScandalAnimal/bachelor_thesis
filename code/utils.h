/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef BACHELOR_THESIS_UTILS_H
#define BACHELOR_THESIS_UTILS_H

#include <stdbool.h>
#include "variable.h"

#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

extern bool getRandomBooleanValue();
extern int getDigitCount(int);

#endif //BACHELOR_THESIS_UTILS_H
