#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "util.h"
#include "heap.h"

int main(){
    //Declare variables
    char c;
    int f, n, v;
    int arraySize = 0;
    HEAP* heap = NULL;
    ELEMENT* arr = NULL;
    //Loop to take input from user
    while(1){
        c = nextCommand(&n, &f, &v);
        switch(c){
            case 's':
            case 'S': //Stop program
                freeMem(heap, arr);
                exit(0);
            case 'c':
            case 'C': //Init heap
                heap = Initialize(n);
                break; 
            case 'r':
            case 'R': //open file for reading, if flag is 1, print number of Heapify calls
                arraySize = getArraySize();
                if(arraySize == -1){
                    break;
                }
                if(arraySize > n || isHeapNull(heap)){
                    printf("Error: heap overflow\n");
                }
                else{
                    arr = new ELEMENT[n];
                    if(populateArray(arr)){ 
                        BuildHeap(heap, arr, arraySize);
                        if(v == 1 && g_counter > 0){
                            printf("Number of Heapify calls: %d\n", g_counter);
                        }
                        g_counter = 0;
                    }
                }
                break;
            case 'p':
            case 'P': //print heap
                printHeap(heap);
                break;
            case 'w':
            case 'W': //Open file for writing
                writeHeap(heap);
                break;
            case 'd':
            case 'D': //Deletes minimum value, if flag is 1, print number of Heapify calls
                ExtractMin(heap);
                if(v == 1 && g_counter > 0){
                    printf("Number of Heapify calls: %d\n", g_counter);
                }
                g_counter = 0;
                break;
            case 'i':
            case 'I': //Inserts dynamically allocated element into heap
                {
                    ELEMENT* insertElement = new ELEMENT;
                    insertElement->key = n;
                    Insert(heap, insertElement);
                    freeMem(insertElement);
                }
                break;
            case 'k':
            case 'K': //Decreases specifiied key in heap
                DecreaseKey(heap, n, f);
                break;
            default:
                break;
        }
    }
    exit(0);
}