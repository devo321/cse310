#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "util.h"
#include "heap.h"


int main(){
    //Declare variables
    char c;
    int f, n;
    int arraySize = 0;
    HEAP* heap = NULL;
    ELEMENT* arr = NULL;
    //Loop to take input from user
    while(1){
        c = nextCommand(&n, &f);
        switch(c){
            case 's':
            case 'S': //Stop program
                printf("COMMAND: %c\n",c);
                freeMem(heap, arr);
                exit(0);
            case 'c':
            case 'C': //Init heap
                printf("COMMAND: %c %d\n", c, n);
                heap = Initialize(n);
                break; 
            case 'r':
            case 'R': //open file for reading  HAS FLAG REMEMBER TO IMPLEMENT
                printf("COMMAND: %c\n", c);
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
                    }
                }
                break;
            case 'p':
            case 'P': //print heap
                printf("COMMAND: %c\n", c);
                printHeap(heap);
                break;
            case 'w':
            case 'W': //Open file for writing
                printf("COMMAND: %c\n", c);
                writeHeap(heap);
                break;
            case 'd':
            case 'D': //HAS FLAG REMEMBER TO IMPLEMENT
                printf("COMMAND: %c\n", c);
                ExtractMin(heap);
                break;
            case 'i':
            case 'I':
                printf("COMMAND: %c\n",c);
                //insert
                {
                    ELEMENT* insertElement = new ELEMENT;
                    insertElement->key = n;
                    Insert(heap, insertElement);
                    freeMem(insertElement);
                }
                break;
            case 'k':
            case 'K':
                printf("COMMAND: %c\n",c);
                DecreaseKey(heap, n, f);
                break;
            default:
                break;
        }
    }
    exit(0);
}


