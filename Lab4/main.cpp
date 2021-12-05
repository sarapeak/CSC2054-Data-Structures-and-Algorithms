#include <iostream>
#include <string>
using namespace std;

#include "temperatureGauge.h"
#include "menu.h"
#include "duck.h"
#include "pond.h"

int main()
{
	TemperatureGauge gauge1;        //A default constructor
	TemperatureGauge gauge2(120);   //A constructor that takes in one parameter

	cout << gauge1.getTempInF() << "\n";
	cout << gauge1.getTempInC() << "\n";

	cout << gauge2.getTempInF() << "\n";
	cout << gauge2.getTempInC() << "\n";
	
	gauge1.setTempInF(-80);   //Sets gauge1 temp to -80
	cout << gauge1.getTempInF() << "\n";

	gauge1.setTempInF(185);   //Sets gauge1 temp to 185
	cout << gauge1.getTempInF() << "\n";

	gauge1.setTempInF(59.5);  //Sets gauge1 temp to 59.5
	cout << gauge1.getTempInC() << "\n";

	gauge2 = gauge1;   //Makes gauge2 equal to gauge1

	gauge2.setTempInF(33);   //sets gauge2 temp to 33
	cout << gauge1.getTempInC() << "\n";

	cout << "\n";

	int endProgram = 0;   //When updated, ends the loop
	char userInput;       //Takes in the user's input

	string duckName;      //Takes in the name of the duck
	int duckHeight = 0;   //Takes in the flying height of the duck

	//Default class constructors
	Duck duck1;
	Duck duck2;
	Pond pond;

	do
	{
		cout << printMenu();   //Prints the menu

		cin >> userInput;      //Takes in the user's input

		switch (userInput)
		{
			//Asks for the name and height of the duck
			case '1':
				cout << "\nWhat is the name and flying height of your duck?\n";
				cin >> duckName >> duckHeight;

				duck1 = Duck(duckName);    //Adds name to one duck constructor for names
				duck2 = Duck(duckHeight);  //Adds height to duck constructor for duck heights

				//Adds the name and height to the pond
				pond.addDuck(duckName, duckHeight);
				break;

			//Increments the flying height of the duck indicated
			case '2':
				cout << "\nWhat is the name of the duck you wish to fly?\n";
				cin >> duckName;

				pond.increaseFly(duckName);   //Calls on the function to increment the height
				break;
			
			//Prints out the ducks and heights in the pond
			case '3':
				pond.print();
				break;

			//Quits the program
			case '4':
				endProgram = 1;   //Updates endProgram to 1
				break;

			//If the user inputs anything else, loops through again
			default:
				cout << "\nInvalid input! Please choose from the menu.\n";
				break;
		}
	} while (endProgram == 0);   //Ends when endProgram is updated
}