/********************************************************************
 * Hand.h
 ********************************************************************
 *  Created on: Nov 28, 2017
 * @author Vagner Machado
 * ******************************************************************
 * Description: This class contains the private and public functions
 * and variables used to manage a hand of cards
 * ******************************************************************
 */


#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include <string>

class Hand
{
private:
	LinkedList<Card> * hand;
public:
	Hand();
	LinkedList<Card>& getHand();
	int countRank(int rank) const ;
	int evaluate() const ;
	Card& getCardAt(int index);
	int getCount();
	bool hasRank(int rank) const ;
	void insertCard(Card * card);
	bool isEmpty() const;
	std::string display() const;
	void clear();
};
#endif
