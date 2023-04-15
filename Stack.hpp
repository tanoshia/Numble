/*
 * Stack.hpp
 *
 *  Created on: Apr 15, 2023
 *      Author: ethan
 */

#ifndef STACK_HPP_
#define STACK_HPP_

template <typename T>
class Stack {
public:
	enum Direction { RIGHT, LEFT};
protected:
	int length;
public:
	Stack() : length(0) { }
	virtual ~Stack() { }
	virtual void clear() = 0;
	virtual int getLength() const = 0;
	virtual bool isEmpty() const = 0;
	virtual T peek() const = 0;
	virtual void pop() = 0;
	virtual void push(const T&) = 0;
	virtual void rotate(Direction) = 0;
};

#endif
