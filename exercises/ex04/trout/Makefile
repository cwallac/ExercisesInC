main: main.o trout.o util.o trout.h util.h
	gcc main.o trout.o util.o -o main -Wall

util.o: util.c util.h
	gcc -c util.c -Wall

trout.o: trout.h trout.c util.o
	gcc -c trout.c -Wall

main.o: main.c trout.o util.o
	gcc -c main.c -Wall 
