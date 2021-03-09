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

void Insert(HEAP* heap, ELEMENT* e);
void ExtractMin(HEAP* heap);
void DecreaseKey(HEAP* heap, int index, int value);
void MinHeapify(HEAP* heap, int index);
void BuildHeap(HEAP* heap, ELEMENT A[], int n);
int Left(int i);
int Right(int i);
int Parent(int i);

#endif