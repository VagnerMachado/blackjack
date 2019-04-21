/**************************************************************************
 * template class LinkedList.h
 **************************************************************************
 *  Created on: Nov 8, 2017
 *      Author: Vagner Machado
 **************************************************************************
 *  Description: This is a template class that allows the user to create a
 *  generic linked list of any type. The public functions allows the user
 *  to insert, remove, search and print the contents of the linked list
 *  amongst other functionalities.
 *  The prototypes and the implementation are contained in the same file
 *  due to the class being a template
 **************************************************************************
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
//#include "Card.h"
#include <string>
#include "Node.h"
#include "CardGameError.h"
#include <cstdlib>
#include <iostream>

template<class T>
class LinkedList
{

private:
	Node * head;
	Node * tail;
	int size;
	void insertAtHead(T * data);
	void insertAtTail(T * data);
	T * removeAtTail();
	T * removeAtHead();
	bool isEmpty();
public:
	LinkedList();
	int getSize();
	std::string display()const ;
	void insert(T * data);
	void insertAt(int x, T * data);
	T * remove(T * data);
	T * removeAt(int x);
	int search(T * data);
	template <class V> friend std::ostream& operator << (std::ostream& out, const LinkedList<T>& b);
	T& operator [] (int index);
	~LinkedList();
	LinkedList<T>& operator = (const LinkedList<T>& x);
	LinkedList(const LinkedList<T>& other);
	void clear();

};

/**
 * LinkedList default constructor - creates a linked list of size zero
 * and head and tail nodes Null
 */
template<class T>
LinkedList<T>::LinkedList() : head(NULL), tail(NULL), size(0)
{

}

/**+
 * getSize - accessor for the sze of the linked list
 * @return size - the size of the linked list
 */
template<class T>
int LinkedList<T>::getSize()
{
	return size;
}

/**
 * insert - inserts an item into the linked list
 * @param data - the item to be inserted in tot he hand
 */
template<class T>
void LinkedList<T>::insert(T * data)
{
	Node * t = new Node(data, NULL);
	if (size == 0)
	{
		head = tail = t;
	}
	else
	{
		tail->setNext(t);
		tail = t;
	}
	size++;
}

/**
 * insertAt - inserts an item at the valid position, exception is thrown if index is invalid
 * @param x - the index
 * @param data - the item to be inserted
 */
template<class T>
void LinkedList<T>::insertAt(int x, T * data)
{
	if (x < 0 || x > size)
		throw CardGameError((char *)"\nException - LinkedList::insertAt - Index Out of Bounds\n");
	else
	{
		if(x == 0)
			return insertAtHead(data);
		else if(x == size)
			return insertAtTail(data);
		Node * temp = head;
		for(int i = 0; i < x - 1; i++)
			temp = temp->getNext();
		Node * newNode = new Node(data, temp->getNext());
		temp->setNext(newNode);
	}
	size++;
}

/**
 * remove - removes a specific item from the linked list
 * @param data - the item to be removed
 * @return - the item removed
 */
template<class T>
T * LinkedList<T>::remove(T * data)
{
	int position = search(data);
	if(size == 0)
		throw CardGameError((char *)"\nException - LinkedList::Remove - EmptyList\n");
	else if(position == -1)
		throw CardGameError((char *)"\nException - LinkedList::Remove - Non Existing Item\n");
	return removeAt(position);
}

/**
 * removeAt - removes the item at the index if it is a valid one
 * @param x - the index
 * @return - the item on that index
 */
template<class T>
T * LinkedList<T>::removeAt(int x)
{
	if(size == 0)
		throw CardGameError((char *)"\nException - LinkedList::RemoveAt - EmptyList\n");
	else if(x < 0 || x >= size )
		throw CardGameError((char *)"\nException - LinkedList::RemoveAt - Invalid Index\n");
	if(x == 0)
		return removeAtHead();
	else if( x == size - 1)
		return removeAtTail();
	else
	{
		int i = 0;
		Node * trav = head;
		while(i < x - 1)
		{
			trav = trav->getNext();
			i++;
		}
		T * r =  trav->getNext()->getData();//new Card(trav->getNext()->getData()->getValue(), trav->getNext()->getData()->getSuit(), trav->getNext()->getData()->getRank());
		Node * toDelete = trav->getNext();
		trav->setNext(trav->getNext()->getNext());
		delete toDelete;
		size --;
		return r;
	}
}

/**
 * search -  looks for a specific item in the list
 * @param data - the item being searched for
 * @return - the index where the item is located, -1 otherwise
 */
template<class T>
int LinkedList<T>::search(T * data)
{
	if (size == 0)
		return -1;
	Node * trav = head;
	for(int i = 0; i < size; i++)
		if(trav->getData()->compareRank(*data) == 0 &&
				trav->getData()->compareSuit(*data) == 0 &&
				trav->getData()->compareValue(*data) == 0)
			return i;
		else
			trav = trav->getNext();
	return -1;
}

/**
 * insertAtHead - inserts an item on the from end of the linked list
 * @param data - the data to be inserted into the list
 */
template<class T>
void LinkedList<T>::insertAtHead(T * data)
{
	Node * newNode = new Node(data, NULL);
	if (size == 0)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->setNext(head);
		head = newNode;
	}
	size++;

}

