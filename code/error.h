/** 
 * @file
 * @brief error codes
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_ERROR_H
#define CODE_ERROR_H

/** OK status*/
#define OK	   			 0
/** general error*/
#define ERROR 			-1
/** error in malloc, realloc*/
#define ERR_MALLOC 		-2
/** error when inserting to map*/
#define ERR_INSERT 		-3
/** error when inserting duplicate to map*/
#define ERR_DUPLICATE 	-4
/** error when map is full*/
#define ERR_MAP_FULL	-5
/** error when deleting from map*/
#define ERR_DELETE		-6
/** error when deleting var that is in node*/
#define ERR_INNODE		-7
/** error deleting node that is in some anf*/
#define ERR_INANF		-8
/** error when opening file*/
#define ERR_OPEN		-9
/** error when selected record is not in map*/
#define ERR_NOTEXIST	-10
/** error when generating graph and port is non existent*/
#define NO_PORT			-1

#endif //CODE_ERROR_H