/*****************************************************************
 * StackError.h
 *****************************************************************
 *  Created on: Oct 20, 2017
 *      Author: Vagner Machado
 *****************************************************************
 * Description : This is an Exception created for this game,
 * derived from the exception class provided by c++. The
 * implementation of this class is inline.
 * ***************************************************************
 */

#ifndef CARDGAMEERROR_H_
#define CARDGAMEERROR_H_
//#include <string>
#include <exception>

class CardGameError : public std::exception
{

private:
	char * error ;
public:
	CardGameError() : error(static_cast<char*>("\nException in Card Game\n")) {}
	CardGameError(char * e) : error(e){ }
	const char * what() const throw()
     {
		return error;
     }
};

#endif /* CARDGAMEERROR_H_ */
