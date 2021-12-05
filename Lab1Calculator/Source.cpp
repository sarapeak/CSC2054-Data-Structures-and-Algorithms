#include <iostream>
using namespace std;

int main()
{
	int endProgram = 1;   //A variable that is used to keep a while loop going until changed
	char userInput;   //A variable that is used to take in what a user inputs
	int X = 0, Y = 0, result = 0;   //Variables for the numbers inputted and for result of the operation
	char operatorType;   //A variable for the inputted operator

	//A while loop that stops when its statement becomes false
	while (endProgram == 1)
	{
		//Asks the user to input a calculation, whatever is entered is inputted into its respectful variables
		cout << "Enter a calculation in the form X + Y\n";
		std::cin >> X >> operatorType >> Y;

		//A switch statement to determine which operator was inputted
		switch (operatorType)
		{
			//If +, then it adds the two numbers
			case '+':
				result = X + Y;
				cout << X << " " << operatorType << " " << Y << " = " << result << "\n";
				break;
			//If -, then it subtracts the two numbers
			case '-':
				result = X - Y;
				cout << X << " " << operatorType << " " << Y << " = " << result << "\n";
				break;
			//If *, then it multiplies the two numbers
			case '*':
				result = X * Y;
				cout << X << " " << operatorType << " " << Y << " = " << result << "\n";
				break;
			//If /, then it divides the two numbers
			case '/':
				if (Y == 0)   //If the Y variable is 0, then it will show an error and end the case
				{
					cout << "Error: Cannot divide by zero.\n";
					break;
				}
				result = X / Y;
				cout << X << " " << operatorType << " " << Y << " = " << result << "\n";
				break;
		}
		if (result > 0)
		{
			//A for loop that prints out the number of stars based on the result
			for (int i = 0; i < result && i < 5; i++)   //No more than five stars can be printed out
			{
				cout << "*";
			}
		}

		//Asks the user if they want to enter another calculation
		cout << "\nDo you want to enter another calculation? Please enter y or n.\n";
		std::cin >> userInput;   //Takes in the user's input
		int endCheck = 1;   //A check to end the loop when updated
		
		//A loop that checks what the user inputted
		while (endCheck == 1)
		{
			//If 'n' then the entire program ends
			if (userInput == 'n')
			{
				endCheck = 0;
				endProgram = 0;
			}
			//If 'y' then the program starts from the beginning
			else if (userInput == 'y')
			{
				endCheck = 0;
			}
			//If the user inputs something besides a y or n
			else
			{
				//Tells user that they inputted something beside 'y' or 'n'
				cout << "That is not a valid y or n! Please try again.\n";
				cout << "Do you want to enter another calculation? Please enter y or n.\n";
				std::cin >> userInput;   //Takes in the user's input
			}
		}
	}
}