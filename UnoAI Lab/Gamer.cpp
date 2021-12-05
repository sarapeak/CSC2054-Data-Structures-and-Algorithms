/*AI Gamer code created by Jeremy Bill and Sara Peak to play the game UNO*/
#include "Gamer.h"
#include "AI.h"
#include <iostream>
using namespace std;

Gamer::Gamer(int num) : AI(num)
{
	myPlayerNumber = num;
}

void Gamer::onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor)
{ }
void Gamer::onOtherPlayerDraw(int playerNumber)
{  }

int Gamer::makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction)
{
	int rcount = 0;
	int gcount = 0;
	int ycount = 0;
	int bcount = 0;
	int blcount = 0;
	//Counting the color cards in our deck
	for (int i = 0; i < cardsInHand.size(); i++)
	{
		if (cardsInHand[i].getColor() == RED)
		{
			rcount++;   //Adds 1 to red
		}
		else if (cardsInHand[i].getColor() == BLUE)
		{
			bcount++;   //Adds 1 to blue
		}
		else if (cardsInHand[i].getColor() == GREEN)
		{
			gcount++;   //Adds 1 to green
		}
		else if (cardsInHand[i].getColor() == YELLOW)
		{
			ycount++;   //Adds 1 to yellow
		}
		else if (cardsInHand[i].getColor() == BLACK)
		{
			blcount++;   //Adds 1 to black
		}
	}

	//We want to check our deck to see which card would be the best play; always pick the highest point card
	int bigNum = -1;
	int index = -1;
	//If the color on top of the deck is red and our red counter is greater than 0
	if (choosenCardColor == RED && rcount > 0)
	{
		//Loops through our deck of cards
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card's number is greater than the biggest number and is a red
			if (bigNum < cardsInHand[i].getNumber() && cardsInHand[i].getColor() == RED)
			{
				bigNum = cardsInHand[i].getNumber();   //Makes bigNum the card number
				index = i;                             //Makes the index equal to i
			}
		}
	}
	//If the color on top of the deck is yellow and our yellow counter is greater than 0
	else if (choosenCardColor == YELLOW && ycount > 0)
	{
		//Loops through our deck of cards
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card's number is greater than the biggest number and is a yellow
			if (bigNum < cardsInHand[i].getNumber() && cardsInHand[i].getColor() == YELLOW)
			{
				bigNum = cardsInHand[i].getNumber();   //Makes bigNum the card number
				index = i;                             //Makes the index equal to i
			}
		}
	}
	//If the color on top of the deck is green and our green counter is greater than 0
	else if (choosenCardColor == GREEN && gcount > 0)
	{
		//Loops through our deck of cards
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card's number is greater than the biggest number and is a green
			if (bigNum < cardsInHand[i].getNumber() && cardsInHand[i].getColor() == GREEN)
			{
				bigNum = cardsInHand[i].getNumber();   //Makes bigNum the card number
				index = i;                             //Makes the index equal to i
			}
		}
	}
	//If the color on top of the deck is blue and our blue counter is greater than 0
	else if (choosenCardColor == BLUE && bcount > 0)
	{
		//Loops through our deck of cards
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card's number is greater than the biggest number and is a blue
			if (bigNum < cardsInHand[i].getNumber() && cardsInHand[i].getColor() == BLUE)
			{
				bigNum = cardsInHand[i].getNumber();   //Makes bigNum the card number
				index = i;                             //Makes the index equal to i
			}
		}
	}
	//If the our black counter is greater than 0
	else if (blcount > 0)
	{
		//Loops through our deck of cards
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card's color is a black and the number is a one
			if (cardsInHand[i].getColor() == BLACK && cardsInHand[i].getNumber() == 1)
			{
				//If the rcount is greater than all the other counts
				if (rcount > gcount && rcount > bcount && rcount > ycount)
				{
					savedColor = RED;   //savedColor is now red
				}
				//If the bcount is greater than all the other counts
				else if (bcount > gcount && bcount > rcount && bcount > ycount)
				{
					savedColor = BLUE;   //savedColor is now blue
				}
				//If the gcount is greater than all the other counts
				else if (gcount > rcount && gcount > bcount && gcount > ycount)
				{
					savedColor = GREEN;   //savedColor is now green
				}
				//If the ycount is greater than all the other counts
				else if (ycount > gcount && ycount > bcount && ycount > rcount)
				{
					savedColor = YELLOW;   //savedColor is now yellow
				}
				//If we have the same amount of cards, below will help us to choose the cards with the most points
				//If the bcount is equal to the gcount
				if (bcount == gcount)
				{
					int bpoints = 0;
					int gpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is green
						else if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to gpoints
						}
					}
					//If bpoints is greater than gpoints
					if (bpoints > gpoints)
					{
						savedColor = BLUE;   //savedColor is now blue
					}
					//If gpoints is greater than bpoints
					else if (gpoints > bpoints)
					{
						savedColor = GREEN;   //savedColor is now green
					}
				}
				//If the bcount is equal to the rcount
				else if (bcount == rcount)
				{
					int bpoints = 0;
					int rpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is red
						else if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to rpoints
						}
					}
					//If bpoints is greater than rpoints
					if (bpoints > rpoints)
					{
						savedColor = BLUE;   //savedColor is blue
					}
					//If rpoints is greater than bpoints
					else if (rpoints > bpoints)
					{
						savedColor = RED;   //savedColor is red
					}
				}
				//If the bcount is equal to the ycount
				else if (bcount == ycount)
				{
					int bpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to ypoints
						}
					}
					//If bpoints is greater than ypoints
					if (bpoints > ypoints)
					{
						savedColor = BLUE;   //savedColor is blue
					}
					//If ypoints is greater than bpoints
					else if (ypoints > bpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				//If the rcount is equal to the ycount
				else if (rcount == ycount)
				{
					int rpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is red
						if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the rpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to the ypoints
						}
					}
					//If rpoints is greater than ypoints
					if (rpoints > ypoints)
					{
						savedColor = RED;   //savedColor is red
					}
					//If ypoints is greater than rpoints
					else if (ypoints > rpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				//If the rcount is equal to the gcount
				else if (rcount == gcount)
				{
					int rpoints = 0;
					int gpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is red
						if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the rpoints
						}
						//If the card is green
						else if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the gpoints
						}
					}
					//If rpoints is greater than gpoints
					if (rpoints > gpoints)
					{
						savedColor = RED;   //savedColor is red
					}
					//If gpoints is greater than rpoints
					else if (gpoints > rpoints)
					{
						savedColor = GREEN;   //savedColor is green
					}
				}
				//If the ycount is equal to the gcount
				else if (ycount == gcount)
				{
					int gpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is green
						if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the gpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to the ypoints
						}
					}
					//If gpoints is greater than ypoints
					if (gpoints > ypoints)
					{
						savedColor = GREEN;   //savedColor is green
					}
					//If the ypoints is greater than gpoints
					else if (ypoints > gpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				index = i;   //Makes index equal to i
			}
			//If the card's color is a black and the number is a zero
			else if (cardsInHand[i].getColor() == BLACK && cardsInHand[i].getNumber() == 0)
			{
				//If the rcount is greater than all the other counts	
				if (rcount > gcount && rcount > bcount && rcount > ycount)
				{
					savedColor = RED;   //savedColor is now red
				}
				//If the bcount is greater than all the other counts
				else if (bcount > gcount && bcount > rcount && bcount > ycount)
				{
					savedColor = BLUE;   //savedColor is now blue
				}
				//If the gcount is greater than all the other counts
				else if (gcount > rcount && gcount > bcount && gcount > ycount)
				{
					savedColor = GREEN;   //savedColor is now green
				}
				//If the ycount is greater than all the other counts
				else if (ycount > gcount && ycount > bcount && ycount > rcount)
				{
					savedColor = YELLOW;   //savedColor is now yellow
				}
				//If we have the same amount of cards, below will help us to choose the cards with the most points
				//If the bcount is equal to the gcount
				if (bcount == gcount)
				{
					int bpoints = 0;
					int gpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is green
						else if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to gpoints
						}
					}
					//If bpoints is greater than gpoints
					if (bpoints > gpoints)
					{
						savedColor = BLUE;   //savedColor is now blue
					}
					//If gpoints is greater than bpoints
					else if (gpoints > bpoints)
					{
						savedColor = GREEN;   //savedColor is now green
					}
				}
				//If the bcount is equal to the rcount
				else if (bcount == rcount)
				{
					int bpoints = 0;
					int rpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is red
						else if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to rpoints
						}
					}
					//If bpoints is greater than rpoints
					if (bpoints > rpoints)
					{
						savedColor = BLUE;   //savedColor is blue
					}
					//If rpoints is greater than bpoints
					else if (rpoints > bpoints)
					{
						savedColor = RED;   //savedColor is red
					}
				}
				//If the bcount is equal to the ycount
				else if (bcount == ycount)
				{
					int bpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is blue
						if (cardsInHand[k].getColor() == BLUE)
						{
							bpoints += cardsInHand[k].getNumber();   //Adds the points from the card to bpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to ypoints
						}
					}
					//If bpoints is greater than ypoints
					if (bpoints > ypoints)
					{
						savedColor = BLUE;   //savedColor is blue
					}
					//If ypoints is greater than bpoints
					else if (ypoints > bpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				//If the rcount is equal to the ycount
				else if (rcount == ycount)
				{
					int rpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is red
						if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the rpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to the ypoints
						}
					}
					//If rpoints is greater than ypoints
					if (rpoints > ypoints)
					{
						savedColor = RED;   //savedColor is red
					}
					//If ypoints is greater than rpoints
					else if (ypoints > rpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				//If the rcount is equal to the gcount
				else if (rcount == gcount)
				{
					int rpoints = 0;
					int gpoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is red
						if (cardsInHand[k].getColor() == RED)
						{
							rpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the rpoints
						}
						//If the card is green
						else if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the gpoints
						}
					}
					//If rpoints is greater than gpoints
					if (rpoints > gpoints)
					{
						savedColor = RED;   //savedColor is red
					}
					//If gpoints is greater than rpoints
					else if (gpoints > rpoints)
					{
						savedColor = GREEN;   //savedColor is green
					}
				}
				//If the ycount is equal to the gcount
				else if (ycount == gcount)
				{
					int gpoints = 0;
					int ypoints = 0;
					//Loops through our deck of cards
					for (int k = 0; k < cardsInHand.size(); k++)
					{
						//If the card is green
						if (cardsInHand[k].getColor() == GREEN)
						{
							gpoints += cardsInHand[k].getNumber();   //Adds the points from the card to the gpoints
						}
						//If the card is yellow
						else if (cardsInHand[k].getColor() == YELLOW)
						{
							ypoints += cardsInHand[k].getNumber();   //Adds the points from the card to the ypoints
						}
					}
					//If gpoints is greater than ypoints
					if (gpoints > ypoints)
					{
						savedColor = GREEN;   //savedColor is green
					}
					//If the ypoints is greater than gpoints
					else if (ypoints > gpoints)
					{
						savedColor = YELLOW;   //savedColor is yellow
					}
				}
				index = i;   //Makes index equal to i
			}
		}
	}
	//If no other statments above work, this statement is called to choose the same number card
	else
	{
		//Loops through our deck of cards	
		for (int i = 0; i < cardsInHand.size(); i++)
		{
			//If the card in our deck matches the number of the card just played
			if (cardsInHand[i].getNumber() == justPlayed.getNumber())
			{
				//If the card is yellow and our ycount is greater than all of the other counts
				if (cardsInHand[i].getColor() == YELLOW && ycount > gcount && ycount > bcount && ycount > rcount)
				{
					index = i;   //Makes index equal to i
					break;
				}
				//If the card is red and our rcount is greater than all of the other counts
				else if (cardsInHand[i].getColor() == RED && rcount > gcount && rcount > bcount && rcount > ycount)
				{
					index = i;   //Makes index equal to i
					break;
				}
				//If the card is blue and our bcount is greater than all of the other counts
				else if (cardsInHand[i].getColor() == BLUE && bcount > gcount && bcount > ycount && bcount > rcount)
				{
					index = i;   //Makes index equal to i
					break;
				}
				//If the card is green and our gcount is greater than all of the other counts
				else if (cardsInHand[i].getColor() == GREEN && gcount > ycount && gcount > bcount && gcount > rcount)
				{
					index = i;   //Makes index equal to i
					break;
				}
				else
				{
					index = i;   //Makes index equal to i
				}
			}
		}
	}
	return index;   //Returns the index

	//special card key
	//reverse = 12, skip = 10, and draw2 = 11 of any of red/blue/green/yellow.
	//wild is black 0, draw4 is black 1

	//should not get here in my AI???
	cerr << "bbaaaad happeeeened\n";
	return -1;
}

string Gamer::getName()
{
	return "Master Chief";   //Our awesome name for our Gamer class is Master Chief
}
Color Gamer::getNewColor()
{
	return savedColor;   //Returns the savedColor
}