all: main

main: biblioLC.o entreeSortieLC.o main.o
	gcc biblioLC.o entreeSortieLC.o main.o -o main

biblioLC.o: biblioLC.c biblioLC.h
	gcc -c biblioLC.c -o biblioLC.o

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -c entreeSortieLC.c -o entreeSortieLC.o

main.o: main.c biblioLC.h entreeSortieLC.h
	gcc -c main.c -o main.o

clean:
	rm -f *.o
	rm -f main
