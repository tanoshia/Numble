/*
 * GenerateEquation.hpp
 *
 *  Created on: Apr 10, 2023
 *      Author: ethan
 */

#ifndef GENERATEEQUATION_HPP_
#define GENERATEEQUATION_HPP_

#include <string>
#include "DoublyList.hpp"
#include "LinkedStack.hpp"

using namespace std;

template <typename T>
class GenerateEquation {
protected:
    int numNiceDigitsSmall = 8;
    int numNiceDigitsLarge = 4;
    char numNiceOperators = 3;
	vector<int> niceDigitsTiny;		// = {1,2};
	vector <int> niceDigitsSmall;	// = {3,4,5,6,7,8,9,10};
	vector <int> niceDigitsLarge;	// = {25,75,50,100};
	vector <string> niceOperators;	// = {*,+,-};

	int eqMaxSize = 6;			//shown digits on UI, possible for equation, default value 6
	int eqSize = 3+rand()%(2);	//numbers used in equation construction, default range 3-6
	DoublyList<T> possibleEqDigits;
	DoublyList<T> eqInfix;		//TODO maybe use queue for final requirements, if easier
	LinkedStack<T> eqPostfix;
	int result = 0;
private:
	void randomizeVector();
	int rngDigit(vector<int>);
	string rngOperator(vector<string>);
public:
	GenerateEquation();
	virtual ~GenerateEquation();

	//getter
	int getEqMaxSize();
	int getEqSize();
	string getEqInfix();
	string getEqPostfix();
	int getResult();
	DoublyList<T> toInfix(LinkedStack<T>);
	LinkedStack<T> toPostfix(DoublyList<T>);

	//setter
	void setEqMaxSize(int);
	void setEqSize(int);
	void buildEq(); //default values t:1,s:2-3,l:2-3,o:2-5
	void buildEq(int, int, int, int);
	void setResult(int);

};

#include "GenerateEquation.tpp"
#endif /* GENERATEEQUATION_HPP_ */
