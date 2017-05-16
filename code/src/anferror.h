/*
	Copyright 1992-2017 Maroš Vasilišin. All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
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