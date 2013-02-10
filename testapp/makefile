INCLUDES = ../listlib/

FLAGS = -DDEBUG \
        -g

all: testapp

testapp: testapp.o list.o
	gcc $(FLAGS) -o testapp testapp.o list.o

testapp.o: testapp.c  ../listlib/list.h
	gcc $(FLAGS) -c testapp.c -I $(INCLUDES) -o testapp.o 

list.o: ../listlib/list.c ../listlib/list.h
	gcc $(FLAGS) -c ../listlib/list.c -I $(INCLUDES) -o list.o 

clean:
	rm list.o testapp testapp.o
