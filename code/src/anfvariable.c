/*
    Copyright 1992-2017 Maroš Vasilišin. All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** 
 * @file
 * @brief functions for manipulating with variables
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <string.h>
#include "anfvariable.h"

tVar createVar(char* name, bool value) {
    
    tVar var;
    var.name = name;
    var.value = value;
    var.origin = "";
    return var;    
}

tVar createVarWithOrigin(char* name, bool value, char* origin) {
    
    tVar var;
    // var.name = name;
    var.name = malloc(sizeof(name) * (strlen(name) + 1));
    strcpy(var.name, name);
    var.value = value;
    var.origin = origin;
    return var;
}

tVar createTrueVar(char* name) {
    
    tVar var;
    var.name = name;
    var.value = true;
    var.origin = "";
    return var;    
}

tVar createFalseVar(char* name) {
    
    tVar var;
    var.name = name;
    var.value = false;
    var.origin = "";
    return var;    
}
