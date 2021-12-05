#include <iostream>
using namespace std;

#include "Node.h"
#include "Tree.h"

int main()
{
	Tree binaryTree;   //The binary tree

	//Inserts a value into the tree
	binaryTree.insert(8);
	binaryTree.insert(4);
	binaryTree.insert(12);
	binaryTree.insert(2);
	binaryTree.insert(6);
	binaryTree.insert(10);
	binaryTree.insert(14);
	binaryTree.insert(1);
	binaryTree.insert(9);
	binaryTree.insert(11);

	//outputs if it found the value or not
	cout << binaryTree.find(4) << "\n";
	cout << binaryTree.find(5) << "\n";
	cout << binaryTree.find(6) << "\n";
	cout << binaryTree.find(10) << "\n";
	cout << binaryTree.find(9) << "\n";

	cout << "\n";

	//Prints out the tree with dashes as the depth
	binaryTree.print();
	cout << "\n";
	//Prints out the tree in a horizontal print
	binaryTree.printHorizontal();
}