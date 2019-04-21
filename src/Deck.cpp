/**************************************************************
 * Deck.cpp
 **************************************************************
 *  Created on: Oct 7, 2017
 *      Author: Vagner Machado
 **************************************************************
 *  Description -  This class contains all the implementations
 *  for the prototypes defined in Deck.h, whic allows the
 *  used to manage a Deck of cards
 ***************************************************************
 *
 */

#include "Deck.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

/**
 * Deck default constructor - initialized the deck to be a stack with
 * capacity to hold 52 cards, instantiates the cards and adds them to the
 * deck
 */
Deck::Deck()//: size(0)
{
	deck = new Stack <Card>();
	for(int i = 0; i < 52; i++)
	{
		int suit = i/13;
		int ran = i%13;
		int val;
		//value optimized for the Balckjack card
		if (ran > 9)
			val = 10;
		else if(ran != 0)
			val = ran + 1;
		else
			val = 1;
		Card * card = new Card(val, suit, ran);
		deck->push(card);
		//	size++;
	}
}

/**
 * Deck parameterized cosntructor - initialized the deck to be a stack with
 *the capacity passed in by the user. That many cards are instantiated and
 *the added to the stack
 * @param v - the capacity for the stack
 */
Deck::Deck(int v)
{
	deck = new Stack <Card>(v);
	for(int i = 0; i < v; i++)
	{
		int suit = i/13;
		int val = i%13;
		Card * card = new Card(val, suit, val);
		deck->push(card);
		//size
	}
}

/**
 * deal - removes the card from the top of the deck and returns it
 * @return deck.pop - a card on top of the stack
 */
Card * Deck::deal()
{
	if(deck->getSize() != 0)
	{
		//size--;
		return deck->pop();
	}
	else
		//i opted to make a new deck to keep the game going, instead of throwing an exception
		//throw CardGameError((char*)"Exception - Deck::deal - The deck is Empty");
	{
		std::cout << "\n***  We are starting a new Deck!  ***\n";
		delete deck;
		deck = new Stack <Card>();
		for(int i = 0; i < 52; i++)
		{
			int suit = i/13;
			int ran = i%13;
			int val;
			//value optimized for the Blackjack card
			if (ran > 9)
				val = 10;
			else if(ran != 0)
				val = ran + 1;
			else
				val = 1;
			Card * card = new Card(val, suit, ran);
			deck->push(card);
			//	size++;
		}
		shuffle(); shuffle();
	}
	return deck->pop();
}

/**
 * shuffle - shuffles the deck of cards
 */
void Deck::shuffle()
{
	int size = deck->getSize();
	//int z = 0;

	bool used [size];
	//std::cout << "\nThis is bool array size: "<< deck->getSize();
	for (int i = 0; i < size; i++)
		used[i] = false;

	Card ** shuffled = new Card * [size];
	int pos;
	srand(time(NULL)); //randomizes all calls to rand
	while(deck->getSize() != 0)
	{

		pos = rand() % deck->getSize();
		while(used[pos] == true){
			pos = rand() % size;
			//z++;
		}
		shuffled[pos]= deck->pop();
		used[pos] = true;
	}
	for(int i = 0; i < size; i++)
		deck->push(shuffled[i]);
}

/**
 * output - gives the user a string with all cards in the deck
 * @return ss - a string with information about all cards on the deck
 */
std::string Deck::output() const
{
	std::stringstream ss;
	ss << deck->output(); //outputs the whole stack
	return ss.str();
}

/**
 * getSize - accessor for the size of the deck
 * @return
 */
int Deck::getSize()const
{
	return deck->getSize();
}

/**
 * isEmpty - let's the user know if th estack is empty
 * @return - true if empty, false otherwise
 */
const bool Deck::isEmpty() const
{
	return deck->getSize() == 0;
}

/**
 * deck destructor - returns all memory dynamically allocated for a deck
 */
Deck::~Deck()
{
	//calls the stack destructor
	delete deck;
}

/**
 * operator = makes a deep copy of Deck x and initializes this deck to x's values
 * @param x - a reference to a deck
 * @return a reference to this deck
 */
Deck& Deck::operator = (const Deck& x)
{
	if ( &x != this)
	{
		deck = x.deck;
		/*if(deck->getSize() != 0)
		{

			for(int i = 0; i < deck->getSize(); i++)
			{
				delete (*deck)[i];
				delete deck;
			}
			deck = new Stack <Card>();
			for(int i = 0; i < x.getSize(); i ++)
			{
				deck->push(new Card((*x.deck)[i]->getValue(), (*x.deck)[i]->getSuit(), (*x.deck)[i]->getRank()));
			}
		}*/

	}
	return *this;
}

/**
 * Deck copy constructor - initialized this deck to a deep copy of x deck
 */
Deck::Deck(const Deck& x)
{
	//calls the stack overloaded = assignment to make a deep copy


	deck = x.deck;


	/*deck = new Stack <Card>();
	//if ( x !=  NULL)
	{
		for ( int i = 0; i < x.getSize(); i++)
		{
			deck->push(new Card((*x.deck)[i]->getValue(), (*x.deck)[i]->getSuit(), (*x.deck)[i]->getRank()));
		}
	}*/

}




