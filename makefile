a.out : main.c LinkedList.o dataGenerate.o BST.o Array.o AwBS.o
	gcc -g main.c LinkedList.o dataGenerate.o BST.o Array.o AwBS.o 
LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -g LinkedList.c
dataGenerate.o: dataGenerate.c dataGenerate.h
	gcc -c -g dataGenerate.c
BST.o: BST.h BST.c
	gcc -c -g BST.c
Array.o: Array.h Array.c
	gcc -c -g Array.c
AwBS.o: AwBS.h AwBS.c
	gcc -c -g AwBS.c
clean:
	-rm a.out
	-rm LinkedList.o
	-rm dataGenerate.o
	-rm BST.o
	-rm Array.o
	-rm AwBS.o
