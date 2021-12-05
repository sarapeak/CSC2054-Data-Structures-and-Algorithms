#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"
#include "Node.h"

//Default Tree constructor
Tree::Tree()
{
	root = NULL;
}
//The public function for the insert
void Tree::insert(int value)
{
	//If there is nothing in the root
	if (root == NULL)
	{
		root = new Node(value, NULL, NULL);   //Sets the roots value and left and right nodes to null
	}
	else
	{
		insert(root, value);   //Goes to the private function to set a leaf
	}
}
//The private function of the insert
void Tree::insert(Node* root, int value)   //Private function
{
	int rootValue = root->getValue();   //Sets a variable to the root's value
	if (rootValue > value)   //If the root value is greater
	{
		if (root->getLeft() != NULL)   //If the root's left node is not null
		{
			insert(root->getLeft(), value);   //It recurses to the left node
		}
		else   //If the root's right node is null
		{
			Node* newRoot = new Node(value, NULL, NULL);   //Creates a new node
			root->setLeft(newRoot);   //Sets the left node with the new node
		}
	}

	if (root->getValue() < value)   //If the value of the root is less than value
	{
		if (root->getRight() != NULL)   //If the root's right node is not null
		{
			insert(root->getRight(), value);   //It recurses to the right node
		}
		else   //If the root's right node is null
		{
			Node* newRoot = new Node(value, NULL, NULL);   //Creates a new node
			root->setRight(newRoot);   //Sets the right node with the new node
		}
	}
}
//Public function of the find
int Tree::find(int value)
{
	return find(root, value);   //Returns the private function
}
//Private function of the find
int Tree::find(Node* root, int value)
{
	if (root == NULL)   //If root is null, returns -1 as not found
	{
		return -1;
	}
	if (root->getValue() == value)   //If root's value equals the value, returns the value
	{
		cout << value << " ";
		return value;
	}
	if (root->getValue() < value)   //If the root's value is less than value, recurses to the right
	{
		cout << root->getValue() << " ";
		return find(root->getRight(), value);
	}
	if (root->getValue() > value)   //If the root's value is more than value, recurses to the left
	{
		cout << root->getValue() << " ";
		return find(root->getLeft(), value);
	}
}
//Public function of the print
void Tree::print()
{
	int depth = 0;   //Makes depth equal to 0
	print(root, depth);   //Calls on the private function print
}
//Private function of the print
void Tree::print(Node* root, int depth)
{
	if (root == NULL)   //If root is NULL, it returns nothing
	{
		return;
	}
	
	depth++;                         //Adds 1 to depth
	print(root->getRight(), depth);  //Recurses to the right
	depth--;                         //Takes 1 away from depth

	//Loops through the depth and prints out a dash
	for (int i = 0; i < depth * 2; i++)
	{
		cout << "-";
	}
	cout << root->getValue() << "\n";   //Prints out the root's value

	depth++;                        //Adds 1 to depth
	print(root->getLeft(), depth);  //Recurses to the left
	depth--;                        //Takes 1 away from depth
}
//Public function for the getHeight
int Tree::getDepth() const
{
	if (root == NULL)   //If NULL, returns 0
	{
		return 0;
	}
	else   //Else return the private of getHeight
	{
		return getDepth(root);
	}
}
//The private function of getHeight
int Tree::getDepth(Node* root) const
{
	if (root == NULL)   //If root is NULL, returns -1
	{
		return -1;
	}

	int depthLeft = getDepth(root->getLeft());    //Gets the height of the left node
	int depthRight = getDepth(root->getRight());  //Gets the height of the right node

	if (depthLeft > depthRight)   //If the left is greater than the right
	{
		return depthLeft + 1;   //Returns the left depth + 1
	}
	else   //If the right is greater than the left
	{
		return depthRight + 1;   //Returns the right depth + 1
	}
}
//The public function of the horizontal print
void Tree::printHorizontal()
{
	int depth = 0;
	int height = getDepth()+1;
	treeArray = new string[height];
	
	if (root != NULL)   //If the root is not null, it calls the private horizontal print function
	{
		printHorizontal(root, treeArray, depth);
	}

	int space = getDepth();   //A variable to help with the space

	for (int i = 0; i < height; i++)   //Loops through the height of the tree
	{
		for (int d = 0; d < space + 2; d++)   //Loops through the space
		{
			cout << "    ";   //Prints out spaces
		}
		cout << treeArray[i] << "\n";   //Prints out the array
		space = space - 1;   //Subtracts 1 from space
	}
}
//The private function of the horizontal print
void Tree::printHorizontal(Node* root, string* treeArray, int depth)
{
	if (root == NULL)   //If the root is null, it returns nothing
	{
		return;
	}

	int space = getDepth();   //A variable to keep track of the spaces

	for (int i = 0; i < getDepth() + 1; i++)   //Loops through the depth of the tree
	{
		if (i == depth)   //If i is equal to the depth
		{
			treeArray[i] += to_string(root->getValue());   //Inputs the value into the array
			for (int d = 0; d < space; d++)   //Loops through the space value
			{
				treeArray[i] += " ";   //Adds spaces in the array
			}
			if (depth % 2 != 0)   //If the depth is odd
			{
				for (int d = 0; d < space; d++)   //Loops through the space value
				{
					treeArray[i] += " ";   //Adds some more spaces in the array
				}
			}
		}
		else   //If i is not equal to the depth
		{
			treeArray[i] += " ";   //Adds spaces in the array
		}
	}
	
	depth++;   //Adds 1 to the depth
	printHorizontal(root->getLeft(), treeArray, depth);   //Recurses to the left
	depth--;   //Subtracts 1 from the depth

	depth++;   //Adds 1 to the depth
	printHorizontal(root->getRight(), treeArray, depth);  //Recurses to the right
	depth--;   //Subtracts 1 from the depth
}