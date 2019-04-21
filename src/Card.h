/**********************************************
 * Card.h
 * ********************************************
 * Description: Contains the public and private
 * instance data and members used to manage a
 * Card object
 * ********************************************
 *
 *  Created on: Oct 4, 2017
 *      Author: Vagner Machado
 **********************************************
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card
{
private:
	int value;
	int suit;
	int rank;

public:
	Card();
	Card( int value, int suit, int rank);
	int getRank() const;
	void setRank(int rank);
	int getSuit() const;
	void setSuit(int suit);
	int getValue() const;
	void setValue(int value);
	int compareValue(const Card &e) const;
	int compareRank(const Card &e) const;
	int compareSuit(const Card &e) const;
	const std::string output() const;
	friend std::ostream& operator << (std::ostream& out, const Card& c);


};


#endif /* CARD_H_ */

