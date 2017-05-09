/** 
 * @file
 * @brief functions for manipulating with node
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <stdbool.h>
#include <string.h>
#include "hashmap.h"
#include "variable.h"

/** structure for representing node*/
typedef struct node {	
	/** variables in node*/	
	char** variables;
	/** number of variables in node*/
    int varCount;
    /** current boolean value of node*/
    bool value;
} tNode;

/**
 * creates new node
 * @return pointer to created node
 */
void* 	newNode();

/**
 * adds existing variable to node
 * @param var variable to add
 * @param node node where to add variable
 * @return return code from <code>error.h</code>
 */
int	 	addVariableToNode(tVar var, tNode* node);

/**
 * adds array of variables to node
 * @param varArray array of variables to add
 * @param size size of varArray
 * @param node node where to add
 * @return return code from <code>error.h</code>
 */
int 	addVariablesToNode(tVar varArray[], int size, tNode* node);

/**
 * deletes variable specified from node
 * @param key name of variable to delete
 * @param node node where deleting
 * @return return code from <code>error.h</code>
 */
int		deleteVariableFromNode(const char* key, tNode* node);

/**
 * prints structure of node to console
 * @param node node to print
 */
void 	printNode(tNode* node);

/**
 * frees node from memory
 * @param node node to free
 */
void 	freeNode(tNode* node);

#endif //CODE_NODE_H