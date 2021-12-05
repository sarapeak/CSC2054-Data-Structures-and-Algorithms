//Node.h
#pragma once
class Node
{
private:
	int value;
	Node* next;

public:
	//Constructors for node
	Node();
	Node(int v, Node * next);
	
	//Functions for node
	void setValue(int v);
	int getValue();

	Node* getNext();
	void setNext(Node* theNewNext);
	void printNode(Node* nodes);
};
