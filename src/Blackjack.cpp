/******************************************************
 * Blackjack.cpp
 ******************************************************
 *  Created on: Nov 29, 2017
 *      Author: Vagner Machado
 ******************************************************
 *  Description: This class contains the implementation
 *  of the public functions declared its header file
 ******************************************************
 */

#include "Blackjack.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <cstdio>

/**
 * Blackjack default constructor - allow the user to instantiate a
 * game of blackjack
 */
Blackjack::Blackjack()
{

}

/**
 * play - contains all the logic for the blackjack game. This method should be called
 * upon the instantiated blackjack object to start the game
 */
void Blackjack::play()
{
	std::cout << "\n\n*** Hello, I am Vagner, your blackjack dealer ***\n\n"
			<< "\nA few simple rules:\n"
			<< "\n- The dealer hits while his hand is less than 17"
			<< "\n- Each player's initial score is zero"
			<< "\n- For each win against the dealer, a player gets 1 score point"
			<< "\n- For each bust or loss against the dealer, a player loses 1 score point"
			<< "\n- For each push/tie against the dealer, the player does not win or lose score points,\n"
			<< "    while other players not holding a blackjack, lose 1 score point\n\n"
			<< "\n\n    *** How many of you would like to play?*** \n";

	//array of players
	int number;
	std::cin >> number;
	std::string * names = new std::string[number + 1];
	names[number] = "The Dealer";
	char c;

	//names
	std::cout << "Now, what is you name?  ";
	std::cin >> names[0];
	while((c = getchar()) != '\n' && c != '\r')
		names[0] += c;
	for(int i = 1; i < number; i++)
	{
		std::cout << "And yours?  ";
		std::cin >> names[i];
		while((c = getchar()) != '\n' && c != '\r')
			names[i] += c;
	}

	//place players in a array, dealer is in array[number]
	Player * players = new Player[number + 1];
	for(int i = 0; i <= number; i++)
	{
		players[i].setName(names[i]);
	}

	//instantiates and shuffles a new deck
	Deck * deck = new Deck();
	deck->shuffle();
	deck->shuffle();

	bool quit = false;
	while(!quit)
	{

		//deal two cards each player
		for(int j = 0; j < 2; j++)
		{
			for(int i = 0; i < number; i++)
			{
				players[i].addCard(deck->deal());
			}
		}

		//prints the cards for the players
		for(int i = 0; i < number; i++)
		{
			std::cout << "\nCards for "
					<< players[i].getName()	<< ":\n"
					<< players[i].getHand()->display()
					<< "You hand is worth " << players[i].getHand()->evaluate()
					<< " points\n";
		}

		//deal two cards for the dealer, one face up;
		players[number].addCard(deck->deal());
		std::cout << "\nCards for " << players[number].getName() << ":\n"
				<< players[number].getHand()->display()
				<< "Another card is facing down!\n";

		//card not shown to players
		players[number].addCard(deck->deal());

		//evaluate all hands and check for winners
		int winnerCount = 0;

		//winner counter
		for(int i = 0; i < number; i++)
		{
			int value = players[i].getHand()->evaluate();
			if(value == 21)
				winnerCount++;
		}

		//if there is a player and the dealer with a blackjack
		if(winnerCount > 0 && players[number].getHand()->evaluate() == 21)
		{
			std::cout << "\n*** It is a Push ***\n";
			for(int i = 0; i < number; i++)
			{
				if(players[i].getHand()->evaluate() == 21)
				{
					std::cout << "\n" << players[i].getName() << "\n"
							<< players[i].getHand()->display()
							<< "\n***   You tied with dealer with 21 points  ***\n";
				}
				else
				{
					std::cout << "\n" << players[i].getName() << "\n"
							<< players[i].getHand()->display();
					int v = players[i].getHand()->evaluate();
					std::cout << "\n*** You lost, your hand has " << v << " points ***\n";
					players[i].lose();
				}
			}
			std::cout << "\n*** The dealer had " << players[number].getHand()->evaluate() << " points ***\n "
					<< players[number].getHand()->display();
		}

		//player win , dealer does not have 21
		/*else if (winnerCount > 0)
		{
			std::cout << "\n*** Who is the winner? ***\n";
			for(int i = 0; i < number; i++)
			{
				if(players[i].getHand()->evaluate() == 21)
				{
					std::cout << "\n" << players[i].getName()
										<< "\n" << players[i].getHand()->display();
					std::cout << "\n*** You won, your hand has 21 points ***\n";
					players[i].win();
				}

				//game continues here
				else
				{
					std::cout << "\n" << players[i].getName() << "\n"
							<< players[i].getHand()->display();
					int v = players[i].getHand()->evaluate();
					std::cout << "\n*** You lost, your hand has " << v << " points ***\n";
					players[i].lose();
				}
			}
			std::cout << "\n*** The dealer had " << players[number].getHand()->evaluate() << " points ***\n "
					<< players[number].getHand()->display();
		}*/
		//the dealer has a blackjack, everyone loses
		else if (players[number].getHand()->evaluate() == 21)
		{
			std::cout << "\n*** The dealer wins! ***\n" << players[number].getHand()->display();
			for(int i = 0; i < number; i++)
			{
				std::cout << "\n" << players[i].getName() << "\n"
						<< players[i].getHand()->display();
				int v = players[i].getHand()->evaluate();
				std::cout << "\n*** You lost, your hand has " << v << " points ***\n";
				players[i].lose();

			}
			std::cout << "\n*** The dealer had " << players[number].getHand()->evaluate() << " points ***\n "
					<< players[number].getHand()->display();
		}

		//if at least one player does not have 21, hit / stand
		else
		{
			if(winnerCount > 0)
			{
				std::cout << "\n*** We have a winner! ***\n";
				for(int i = 0; i < number; i++)
				{
					if(players[i].getHand()->evaluate() == 21)
					{
						std::cout << "\n" << players[i].getName() << "\n" << players[i].getHand()->display();
						std::cout << "\n*** You won, your hand has 21 points ***\n";
						players[i].win();
						players[i].setWin(true);

					}
				}
			}
			int bust = 0;
			char answer;
			for (int i = 0; i < number; i++)
			{
				if(players[i].getWin() == false)
				{
					bool done = false;
					while(!done)
					{
						do
						{
							std::cout << "\n" <<  players[i].getName() << ", do you want another card? (Y/N)\n";
							std::cin >> answer;
						}
						while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

						if (answer == 'n' || answer == 'N')
							done = true;
						else
						{
							players[i].getHand()->insertCard(deck->deal());
							std::cout << players[i].getHand()->display();
							int v = players[i].getHand()->evaluate();
							std::cout << "\n*** You have " << v << " points ***\n";
							if(v > 21)
							{
								players[i].setBust(true);
								players[i].lose();
								std::cout << "\n*** "<< players[i].getName() << ", you busted! ***\n";
								done = true;
								bust++;
							}
						}
					}
				}
			}
			//all busted, the dealer wins
			if(bust == (number - winnerCount))
				std::cout << "\n*** Everyone busted, the dealer wins! ***\n";

			//dealer gets cards till at least 17
			else
			{
				bool done = false;
				while(!done && players[number].getHand()->evaluate() < 17)
				{
					std::cout << "\n*** The dealer gets cards ***\n";
					//std::cout << players[number].getHand()->display();
					players[number].getHand()->insertCard(deck->deal());
					int v = players[number].getHand()->evaluate();
					std::cout << "\n" << players[number].getHand()->display();
					std::cout << "*** The dealer has " << v << " points ***\n";

					//if dealer busted, all players not yet busted win
					if(v > 21)
					{
						std::cout << "\n***    The Dealer Busted!  ***\n";
						done = true;
						players[number].setBust(true);
						//std::cout << "\n***  Here are the winners  ***\n";
						for(int i = 0; i < number; i++)
						{
							if(players[i].getBust() == false && players[i].getWin() == false)
							{
								std::cout << "\n***  " << players[i].getName() << " wins! ***\n"
										<< players[i].getHand()->display()
										<< "*** You have " << players[i].getHand()->evaluate()  << " points ***\n";
								players[i].win();
								players[i].setWin(true);
							}
							else if(players[i].getBust() == true)
							{
								std::cout << "\n***  " << players[i].getName() << " lost! ***\n"
										<< players[i].getHand()->display()
										<< "*** You have " << players[i].getHand()->evaluate()  << " points ***\n";
								if(players[i].getBust() != true)
									players[i].lose();
							}
						}
					}
					else
						if(players[number].getHand()->evaluate() >= 17)
							done = true; //safety check for the while loop
				}

				//if dealer is not busted, analyzes all players that have not yet won (i.e. got a blackjack on the first two cards)
				if(players[number].getBust() == false)
				{
					for(int i = 0; i < number;i++)
					{
						if(players[i].getBust() == false && players[i].getHand()->evaluate() > players[number].getHand()->evaluate() && players[i].getWin() == false)
						{
							std::cout << "\n***  " << players[i].getName() << " wins! ***\n"
									<< players[i].getHand()->display()
									<< "*** You have " << players[i].getHand()->evaluate()  << " points ***\n";
							players[i].win();
						}
						else if (players[i].getBust() == false && players[i].getHand()->evaluate() == players[number].getHand()->evaluate() && players[i].getWin() == false)
						{
							std::cout << "\n***  " << players[i].getName() << " and the dealer tied! ***\n"
									<< players[i].getHand()->display()
									<< "*** You have " << players[i].getHand()->evaluate()  << " points ***\n";
						}
						else if (players[i].getWin() == false)
						{
							std::cout << "\n***  " << players[i].getName() << " lost! ***\n"
									<< players[i].getHand()->display()
									<< "*** You have " << players[i].getHand()->evaluate()  << " points ***\n";
							if(players[i].getBust() != true)
								players[i].lose();
						}

					}
					std::cout << "\n*** The dealer's hand *** \n" << players[number].getHand()->display() <<
							"*** The dealer has " << players[number].getHand()->evaluate()  << " points ***\n";
				} //end dealer and players not busted
			} //ends dealer get card
		} //end hit / stand

		//print an updated score
		std::cout << "\n*** Score Update ***\n\n";
		for(int i = 0; i < number; i++)
		{
			std::cout << players[i].getName() << " your score is " << players[i].getScore() << " points" << "\n";
		}

		//ask for another round, if yes point can accumular
		char answer;
		do
		{
			std::cout << "\n\n*** Would you like to play again: (y/n) ***   ";
			std::cin >> answer;
		}while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

		if( answer == 'y' || answer == 'Y')
		{
			for(int i = 0; i <= number; i++)
			{
				players[i].getHand()->clear();
				players[i].setBust(false);
				players[i].setWin(false);
			}
		}
		else
		{
			quit = true;
			std::cout << "\n***  Good Bye  ***\n";
		}

	} // end while !quit
}// end function play
