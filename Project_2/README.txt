This program uses dynamic allocation.
This file explains what lines and which files the memory is dynamically allocated in.

Dynamic Allocation: 
    The file and line numbers for where dynamic allocation occurs are as follows:
main.cpp:
    line 40:
        At this location, an array of n elements is dynamically allocated.

heap.cpp:
    line 10:
        At this location a HEAP object is dynamically allocated.
    line 13:
        At this location an array of ELEMENTS is dynamically allocated.

Freeing of Dynamically Allocated Memeory:
    The dynamically allocated memory is also freed at these locations:

util.cpp:
    line 48:
        At this location, the array of ELEMENTS from heap.cpp is freed.
    line 49:
        At this location, the HEAP object from heap.cpp is freed.
    line 55:
        At this location, the array from main.cpp is freed.