//LinkedList.cpp
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
	//Sets the next to 0 or NULL and value to 0
	next = 0;
	value = 0;
}
Node::Node(int v, Node * next_in)
{
	//Takes in an int and node pointer
	value = v;
	next = next_in;
}
void Node::setValue(int v)   //Sets the value in a node
{
	value = v;
}
int Node::getValue()   //When called, gets a value from a node
{
	return value;
}

Node* Node::getNext()   //Gets the next node in a list
{
	return next;
}
void Node::setNext(Node* theNewNext)   //Sets the next node in the list
{
	next = theNewNext;
}

void Node::printNode(Node* nodes)   //When called, prints out the node values
{
	Node* nodePtr = nodes;   //A node pointer equal to the user inputted nodes
	//Loops through until nodePtr is NULL
	while (nodePtr != 0)
	{
		cout << nodePtr->getValue() << " ";  //Prints out the value from a node
		nodePtr = nodePtr->getNext();        //Looks at the next node in the list
	}
}