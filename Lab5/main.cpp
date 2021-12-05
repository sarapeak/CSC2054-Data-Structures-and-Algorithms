#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "VerticalList.h"
using namespace std;

int main()
{
	//Part 1
	//A node pointer which equals a memory area in which the value is stored and sets the next node pointer
	Node* node1 = new Node(35, NULL);
	Node* node2 = new Node(25, node1);
	Node* node3 = new Node(15, node2);
	Node* node4 = new Node(5, node3);
	Node* node5 = new Node(-5, node4);

	//Prints out the linked nodes starting at node5
	node5->printNode(node5);

	cout << "\n\n";

	//Part 2
	VerticalList list1;
	list1.printVerticalList();   //Prints out list1

	cout << "\n\n";

	list1.incrementList();       //Increments each value in the list by 1
	list1.printVerticalList();   //Prints list1 out

	cout << "\n\n";

	VerticalList list2(list1);   //Copies the values from list1 into list2
	list1.incrementList();       //Only increments list1

	list1.printVerticalList();   //Prints out list1
	cout << "\n";
	list2.printVerticalList();   //Prints out list2

	VerticalList list3;          //Creates list3
	list3 = list1;               //Sets list3 equal to the information from list1
	list3.incrementList();       //Only increments list3

	//Prints out each of the lists
	cout << "\n\n";
	list1.printVerticalList();
	cout << "\n";
	list2.printVerticalList();
	cout << "\n";
	list3.printVerticalList();

	//Increments each of the lists
	list1.incrementList();
	list2.incrementList();
	list3.incrementList();

	//Prints out the lists
	cout << "\n\n";
	list1.printVerticalList();
	cout << "\n";
	list2.printVerticalList();
	cout << "\n";
	list3.printVerticalList();
}