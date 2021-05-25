a.out : main.c Hash.o LinkedList.o dataGenerate.o BST.o Array.o AwBS.o AVLTree.o
	gcc -g main.c Hash.o LinkedList.o dataGenerate.o BST.o Array.o AwBS.o AVLTree.o
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
Hash.o: Hash.h Hash.c LinkedList.c LinkedList.h
	gcc -c -g Hash.c LinkedList.c
AVLTree.o: AVLTree.c AVLTree.h
	gcc -c -g AVLTree.c 
clean:
	-rm a.out
	-rm LinkedList.o AVLTree.o
	-rm dataGenerate.o BST.o
	-rm Array.o AwBS.o Hash.o
