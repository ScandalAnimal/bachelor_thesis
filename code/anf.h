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
} tANFBundle;

// initialCapacity, loadFactor
extern void* 	createANFBundle(unsigned int, double);
extern void  	freeANFBundle(tANFBundle*);
extern void  	printBundle(tANFBundle*);
extern void		printBundleMap(tANFBundle*);


extern void*	createEmptyAnf();
extern void*	createEmptyAnfInBundle(tANFBundle*);
extern int  	addAnfToBundle(tANFBundle*, tAnf*);
extern int		deleteAnfFromBundle(tANFBundle*, tAnf*);
extern void		freeAnf(tAnf*);
extern void 	printAnf(tAnf*);

extern void*	createAnfWithNodesInBundle(tANFBundle*, tNode**, int);

extern void* 	createNodeInBundle(tANFBundle*);
extern int	 	deleteNodeFromBundle(tANFBundle*, tNode*);
extern void*	createNodeWithVarsInBundle(tANFBundle*, tVar[], int);

extern int 		addNodeToAnf(tNode*, tAnf*);
extern int 		addNodesToAnf(tNode**, int, tAnf*);

extern tVar		createVarInBundle(tANFBundle*, char*, bool);
extern tVar		createTrueVarInBundle(tANFBundle*, char*);
extern tVar		createFalseVarInBundle(tANFBundle*, char*);
extern int		createVarsInBundle(tANFBundle*, tVar[], int);

// extern void		iterateOverBundle(tANFBundle*);


#endif //CODE_ANF_H