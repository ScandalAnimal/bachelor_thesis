/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

typedef void * anyType;
//typedef anyType mapType;

extern anyType createHashMap();
extern void    freeHashMap(anyType);
extern int     getHashMapSize(anyType);

#endif //CODE_HASHMAP_H
