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
 	tMap hashMap;
 	int nodeCount;
    bool value;
} tAnf;

void printAnfMap(tAnf*);

void*	newAnf();
void* 	newAnfFrom2Anfs(tAnf*, tAnf*, bool);
void	freeAnf(tAnf*);
void 	printAnf(tAnf*);

void* 	newNodeInAnf(tAnf*);
int	 	deleteNodeFromAnf(tAnf*, tNode*);
int 	deleteAllNodesFromAnf(tAnf*, bool);
void*	newNodeWithVarsInAnf(tAnf*, tVar[], int);
int 	addVarToNodeInAnf(tAnf*, tNode*, tVar);
int 	addVarsToNodeInAnf(tAnf*, tNode*, tVar[], int);

tVar	createVarInAnf(tAnf*, char*, bool);
tVar	createTrueVarInAnf(tAnf*, char*);
tVar	createFalseVarInAnf(tAnf*, char*);
int		createVarsInAnf(tAnf*, tVar[], int);
int 	deleteVarFromAnf(tAnf*, char*, bool);
int 	switchVarValueInAnf(char*, tAnf*);

int 	generateAnfGraph(tAnf*, char*);

#endif //CODE_ANF_H