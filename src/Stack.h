/**********************************************************
 * template class stack.h
 **********************************************************
 *  Created on: Oct 18, 2017
 *      Author: Vagner Machado
 **********************************************************
 *  Description: This class contains the code to instantiate
 *  stacks from any data type since this is a template class.
 *  The instantiated Stack allows the user to pop, push and
 *  peek items in the stack. Items can also be displayed.
 *  *******************************************************
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <string>
#include <sstream>
#include "CardGameError.h"
#include <cstdlib>

template <class C>
class Stack
{
private:
	int size;
	C ** stack ;
	int capacity;
	bool isEmpty();
	bool isFull();

public:
	Stack();
	Stack(int x);
	int getSize() const;
	void setSize(int);
	void setCapacity(int);
	int getCapacity() const;
	bool push(C * c);
	C *  pop();
	C * peek();
	std::string output()const;
	C * operator [] (int index);
	~Stack();
	Stack<C>& operator =(Stack<C>& other);
	Stack(Stack<C>& other);
};

/**
 * default constructor - initialized an array with 52 places for C items
 */
template <class C>
Stack<C>::Stack() : size(0), capacity(52)
{
	stack = new C * [capacity];
}

/**
 * parameterized Stack constructor - initializes the capacity to the parameter passed by the user,
 * and initialized an array with that capacity
 * @param x - the capacity for the stack
 */
template <class C>
Stack<C>::Stack(int x) : size(0), capacity(x)
{
	stack = new C * [capacity];
}

/**
 * peek - allows the user to see the item on top of the stack
 * @return C - the item on top of the stack
 */
template <class C>
C * Stack<C>::peek()
{
	if(isEmpty())
	{
		throw CardGameError((char *)"\nException - Stack::Peek - The Stack is Empty\n");
		//throw e;
	}
	else
		return stack[size-1];
}

/**
 * getSize - accessor for the size of the stack
 * @return size - the size of the stack
 */
template <class C>
int Stack<C>::getSize() const
{
	return size;
}

/**
 * setSize - mutator for the size of the stack
 * @param s - the size of the stack
 */
template <class C>
void Stack<C>::setSize(int s)
{
	size = s;
}

/**
 * setCapacity - mutator for the capacity of the stack
 * @param c - the capacity of the stack
 */
template <class C>
void Stack<C>::setCapacity(int c)
{
	capacity = c;
}

/**
 * getCapacity - accessor for the capacith of the stack
 * @return capacity - the capacity of the stack
 */
template <class C>
int Stack<C>::getCapacity() const
{
	return capacity;
}

/**
 * push - adds an item to the top of the stack if not full
 * @param c - the item to be added to the stack
 * @return true fi item was added, false otherwise
 */
template <class C>
bool Stack<C>::push(C * const c)
{
	if (isFull())
	{
		throw CardGameError((char *)"\nException - Stack::Push - The Stack is Full\n");
		//throw f;
		//return false;
	}
	else
	{
		(stack[size]) = c;
		size++;
	}
	return true;
}

/**
 * pop - removes and returns the item on top of the stack if not empty
 * @return C - the item on top of the stack
 */
template <class C>
C * Stack<C>::pop()
{
	if (isEmpty())
	{
		throw CardGameError((char *)"\nException - Stack::Pop - The Stack is Empty\n");
		//throw g;
	}
	size--;
	return (stack[size]);
}

/**
 * output - displays all the items in a readable format
 * @return ss - a string with all the items in the stack
 */
template <class C>
std::string Stack<C>::output()const
{
	std::stringstream ss;
	for (int i = size; i > 0 ; i--)
		ss << stack[i-1]->output();
	return ss.str();
}

/**
 * isEmpty - let's the user know if the stack is empty
 * @return true if empty, false otherwise
 */
template <class C>
bool Stack<C>::isEmpty()
{
	return size == 0;
}

/**
 * isFull - let's the user know if the stack is full
 * @return - true if full, false otherwise
 */
template <class C>
bool Stack<C>::isFull()
{
	return size == capacity;
}

/**
 * operator [] - accessor for an item int he stack
 * @param index - the location in the stack
 * @return C - the item at a valid index
 */
template<class C>
C* Stack<C>::operator [] (int index)
{
	if( index < 0 || index >= size)
	{
		std::cout << "Out of Bounds: Stack [] operator";
		exit(1);
	}
	else
		return stack[index];
}

/**
 * Stack destructor - deletes all dynamically allocated memory for the Stack
 */
template<class C>
Stack<C>::~Stack()
{
	if(stack != NULL)
	{
		for(int i = 0; i < size; i++)
			delete stack[i];
		delete [] stack;
		stack = NULL;
	}
}

/**
 * overload = operator - makes a deep copy of the parameter stack
 * and assigns all values to this stack case they are not the same stacks
 * @param other - the stack having the values assigned to this stack
 * @return a reference to this stack to allow for chaining
 */
template<class C>
Stack<C>& Stack<C>::operator = (Stack<C>& other)
{
	if(this != &other)
	{
		if(stack != NULL)
		{
			for(int i = 0; i < size; i++)
				delete stack[i];
			delete [] stack;
			stack = NULL;
		}
		size = other.size;
		capacity = other.capacity;
		stack = new C * [capacity];
			for(int i = 0; i < size; i++)
				stack[i] = new C(*other.stack[i]);


	}
	return *this;
}

/**
 * Stack copy constructor - makes a deep copy of values in other stack and
 * and assigns to this stack
 * @param other - the stack having its values copied into this ones
 */
template<class C>
Stack<C>::Stack(Stack& other) : size(other.size), capacity(other.capacity)
{
	stack = new C * [capacity];
	for(int i = 0; i < size; i++)
		stack[i] = new C(*other.stack[i]);
}

#endif /* STACK_H_ */
