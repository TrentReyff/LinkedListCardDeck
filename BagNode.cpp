//Title: BagNode
//Desc: a Node used for a linked list of cards, holds a card pointer and a pointer to the next node

#include "BagNode.h"
#include <stdlib.h>

//basic constructor sets card and next to null
BagNode::BagNode()
{
	this->card = NULL;
	this->next = NULL;
}

//basic constructor sets card and next to parameter values
BagNode::BagNode(Card* card, BagNode* node)
{
	this->card = card;
	this->next = node;
}

//getter for card
Card* BagNode::getCard()
{
	return this->card;
}

//getter for next
BagNode* BagNode::getNext()
{
	return this->next;
}

//setter for card
void BagNode::setCard(Card* card)
{
	this->card = card;
}

//setter for next
void BagNode::setNext(BagNode* node)
{
	this->next = node;
}