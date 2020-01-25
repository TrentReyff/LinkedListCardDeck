// Author: Trent Reyff   Date: 11/10/19
// Title: Assignment4
// Description: A Hi-Low-Guess game using a deck of cards made with a linked list
#include <stdio.h>
#include <iostream>
#include "Card.h"
#include "BagNode.h"
#include "Bag.h"
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void gameDriver();
void getProbability(Bag*, Card*, int);


int main()
{
	cout << "Welcome to the Hi-Low-Guess Game!\n\n";
	gameDriver(); //starts the game

	system("pause");
	return 0;
}

// plays a game of HI-LOW-Guess
// uses getProbability to simulate counting cards
void gameDriver()
{
	int drawnCount = 0;
	int points = 0;
	int choice = 0;
	int nextVal = 0;
	bool isOver = false;
	Card* drawn[32];
	Card* last = NULL;
	Card* next = NULL;
	Bag* deck = new Bag();
	deck->fillWithCards();

	do
	{
		if (drawnCount == 0)
		{
			last = deck->grab();
			drawn[drawnCount] = last;
			drawnCount++;
		}
		cout << "Cards drawn:\n";
		for (int i = 0; i < drawnCount; i++)
		{
			drawn[i]->print();
			cout << " ";
		}
		cout << "\n\n";
		cout << "Cards left in deck: " << 52 - drawnCount << "\n";
		getProbability(deck, last, drawnCount);

		cout << "Last card: ";
		last->print();
		cout << "\nPoints: " << points << "\nChoose option:\n";
		printf("1 %c Next card will be higher\n", '-');
		printf("2 %c Next card will be lower\n", '-');
		printf("3 %c Guess exact value\n", '-');

		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			cout << "Invalid choice, choose again!\n";
			cin >> choice;
		}

		
		if (choice == 1 || choice == 2)
		{
			next = deck->grab();
			cout << "\ndrawing card...\n";
			next->print();
			if (next->isHigher(*last))
			{
				cout << " is higher than ";
				last->print();
				cout << "\n";
				if (choice == 1)
				{
					points++;
					cout << "One point added\n";
				}
				else
				{
					isOver = true;
				}
			}
			else if (next->isLower(*last))
			{
				cout << " is lower than ";
				last->print();
				cout << "\n";
				if (choice == 2)
				{
					points++;
					cout << "One point added\n";
				}
				else
				{
					isOver = true;
				}
			}
			else
			{
				cout << " has value equal to ";
				last->print();
				cout << "\nNo points added\n";
			}
		}
		else
		{
			cout << "\nGuess the next cards value, 1 through 13: ";
			cin >> nextVal;
			next = deck->grab();
			cout << "\ndrawing card...\n";
			next->print();

			if (nextVal == next->getValue())
			{
				cout << " has value equal to " << nextVal << "\n";
				points+= 5;
				cout << "Five points added\n";
			}
			else
			{
				isOver = true;
			}
		}
		if (drawnCount == 32 && isOver == false) //reshuffles the deck once the drawnCount hits 32
		{
			cout << "Shuffling deck..\n";
			deck->fillWithCards();
			drawnCount = 0;
		}
		if (isOver == false)
		{
			drawn[drawnCount] = next;
			last = next;
			drawnCount++;
			system("pause");
		}
	} while (isOver == false); //loops till player losses
	cout << "\nGAME OVER\n";
	cout << "Total Points: " << points << "\n";

	//free memory
	deck->empty();
	delete deck;
	delete last;
	delete next;
}

// helper method specifically for gameDriver
// calculates different probabilites of what the next card drawn will be based on whats left in the deck
void getProbability(Bag* deck, Card* last, int drawnCount)
{
	int lowerCount = 0;
	int lastValCount;
	int lastVal = last->getValue();
	int valCount[13] = { 0 };
	double prob[13] = { 0 };
	BagNode* temp = deck->head;
	do
	{
		valCount[temp->getCard()->getValue() - 1] ++;
		temp = temp->getNext();
	} while (temp != NULL);
	delete temp;
	lastValCount = valCount[lastVal - 1];

	for (int i = 0; i < 13; i++)
	{
		if (i < lastVal - 1)
		{
			lowerCount += valCount[i];
		}
		prob[i] = (double) 100.0 * valCount[i] / (52.0 - drawnCount);
	}

	cout << setprecision(2) <<  "Probability of next card being higher: " << (double) (52.0 - drawnCount -	lowerCount - lastValCount) / (52.0 - drawnCount) * 100 << "%\n";
	cout << setprecision(2) << "Probability of next card being lower: " << (double) (lowerCount) / (52.0 - drawnCount) * 100 << "%\n";
	cout << setprecision(2) << "Probability of next card being the same: " << (double) lastValCount / (52.0 - drawnCount) * 100 << "%\n\n";

	cout << setprecision(2) << "Probability of next card being:\n";
	cout << setprecision(2) << "A       " << prob[0] << "%\n";
	cout << setprecision(2) << "2       " << prob[1] << "%\n";
	cout << setprecision(2) << "3       " << prob[2] << "%\n";
	cout << setprecision(2) << "4       " << prob[3] << "%\n";
	cout << setprecision(2) << "5       " << prob[4] << "%\n";
	cout << setprecision(2) << "6       " << prob[5] << "%\n";
	cout << setprecision(2) << "7       " << prob[6] << "%\n";
	cout << setprecision(2) << "8       " << prob[7] << "%\n";
	cout << setprecision(2) << "9       " << prob[8] << "%\n";
	cout << setprecision(2) << "10      " << prob[9] << "%\n";
	cout << setprecision(2) << "J       " << prob[10] << "%\n";
	cout << setprecision(2) << "Q       " << prob[11] << "%\n";
	cout << setprecision(2) << "K       " << prob[12] << "%\n\n";
}