/***********************************************************************************
 * Node.h
 ***********************************************************************************
 *  Created on: Nov 9, 2017
 *      Author: Vagner Machado
 ***********************************************************************************
 * Description: This class contains the private instance variable and public
 * prototypes for functions needed to manage a node with a pointer to the data
 * and another pointer to the next node
 ***********************************************************************************
 */

#ifndef NODE_H_
#define NODE_H_
#include "Card.h"

class Node
	{
	private:
		Card * data;
		Node * next;

	public:
		Node();
		Node(Card * c);
		Node(Card * c, Node * next);
		Node * getNext();
		void setNext(Node * n);
		Card * getData();
		void setData(Card * c);
	};

#endif /* NODE_H_ */
