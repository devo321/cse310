#ifndef _UTIL_H_
#define _UTIL_H_

#include "heap.h"

extern int g_counter;

int nextCommand(int *n, int *f, int* v);
int getArraySize();
void freeMem(HEAP* heap, ELEMENT a[]);
void freeMem(ELEMENT* e);
bool populateArray(ELEMENT a[]);
bool isHeapNull(HEAP* heap);
void writeHeap(HEAP* heap);

void PrintArray(HEAP* heap);

#endif