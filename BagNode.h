#pragma once
#include "Card.h"
class BagNode
{
private:
	Card* card;
	BagNode* next;
public:
	BagNode();
	BagNode(Card*,BagNode*);
	Card* getCard();
	BagNode* getNext();
	void setCard(Card*);
	void setNext(BagNode*);
};

