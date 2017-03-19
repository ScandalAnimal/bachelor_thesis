/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_ANF_H
#define CODE_ANF_H

#include <stdbool.h>
#include "node.h"

typedef struct anf {
    int length;
    node nodes[10];
} anf;

extern anf createAnf();
extern anf createAnfWithNodes(node[], int);
extern void addNodeToAnf(node, anf*);
extern void printAnf(anf);

#endif //CODE_ANF_H