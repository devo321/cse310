#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"
#include "util.h"

//Creates a heap object of capacity n and size 0
//Initializes array of n+1 ELEMENTS
HEAP* Initialize(int n){
    HEAP* heap = new HEAP;
    heap->capacity = n;
    heap->size = 0;
    heap->H = new ELEMENT[n+1];
    return heap;
}
//Prints heap 
void printHeap(HEAP* heap){
    if(isHeapNull(heap)){ //check if heap is null
        printf("Error: heap is null\n");
    }
    else{
        if(/*heap->size != 0*/ true){
            printf("capacity=%d, ", heap->capacity);
            printf("size=%d\n", heap->size);
            for(int i = 1; i <= heap->size; i++){
                if(i == heap->size){ //Checks if last element, if so, no "," is printed
                    printf("%d\n", heap->H[i].key);
                }
                else{
                    printf("%d, ", heap->H[i].key);
                }
            }
        }
        
    }
    
}

//Builds a the heap from array A of size n
void BuildHeap(HEAP* heap, ELEMENT A[], int n){
    heap->size = n;
    for(int i = n; i > 0; i--){
        heap->H[i].key = A[i].key;
    }
    for(int i = n/2; i > 0; i--){
        MinHeapify(heap, i);
    }
}

//Maintains Min-Heap Property
void MinHeapify(HEAP* heap, int index){
    int l = Left(index);
    int r = Right(index);
    int smallest = index;

    if(l <= heap->size && heap->H[l].key < heap->H[index].key){
        smallest = l;
    }
    if(r <= heap->size && heap->H[r].key < heap->H[smallest].key){
        smallest = r;
    }
    if(smallest != index){
        ELEMENT tmp = heap->H[index];
        heap->H[index] = heap->H[smallest];
        heap->H[smallest] = tmp;
        MinHeapify(heap, smallest);
    }
}


void ExtractMin(HEAP* heap){
    if(heap->size < 1 || isHeapNull(heap)){
        printf("Error: heap is NULL or empty\n");
    }
    else{
        int min = heap->H[1].key;
        heap->H[1].key = heap->H[heap->size].key;
        heap->size -= 1;
        MinHeapify(heap, 1);
        printf("Deleted key: %d\n", min);
    }
}

void DecreaseKey(HEAP* heap, int index, int value){
    if(value > heap->H[index].key || isHeapNull(heap) || index < 1 || index > heap->size){
        printf("Error: invalid call to DecreaseKey\n");
    }
    else{
        heap->H[index].key = value;
        while(index > 1 && heap->H[Parent(index)].key > heap->H[index].key){
            ELEMENT tmp = heap->H[index];
            heap->H[index] = heap->H[Parent(index)];
            heap->H[Parent(index)] = tmp;
            index = Parent(index);
        }
    }
}

void Insert(HEAP* heap, ELEMENT* e){
    int heapSize = heap->size + 1;
    if(heapSize > heap->capacity){
        printf("Error: heap is NULL or full\n");
    }
    else{
        heap->size += 1;
        heap->H[heap->size].key = __INT_MAX__;
        DecreaseKey(heap, heap->size, e->key);
    }
}

int Parent(int i){
    return i/2;
}

int Left(int i){
    return (2*i);
}

int Right(int i){
    return (2*i + 1);
}



