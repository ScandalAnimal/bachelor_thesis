/**
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "anf.h"
#include "utils.h"

tAnf* evaluateBooleanFunction(tAnf* indexes[]) {

	// A0 = A1 xor A2 xor A3;

	tAnf* newA0 = newAnfFrom2Anfs(indexes[1], indexes[2], true);
	if (newA0 == NULL) {
		return NULL;
	}
	newA0 = newAnfFrom2Anfs(newA0, indexes[3], true);
	if (newA0 == NULL) {
		return NULL;
	}
	return newA0;
}


int main(int argc, char *argv[]) {

	int registerLength = 4;
	tVar originalValues[] = {
		createVar("A0", true),
		createVar("A1", false),
		createVar("A2", false),
		createVar("A3", false)
	};
	tAnf* reg[registerLength];
	tNode* garbage[registerLength];
	

	for (int i = 0; i < registerLength; i++) {
		reg[i] = newAnf();
		if (reg[i] == NULL) {
		    return ERROR;
    	}
    	tVar array[1];
    	array[0] = originalValues[i];
    	garbage[i] = newNodeWithVarsInAnf(reg[i], array, 1);
	}

    printAnf(reg[0]);
    printAnf(reg[1]);
    printAnf(reg[2]);
    printAnf(reg[3]);

    for (int count = 0; count < 20; count++) {

    	tAnf* newA0 = evaluateBooleanFunction(reg);

    	printAnf(newA0);

	    for (int i = (registerLength - 1); i > 0; i--) {
	    	reg[i] = reg[i-1];
	    }
	    reg[0] = newA0;

	    printAnf(reg[0]);
	    printAnf(reg[1]);
	    printAnf(reg[2]);
	    printAnf(reg[3]);	
    }
    

    for (int i = 0; i < registerLength; i++) {
		freeAnf(reg[i]);
		freeNode(garbage[i]);
	}

	// freeAnf(newA0);
    return 0;
}

// #include <assert.h>
// #include <stdio.h>

// int main()
// {
//   int i;

//   GC_INIT();	/* Optional on Linux/X86; see below.  */
//   for (i = 0; i < 10000000; ++i)
//    {
//      int **p = (int **) GC_MALLOC(sizeof(int *));
//      int *q = (int *) GC_MALLOC_ATOMIC(sizeof(int));
//      assert(*p == 0);
//      *p = (int *) GC_REALLOC(q, 2 * sizeof(int));
//      if (i % 100000 == 0)
//        printf("Heap size = %d\n", GC_get_heap_size());
//    }
//   return 0;
// }