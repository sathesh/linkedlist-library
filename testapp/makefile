INCLUDES = ../listlib/

all: testapp

testapp: testapp.o list.o
	gcc -o testapp testapp.o list.o

testapp.o: testapp.c  ../listlib/list.h
	gcc -c testapp.c -I $(INCLUDES) -o testapp.o -g

list.o: ../listlib/list.c ../listlib/list.h
	gcc -c $(INCLUDES) ../listlib/list.c -o list.o -g

clean:
	rm list.o testapp testapp.o
