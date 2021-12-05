#include <iostream>
using namespace std;

#include "Node.h"

//Default Node
Node::Node()
{ }
//A Node that takes in a value and two different Node*
Node::Node(unsigned int value_in, Node* left_in, Node* right_in)
{
	value = value_in;
	left = left_in;
	right = right_in;
}
//Returns the value
unsigned int Node::getValue() const
{
	return value;
}
//Returns the left node*
Node* Node::getLeft() const
{
	return left;
}
//Returns the right node*
Node* Node::getRight() const
{
	return right;
}
//Sets the value
void Node::setValue(unsigned int value_in)
{
	value = value_in;
}
//Sets the left node*
void Node::setLeft(Node* left_in)
{
	left = left_in;
}
//Sets the right node*
void Node::setRight(Node* right_in)
{
	right = right_in;
}