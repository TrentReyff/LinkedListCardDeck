#pragma once
#include "BagNode.h"

class Bag
{
private:
	int size;
public:
	BagNode* head;
	BagNode* tail;
	int getCurrentSize();
	bool isEmpty();
	void add(BagNode*);
	Card* grab();
	int getFrequencyOf(char);
	void empty();
	void fillWithCards();
	Bag();
};

