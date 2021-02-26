EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC)	:main.o util.o heap.o


	$(CC) -o $(EXEC) main.o util.o heap.o

main.o	: main.cpp
		$(CC) $(CFLAGS) main.cpp

util.o	: util.h util.cpp
		$(CC) $(CFLAGS) util.cpp

heap.o	: heap.h heap.cpp
		$(CC) $(CFLAGS) heap.cpp


clean	:
	rm *.o