///*****************************************************************************************************************
///
///     This class is not being used since the template of LinkedList.h and kept here for reference
///
/// *****************************************************************************************************************
/// *****************************************************************************************************************
///
// * LinkedList.cpp
// *
// *  Created on: Nov 9, 2017
// *      Author: Vagner Machado
// */
//
//#include "LinkedList.h"
//#include "CardGameError.h"
//#include <cstdlib>
//#include <iostream>
//#include "Node.h"
//#include <cstdlib>
//
//
//
//LinkedList::LinkedList() :	head(NULL), tail(NULL), size(0)
//{
//
//}
//
//
//int LinkedList::getSize()
//{
//	return size;
//}
//
//
//void LinkedList::insert(Card * data)
//{
//	Node * t = new Node(data, NULL);
//	if (size == 0)
//	{
//		head = tail = t;
//	}
//	else
//	{
//		tail->setNext(t);
//		tail = t;
//	}
//	size++;
//}
//
//void LinkedList::insertAt(int x, Card * data)
//{
//	if (x < 0 || x > size)
//		throw CardGameError((char *)"\nException - LinkedList::insertAt - Index Out of Bounds\n");
//	else
//	{
//		if(x == 0)
//			return insertAtHead(data);
//		else if(x == size)
//			return insertAtTail(data);
//		Node * temp = head;
//		for(int i = 0; i < x - 1; i++)
//			temp = temp->getNext();
//		Node * newNode = new Node(data, temp->getNext());
//		temp->setNext(newNode);
//	}
//	size++;
//}
//
//Card * LinkedList::remove(Card * data)
//{
//	int position = search(data);
//	if(size == 0)
//		throw CardGameError((char *)"\nException - LinkedList::Remove - EmptyList\n");
//	else if(position == -1)
//		throw CardGameError((char *)"\nException - LinkedList::Remove - Non Existing Card\n");
//	return removeAt(position);
//}
//
//Card * LinkedList::removeAt(int x)
//{
//	if(size == 0)
//		throw CardGameError((char *)"\nException - LinkedList::RemoveAt - EmptyList\n");
//	else if(x < 0 || x >= size )
//		throw CardGameError((char *)"\nException - LinkedList::RemoveAt - Invalid Index\n");
//	if(x == 0)
//		return removeAtHead();
//	else if( x == size - 1)
//		return removeAtTail();
//	else
//	{
//		int i = 0;
//		Node * trav = head;
//		while(i < x - 1)
//		{
//			trav = trav->getNext();
//			i++;
//		}
//		Card * r =  trav->getNext()->getData();//new Card(trav->getNext()->getData()->getValue(), trav->getNext()->getData()->getSuit(), trav->getNext()->getData()->getRank());
//		Node * toDelete = trav->getNext();
//		trav->setNext(trav->getNext()->getNext());
//		delete toDelete;
//		size --;
//		return r;
//	}
//
//}
//
//int LinkedList::search(Card * data)
//{
//	if (size == 0)
//		return -1;
//	Node * trav = head;
//	for(int i = 0; i < size; i++)
//		if(trav->getData()->compareRank(*data) == 0 &&
//				trav->getData()->compareSuit(*data) == 0 &&
//				trav->getData()->compareValue(*data) == 0)
//			return i;
//		else
//			trav = trav->getNext();
//	return -1;
//}
//
//void LinkedList::insertAtHead(Card * data)
//{
//	Node * newNode = new Node(data, NULL);
//	if (size == 0)
//	{
//		head = tail = newNode;
//	}
//	else
//	{
//		newNode->setNext(head);
//		head = newNode;
//	}
//	size++;
//
//}
//
//void LinkedList::insertAtTail(Card * data)
//{
//	Node * newNode = new Node(data, NULL);
//	if (size == 0)
//	{
//		head = tail = newNode;
//	}
//	else
//	{
//		tail->setNext(newNode);
//		tail = newNode;
//	}
//	size++;
//
//}
//
//Card * LinkedList::removeAtTail()
//{
//	Card * result = tail->getData();//new Card(tail->getData()->getValue(), tail->getData()->getSuit(), tail->getData()->getRank());
//	Node * newTail = head;
//	while(newTail->getNext() != tail)
//		newTail = newTail->getNext();
//	delete tail;
//	size--;
//	tail = newTail;
//	return result;
//
//}
//
//Card * LinkedList::removeAtHead()
//{
//	Card * result = head->getData();//new Card(head->getData()->getValue(), head->getData()->getSuit(), head->getData()->getRank());
//	Node * copyHead = head;
//	head = head->getNext();
//	delete(copyHead);
//	size--;
//	return result;
//
//}
//
//std::string LinkedList::display()const
//{
//	std::string result;
//	Node * trav = head;
//	//std::cout << "size: " << size;
//	for(int i = 0; i < size; i++)
//	{
//		result +=  (trav->getData())->output();
//		//if(trav->getNext() != NULL)
//		trav = trav->getNext();
//		//std::cout << trav->getData()->output();
//	}
//	return result;
//}
//
//std::ostream& operator << (std::ostream& out, const LinkedList& b)
//{
//	std::string result;
//	Node * trav = b.head;
//	//std::cout << "size: " << size;
//	for(int i = 0; i < b.size; i++)
//	{
//		out <<  (trav->getData())->output();
//		//if(trav->getNext() != NULL)
//		trav = trav->getNext();
//		//std::cout << trav->getData()->output();
//	}
//	return out;
//}
//
////Card * LinkedList::operator [] (int index) //this is the l value operator array[0] = 90; default: works for right side
////{
////	return const_cast<Card *>((static_cast<const LinkedList*>(this))->operator [] (index));
////}
//
//Card& LinkedList::operator [] (int index)
//{
//	if(index < 0 || index >= size)
//	{
//		std::cout << "Error: Index Out Of Bounds";
//		exit(1);
//	}
//	Node * temp = head;
//	for (int i = 0; i < index; i++)
//		temp = temp->getNext();
//	return *(temp->getData());
//}
//
//bool LinkedList::isEmpty()
//{
//	return size == 0;
//}
//
//LinkedList::~LinkedList()
//{
//
//	//std::cout << "Entered destructor";
//	if (head != NULL)
//	{
//		Node * trav = head;
//		for(int i = 0; i < size; i++)
//		{
//			if(head->getNext() != NULL)
//				head = head->getNext();
//			if(trav != NULL)
//				delete trav;
//			trav = head;
//		}
//	}
//	//std::cout << "left destructor";
//}
//LinkedList& LinkedList::operator = (const LinkedList& x)
//{
//	if ( &x != this)
//	{
//		if(size != 0)
//		{
//			Node * temp = head;
//			for(int i = 0; i < size; i++)
//			{
//				head = head->getNext();
//				delete temp;
//				//temp->data-> = NULL;
//				temp = head;
//			}
//		}
//		size = 0;
//		Node * trav = x.head;
//		for (int i = 0; i < x.size; i++)
//		{
//			insert(new Card(trav->getData()->getValue(), trav->getData()->getSuit(), trav->getData()->getRank()));
//			trav = trav->getNext();
//			//array = new int[size];
//		}
//
//	}
//	return *this;
//}
//LinkedList::LinkedList(const LinkedList& x) : head(NULL), tail(NULL), size(0)
//{
//	Node * trav = x.head;
//	for (int i = 0; i < x.size; i++)
//	{
//		insert(new Card(trav->getData()->getValue(), trav->getData()->getSuit(), trav->getData()->getRank()));
//		trav = trav->getNext();
//	}
//
//}
//
//void LinkedList::clear()
//{
//	for(int i = 0; i < size; i++)
//		removeAt(i);
//	size = 0;
//	head = tail = NULL;
//}
