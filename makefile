a.out : LinkedList.o dataGenerate.o BST.o Array.o main.c
	gcc -g LinkedList.o dataGenerate.o BST.o Array.o main.c
LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -g LinkedList.c
dataGenerate.o: dataGenerate.c dataGenerate.h
	gcc -c -g dataGenerate.c
BST.o: BST.h BST.c
	gcc -c -g BST.c
Array.o: Array.h Array.c
	gcc -c -g Array.c
clean:
	-rm a.out
	-rm LinkedList.o
	-rm dataGenerate.o
	-rm BST.o
	-rm Array.o
