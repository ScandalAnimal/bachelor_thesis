# 1 "list_atomic.c"
# 1 "/home/norman/CLionProjects/bachelor_thesis/code/lib/gc-7.2/libatomic_ops/tests//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "list_atomic.c"
# 1 "../src/atomic_ops.h" 1
# 27 "../src/atomic_ops.h"
# 1 "/usr/include/assert.h" 1 3 4
# 35 "/usr/include/assert.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 367 "/usr/include/features.h" 3 4
# 1 "/usr/include/i386-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/i386-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/i386-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/i386-linux-gnu/sys/cdefs.h" 2 3 4
# 368 "/usr/include/features.h" 2 3 4
# 391 "/usr/include/features.h" 3 4
# 1 "/usr/include/i386-linux-gnu/gnu/stubs.h" 1 3 4






# 1 "/usr/include/i386-linux-gnu/gnu/stubs-32.h" 1 3 4
# 8 "/usr/include/i386-linux-gnu/gnu/stubs.h" 2 3 4
# 392 "/usr/include/features.h" 2 3 4
# 36 "/usr/include/assert.h" 2 3 4
# 28 "../src/atomic_ops.h" 2
# 1 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 3 4

# 149 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 216 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 3 4
typedef unsigned int size_t;
# 328 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 3 4
typedef long int wchar_t;
# 426 "/usr/lib/gcc/i686-linux-gnu/5/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 29 "../src/atomic_ops.h" 2
# 212 "../src/atomic_ops.h"
# 1 "../src/atomic_ops/sysdeps/gcc/x86.h" 1
# 24 "../src/atomic_ops/sysdeps/gcc/x86.h"
# 1 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h" 1
# 28 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h"
# 1 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h" 1
# 26 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h"

# 26 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h"
static __inline size_t
AO_load(const volatile size_t *addr)
{
  
# 29 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 29 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h"
                                                 ;


  return *(size_t *)addr;
}


static __inline void
AO_store(volatile size_t *addr, size_t new_val)
{
  
# 39 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 39 "../src/atomic_ops/sysdeps/gcc/../aligned_atomic_load_store.h"
                                                 ;
  (*(size_t *)addr) = new_val;
}
# 29 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h" 2
# 1 "../src/atomic_ops/sysdeps/gcc/../char_atomic_load_store.h" 1
# 26 "../src/atomic_ops/sysdeps/gcc/../char_atomic_load_store.h"
static __inline unsigned char
AO_char_load(const volatile unsigned char *addr)
{


  return (*(const unsigned char *)addr);
}


static __inline void
AO_char_store(volatile unsigned char *addr, unsigned char new_val)
{
  (*(unsigned char *)addr) = new_val;
}
# 30 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h" 2
# 1 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h" 1
# 28 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h"
static __inline unsigned short
AO_short_load(const volatile unsigned short *addr)
{
  
# 31 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 31 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h"
                                                           ;


  return (*(unsigned short *)addr);
}


static __inline void
AO_short_store(volatile unsigned short *addr, unsigned short new_val)
{
  
# 41 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 41 "../src/atomic_ops/sysdeps/gcc/../short_aligned_atomic_load_store.h"
                                                           ;
  (*(unsigned short *)addr) = new_val;
}
# 31 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h" 2
# 1 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h" 1
# 26 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h"
static __inline unsigned int
AO_int_load(const volatile unsigned int *addr)
{
  
# 29 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 29 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h"
                                                         ;


  return (*(unsigned int *)addr);
}


