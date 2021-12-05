# include <iostream>
using namespace std;

int main()
{
	int x = 0, y = 0;    //x and y are integers
	char comma;   //A place holder for the comma that will be inputted
	cout << "Enter 2 numbers separated by a comma and press enter\n";
	cout << ": ";
	cin >> x >> comma >> y;   //Takes in the input and assigns them to the variables
	
	if (x == y)   //If x and y are equal, it will print out its output
	{
		cout << "x equals y!\n";
	}
	if (x = y)   //Makes x equal to y and prints out its output
	{
		cout << "x is y!\n";
	}
	if (x == y)   //If x and y are equal, it will print out its output
	{
		cout << "x is still y!\n";
	}
}