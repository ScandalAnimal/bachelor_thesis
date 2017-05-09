/** 
 * @file
 * @brief functions for manipulating with variables
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include "variable.h"

tVar createVar(char* name, bool value) {
    
    tVar var;
    var.name = name;
    var.value = value;
    return var;    
}

tVar createTrueVar(char* name) {
    
    tVar var;
    var.name = name;
    var.value = true;
    return var;    
}

tVar createFalseVar(char* name) {
    
    tVar var;
    var.name = name;
    var.value = false;
    return var;    
}