static __inline void
AO_int_store(volatile unsigned int *addr, unsigned int new_val)
{
  
# 39 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h" 3 4
 ((void) (0))
# 39 "../src/atomic_ops/sysdeps/gcc/../int_aligned_atomic_load_store.h"
                                                         ;
  (*(unsigned int *)addr) = new_val;
}
# 31 "../src/atomic_ops/sysdeps/gcc/../all_aligned_atomic_load_store.h" 2
# 25 "../src/atomic_ops/sysdeps/gcc/x86.h" 2
# 33 "../src/atomic_ops/sysdeps/gcc/x86.h"
# 1 "../src/atomic_ops/sysdeps/gcc/../ordered_except_wr.h" 1
# 30 "../src/atomic_ops/sysdeps/gcc/../ordered_except_wr.h"
# 1 "../src/atomic_ops/sysdeps/gcc/../read_ordered.h" 1
# 30 "../src/atomic_ops/sysdeps/gcc/../read_ordered.h"
static __inline void
AO_nop_read(void)
{
  __asm__ __volatile__("" : : : "memory");
}



  static __inline size_t
  AO_load_read(const volatile size_t *addr)
  {
    size_t result = AO_load(addr);
    __asm__ __volatile__("" : : : "memory");
    return result;
  }







  static __inline unsigned char
  AO_char_load_read(const volatile unsigned char *addr)
  {
    unsigned char result = AO_char_load(addr);
    __asm__ __volatile__("" : : : "memory");
    return result;
  }







  static __inline unsigned short
  AO_short_load_read(const volatile unsigned short *addr)
  {
    unsigned short result = AO_short_load(addr);
    __asm__ __volatile__("" : : : "memory");
    return result;
  }







  static __inline unsigned int
  AO_int_load_read(const volatile unsigned int *addr)
  {
    unsigned int result = AO_int_load(addr);
    __asm__ __volatile__("" : : : "memory");
    return result;
  }
# 31 "../src/atomic_ops/sysdeps/gcc/../ordered_except_wr.h" 2

static __inline void
AO_nop_write(void)
{
  __asm__ __volatile__("" : : : "memory");


}



  static __inline void
  AO_store_write(volatile size_t *addr, size_t val)
  {
    __asm__ __volatile__("" : : : "memory");
    AO_store(addr, val);
  }







  static __inline void
  AO_char_store_write(volatile unsigned char *addr, unsigned char val)
  {
    __asm__ __volatile__("" : : : "memory");
    AO_char_store(addr, val);
  }







  static __inline void
  AO_short_store_write(volatile unsigned short *addr, unsigned short val)
  {
    __asm__ __volatile__("" : : : "memory");
    AO_short_store(addr, val);
  }







  static __inline void
  AO_int_store_write(volatile unsigned int *addr, unsigned int val)
  {
    __asm__ __volatile__("" : : : "memory");
    AO_int_store(addr, val);
  }
# 34 "../src/atomic_ops/sysdeps/gcc/x86.h" 2

# 1 "../src/atomic_ops/sysdeps/gcc/../test_and_set_t_is_char.h" 1
# 30 "../src/atomic_ops/sysdeps/gcc/../test_and_set_t_is_char.h"
typedef enum {AO_BYTE_TS_clear = 0, AO_BYTE_TS_set = 0xff} AO_BYTE_TS_val;
# 36 "../src/atomic_ops/sysdeps/gcc/x86.h" 2

# 1 "../src/atomic_ops/sysdeps/gcc/../standard_ao_double_t.h" 1
# 16 "../src/atomic_ops/sysdeps/gcc/../standard_ao_double_t.h"
  typedef unsigned long long double_ptr_storage;



typedef union {
    double_ptr_storage AO_whole;
    struct {size_t AO_v1; size_t AO_v2;} AO_parts;
} AO_double_t;
# 38 "../src/atomic_ops/sysdeps/gcc/x86.h" 2
# 59 "../src/atomic_ops/sysdeps/gcc/x86.h"
static __inline size_t
AO_fetch_and_add_full (volatile size_t *p, size_t incr)
{
  size_t result;

  __asm__ __volatile__ ("lock; xaddl %0, %1" :
                        "=r" (result), "=m" (*p) : "0" (incr), "m" (*p)
                        : "memory");
  return result;
}


