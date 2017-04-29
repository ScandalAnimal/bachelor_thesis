/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_ANF_H
#define CODE_ANF_H

#include <stdbool.h>
#include "node.h"
#include "graph.h"
#include "hashmap.h"
#include "error.h"
#include "variable.h"

typedef struct anf {
    tNode** nodeList;
 	tHashMap* hashMap;
 	int nodeCount;
    bool value;
} tAnf;

// typedef struct ANFBundle {
// 	tHashMap* hashmap;
// 	tNode** nodes;
// 	unsigned int nodeCount;
// 	tAnf** anfs;
// 	unsigned int anfsCount;
// } tANFBundle;

// void* 	createANFBundle(unsigned int, double);
// void  	freeANFBundle(tANFBundle*);
// void  	printBundle(tANFBundle*);
// void	printBundleMap(tANFBundle*);

// initialCapacity, loadFactor
void*	newAnf(int, double);
// void*	createEmptyAnfInBundle(tANFBundle*);
// int  	addAnfToBundle(tANFBundle*, tAnf*);
// int		deleteAnfFromBundle(tANFBundle*, tAnf*);
void	freeAnf(tAnf*);
void 	printAnf(tAnf*);

// void*	createAnfWithNodesInBundle(tANFBundle*, tNode**, int);

void* 	newNodeInAnf(tAnf*);
int	 	deleteNodeFromAnf(tAnf*, tNode*);
void*	newNodeWithVarsInAnf(tAnf*, tVar[], int);

// int 	addNodeToAnf(tAnf*, tNode*);
// int 	addNodesToAnf(tANFBundle*, tNode**, int, tAnf*);

tVar	createVarInAnf(tAnf*, char*, bool);
tVar	createTrueVarInAnf(tAnf*, char*);
tVar	createFalseVarInAnf(tAnf*, char*);
int		createVarsInAnf(tAnf*, tVar[], int);

// int 	generateAnfGraph(tAnf*, char*);
// int 	generateBundleGraph(tANFBundle*, char*);

//void	iterateOverBundle(tANFBundle*);


#endif //CODE_ANF_H