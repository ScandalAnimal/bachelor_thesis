/** 
 * @file
 * @brief functions for manipulating with anf
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

/** structure for representing boolean function in anf*/
typedef struct anf {
	/** list of pointers to all nodes in anf*/
    tNode** nodeList; 
 	/** hash map of all variables in anf*/
 	tMap hashMap; 
 	/** count of nodes in anf*/
 	int nodeCount;
 	/** current boolean value of anf*/ 
    bool value; 
} tAnf;

/**
 * function prints contents and structure of hash map to console
 * @param anf anf in which is hash map to print
 */
void printAnfMap(tAnf* anf);

/**
 * function creates new anf structure
 * @return created anf
 */
void* newAnf();

/**
 * function xors 2 exiting anfs to one new
 * @param anf1 first anf to merge
 * @param anf2 second anf to merge
 * @param valuesFromAnf1 if true values from anf1 have higher priority, if false in reverse
 * @return pointer to created new anf
 */
void* newAnfFrom2Anfs(tAnf* anf1, tAnf* anf2, bool valuesFromAnf1);

/**
 * frees anf from memory
 * @param anf anf to free
 */
void freeAnf(tAnf* anf);

/**
 * prints structure of anf to console
 * @param anf anf to print
 */
void printAnf(tAnf* anf);

/**
 * creates new node in anf
 * @param anf anf in which to create node
 * @return pointer to created node
 */
void* newNodeInAnf(tAnf* anf);

/**
 * deletes node from anf specified
 * @param anf anf in which node is located
 * @param node node to delete
 * @return return code from <code>error.h</code>
 */
int	deleteNodeFromAnf(tAnf* anf, tNode* node);

/**
 * deletes all nodes from anf, optionally all variables too
 * @param anf anf in which to delete nodes
 * @param deleteVariables if true delets variables too
 * @return return code from <code>error.h</code>
 */
int deleteAllNodesFromAnf(tAnf* anf, bool deleteVariables);

/**
 * creates new node with variables specified in anf specified
 * @param anf anf in which to create node
 * @param varArray array of variables to insert to node
 * @param size size of varArray
 * @return pointer to created node
 */
void* newNodeWithVarsInAnf(tAnf* anf, tVar varArray[], int size);

/**
 * adds existing variables to node in anf
 * @param anf anf in which to add variable
 * @param node node to which adding variable
 * @param var variable to add
 * @return return code from <code>error.h</code>
 */
int addVarToNodeInAnf(tAnf* anf, tNode* node, tVar var);

/**
 * adds existing variables to node in anf
 * @param anf anf in which to add variables
 * @param node node to which adding variables
 * @param varArray array of variables to add to node
 * @param size size of varArray
 * @return return code from <code>error.h</code>
 */
int addVarsToNodeInAnf(tAnf* anf, tNode* node, tVar varArray[], int size);

/**
 * creates variable in anf
 * @param anf anf in which creating variable
 * @param name name of variable
 * @param value boolean value of variable
 * @return created variable
 */
tVar createVarInAnf(tAnf* anf, char* name, bool value);

/**
 * creates variable in anf with value true
 * @param anf anf in which creating variable
 * @param name name of variable
 * @return created variable
 */
tVar createTrueVarInAnf(tAnf* anf, char* name);

/**
 * creates variable in anf with value false
 * @param anf anf in which creating variable
 * @param name name of variable
 * @return created variable
 */
tVar createFalseVarInAnf(tAnf* anf, char* name);

/**
 * creates variables in anf
 * @param anf anf in which creating variables
 * @param varArray array of variables to create in anf
 * @param size size of varArray
 * @return return code from <code>error.h</code>
 */
int	createVarsInAnf(tAnf* anf, tVar varArray[], int size);

/**
 * function deletes variable from anf
 * @param anf anf in which deleting variable
 * @param name name of variable
 * @param deleteFromNodes if true deletes variable also from nodes, if false cannot delete if used in nodes
 * @return return code from <code>error.h</code>
 */
int deleteVarFromAnf(tAnf* anf, char* name, bool deleteFromNodes);

/**
 * triggers variable value switch between true/false
 * @param name name of variable
 * @param anf anf in which change happens
 * @return return code from <code>error.h</code>
 */
int switchVarValueInAnf(char* name, tAnf* anf);

/**
 * creates graph in DOT from anf
 * @param anf anf from which generating grah
 * @param filename file name where store result
 * @return return code from <code>error.h</code>
 */
int generateAnfGraph(tAnf* anf, char* filename);

#endif //CODE_ANF_H