op.out : a.out b.out
	g++ a.out b.out -o op.out
a.out : BST.h BST.cpp client.cpp
	g++ -c client.cpp -o a.out
b.out : BST.h BST.cpp
	g++ -c BST.hxx -o b.out