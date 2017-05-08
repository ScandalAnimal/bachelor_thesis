/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

void printInitGraphSequence(FILE*);
void printEndGraphSequence(FILE*);
void printSingleRootNode(FILE*, char*);
void printMultipleRootNodes(FILE*, int);
void printArrow(FILE*, int, int, int);
void printNodeWithValue(FILE*, int, const char*, bool);
void printNodeWithoutValue(FILE*, int, char*);

int  printAnonymousNodes(FILE*, int, int, char*, int);

#endif //CODE_GRAPH_H