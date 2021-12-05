#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "getString.h";   //Includes the getString h file
#include "movePlayer.h";   //Includes the movePlayer h file
#include "moveObstacles.h";   //Includes the moveObstacles h file

int main()
{
	int player = 0;   //Initializes the player
	
	vector<int> obstacle;   //Initializes obstacle
	obstacle.resize(29);   //Resizes the vector to 29
	obstacle.push_back(1);   //Pushes 1 to the end of the vector
	
	char letter;   //Stores a character
	int endProgram = 0;   //Initializes the endProgram
	int frame = 0;   //Initializes the frame

	do   //Loops through until changed to false
	{
		//If frame is divisible by 3
		if (frame / 3 == 1)
		{
			obstacle.at(29) = 1;   //Adds a 1 to the end of the vector
			frame = 0;   //Resets frame to 0
		}

		//Prints out the board
		cout << getString(player, obstacle);
		
		cout << "\n--> ";   //Shows where the player inputs their letter
		cin >> letter;   //Takes in the input
		movePlayer(letter, player);   //Calls the movePlayer function

		if (player == 0)   //If the player is 0, nothing happens
		{	}
		else if (player > 29)   //If player is greater than 29
		{
			if (letter == 'd')   //If letter is d
			{
				player = player - 1;   //Takes one away from player
			}
			else if (letter == 'f')   //If letter is f
			{
				player = player - 2;   //Takes 2 away from player
			}
		}
		else   //If all above are false
		{
			frame++;   //Frame incremented
			moveObstacles(obstacle);   //Calls the moveObstacles function
		}
		
		//Loops through the board
		for (int i = 0; i < 30; i++)
		{
			//If player is at i position and obstacle at the i position equals 1
			if(player == i && obstacle.at(i) == 1)
			{
				//Tells the user they collided with an obstacle
				cout << "You collided with an obstacle! Try again next time!";
				endProgram = 1;   //Updates endProgram
			}
		}

		//If player equals 29
		if (player == 29)
		{
			cout << getString(player, obstacle);   //Prints the board
			cout << "\nYou win!";   //Tells the user that they won
			endProgram = 1;   //Updates endProgram
		}
	} while (endProgram == 0);
}
