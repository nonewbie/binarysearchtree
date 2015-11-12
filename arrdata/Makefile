#Thu Oct  1 01:19:10 PDT 2015
CC = gcc
taolib_dir = ../taolib
all : test.o arr.o
	gcc -o test test.o arr.o
arr.o : 
	gcc -c arr.c arr.h $(taolib_dir)/maclib.h
clean :
	-rm -f *.o *.gch test
