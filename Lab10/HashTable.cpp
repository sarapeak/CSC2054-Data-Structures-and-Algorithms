#include <iostream>
#include <list>
#include <vector>
using namespace std;

#include "HashTable.h"
#include "Train.h"

//A constructor that does not take in anything
HashTable::HashTable()
{
	//Defines that private variables here
	numOfEntries = 0;
	sizeOfTable = 2;
	table = new list<Train*>[sizeOfTable];
}
//An insert function that takes in a Train*
bool HashTable::insertTrain(Train* train_in)
{
	int index = train_in->hash(sizeOfTable);   //Sets the index to the train* hash value
	bool trueOrFalse = true;   //Sets the bool to true

	//Creates an iterator of list train*
	list<Train*>::iterator it;
	//Loops through the iterator
	for (it = table[index].begin(); it != table[index].end(); ++it)
	{
		//If the iterator and the train_in are equal to each other
		if (*it == train_in)
		{
			trueOrFalse = false;   //Sets the bool to false
		}
	}
	//If the bool is true
	if (trueOrFalse == true)
	{
		table[index].push_front(train_in);   //Pushes the train* to the front of the list
		numOfEntries++;   //Adds 1 to the number of entries
	}
	//If the number of entries is greater than the size of the table times 2
	if (numOfEntries > sizeOfTable * 2)
	{
		rehash();   //calls on the rehash function
	}
	return false;   //Returns false
}
//A rehash function that does not take in anything
void HashTable::rehash()
{
	vector<Train*>* trainVec = new vector<Train*>();   //Creates a vector of train*
	list<Train*>::iterator it;   //Creates an iterator of list of train*
	//Loops through the size of the table
	for (int i = 0; i < sizeOfTable; i++)
	{
		//Loops through the iterator
		for (it = table[i].begin(); it != table[i].end(); ++it)
		{
			trainVec->push_back(*it);   //Pushes back the iterator in the trainVec
		}
	}

	sizeOfTable = sizeOfTable * 2;   //Multiplie the size of the table by 2
	numOfEntries = 0;   //Sets the number of entries to 0

	//Creates a list of train* the size of the new size of table
	list<Train*>* newTable = new list<Train*>[sizeOfTable];
	table = newTable;   //Sets table equal to the new table
	//Loops through the size of the train vector
	for (int i = 0; i < trainVec->size(); i++)
	{
		insertTrain(trainVec->at(i));   //Recurses the insert function with the trainVec at i
	}
}
//A function to print
void HashTable::print()
{
	//Creates an iterator
	list <Train*>::iterator it;
	//Loops through the size of the table
	for (int i = 0; i < sizeOfTable; i++)
	{
		cout << i << ":";   //Outputs the index and the colon
		//Loops through the iterator
		for (it = table[i].begin(); it != table[i].end(); ++it)
		{
			cout << " " << *it;   //Outputs the train* from the list iterator
		}
		cout << "\n";   //Spaces the trains
	}
}
//A contains function to find a specified train
bool HashTable::contains(Train* train_in)
{
	int index = train_in->hash(sizeOfTable);   //Makes the index equal to the hash of the train and size of table
	
	//Creates an iterator of list of train*
	list<Train*>::iterator it;
	//Makes the it equal to the finc function of the list class
	it = find(table[index].begin(), table[index].end(), train_in);

	//If the iterator is in the list, it returns true
	if (it != table[index].end())
	{
		return true;
	}
	else   //If the iterator is not in the list, it returns false
	{
		return false;
	}
}
//A function that removes a specified train from the list
void HashTable::remove(Train* train_in)
{
	//Makes the index equal to the hash of the train and size of table
	int index = train_in->hash(sizeOfTable);

	//If the contains function returns true
	if (contains(train_in) == true)
	{
		table[index].remove(train_in);   //Removes the specified train
		numOfEntries--;   //Subtracts 1 from the number of entries
	}
}
//Overload operator to print out the train name and number
ostream& operator << (ostream& out, list <Train*> t)
{
	out << t;
	return out;
}