/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include <stdio.h>
#include "utils.h"

extern void printInitGraphSequence(FILE*);
extern void printEndGraphSequence(FILE*);
extern void printSingleRootNode(FILE*, char*);
extern void printMultipleRootNodes(FILE*, int);

#endif //CODE_GRAPH_H