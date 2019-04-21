/***************************************************************************
 * Player.cpp
 ***************************************************************************
 *  Created on: Nov 29, 2017
 *      Author: Vagner Machado
 ***************************************************************************
 *Description: This class contains the implementation of the function
 *prototypes declared in Player.h. The constructors and public functions
 *prototypes are used to manage a player in a card game.
 ***************************************************************************
 */


#include <iostream>
#include "Player.h"
#include "Hand.h"

/**
 * Player default constructor - instantiates a player with default values
 */
Player::Player() : hand(new Hand()), score(0), name(""), bust(false), won(false)
{

}

/**
 * Player parameterized constructor - initialized a player with the data passed as parameter
 * @param n - the name for the player
 */
Player::Player(const std::string& n) : hand(new Hand()), score(0), name(n), bust(false), won(false)
{

}

/**
 * addCard - adds a card to the player's hand
 * @param x - the card tot be added to the player's hand
 */
void Player::addCard(Card * x)
{
	hand->insertCard(x);
}

/**
 * getHand - accessor for this player's hand
 * @return hand -  this player's hand
 */
Hand * Player::getHand()
{
	return hand;
}

/**
 * getScore - accessor for this player's score
 * @return score - this player's score
 */
int Player::getScore()const
{
	return score;
}

/**
 * win - adds a point to this player's score
 */
void Player::win()
{
	score++;
}

/**
 * lose - subtracts a point from this player's score
 */
void Player::lose()
{
	score--;
}

/**
 * setName - mutator for the name instance data
 * @param n - the name for this player
 */
void Player::setName(const std::string& n)
{
	name = n;
}

/**
 * getName - accessor for the name instance data
 * @return name - this player's name
 */
const std::string& Player::getName()
{
	return name;
}

/**
 * setBust - mutator for the bust instance data
 * @param x - true if player busted, false to restart the player's bust status
 */
void Player::setBust(bool x)
{
	bust = x;
}

/**
 * getBust - accessor for the bust instance data
 * @return bust - true if player busted, false otherwise
 */
bool Player::getBust() const
{
	return bust;
}

/**
 * setWin - mutator for the won instance data
 * @param x - true if player won hand, false to restart the player's win status
 */
void Player::setWin(bool x)
{
	won = x;
}

/**
 * getWin - accessor for the won instance data
 * @return won - true if player won hand, false otherwise
 */
bool Player::getWin() const
{
	return won;
}
