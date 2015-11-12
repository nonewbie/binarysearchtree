#Thu Oct  1 01:23:56 PDT 2015
CC = gcc
arr_dir = arrdata
taolib_dir = taolib

test : test.o bst.o $(arr_dir)/arr.o 
	gcc -o test test.o bst.o $(arr_dir)/arr.o 
test.o : 
	gcc -c test.c bst.h $(taolib_dir)/maclib.h
bst.o : 
	gcc -c bst.c bst.h
arr.o :
	$(MAKE) -C $(arr_dir)
clean :
	-rm -f *.o *.gch test 
	cd $(arr_dir) ; make clean
