/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

extern void printInitGraphSequence(FILE*);
extern void printEndGraphSequence(FILE*);
extern void printSingleRootNode(FILE*, char*);
extern void printMultipleRootNodes(FILE*, int);
extern void printArrow(FILE*, int, int, int);
extern void printNodeWithValue(FILE*, int, char*, bool);
extern void printNodeWithoutValue(FILE*, int, char*);

extern int  printAnonymousNodes(FILE*, int, int, char*, int);

#endif //CODE_GRAPH_H