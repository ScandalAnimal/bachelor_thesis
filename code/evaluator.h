/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_EVALUATOR_H
#define CODE_EVALUATOR_H

#include <stdbool.h>

typedef struct evaluator {
    void* variables;
} tEvaluator;

extern tEvaluator initEvaluator();
extern void     addVariable(void*, unsigned char*, bool);
extern void     destroyEvaluator(void*);

#endif //CODE_EVALUATOR_H
