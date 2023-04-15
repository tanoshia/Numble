/*
 * DoublyList.hpp
 *
 *  Created on: Apr 5, 2023
 *      Author: ethan
 */

#ifndef DOUBLYLIST_HPP_
#define DOUBLYLIST_HPP_

#include "List.hpp"
#include <iostream>

using namespace std;

template <typename T>
class DoublyList : public List<T> {
protected:
	struct Node {
		T value;
		Node* next;
		Node* prev;

		Node(T v = T(), Node* nNext = nullptr, Node* nPrev = nullptr)
		: value(v), next(nNext), prev(nPrev) {}
	};

	Node* header;
	Node* trailer;

private:
	void copy(const DoublyList<T>&);

public:
	//constructors
	DoublyList();
	DoublyList(const DoublyList<T>&);
	virtual ~DoublyList();

	//getters
	virtual T getElement(int) const override;
	virtual int getLength() const override;
	virtual bool isEmpty() const override;

	//"setters"
	virtual void append(const T&) override;
	virtual void clear() override;
	virtual void insert(int, const T&) override;
	virtual void remove(int) override;
	virtual void removeValue(const T&) override;
	virtual void replace(int, const T&) override;

	DoublyList<T>& operator=(const DoublyList<T>&);

};

#include "DoublyList.tpp"
#endif /* DOUBLYLIST_HPP_ */