static __inline unsigned char
AO_char_fetch_and_add_full (volatile unsigned char *p, unsigned char incr)
{
  unsigned char result;

  __asm__ __volatile__ ("lock; xaddb %0, %1" :
                        "=q" (result), "=m" (*p) : "0" (incr), "m" (*p)
                        : "memory");
  return result;
}


static __inline unsigned short
AO_short_fetch_and_add_full (volatile unsigned short *p, unsigned short incr)
{
  unsigned short result;

  __asm__ __volatile__ ("lock; xaddw %0, %1" :
                        "=r" (result), "=m" (*p) : "0" (incr), "m" (*p)
                        : "memory");
  return result;
}



static __inline void
AO_or_full (volatile size_t *p, size_t incr)
{
  __asm__ __volatile__ ("lock; orl %1, %0" :
                        "=m" (*p) : "r" (incr), "m" (*p) : "memory");
}


static __inline AO_BYTE_TS_val
AO_test_and_set_full(volatile unsigned char *addr)
{
  unsigned char oldval;

  __asm__ __volatile__("xchgb %0, %1"
                : "=q"(oldval), "=m"(*addr)
                : "0"((unsigned char)0xff), "m"(*addr) : "memory");
  return (AO_BYTE_TS_val)oldval;
}



static __inline int
AO_compare_and_swap_full(volatile size_t *addr, size_t old, size_t new_val)
{



    char result;
    __asm__ __volatile__("lock; cmpxchgl %3, %0; setz %1"
                         : "=m" (*addr), "=a" (result)
                         : "m" (*addr), "r" (new_val), "a" (old) : "memory");
    return (int)result;

}






static __inline int
AO_compare_double_and_swap_double_full(volatile AO_double_t *addr,
                                       size_t old_val1, size_t old_val2,
                                       size_t new_val1, size_t new_val2)
{
  char result;
# 186 "../src/atomic_ops/sysdeps/gcc/x86.h"
    __asm__ __volatile__("lock; cmpxchg8b %0; setz %1"
                       : "=m" (*addr), "=a" (result)
                       : "m" (*addr), "d" (old_val2), "a" (old_val1),
                         "c" (new_val2), "b" (new_val1) : "memory");

  return (int) result;
}
# 229 "../src/atomic_ops/sysdeps/gcc/x86.h"
# 1 "../src/atomic_ops/sysdeps/gcc/../ao_t_is_int.h" 1
# 229 "../src/atomic_ops/sysdeps/gcc/x86.h" 2
# 213 "../src/atomic_ops.h" 2
# 379 "../src/atomic_ops.h"
# 1 "../src/atomic_ops/generalize.h" 1
# 141 "../src/atomic_ops/generalize.h"
  static __inline void AO_nop(void) {}




  static __inline void
  AO_nop_full(void)
  {
    unsigned char dummy = (size_t)AO_BYTE_TS_clear;
    AO_test_and_set_full(&dummy);
  }
# 979 "../src/atomic_ops/generalize.h"
# 1 "../src/atomic_ops/generalize-small.h" 1
# 980 "../src/atomic_ops/generalize.h" 2
# 1219 "../src/atomic_ops/generalize.h"
  static __inline int
  AO_double_compare_and_swap_release(volatile AO_double_t *addr,
                                     AO_double_t old_val, AO_double_t new_val)
  {
    return AO_compare_double_and_swap_double_full(addr,old_val.AO_parts.AO_v1,old_val.AO_parts.AO_v2,new_val.AO_parts.AO_v1,new_val.AO_parts.AO_v2)

                                                                           ;
  }





  static __inline int
  AO_double_compare_and_swap_acquire(volatile AO_double_t *addr,
                                     AO_double_t old_val, AO_double_t new_val)
  {
    return AO_compare_double_and_swap_double_full(addr,old_val.AO_parts.AO_v1,old_val.AO_parts.AO_v2,new_val.AO_parts.AO_v1,new_val.AO_parts.AO_v2)

                                                                           ;
  }





  static __inline int
  AO_double_compare_and_swap_full(volatile AO_double_t *addr,
                                  AO_double_t old_val, AO_double_t new_val)
  {
    return AO_compare_double_and_swap_double_full(addr,
                                          old_val.AO_parts.AO_v1, old_val.AO_parts.AO_v2,
                                          new_val.AO_parts.AO_v1, new_val.AO_parts.AO_v2);
  }
