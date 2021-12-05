#pragma once

class Node
{
private:
	//Variables
	unsigned int value = 0;
	Node* left = 0;
	Node* right = 0;

public:
	//Constructors
	Node();
	Node(unsigned int value, Node* left, Node* right);
	//Accessors
	unsigned int getValue() const;
	Node* getLeft() const;
	Node* getRight() const;
	//Mutators
	void setValue(unsigned int value);
	void setLeft(Node* left);
	void setRight(Node* right);
};