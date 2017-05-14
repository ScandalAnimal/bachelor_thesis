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
