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
        if(heap->size != 0){
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
}

