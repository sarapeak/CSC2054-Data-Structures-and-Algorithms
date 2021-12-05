#pragma once

class Node;

class Tree
{
private:
	//Variables
	Node* root;
	string* treeArray;
	//Private functions
	void insert(Node* root, int value);
	int find(Node* root, int value);
	void print(Node* root, int depth);
	int getDepth(Node* root) const;
	void printHorizontal(Node* root, string* treeArray, int depth);

public:
	//Default constructor
	Tree();
	//Public functions
	void insert(int value);
	int find(int value);
	void print();
	int getDepth() const;
	void printHorizontal();
};