/**
 * insertAtTail - inserts an item on the end of the linked list
 * @param data - the data to be inserted into the linked list
 */
template<class T>
void LinkedList<T>::insertAtTail(T * data)
{
	Node * newNode = new Node(data, NULL);
	if (size == 0)
	{
		head = tail = newNode;
	}
	else
	{
		tail->setNext(newNode);
		tail = newNode;
	}
	size++;

}

/**
 * removeAtTail - removes the last item in the linked list
 * @return - the item on the end of the linked list
 */
template<class T>
T * LinkedList<T>::removeAtTail()
{
	T * result = tail->getData();//new Card(tail->getData()->getValue(), tail->getData()->getSuit(), tail->getData()->getRank());
	Node * newTail = head;
	while(newTail->getNext() != tail)
		newTail = newTail->getNext();
	delete tail;
	size--;
	tail = newTail;
	return result;

}

/**
 * removeAtHead - removes the item on the beginning of the linked list
 * @return - the item on the beginning of the linked list
 */
template<class T>
T * LinkedList<T>::removeAtHead()
{
	T * result = head->getData();//new Card(head->getData()->getValue(), head->getData()->getSuit(), head->getData()->getRank());
	Node * copyHead = head;
	head = head->getNext();
	delete(copyHead);
	size--;
	return result;

}

/**
 * display - makes a string with all items in the linked list
 * @return - a string with all the items in the linked list
 */
template<class T>
std::string LinkedList<T>::display()const
{
	std::string result;
	Node * trav = head;
	//std::cout << "size: " << size;
	for(int i = 0; i < size; i++)
	{
		result +=  (trav->getData())->output();
		//if(trav->getNext() != NULL)
		trav = trav->getNext();
		//std::cout << trav->getData()->output();
	}
	return result;
}

/**
 * overload operator << - displays the contents of the linked list
 * @param out - a reference to a ostream
 * @param b - the linked list to be displayed
 * @return - a reference to this ostream
 */
template<class T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list)
{
	std::string result;
	Node * trav = list.head;
	//std::cout << "size: " << size;
	for(int i = 0; i < list.size; i++)
	{
		out <<  (trav->getData())->output();
		//if(trav->getNext() != NULL)
		trav = trav->getNext();
		//std::cout << trav->getData()->output();
	}
	return out;
}

/**
 * overload [] operator - goves access to an item at a specific index, if valid
 * @param index - the index where item is located
 * @return
 */
template<class T>
T& LinkedList<T>::operator [] (int index)
{
	if(index < 0 || index >= size)
	{
		std::cout << "Error: Index Out Of Bounds";
		exit(1);
	}
	Node * temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->getNext();
	return *(temp->getData());
}

/**
 * isEmpty - used to check if a linked list is empty
 * @return true if it is empty, false otherwise
 */
template<class T>
bool LinkedList<T>::isEmpty()
{
	return size == 0;
}

/**
 * LinkedList destructor - deallocates all the memory allocated for the linked list
 */
template<class T>
LinkedList<T>::~LinkedList()
{
	//std::cout << "Entered destructor";
	if (head != NULL)
	{
		Node * trav = head;
		for(int i = 0; i < size; i++)
		{
			if(head->getNext() != NULL)
				head = head->getNext();
			if(trav != NULL)
				delete trav;
			trav = head;
		}
	}
	//std::cout << "left destructor";
}
/**
 * operator = overload - allows the userto make a deep copy of a linked list and
 * assign to another one.
 * @param x - the linked list being copied to this one
 * @return - a reference to this linked list
 */
template<class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& x)
{
	if ( &x != this)
	{
		if(size != 0)
		{
			Node * temp = head;
			for(int i = 0; i < size; i++)
			{
				head = head->getNext();
				delete temp;
				//temp->data-> = NULL;
				temp = head;
			}
		}
		size = 0;
		Node * trav = x.head;
		for (int i = 0; i < x.size; i++)
		{
			//changes for template
			//insert(new Card(trav->getData()->getValue(), trav->getData()->getSuit(), trav->getData()->getRank()));
			insert(new T(*trav->getData()));
			trav = trav->getNext();
			//array = new int[size];
		}
	}
	return *this;
}

/**
 * LinkedList copy constructor - allows the user to instantiate a a linked list with
 * a deep copy of the values from other linked list
 * @param x - the linked list used to copy values into the instantiation of this linked list
 */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : head(NULL), tail(NULL), size(0)
{
	Node * trav = list.head;
	for (int i = 0; i < list.size; i++)
	{
		//changes for template
		//insert(new Card(trav->getData()->getValue(), trav->getData()->getSuit(), trav->getData()->getRank()));
		insert(new T(*trav->getData()));//->getValue(), trav->getData()->getSuit(), trav->getData()->getRank()));

		trav = trav->getNext();
	}
}

/**
 * clear - removes all items from this linked list and and restarts its variables
 */
template<class T>
void LinkedList<T>::clear()
{
	for(int i = 0; i < size; i++)
		removeAt(i);
	size = 0;
	head = tail = NULL;
}


#endif /* LINKEDLIST_H_ */
