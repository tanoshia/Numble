/*
 * LinkedStack.tpp
 *
 *  Created on: Apr 15, 2023
 *      Author: ethan
 */

template <typename T>
LinkedStack<T>::LinkedStack()
: head(nullptr), last (nullptr)
{ }

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& copyObj) {
	copy(copyObj);
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
	clear();
}

template <typename T>
void LinkedStack<T>::copy(const LinkedStack<T>& copyObj) {
    this->length = copyObj.length;
    head = nullptr;
    last = nullptr;

    if (this->length > 0) {
        head = new Node(copyObj.head->value);
        Node* myCurr = head;
        Node* copyCurr = copyObj.head->next;

        while (copyCurr != nullptr) {
            Node* n = new Node(copyCurr->value);
            n->prev = myCurr;
            myCurr->next = n;
            myCurr = n;
            copyCurr = copyCurr->next;
        }
        last = myCurr;
    }
}

template <typename T>
int LinkedStack<T>::getLength() const {
	return this->length;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const {
	return this->length == 0;
}

template <typename T>
T LinkedStack<T>::peek() const {
	if (isEmpty()) { throw string("peek error: stack empty"); }
	return last->value;
}

template <typename T>
void LinkedStack<T>::pop() {
	if (isEmpty()) { throw string("pop error: stack empty"); }
	if (last == head) {
		delete last;
		head = last = nullptr;
	}
	else {
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
	this->length--;
}

template <typename T>
void LinkedStack<T>::push(const T& elem) {
	Node* n = new Node(elem);
	if (isEmpty()) {
		head = last = n;
	}
	else {
		n->prev = last;
		last->next = n;
		last = n;
	}
	this->length++;
}

template <typename T>
void LinkedStack<T>::rotate(typename Stack<T>::Direction dir) {
	if (isEmpty()) { throw string("rotate error: stack empty"); }
	else if (dir == Stack<T>::RIGHT) {
		Node* newHead = head->next;
		newHead->prev = nullptr;
		head->next = nullptr;
		last->next = head;
		head->prev = last;
		last = head;
		head = newHead;
	}
	else if (dir == Stack<T>::LEFT) {
	   Node* newTail = last->prev;
	   newTail->next = nullptr;
	   last->prev = nullptr;
	   head->prev = last;
	   last->next = head;
	   head = last;
	   last= newTail;
	}
	else { throw string("rotate error: unknown direction"); }
}

template <typename T>
void LinkedStack<T>::clear() {
	while (head != nullptr) {
		Node* prev = head;
		head = head->next;
		delete prev;
	}
	last = nullptr;
	this->length = 0;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rightObj){
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedStack<T>& myObj) {
    if (myObj.isEmpty()) { outStream << "List is empty, no elements to display.\n"; }
    else {
        typename LinkedStack<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }
    return outStream;
}
