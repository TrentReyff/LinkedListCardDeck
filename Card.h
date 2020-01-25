#pragma once
class Card
{
private:
	char suit;
	int value;
public:
	Card(int, char);
	void print();
	char getSuit();
	int getValue();
	bool isHigher(Card);
	bool isLower(Card);
	bool isEqual(Card);
};
