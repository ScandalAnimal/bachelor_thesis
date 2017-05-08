/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include "variable.h"

tVar createVar(const char* name, bool value) {
    
    tVar var;
    var.name = name;
    var.value = value;
    return var;    
}

tVar createTrueVar(const char* name) {
    
    tVar var;
    var.name = name;
    var.value = true;
    return var;    
}

tVar createFalseVar(const char* name) {
    
    tVar var;
    var.name = name;
    var.value = false;
    return var;    
}