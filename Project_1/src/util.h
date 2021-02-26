#ifndef _UTIL_H_
#define _UTIL_H_

#include "heap.h"


int nextCommand(int *n, int *f);
int getArraySize();
void freeMem(HEAP* heap, ELEMENT a[]);
bool populateArray(ELEMENT a[]);
bool isHeapNull(HEAP* heap);
void writeHeap(HEAP* heap);

#endif