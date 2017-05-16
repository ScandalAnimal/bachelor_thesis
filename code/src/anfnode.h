/*
	Copyright 1992-2017 Maroš Vasilišin. All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** 
 * @file
 * @brief functions for manipulating with node
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_NODE_H
#define CODE_NODE_H

#include <stdbool.h>
#include <string.h>
#include "anfhashmap.h"
#include "anfvariable.h"

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
