#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

#include "HashTable.h"
#include "Train.h"

int main()
{
	//Create 3 trains
	Train* train1 = new Train("4-4-2", 343);
	Train* train2 = new Train("2-8-0", 344);
	Train* train3 = new Train("4-0-4", 345);

	//Creates a hashtable object
	HashTable hashTable;

	//Prints out the hashtable with nothing in it
	hashTable.print();

	//Inserts the trains into the hashtable
	hashTable.insertTrain(train1);
	hashTable.insertTrain(train2);
	hashTable.insertTrain(train3);
	cout << "\n";

	//Prints out the hashtable
	cout << "Original print:\n";
	hashTable.print();

	//Inserts the trains again
	hashTable.insertTrain(train1);
	hashTable.insertTrain(train2);
	hashTable.insertTrain(train3);
	cout << "\n";

	//Prints out the hashtable
	cout << "Print after adding same three again:\n";
	hashTable.print();

	//Creates new trains
	Train* train4 = new Train("2-8-0", 1);
	Train* train5 = new Train("2-8-0", 2);
	Train* train6 = new Train("2-8-0", 3);
	Train* train7 = new Train("12-0-0", 42);
	Train* train8 = new Train("12-0-12", 84);
	Train* train9 = new Train("2-2", 2);
	Train* train10 = new Train("4-4", 4);

	//Inserts the trains into the hashtable
	hashTable.insertTrain(train4);
	hashTable.insertTrain(train5);
	hashTable.insertTrain(train6);
	hashTable.insertTrain(train7);
	hashTable.insertTrain(train8);
	hashTable.insertTrain(train9);
	hashTable.insertTrain(train10);

	//Prints out the hashtable with the added trains
	cout << "\nPrint after adding more trains:\n";
	hashTable.print();

	//Removes the first three trains
	hashTable.remove(train1);
	hashTable.remove(train2);
	hashTable.remove(train3);

	//Creates a new train, inserts it, and removes it from the hashtable
	Train* train11 = new Train("2-8-0", 99);
	hashTable.insertTrain(train11);
	hashTable.remove(train11);

	//Prints out the hashtable
	cout << "\nPrint after deleting the trains:\n";
	hashTable.print();
}