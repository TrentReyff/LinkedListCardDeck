//Title: Bag
//Desc: a linked list of BagNode's used to simulate a deck of cards
#include "Bag.h"
#include <stdlib.h>
#include <time.h>

//basic constructor
Bag::Bag()
{
	this->size = 0;
	this->head = NULL;
	this->tail = head;
}

//getter for size
int Bag::getCurrentSize()
{
	return this->size;
}

//returns true if size = 0
bool Bag::isEmpty()
{
	return this->size == 0;
}

//adds a BagNode to the tail of the list
void Bag::add(BagNode* node)
{
	if (size == 0)
	{
		this->head = node;
		this->tail = head;
	}
	else
	{
		this->tail->setNext(node);
		this->tail = node;
	}
	this->size++;
}

//removes a random node from the bag and returns the card value
Card* Bag::grab()
{
	srand(time(NULL));
	int index = (rand() % this->size) + 1;
	int i = 1;
	BagNode* current = head;
	BagNode* previous = head;
	Card* grabbed;
	if (index == 1)
	{
		head = head->getNext();
	}
	else
	{
		while (i < index)
		{
			previous = current;
			current = (current->getNext());
			i++;
		}
		if (index == size)
		{
			tail = previous;
		}
		else
		{
			previous->setNext(current->getNext());
		}
	}
	grabbed = current->getCard();
	delete current;
	size--;
	return grabbed;
}

//returns the count of nodes with card value equal to the parameter
int Bag::getFrequencyOf(char value)
{
	int count = 0;
	BagNode* temp = head;
	while (temp != NULL)
	{
		if (temp->getCard()->getValue() == value)
		{
			count++;
		}
		temp = temp->getNext();
	}
	return count;
}

//empties the bag
void Bag::empty()
{
	BagNode* temp = head;
	while (temp != NULL)
	{
		temp = temp->getNext();
		delete head;
		head = temp;
	}
	size = 0;
}

//emptys the bag and fills it with a deck of cards
void Bag::fillWithCards()
{
	int i = 0;
	int vals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char suits[] = { 'C', 'D', 'H', 'S' };
	this->empty();

	do
	{
		for (int j = 0; j < 13; j++)
		{
			this->add(new BagNode(new Card(vals[j], suits[i]), NULL));
		}
		i++;
	} while (i < 4);
}