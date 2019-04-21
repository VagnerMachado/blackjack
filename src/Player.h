/***************************************************************************
 * Player.h
 ***************************************************************************
 *  Created on: Nov 29, 2017
 *      Author: Vagner Machado
 ***************************************************************************
 *Description: This class contains the private instance data and public
 *functions needed to manage a Player in a card game
 ***************************************************************************
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"
#include <string>

class Player
{
private:
	Hand * hand;
	int score;
	std::string name;
	bool bust;
	bool won;
public:
	Player();
	Player(const std::string& name);
	void addCard(Card * x);
	Hand * getHand();
	int getScore()const ;
	//void addScore(int x);
	void win();
	void lose();
	void setName(const std::string& n);
	const std::string& getName();
	void setBust(bool x);
	bool getBust() const;
	void setWin(bool x);
		bool getWin() const;
};


#endif /* PLAYER_H_ */
