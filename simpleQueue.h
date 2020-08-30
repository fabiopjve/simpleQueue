/*
    Simple Queue - a simple and flexible macro-based queue

    Usage: use SIMPLEQUEUE8 to declare a queue of up to 256 elements or SIMPLEQUEUE16 to declare a queue of up to 65536 elements
    
    SIMPLEQUEUE8(test, char, 16) -> creates a queue named test which stores up to 16 char elements
    SIMPLEQUEUE8(test2, uint32_t, 40) -> creates a queue named test2 which stores up to 40 uint32_t elements
    SIMPLEQUEUE16(test3, char, 512) -> creates a queue named test3 which stores up to 512 char elements

*/

#ifndef __SIMPLEQUEUE_H
#define __SIMPLEQUEUE_H

#include <stdint.h>

/*
    SIMPLEQUEUE8 - declares a new queue "name" with "size" elements of "type", can be used for sizes up to 256
*/
#define SIMPLEQUEUE8(name, type, size) struct {type buffer[size]; uint8_t wIndex; uint8_t rIndex; uint8_t sz;}name={.wIndex=0,.rIndex=0,.sz=size};

/*
    SIMPLEQUEUE16 - declares a new queue "name" with "size" elements of "type", can be used for sizes up to 65536
*/
#define SIMPLEQUEUE16(name, type, size) struct {type buffer[size]; uint16_t wIndex; uint16_t rIndex; uint16_t sz = size;}name={.wIndex=0,.rIndex=0,.sz=size};

/*
    SIMPLEQUEUE_ISFULL - returns TRUE if the specified queue is full
*/
#define SIMPLEQUEUE_ISFULL(name)            (name.rIndex==(name.wIndex+1)%name.sz)

/*
    SIMPLEQUEUE_ISEMPTY - returns TRUE if the specified queue is empty
*/
#define SIMPLEQUEUE_ISEMPTY(name)           (name.wIndex==name.rIndex)

/*
    SIMPLEQUEUE_ENQUEUE - enqueue a new "data" onto the specified "name" queue
*/
#define SIMPLEQUEUE_ENQUEUE(name, data)     {name.buffer[name.wIndex++]=data;if(name.wIndex>=name.sz)name.wIndex=0;}

/*
    SIMPLEQUEUE_DEQUEUE - dequeue one element from the specified "name" queue
    Obs.: this macro can only be used in assignments, it can't be used as part of an expression!
*/
#define SIMPLEQUEUE_DEQUEUE(name)           (name.buffer[name.rIndex++]);if(name.rIndex>=name.sz)name.rIndex=0;

#endif
