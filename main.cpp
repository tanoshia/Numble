/*
 * main.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: ethan
 */

/*
 * Elements:
 * main: function calls
 * class 1: rng
 * class 2:
 *
 *
 * Order:
 * int result;
 * rng numDigits
 * for (int i = 0; i < numDigits-1; i++) {
 * 		rng digit
 * 		rng operator
 * }
 * rng digit
 *
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "GenerateEquation.hpp"
#include "DoublyList.hpp"

using namespace std;


int main() {
	cout << "Hello World!\n";

	srand(time(0));

	GenerateEquation<char> game1;
	DoublyList<string> eI;
	int eqSz = 4;
	eI.append("1");
	eI.append("*");
	eI.append("2");
	eI.append("+");
	eI.append("3");
	eI.append("-");
	eI.append("4");


	try { cout << eI.getElement(4) <<"\n\n"; }
		catch (const string& e) { cout << e; }

	string s = "";
	string delimiter = " ";
	for (int i = 0; i<7 ; i++) {	// 7
		s.append(eI.getElement(i));
		s.append(delimiter);
		cout << "s: " << i << ", " << eI.getElement(i) <<"\n";
	}
	//s.replace(2*eqSz,1,"."); //sets last character to "." instead of the last delimiter (which had no RHS digit)
	cout << s;
	cout << "fin";



//Notes:
		// eqMaxSize = 6, eqSize, digit sets and operator sets can change
//Outline of pseudocode:
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

	linked stack postfixParse function (=result)
	display UI
	attempt equation
	calculate attemptResult
		infix queue to postfix stack
		postfixParse calculate attemptResult
	win? lose?
*/
// Functions:
	//F infix to postfix
	//F postfix to infix


	//terminate
	return 0;
}











