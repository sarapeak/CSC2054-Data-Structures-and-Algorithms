#pragma once

class Train;

class HashTable
{
private:
	//Private variables
	int numOfEntries;
	int sizeOfTable;
	int num = 1;
	list <Train*>* table;

public:
	//Default constructor
	HashTable();
	//Functions
	bool insertTrain(Train* train_in);   //Takes in a train*
	void rehash();
	void print();
	bool contains(Train* train_in);   //Takes in a train*
	void remove(Train* train_in);   //Takes in a train*
	//Train pointer of a list
	list <Train*>* trainPtr = new list <Train*>;
};