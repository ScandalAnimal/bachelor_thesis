/** 
 * @file
 * @brief functions for generating DOT graphs
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include <stdio.h>
#include <stdbool.h>
#include "anfutils.h"

/**
 * prints initial graph sequence that makes graph style
 * @param file file to write
 */
void printInitGraphSequence(FILE* file);

/**
 * basically prints one bracket
 * @param file file to write
 */
void printEndGraphSequence(FILE* file);

/**
 * prints root node of graph
 * @param file file to write
 * @param rootName root label
 * @param printValue if true printing also value of node
 * @param value value of node to print
 */
void printSingleRootNode(FILE* file , char* rootName, bool printValue, bool value);

/**
 * prints multiple roots of graph
 * @param file file to write
 * @param nodeCount counter of how many roots to print
 */
void printMultipleRootNodes(FILE* file, int nodeCount);

/**
 * prints arrow that connects two nodes
 * @param file file to write
 * @param leftSideNodeNumber number of node from which arrow starts
 * @param leftSideNodePort field number from which arrow starts
 * @param rightSideNodeNumber number of node where arrow finishes
 */
void printArrow(FILE* file, int leftSideNodeNumber, int leftSideNodePort, int rightSideNodeNumber);

/**
 * prints node with its boolean value
 * @param file file to write
 * @param nodeNumber number of node to print
 * @param key label of node
 * @param value value to print
 */
void printNodeWithValue(FILE* file, int nodeNumber, const char* key, bool value);

/**
 * prints node without its value
 * @param file file to write
 * @param nodeNumber number of node to print
 * @param key label of node
 */
void printNodeWithoutValue(FILE* file, int nodeNumber, char* key);

/**
 * prints nodes without specific labels
 * @param file file to write
 * @param nodeCount how many nodes to print
 * @param nodeInitNumber initial number from which start numbering created nodes
 * @param prefix name prefix for labeling nodes
 * @param arrowLeftSidePort number of field from which add arrows to newly created nodes
 * @return number of last created node
 */
int  printAnonymousNodes(FILE* file, int nodeCount, int nodeInitNumber, char* prefix, int arrowLeftSidePort);

#endif //CODE_GRAPH_H
