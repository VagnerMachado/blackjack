/**************************************************************************
 * Hand.cpp
 **************************************************************************
 *  Created on: Nov 28, 2017
 *      Author: Vagner Machado
 **************************************************************************
 * Description: This class constains the implementation of the prototypes
 * declared in its Hand.h. These function allow the user to manage a hand
 * of cards by inserting, removing and printing its contents amongst other
 * functions.
 * ***********************************************************************
 */

#include "Hand.h"
#include <iostream>
#include <cstdlib>

/**
 * Hand default cosntructor -  instantiates a linked list, which will be used to
 * hold the cards on the hand
 */
Hand::Hand()
{
	hand = new LinkedList<Card>();
}

/**
 * getHand - accessor for the hand of cards
 * @return hand - the hand of cards
 */
LinkedList<Card>& Hand::getHand()
{
	return * hand;
}

/**
 * countRank - accessor to the sum of ranks
 * @param rank - the ranks to be summed up
 * @return
 */
int Hand::countRank(int rank) const
{
	int result;
	for(int i = 0; i < hand->getSize(); i++)
	{
		result += (*hand)[i].getRank();
	}
	return result;
}

/**
 * evaluate - designed to evaluate a blackjack hand
 * @return an int value for the hand
 */
int Hand::evaluate() const
{
	int result = 0;
	int aceCount = 0;
	//add all non ace values
 for(int i = 0; i < hand->getSize(); i++)
 {
	 int value = (*hand)[i].getValue();
	 if(value != 1)
	 {
		 result += value;
		// std::cout << "\nAdding " << x;
	 }
	 else
	 {
		 aceCount++;
		 //std::cout << "\nFound ACE ";
	 }
 }
 //case there are aces:
 //two aces would go over 21 at 11,
 //so if you have more than one ace, they add as one, the last ace is evaluated to be either 1 or 11
 if(aceCount > 0)
 {
	 //additional aces are worth 1
	 if(aceCount > 1)
	 {
		 result += aceCount - 1;
		 //std::cout << "\nMORE than one ACE, there are " << aceCount;
	 }
	 //last ace is evaluated to be 1 or 11;
	 if (result + 11 > 21)
	 {
		 result += 1;
		 //std::cout << "\nOVER 21, adding 1";
	 }
	 else
	 {
		 result +=11;
		// std::cout << "\nNOT OVER 21, adding 11 ";
	 }
 }
 return result;

}

/**
 * getCardAt - accessor for a specific card at a valid index
 * @return - the card at that valid index
 */
Card& Hand::getCardAt(int index)
{
	if(index < 0 || index >= hand->getSize())
	{
		std::cout << "Hand - getCardAt - Index out of bounds";
		exit(1);
	}

	return (*hand)[index];
}

/**
 * getCount - accessor for the size of the hand
 * @return - the size of the hand
 */
int Hand::getCount()
{
	return hand->getSize();
}

/**
 * hasRank - let's user know if the hand has card with certain rank
 * @param rank - the rank being searched
 * @return - true if there is a card with that rank, false otherwise
 */
bool Hand::hasRank(int rank) const
{
	for(int i = 0; i < hand->getSize(); i++)
	{
		if((*hand)[i].getRank() == rank)
			return true;
	}
	return false;
}

/**
 * insertCard - inserts a card into the hand
 * @param card - the card to be inserted
 */
void Hand::insertCard(Card * card)
{
hand->insert(card);
}

/**
 * isEmpty - let's user know if the hand is empty
 * @return true if empty, false otherwise
 */
bool Hand::isEmpty() const
{
	return hand->getSize() == 0;
}

/**
 * display - gives the user a string with all cards in the hand
 * @return - a string with all cards in the hand
 */
std::string Hand::display() const
{

	return hand->display();

}

/**
 * deletes the current hand and instantiates a new one
 */
void Hand::clear()
{
	delete hand;
	hand = new LinkedList<Card>();
}


