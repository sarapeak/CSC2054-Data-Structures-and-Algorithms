//LinkedList.cpp
#include "LinkedList.h";
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	head = 0;   //Sets head equal to 0 or NULL
}

void LinkedList::append(int value_in)
{
	if (head == 0)   //If head is NULL
	{
		head = new Node();         //Head is equal to a new Node
		head->setValue(value_in);  //Sets the nodes value to the int inputted by user
		head->setNext(0);          //Sets the next to 0
	}
	else   //If head is not NULL
	{
		Node* myPtr = head;   //Creates a node pointer
		//Loops through to get the next thing in the node until it is NULL
		while (myPtr->getNext() != 0)
		{
			myPtr = myPtr->getNext();
		}
		myPtr->setNext(new Node());            //Sets the next thing to be a new node
		myPtr->getNext()->setValue(value_in);  //Gets the next node and sets the value
		myPtr->getNext()->setNext(0);          //Gets the next node and sets the next node to be NULL
	}
}

void LinkedList::print()
{
	Node* myPtr = head;   //Creates a node pointer equal to head
	//Loops through until the pointer is NULL
	while (myPtr != 0)
	{
		cout << myPtr->getValue() << " "; //Prints out the value in the node
		myPtr = myPtr->getNext();         //Gets the next node
	}
}

