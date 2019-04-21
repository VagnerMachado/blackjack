/*********************************************************
 * Deck.h
 *********************************************************
 *  Created on: Oct 7, 2017
 *      Author: Vagner Machado
 *********************************************************
 *  Description: This class has the private and public
 *  instance data and function prototypes used to manage
 *  a Deck of cards placed on a Stack
 *********************************************************
 */

#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include "Stack.h"

class Deck
{
private:
	Stack <Card> * deck;

public:
	Deck();
	Deck(int v);
	Card * deal();
	void shuffle();
	std::string output() const;
	int getSize()const;
	const bool isEmpty() const;
	~Deck();
	Deck& operator = (const Deck& x);
	Deck(const Deck& other);
};

#endif /* DECK_H_ */

/*
 *
 * Notes:
 *
 *
 */
