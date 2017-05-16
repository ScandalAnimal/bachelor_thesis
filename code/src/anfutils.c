/*
    Copyright 1992-2017 Maroš Vasilišin. All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @file
 * @brief util functions
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdlib.h>
#include "anfutils.h"


bool getRandomBooleanValue() {
    return 0 == rand() % 2 ? true : false;
}

int getDigitCount(int number) {
    int count = 0;

    if (number == 0) {
        return 1;
    }

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
