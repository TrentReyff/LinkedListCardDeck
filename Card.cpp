//Title: Card
//Desc: an object representing a card, holds a suit and numerical card value with Aces low

#include "Card.h"
#include <iostream>
using namespace std;

//basic constructor setting value and suit to the parameter values
Card::Card(int value, char suit)
{
	this->value = value;
	this->suit = suit;
}

//getter for suit
char Card::getSuit()
{
	return this->suit;
}

//getter for value
int Card::getValue()
{
	return this->value;
}

//outputs the card
void Card::print()
{
	if (this->value == 1)
	{
		cout << "[A-" << this->suit << "]";
	}
	else if (this->value == 11)
	{
		cout << "[J-" << this->suit << "]";
	}
	else if (this->value == 12)
	{
		cout << "[Q-" << this->suit << "]";
	}
	else if (this->value == 13)
	{
		cout << "[K-" << this->suit << "]";
	}
	else
	{
		cout << "[" << this->value << "-" << this->suit << "]";
	}
}

//returns true if value is greater than the value of other
bool Card::isHigher(Card other)
{
	return this->value > other.getValue();
}

//returns true if value is less than the value of other
bool Card::isLower(Card other)
{
	return this->value < other.getValue();
}

//returns true if value is equal to the value of other
bool Card::isEqual(Card other)
{
	return this->value == other.getValue();
}