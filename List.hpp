/*
 * List.hpp
 *
 *  Created on: Apr 5, 2023
 *      Author: ethan
 */

#ifndef LIST_HPP_
#define LIST_HPP_

template <typename T>
class List {
protected:
	int length;
public:
	List() : length(0) { }
	virtual ~List() { }
	virtual void append(const T&) = 0;
	virtual void clear() = 0;
	virtual T getElement(int) const = 0;
	virtual int getLength() const = 0;
	virtual void insert(int, const T&) = 0;
	virtual bool isEmpty() const = 0;
	virtual void remove(int) = 0;
	virtual void removeValue(const T&) = 0;
	virtual void replace(int, const T&) = 0;
};

#endif