# 380 "../src/atomic_ops.h" 2
# 2 "list_atomic.c" 2
# 15 "list_atomic.c"
void list_atomic(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;


    "AO_nop(): ";
    AO_nop();




    "AO_load(&val):";
    AO_load(&val);




    "AO_store(&val, newval):";
    AO_store(&val, newval);




    "AO_test_and_set(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 83 "list_atomic.c"
void list_atomic_release(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;





    "No AO_nop_release";





    "No AO_load_release";


    "AO_store_release(&val, newval):";
    AO_store_write(&val, newval);




    "AO_test_and_set_release(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_release(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_release(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_release(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_release(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 151 "list_atomic.c"
void list_atomic_acquire(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;





    "No AO_nop_acquire";


    "AO_load_acquire(&val):";
    AO_load_read(&val);







    "No AO_store_acquire";


    "AO_test_and_set_acquire(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_acquire(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_acquire(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_acquire(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_acquire(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 219 "list_atomic.c"
void list_atomic_read(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;


    "AO_nop_read(): ";
    AO_nop_read();




    "AO_load_read(&val):";
    AO_load_read(&val);







    "No AO_store_read";


    "AO_test_and_set_read(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_read(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_read(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_read(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_read(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 287 "list_atomic.c"
void list_atomic_write(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;


    "AO_nop_write(): ";
    AO_nop_write();







    "No AO_load_write";


    "AO_store_write(&val, newval):";
    AO_store_write(&val, newval);




    "AO_test_and_set_write(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_write(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_write(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_write(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_write(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 355 "list_atomic.c"
void list_atomic_full(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;


    "AO_nop_full(): ";
    AO_nop_full();




    "AO_load_full(&val):";
    (AO_nop_full(), AO_load_read(&val));




    "AO_store_full(&val, newval):";
    (AO_store_write(&val, newval), AO_nop_full());




    "AO_test_and_set_full(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_full(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_full(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_full(&val, incr):";
    AO_fetch_and_add_full(&val, incr);




    "AO_compare_and_swap_full(&val, oldval, newval):";
    AO_compare_and_swap_full(&val, oldval, newval);



}
# 423 "list_atomic.c"
void list_atomic_release_write(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;





    "No AO_nop_release_write";





    "No AO_load_release_write";


    "AO_store_release_write(&val, newval):";
    AO_store_write(&val, newval);




    "AO_test_and_set_release_write(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_release_write(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_release_write(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_release_write(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_release_write(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
# 491 "list_atomic.c"
void list_atomic_acquire_read(void)
{
  size_t val, newval = 0, oldval = 0;
  unsigned char ts;
  long incr = 0;





    "No AO_nop_acquire_read";


    "AO_load_acquire_read(&val):";
    AO_load_read(&val);







    "No AO_store_acquire_read";


    "AO_test_and_set_acquire_read(&ts):";
    AO_test_and_set_full(&ts);




    "AO_fetch_and_add1_acquire_read(&val):";
    AO_fetch_and_add_full(&val,1);




    "AO_fetch_and_sub1_acquire_read(&val):";
    AO_fetch_and_add_full(&val,(size_t)(-1));




    "AO_fetch_and_add_acquire_read(&val, incr):";
    AO_fetch_and_add_full(&val,incr);




    "AO_compare_and_swap_acquire_read(&val, oldval, newval):";
    AO_compare_and_swap_full(&val,oldval,newval);



}
