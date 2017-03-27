/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_ANF_H
#define CODE_ANF_H

#include <stdbool.h>
#include "node.h"
#include "hashmap.h"
#include "error.h"
#include "variable.h"

typedef struct anf {
    int length;
    tNode** nodes;
    bool value;
} tAnf;

typedef struct ANFBundle {
	tHashMap* hashmap;
	tNode** nodes;
	unsigned int nodeCount;
	tAnf** anfs;
	unsigned int anfsCount;
	unsigned int maxVarLength;
} tANFBundle;


// initialCapacity, loadFactor, maxVariableNameLength
extern void* 	createANFBundle(unsigned int, double, unsigned int);

extern void  	freeANFBundle(tANFBundle*);

extern void* 	createNodeInBundle(tANFBundle*);
extern void*	createNodeWithVarsInBundle(tANFBundle*, tVar[], int);

extern tVar		createVarInBundle(tANFBundle*, char*, bool);
extern void		createVarsInBundle(tANFBundle*, tVar[], int);

extern void  	printBundle(tANFBundle*);
extern void		printBundleMap(tANFBundle*);

extern void*	createAnf();
extern void*	createAnfWithNodesInBundle(tANFBundle*, tNode**, int);
extern void 	addNodeToAnf(tNode*, tAnf*);
extern void 	addNodesToAnf(tNode**, int, tAnf*);

extern void		iterateOverBundle(tANFBundle*);

extern void 	printAnf(tAnf*);
extern void		freeAnf(tAnf*);

#endif //CODE_ANF_H