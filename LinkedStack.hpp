/*
 * LinkedStack.hpp
 *
 *  Created on: Apr 15, 2023
 *      Author: ethan
 */

#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_

#include "Stack.hpp"
//#include <iostream>
//using namespace std;

template <typename T>
class LinkedStack : public Stack<T> {
protected:
	struct Node {
		T value;
		Node* next;
		Node* prev;
        Node(const T& v) : value(v), next(nullptr), prev(nullptr) {}
	};
	Node *head, *last;
private:
	void copy(const LinkedStack<T>&);				//O(n)
public:
	LinkedStack();									//O(1)
	LinkedStack(const LinkedStack<T>&);				//O(n)
	~LinkedStack();									//O(1)
	virtual int getLength() const override;			//O(1)
	virtual bool isEmpty() const override;			//O(1)
	virtual T peek() const override;				//O(1)
	virtual void pop() override;					//O(1)
	virtual void push(const T&) override;			//O(1)
	virtual void rotate(typename Stack<T>::Direction) override;//O(1)
	virtual void clear() override; 					//O(n)
	LinkedStack<T>& operator=(const LinkedStack<T>&);//O(n)
    template <typename U>
    friend ostream& operator<<(ostream&, const LinkedStack<U>&);
};

#include "LinkedStack.tpp"
#endif /* LINKEDSTACK_HPP_ */
