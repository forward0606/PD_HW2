a.out : LinkedList.o dataGenerate.o BST.o Array.o main.c
	gcc LinkedList.o dataGenerate.o main.c
LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c
dataGenerate.o: dataGenerate.c dataGenerate.h
	gcc -c dataGenerate.c
BST.o: BST.h BST.c
	gcc -c BST.c
Array.o: Array.h Array.c
	gcc -c Array.c
clean:
	-rm a.out
	-rm LinkedList.o
	-rm dataGenerate.o
	-rm BST.o
	-rm Array.o
