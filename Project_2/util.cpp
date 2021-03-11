#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "util.h"
#include "heap.h"
using namespace std;

int g_counter = 0; //Initializes global counter

//Gets input from user
int nextCommand(int *n, int *f, int* v){
    char c;
    while(1){
        scanf("%c", &c);
        if(c == ' ' || c == '\t' || c == '\n'){
            continue;
        }
        if(c == 'S' || c == 's' ||  c == 'W' || c == 'w' || c == 'P' || c == 'p'){
            break;
        }
        if( c == 'C' || c == 'c'){
            scanf("%d", n);
            break;
        }
        if(c == 'K' || c== 'k'){
            scanf("%d %d", n, f);
            break;
        }
        if(c == 'I' || c == 'i'){
            scanf("%d", n);
            break;
        }
        if( c == 'R' || c == 'r' || c == 'D' || c == 'd'){
            scanf("%d", v);
            break;
        }
        else{
            printf("Invalid Command\n");
        }

    }
    return c;
}

//Gets size of array
//Reads the first value from HEAPinput.txt (size) and returns it
int getArraySize(){
    int data;
    std::ifstream inFile ("HEAPinput.txt");
    if(inFile.is_open()){
        inFile >> data;
        inFile.close();
    }
    else{
        printf("Error: cannot open file for reading\n");
        data = -1;
    }
    return data;
}

//Frees dynamically allocated memory
void freeMem(HEAP* heap, ELEMENT a[]){
    if(heap != NULL){
        if(heap->H != NULL){
            delete[] heap->H;
            heap -> H = NULL;
        }
        delete heap;
        heap = NULL;
    }
    if(a != NULL){
        delete[] a;
        a = NULL;
    }
    
}
//Frees memory of given element e
void freeMem(ELEMENT* e){
    if (e != NULL){
        delete e;
        e = NULL;
    }
}

//Should probably be called read or something
//Reads the values from HEAPinput.txt and stores them in an array of type ELEMENT
//Returns true if file is able to be opened
bool populateArray(ELEMENT a[]){
    bool rtn = false;
    std::ifstream inFile ("HEAPinput.txt");
    int data;
    if(inFile.is_open()){
        rtn = true;
        int i = 1;
        inFile >> data;
        ELEMENT e;
        while(inFile >> data){
            e.key = data;
            a[i] = e;
            i++;
        }
    }
    else{
        printf("Error: cannot open file for reading\n");
    }
    inFile.close();
    return rtn;
}

//Checks if heap is null
bool isHeapNull(HEAP* heap){
    if(heap == NULL){
        return true;
    }
    return false;
}

//Writes the keys from heap to HEAPoutput.txt
void writeHeap(HEAP* heap){
    if(!isHeapNull(heap)){
        std::ofstream outFile ("HEAPoutput.txt");
        if(outFile){
            //write size since it goes at the top of the output/input files
            outFile << heap->size << "\n";
            for(int i = 1; i <= heap->size; i++){
                outFile << heap->H[i].key << "\n";
            }
        }
        else{
            printf("Error: cannot open file for writing\n");
        }
        outFile.close();
    }
    else{
        printf("Error: cannot write\n");
    }
}
//Prints the array held in heap, used for debugging purposes while writing
void PrintArray(HEAP* heap){
    for(int i = 0; i < heap->capacity; i++){
        std::cout << heap->H[i].key << " ";
    }
    std::cout << "\n";
}
