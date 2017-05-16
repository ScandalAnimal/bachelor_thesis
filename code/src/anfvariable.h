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

#ifndef CODE_VARIABLE_H
#define CODE_VARIABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "uthash.h"

/** structure for representing variable*/
typedef struct variable {
	/** namoe of variable*/
    char* name;
    /** boolean value of variable*/
    bool value;
    /** if variable was created from other variables, here is pseudo representation of its origin*/
    char* origin;
    /** handler for UTHash*/
   	UT_hash_handle hh;
} tVar;

/**
 * creates variable
 * @param name name of variable
 * @param value value of variable
 * @return created variable
 */
tVar createVar(char* name, bool value);

/**
 * creates variable with origin
 * @param name name of variable
 * @param value value of variable
 * @param origin origin of variable 
 * @return created variable
 */
tVar createVarWithOrigin(char* name, bool value, char* origin);

/**
 * creates variable with true value
 * @param name name of variable
 * @return created variable
 */
tVar createTrueVar(char* name);

/**
 * creates variable with false value
 * @param name name of variable
 * @return created variable
 */
tVar createFalseVar(char* name);

#endif //CODE_VARIABLE_H
