#include <iostream>
#include <vector>
using namespace std;

#include "printMenu.h";
#include "add.h";

int main()
{
	//Part 1
	int aInt = 8;
	int bInt = 11;

	int* aPtr = &aInt;   //aPtr points to the address of aInt
	int* bPtr = &bInt;   //bPtr points to the address of bInt

	cout << "aptr: " << *aPtr;   //Prints the value of where the aPtr is pointing
	cout << "\nbptr: " << *bPtr; //Prints the value of where the bPtr is pointing
	cout << "\naptr: " << aPtr << "\tbptr: " << bPtr;   //Prints the addresses

	int* cPtr = aPtr;   //cPtr points to the aPtr
	aPtr = bPtr;        //aPtr is now bPtr
	bPtr = cPtr;        //bPtr is now cPtr which is aPtr

	cout << "\naptr: " << *aPtr;
	cout << "\nbptr: " << *bPtr;
	cout << "\naptr: " << aPtr << "\tbptr: " << bPtr << "\n\n";

	//Part 2
	vector<char*> *alphabet = new vector<char*>;   //A vector of char pointers

	for (int i = 0; i < 26; i++)
	{
		alphabet->push_back(new char);  //Pushes back new char
		char letter = 'a' + i;          //letter is incremented each loop
		*alphabet->at(i) = letter;      //Letter is added to a certain index
	}

	for (int i = 0; i < 26; i++)
	{
		cout << *alphabet->at(i) << "\n";  //Prints out the letters
		delete alphabet->at(i);            //Deletes the letter at each index
	}
	delete alphabet;   //Deletes the vector

	cout << "\n";

	//Part 3
	int * myArray = new int[15];   //A pointer array
	int memory = 0;

	for (int i = 0; i < 15; i++)
	{
		memory = i * i * i * i;  //Memory equals i to the fourth power, incremented each loop
		myArray[i] = memory;     //Memory is stored at an index
		cout << "i: " << myArray[i] << " ";   //Prints out the memory in the index
	}
	delete[] myArray;   //Deletes the array

	cout << "\n\n";

	//Part 4
	vector<int*>* ptrs = new vector<int*>();   //A vector of int pointers
	int size = 10;

	for (int i = 0; i < size; i++)
	{
		ptrs->push_back(new int);  //Pushes back a new int each loop
		*ptrs->at(i) = 0;          //Sets 0 to each index
	}

	//Variables I use for Part 4
	char letter;
	int index = 0;
	int value = 0;
	int index1 = 0;
	int index2 = 0;
	int result = 0;

	int endProgram = 0;   //A variable that helps with ending the program

	do
	{
		cout << printMenu();  //Calls on the printMenu function to print the menu
		cin >> letter;        //Takes in the letter a user enters

		//A switch statement that has cases for each menu item
		switch (letter)
		{
			case 's':
				cout << "->> ";
				cin >> index;   //Takes in the index specified by user
				cout << "->> ";
				cin >> value;   //Takes in the value specified by user
				
				if (index >= size || index < 0)   //Checks to see if the index is out of range
				{
					cout << "Index is out of range!\n";
				}
				else
				{
					*ptrs->at(index) = value;   //Points the value to the index
				}
				break;

			case 'p':
				cout << "->> ";
				cin >> index;   //Takes in index specified by user

				if (index >= size || index < 0)   //Checks to see if the index is out of range
				{
					cout << "Index is out of range!\n";
				}
				else if (ptrs->at(index) == NULL)   //Checks to see if the ptr at index is NULL
				{
					cout << "Index " << index << " is null!\n";
				}
				else
				{
					cout << *ptrs->at(index) << "\n";   //Prints out the value at the index
				}
				break;

			case 'd':
				cout << "->> ";
				cin >> index;   //Takes in index specified by the user

				if (index >= size || index < 0)   //Checks if the index is out of range
				{
					cout << "Index " << index << " is out of range!\n";
				}
				else if (ptrs->at(index) == NULL) //Checks if the index is NULL
				{
					cout << "Index " << index << " is null!\n";
				}
				else
				{
					ptrs->at(index) = NULL;   //Makes the index NULL
				}
				break;

			case 'i':
				cout << "->> ";
				cin >> index;   //Takes in index specified by the user

				if (index >= size || index < 0)  //Checks if the index is out of range
				{
					cout << "Index " << index << " is out of range!\n";
				}
				else if (ptrs->at(index) != NULL)  //Checks if the index is not NULL
				{
					cout << "Index " << index << " is active memory!\n";
				}
				else
				{
					ptrs->at(index) = new int; //Instantiates the index
					*ptrs->at(index) = 0;      //Makes the value at the index 0
				}
				break;

			case 'w':
				cout << "->> ";
				cin >> index1;   //Takes in the first index specified

				cout << "->> ";
				cin >> index2;   //Takes in the second index specified

				if (index1 >= size || index1 < 0)   //Checks if index1 is out of range
				{
					cout << "Index " << index1 << " is out of range!\n";
					break;
				}
				else if (ptrs->at(index1) == NULL)  //Checks if index1 is NULL
				{
					cout << "Index " << index1 << " is set to null!\n";
					break;
				}

				if (index2 >= size || index2 < 0)   //Checks if index2 is out of range
				{
					cout << "Index " << index2 << " is out of range!\n";
					break;
				}
				else if (ptrs->at(index2) == NULL)  //Checks if index2 is NULL
				{
					cout << "Index " << index2 << " is set to null!\n";
					break;
				}

				//Calls the function which returns an int which is set equal to result
				result = add(ptrs->at(index1), ptrs->at(index2));

				//Points the result to the index
				*ptrs->at(index1) = result;
				*ptrs->at(index2) = result;
				break;

			case 'q':
				delete ptrs;     //Deletes the ptrs vector
				endProgram = 1;  //Changes endProgram to 1
				break;
		}
	} while (endProgram == 0);   //Loops until false
}