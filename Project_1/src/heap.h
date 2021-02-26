#ifndef _HEAP_H_
#define _HEAP_H_

struct ELEMENT{
    int key;
};

struct HEAP {
    int capacity;
    int size;
    ELEMENT *H;
};

HEAP* Initialize(int n);
void printHeap(HEAP* heap);


void BuildHeap(HEAP* heap, ELEMENT A[], int n);


#endif