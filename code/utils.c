/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include "utils.h"


bool getRandomBooleanValue() {
    return 0 == rand() % 2 ? true : false;
}

int getDigitCount(int number) {
    int count = 0;

    while(number != 0)
    {
        number /= 10;
        ++count;
    }
    return count;
}

FILE* openAndClearFile(char* filename) {

	FILE* file = fopen(filename, "w");
  
    if (file == NULL) {
        return NULL;
    }
    fclose(file);

    file = fopen(filename, "a");
  
    if (file == NULL) {
        return NULL;
    }

    return file;
}