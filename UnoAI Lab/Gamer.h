#pragma once

#include "AI.h"
#include "Card.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Gamer : public AI
{
public:
	Gamer(int num);

	void onOtherPlayerMove(int playerNumber, Card justPlayed, Color choosenCardColor);
	void onOtherPlayerDraw(int playerNumber);

	//the returned int refers to the index of which card is played in your hand.
	int makeMove(Card justPlayed, Color choosenCardColor, bool justDrew, vector<int> scores, vector<int> cardAmountsByPlayer, vector<Card> cardsInHand, int direction);
	string getName();
	Color getNewColor();

private:
	int myPlayerNumber;
	Color savedColor;
	Gamer* Kratos;
};