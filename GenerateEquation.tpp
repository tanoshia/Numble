/*
 * generate.cpp
 *
 *  Created on: Apr 10, 2023
 *      Author: ethan
 */

#include <cstdlib>
#include <ctime>
//#include "GenerateEquation.hpp"


template <typename T>
GenerateEquation<T>::GenerateEquation() {
    //int randomNumber = min + rand() % (max - min + 1);
	//int min = 3; int max = 6; eqSize = min + rand() % (max - min + 1);
	//eqMaxSize = value 6 in header
	//eqSize = random 3-6 in header
    niceDigitsTiny = {1,2};
    niceDigitsSmall = {3,4,5,6,7,8,9,10};
    niceDigitsLarge = {25,50,75,100};
    niceOperators = {"*","+","-"};
}

template <typename T>
GenerateEquation<T>::~GenerateEquation() {
}

//getter
template <typename T>
int GenerateEquation<T>::getEqMaxSize() {
	return eqMaxSize;
}

template <typename T>
int GenerateEquation<T>::getEqSize() {
	return eqSize;
}

template <typename T>
string GenerateEquation<T>::getEqInfix() {
	string s = "";
	string delimiter = " ";
	//build string of eqInfix (with delimiter because multi-character numbers are legal)
	for (int i = 0; !(eqInfix[i]->next == nullptr); i++) {	//eqSize is num of digits for equation, thus num elements in this is
		s.append(eqInfix.getElement(i));
		s.append(delimiter);
	}
	s.replace(eqSize,1,"."); //sets last character to "." instead of the last delimiter (which had no RHS digit)
	return s;
}

template <typename T>
string GenerateEquation<T>::getEqPostfix() {
	string s = "";
	string delimiter = " ";
	//build string of eqPostfix (with delimiter because multi-character numbers are legal)
	for (int i = 0; i < (2*eqSize)-1; i++) {	//eqSize is num of digits for equation, thus num elements in this is #digits + # operators (which is always digits -1 ?)
		s.append(eqPostfix.getElement(i));
		s.append(delimiter);
	}
	s.replace(eqSize,1,"."); //sets last character to "." instead of the last delimiter (which had no RHS digit)
	return s;
}

template <typename T>
int GenerateEquation<T>::getResult() {
	return numNiceDigitsSmall;
}


//setter
template <typename T>
void GenerateEquation<T>::setEqMaxSize(int i) {
	eqMaxSize = i;
}

template <typename T>
void GenerateEquation<T>::setEqSize(int i) {
	eqSize = i;
}

template <typename T>
int GenerateEquation<T>::rngDigit(vector<int> digitList) {
//void GenerateEquation<T>::rngDigit(int numTiny, int numSmall, int numLarge) {
	//int randomNumber = min + rand() % (max - min + 1);
	return digitList[1 + rand() % (digitList.size() - 1 + 1)];

	/* 001Blockout
	//builds eq (doublyStack) of numbers)
	for (int i = 0; i < numTiny; i++) {
		d = 1 + rand() % (2); //min + rand() % (max - min + 1);
		eq.append(d);
	}
	for (int i = 0; i < numSmall; i++) {
		d = niceDigitsSmall[rand() % numNiceDigitsSmall];
		eq.append(d);
	}
	for (int i = 0; i < numLarge; i++) {
		d = niceDigitsLarge[rand() % numNiceDigitsLarge];
		eq.append(d);
	}
	*/

}

template <typename T>
string GenerateEquation<T>::rngOperator(vector<string> operatorList) {
	//char op = '';
	/* 001Blockout

	for (int i = 0; i < eq.getLength()-1; i++) {
		op = niceDigitsLarge[rand() % numNiceDigitsLarge];
		eq.append(op);
	}
	*/

}

template <typename T>
void GenerateEquation<T>::randomizeVector() {
	T temp;
	int r = 0 + rand() % (this->DoublyList<T>::getLength() - 0 + 1);	//random num size of this
	for (int i = 0; i < this->DoublyList<T>::getLength(); i++) {		//randomize the order of this for every element
		temp = this[i];
		this[i] = this[r];
		this[r] = temp;
	}
}

