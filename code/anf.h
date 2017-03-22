/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_ANF_H
#define CODE_ANF_H

#include <stdbool.h>
#include "node.h"
#include "hashmap.h"
#include "variable.h"

typedef struct ANFBundle {
	tHashMap* hashmap;
	tNode** nodes;
	unsigned int nodeCount;
	// tVar** vars;
	// unsigned int varsCount;
	unsigned int maxVarLength;
} tANFBundle;


// typedef struct anf {
//     int length;
//     node nodes[10];
// } anf;


// initialCapacity, loadFactor, maxVariableNameLength
extern void* 	createANFBundle(unsigned int, double, unsigned int);

extern void  	freeANFBundle(tANFBundle*);
extern void* 	createNodeInBundle(tANFBundle*);
extern tVar		createVarInBundle(tANFBundle*, char*, bool);

extern void  	printBundle(tANFBundle*);
extern void		printBundleMap(tANFBundle*);

// extern anf createAnf();
// extern anf createAnfWithNodes(node[], int);
// extern void addNodeToAnf(node, anf*);
// extern void printAnf(anf);

#endif //CODE_ANF_H