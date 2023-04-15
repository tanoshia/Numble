/*
 * DoublyList.tpp
 *
 *  Created on: Apr 5, 2023
 *      Author: ethan
 */

//#include "DoublyList.hpp"

//constructors
template <typename T> //TODONE O(1)
DoublyList<T>::DoublyList()
: header(nullptr), trailer(nullptr) { }

template <typename T> //TODONE O(n)
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj) {
	copy(copyObj);
}

template <typename T>
DoublyList<T>::~DoublyList() {
	delete header;
	delete trailer;
	header = nullptr;
	trailer = nullptr;
}

template <typename T> //TODONE O(n)
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
	clear();
	if (copyObj.length > 0) {
		this->length = copyObj.length;
		header = new Node(copyObj.header->value);
		trailer = new Node(copyObj.trailer->value);
		Node* myCurr = header;
		Node* copyCurr = copyObj.header;

		while (copyCurr != nullptr) {
			//append(copyCurr->value);
			Node* n = new Node(copyCurr->value);	//append function contents without length addition
			trailer->next = n;						//^
			n->prev = trailer;						//^
			trailer = n;							//^
			copyCurr = copyCurr->next;
		}
	}
	else {
		header = nullptr;
		trailer = nullptr;
	}
}

//getters
template <typename T> //TODONE O(n)
T DoublyList<T>::getElement(int position) const { //TODONE throw error on fail
	if (position < 0 || position >= this->length) {
		throw string("getElement: error, position out of bonds");
	}

	Node* curr;
	if (position > (this->length)/2) {
		curr = trailer;
		for (int i = this->length-1; i > position; i--) {
			curr = curr->prev; }
	}
	else {
		curr = header;
		for (int i = 0; i < position; i++) {
			curr = curr->next; }
	}
	return curr->value;
}

template <typename T> //TODONE O(1)
int DoublyList<T>::getLength() const {
	return this->length;
}

template <typename T> //TODONE O(1)
bool DoublyList<T>::isEmpty() const {
	//return header == trailer;
	return this->length == 0;
}


//"setters"
template <typename T> //TODONE O(1)
void DoublyList<T>::append(const T& elem) {
	Node* n = new Node(elem);
	if (isEmpty()) {
		header = n;
		trailer = n;
	}
	else {
		trailer->next = n;
		n->prev = trailer;
		trailer = n;
	}
	this->length++;
}

template <typename T> //TODONE O(n)
void DoublyList<T>::clear() {
	if (this->length == 0) {
		return;
	}
	else {
		Node* curr = header;
		Node* prev = curr;
		for (int i = 0; i < this->length; i++) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}
	header = nullptr;
	trailer = nullptr;
	this->length = 0;
}

template <typename T> //TODONE O(n)
void DoublyList<T>::insert(int position, const T& elem) { //TODONE throw error on fail
	if (position < 0 || position < this->length) {
		throw string("insert: error, position out of bonds");
	}
	//TODONE optimized search direction
	Node* curr = header;
	if (position > (this->length)/2) {
		curr = trailer;
		for (int i = 0; i < position; i++) {
			curr = curr->prev; }
	}
	else {
		curr = header;
		for (int i = 0; i < position; i++) {
			curr = curr->next; }
	}

	Node* n = new Node(elem);

	n->next = curr->next;
	n->prev = curr->prev;
	curr->prev->next = n;
	curr->prev = n;

	this->length++;
}

template <typename T> //TODO O(n)
void DoublyList<T>::remove(int position) { //TODONE throw error on fail
	//remove one element at position
	if (position < 0 || position < this->length) {
		throw string("remove: error, position out of bonds");
	}

	//TODONE optimized search direction
	Node* curr = header;
	if (position > (this->length)/2) {
		curr = trailer;
		for (int i = 0; i < position; i++) {
			curr = curr->prev; }
	}
	else {
		curr = header;
		for (int i = 0; i < position; i++) {
			curr = curr->next; }
	}

	//dereference curr(linked list at "position") then set to nullptr
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	curr = nullptr;
	this->length--;
}

template <typename T> //TODO O(n)
void DoublyList<T>::removeValue(const T& elem) { //TODO throw error on fail
	Node* curr = header;
	int numRemoves = 0;
	for (int i = 0; i < this->length; i++) {
		curr = curr->next;
		if (curr->value == elem) {
			//dereference curr(linked list at "position") then set to nullptr
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr = nullptr;
			this->length--;
			numRemoves++;
		}

	}
	if (numRemoves == 0) {
		throw string("removeValue: error, no values to remove matching the entered value");
	}
}

template <typename T> //TODO O(n)
void DoublyList<T>::replace(int position, const T& elem) { //TODONE throw error on fail
	if (position < 0 || position < this->length) {
		throw string("replace: error, position out of bonds");
	}

	//TODONE optimized search direction
	Node* curr = header;
	if (position > (this->length)/2) {
		curr = trailer;
		for (int i = 0; i < position; i++) {
			curr = curr->prev; }
	}
	else{
		curr = header;
		for (int i = 0; i < position; i++) {
			curr = curr->next; }
	}

	curr->value = elem;
}

template <typename T> //TODO O(n)
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
	if (this != &rightObj) {
		clear();
		copy(rightObj);
	}
	return *this;
}