template <typename T>
//default eq build, tiny:1, small:2-3, large:2-3, operators:2-5
void GenerateEquation<T>::buildEq() {
	//for eqSize
		//eq.append(rngDigit())
		//rngOperator

	//rng pick 1-4
	//rng append all digits and operators to temp list
	//set eq digit
	//set eq digit
	//switch statement to pick a random digit or operator
	//set eq operator


////////////////////////////
	//set eq 1,2-3,2-3 to possibleEqDigits (which will be the set to display on UI, 3-6 are used but all displayed)
	//randomize() order
	//use eqSize to: (random 3-6 by default)
	//insert operators every other (infix) (into eqInfix which holds only the digits and operators for equation solution)
	//assign eqPostfix by converting eqInfix with outer function

	int rngNumDigitsSmall = 2 + rand() % (3 - 2 + 1);
	for (int i = 0; i < 1; i++) {					//add 1 digit 1-2
		possibleEqDigits.append(to_string(rngDigit(niceDigitsTiny)));
	}
	for (int i = 0; i < rngNumDigitsSmall; i++) {	//add 2-3 digits 3-10 (2-3 determined by rngNumDigitsSmall)
		possibleEqDigits.append(to_string(rngDigit(niceDigitsSmall)));
	}
	for (int i = 0; i < (5-rngNumDigitsSmall); i++) {//add 2-3 digits 3-10 (2-3 determined by negation of above)
		possibleEqDigits.append(to_string(rngDigit(niceDigitsLarge)));
	}
	//possibleEqDigits EX: "1"-->"4"-->"9"-->"7"-->"75"-->"25"
	possibleEqDigits.randomizeVector();
	//possibleEqDigits EX: "25"-->"1"-->"9"-->"75"-->"4"-->"7"

	//TODO? set max size ?

	//possibleEq to eqInfix by adding operators between numbers x times then discarding remaining numbers;
	for (int i = 0; i < eqSize-1; i++) {	//insert between each number, for infix notation //eqSize-1 is number of operators
		eqInfix.append(possibleEqDigits[i]);
		eqInfix.append(rngOperator(niceOperators));
	}
	eqInfix.append(possibleEqDigits[eqSize-1]); //inserts digit in last place as previous for loop ends on an operator
	//possibleEqDigits EX: "25"-->"1"-->"9"-->"75"-->"4"-->"7"
	//eqInfix EX: "25"-->"+"-->"1"-->"*"-->"9"-->"-"-->"75"
	eqPostfix = toPostfix(eqInfix); //from infix DoublyList to postfix DoublyStack


////////////////////////////
/*
	int rngNumDigitsSmall = 2 + rand() % (3 - 2 + 1);
	int rngNumOperators = 2 + rand() % (5 - 2 + 1);
	for (int i = 0; i < 1; i++) {					//add 1 digit 1-2
		tempEq.append(rngDigit(niceDigitsTiny));
	}
	for (int i = 0; i < rngNumDigitsSmall; i++) {	//add 2-3 digits 3-10 (2-3 determined by rngNumDigitsSmall)
		tempEq.append(rngDigit(niceDigitsSmall));
	}
	for (int i = 0; i < (5-rngNumDigitsSmall); i++) {//add 2-3 digits 3-10 (2-3 determined by negation of above)
		tempEq.append(rngDigit(niceDigitsLarge));
		//check for duplicates
//		for (int j = 0; j < 6 ; j++) {		//6 being max eqSize rn
//			while (tempEq[i] == tempEq[j]) {
//				tempEq.append(rngDigit(niceDigitsLarge)); } }
	}
	for (int i = 0; i < rngNumOperators-1; i++) {	//add 1-2 operators *,+,-	//-1 here so last one can add on last line, to insure last isn't a number
		tempEq.append(rngOperator(niceOperators));
	}
	//tempEq state example: 1,4,9,7,75,25,-,*,+

	eqSize = 6 + rngNumOperators;			//set class eqSize

	//sets eq slot 1 and 2 to a random digit from tempEq
	//guarentees no illegal postfix starter EX: 1*234+56-
	int r = 0 + rand() % (eqSize-rngNumOperators - 0 + 1);		//random num(as index) size of number portion of tempEq
	eq.append(tempEq[r]);
		tempEq.remove(r);
	eq.append(tempEq[r]);
		tempEq.remove(r);

	//sets eq slots to a random slot from tempEq
	r = 0 + rand() % (eqSize-3 - 0 + 1);	//random num size of eqSize
	for (int i =0; tempEq.isEmpty(); i++) {	//it over tempEq while not empty
		eq.append(tempEq[r]);				//move 1 slot from tempEq to eq
		tempEq.remove(r);					//remove moved slot from tempEq
	}
	eq.append(rngOperator(niceOperators));

	for (int i = 0; tempList.size() < 0; i++) {
		switch (6) { //rng 1-6
			case 0:
				eq.append(tempEq[0]);
				break;
			case 1:
				eq.append(tempEq[0]);
				break;
			case 2:
				eq.append(tempEq[0]);
				break;



							eq.append(rngDigit(niceDigitsSmall));
				break;
			case 4: // 50% chance to be small or large digit (0 or 1)
				if ((0 + rand() % (1 - 0 + 1)) == 0) {
					eq.append(rngDigit(niceDigitsSmall));
				}
				else
					eq.append(rngDigit(niceDigitsLarge));
				break;
			case 5:
			case 6:
				for (int i = 0; i < niceDigitsLarge; i++) {
					eq.append(rngDigit(niceDigitsLarge));
				}
				break;
			case 7:

			default:
				break;
		}
	}
	*/
/*
	make random eq - recursive
		rngNum()
		rngNum()
		for Loop size-3 ; rngNumOrOperator {
			if rngNumOrOperator() 0
				rngNum()
			else if rngNumOrOperator() 1
				rngOperator()
			}
		rngOperator()
*/

}

template <typename T> //WIP
void GenerateEquation<T>::buildEq(int numTiny, int numSmall, int numLarge, int numOperators) {

}

template <typename T>
void GenerateEquation<T>::setResult(int i) {
	result = i;
}

template <typename T>
DoublyList<T> GenerateEquation<T>::toInfix(LinkedStack<T> stack) {

}

template <typename T>
LinkedStack<T> GenerateEquation<T>::toPostfix(DoublyList<T> list) {

}
