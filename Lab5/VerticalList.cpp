#include <iostream>
#include "VerticalList.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

VerticalList::VerticalList()
{
	head = 0;   //Sets head equal to 0 or NULL

	//Loops through to create the values being inputted in the list
	for (int i = 10; i < 20; i++)
	{
		int valueInList = i;   //The value is equal to whatever i is

		if (head == 0)   //If head is NULL
		{
			head = new Node();           //Head is equal to a new Node
			head->setValue(valueInList); //Sets the nodes value to the int determined above
			head->setNext(0);            //Sets the next to 0
		}
		else   //If head is not NULL
		{
			Node* myHead = head;   //Creates a node pointer
			//Loops through to get the next thing in the node until it is NULL
			while (myHead->getNext() != 0)
			{
				myHead = myHead->getNext();
			}
			myHead->setNext(new Node());              //Sets the next thing to be a new node
			myHead->getNext()->setValue(valueInList); //Gets the next node and sets the value
			myHead->getNext()->setNext(0);            //Gets the next node and sets the next node to be NULL
		}
	}
}
void VerticalList::incrementList()
{
	Node* current = head;   //Sets the current node pointer equal to head
	
	//Loops through until current is NULL
	while (current != NULL)
	{
		int num = current->getValue(); //Has the num equal to the value in the node
		num++;                         //Increments the num by 1
		current->setValue(num);        //Sets the value at the same node to the incremented num
		current = current->getNext();  //Gets the next node
	}
}
void VerticalList::printVerticalList()
{
	Node* vListPtr = head;

	//Loops through until the vListPtr is NULL
	while (vListPtr != 0)
	{
		cout << vListPtr->getValue() << " ";  //Gets and prints out the value
		vListPtr = vListPtr->getNext();       //Gets the next node
	}
}
//Destructor constructor
VerticalList::~VerticalList()
{
	delete head;   //Deltes head to prevent memory leaks
}
//Copy constructor
VerticalList::VerticalList(const VerticalList& vl)
{
	Node* copyPtr = vl.head->getNext();      //Sets the node pointer equal to the lists node next to head
	head = new Node(vl.head->getValue(), 0); //Makes head equal to a new node that has a pointer and NULL
	Node* headPtr = head;   //Creates a node pointer equal to head
	
	//Loops through until copyPtr is NULL
	while (copyPtr != 0)
	{
		headPtr->setNext(new Node());   //Sets the next to a new node
		headPtr->getNext()->setValue(copyPtr->getValue());   //Gets next and sets the value from the copyPtr

		headPtr = headPtr->getNext();   //Gets next for the headPtr
		copyPtr = copyPtr->getNext();   //Gets next for the copyPtr
	}
	/**this = vl;*/
}
//= operator
const VerticalList& VerticalList::operator=(const VerticalList& rhs)
{
	Node* rhsPtr = rhs.head->getNext();       //Sets the node pointer equal to the lists node next to head
	head = new Node(rhs.head->getValue(), 0); //Makes head equal to a new node that takes in a pointer and NULL
	Node* rhsHeadPtr = head;   //Creates a node pointer equal to head
	
	//Loops through until rhsPtr is NULL
	while (rhsPtr != 0)
	{
		rhsHeadPtr->setNext(new Node());   //Sets the next to a new node
		rhsHeadPtr->getNext()->setValue(rhsPtr->getValue()); //Gets next and sets the value from the rhsPtr

		rhsHeadPtr = rhsHeadPtr->getNext(); //Gets next for the rhsHeadPtr
		rhsPtr = rhsPtr->getNext();         //Gets next for the rhsPtr
	}
	return *this;   //Returns the copied list
}