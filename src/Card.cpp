/*********************************************************
 * Card.cpp
 *********************************************************
 *  Created on: Oct 4, 2017
 *  Author: Vagner Machado
 *********************************************************
 *  Description: This class contains the implementations
 *  for the function prototypes declared in Card.h
 *  ******************************************************
 */

#include "Card.h"
#include <string>
#include <iomanip>
#include <sstream>

/**
 * Card default constructor: initialized all instance data to 0
 */
Card::Card(): value(0), suit(0), rank(0)
{

}

/**
 * Card parameterized constructor - initializes all values to the parameters passed in
 * by the user
 * @param v - the card value
 * @param s - the card suit
 * @param r - the card rank
 */
Card::Card(int v, int s, int r):value(v), suit(s), rank(r)
{

}

/**
 * getRank - accessor for the rank
 * @return rank - the card rank
 */
int Card::getRank() const
{
	return rank;
}

/**
 * setRank - mutator for the rank instance data
 * @param r - the rank for the Card
 */
void Card::setRank(int r)
{
	rank = r;
}

/**
 * getSuit - accessor for the suit of a Card
 * @return suit - this Card suit
 */
int Card::getSuit() const
{
	return suit;
}

/**
 * setSuit - mutator for the Card suit
 * @param s - this Card suit
 */
void Card::setSuit(int s)
{
	suit = s;
}

/**
 * getValue - accessor for the value instance data
 * @return value - this Card value
 */
int Card::getValue() const
{
	return value;
}

/**
 * setValue - mutator for the value instance data
 * @param v - the card value
 */
void Card::setValue(int v)
{
	value = v;
}

/**
 * compareValue - compares the value of two cards
 * @param c - the card being compared to this
 * @return positive number if this card has greater value, negative number if this card has lower value, zero if the same value
 */
int Card::compareValue(const Card& c) const
{
	return value - c.value;
}

/**
 * compareRank - compares the rank of two cards
 * @param e - the card being compared to this
 * @return positive number if this card has greater rank, negative number if this card has lower rank, zero if the same rank
 */
int Card::compareRank(const Card &e) const
{
	return rank - e.rank;
}

/**
 * compareSuit- compares the suit of two cards
 * @param e - the card being compared to this
 * @return positive number if this card has greater suit, negative number if this card has lower suit, zero if the same suit
 */
int Card::compareSuit(const Card &e) const
{
	return suit - e.suit;
}

/**
 * output - prints out the card isntance data in a readable format
 * @return ss - a string containing the value, suit and rank for a card
 */
const std::string Card::output() const
{

	std::string s[] = {"Diamonds", "Clubs", "Hearts","Spades"};
	std::string r[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack", "Queen","King"};
	std::stringstream ss;
	ss << std::setw(5) << std::right << r[rank] << " of " << std::setw(8) << std::left << s[suit] << " - Value: " << value << '\n';
	return ss.str();
	/*
	 ALTERNATIVE: the problem is that you cannot use setw and std::right flags concatenated into string
	    char vBuffer[3];
		vBuffer[2] = '\0';
		vBuffer[1] = '\0';
		sprintf(vBuffer, "%i", value);
		std::string val(vBuffer);
		return  r[rank] + " of " + s[suit] + " - Value: " + val + '\n';
		//the problem is that you cannot use setw and std::right flags
	 */
}

/**
 * operator << - prints out the card isntance data in a readable format
 * @param out -  a reference to an output stream
 * @param c - a reference to a card to be displayed
 * @return - a reference to the output stream
 */
std::ostream& operator << (std::ostream& out, const Card& c)
{
	std::string s[] = {"Diamonds", "Clubs", "Hearts","Spades"};
	std::string r[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack", "Queen","King"};
	std::stringstream ss;
	ss << std::setw(5) << std::right << r[c.getRank()] << " of " << std::setw(8) << std::left << s[c.getSuit()] << " - Value: " << c.getValue() << '\n';
	out << ss.str();
	return out;
}
