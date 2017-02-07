/** 
 * @author Maroš Vasilišin <mvasilisin@gmail.com>
 */

#ifndef CODE_HASHMAP_H
#define CODE_HASHMAP_H

#define DEFAULT_HASHMAP_CAPACITY 256

extern void*    createHashMap(long);

extern void     freeHashMap(void*);
extern long     getHashMapCapacity(void*);

#endif //CODE_HASHMAP_H
