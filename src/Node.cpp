/**********************************************************************************
 * Node.cpp
 **********************************************************************************
 *  Created on: Nov 9, 2017
 *      Author: Vagner Machado
 **********************************************************************************
 *  Description: This class contains the implementation of the prototypes  declared
 *  in Node.h. The constructors and functions allow the user to manage a Node
 *  containing a pointer to data and another to the next node
 **********************************************************************************
 */
#include "Node.h"
#include <cstdlib>

/**
 * Node default constructor - instantiates a node with null pointer for both isntance
 * variables
 */
Node::Node(): data(NULL), next(NULL)
{

}

/**
 * Parameterized Node constructor - initializes the Node data to a card pointer and
 * the next node pointer to null
 * @param c - the card this node data is pointing to
 */
Node::Node(Card * card) : data(card), next(NULL)
{

}

/**
 * Node parameterized constructor - initialized a Node data that points to the
 * card and the next node
 * @param card - the card this node's data points to
 * @param nex - the node next to this one
 */
Node::Node(Card * card, Node * nex) : data(card), next(nex)
{

}

/**
 * getNext - accessor to the next node
 * @return next - the node next to this one
 */
Node * Node::getNext()
{
	return next;
}

/**
 * setNext - mutator to the next node
 * @param x - the node next to this one
 */
void Node::setNext(Node * x)
{
	next = x;
}

/**
 * getData - accessor for the data in this node
 * @return data - a pointer to the data of this node
 */
Card * Node::getData()
{
	return data;
}

/**
 * setData - mutator for the data instance variable
 * @param c - the card the data variable points to
 */
void Node::setData(Card * c)
{
	data = c;
}
