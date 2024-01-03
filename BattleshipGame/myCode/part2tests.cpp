/*!
 * @file part2tests.cpp
 *
 * \n Created on: 05-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */
#include "tests.h"

using namespace std;

/*!
 * This function checks for all the conditions for task 2.2 Arrangement Rules.
 */
void part2tests ()
{
	auto myBoard =  make_shared<Board>(10,10);

	ConsoleView	myConsole(myBoard);

	OwnGrid& testCondition = myConsole.getBoard()->getOwnGrid();

	// cout << endl << "==================Part 2 tests started!!!!!!=================" << endl << endl;

	//! Test placeShip function.
	assertTrue(testCondition.placeShip(Ship{GridPosition("B2"), GridPosition("B4")}),
			"1st Ship of length 3 not placed Horizontally");
	assertTrue(testCondition.placeShip(Ship{GridPosition("D4"), GridPosition("G4")}),
			"1st Ship of length 4 not placed Vertically");
	assertTrue(testCondition.placeShip(Ship{GridPosition("F6"), GridPosition("F9")}),
			"2nd Ship of length 4 not placed Horizontally");

	// cout << endl << "Display 2.2.1 output!!!!" << endl << endl;
	// myConsole.print();

	//! Test placeShip on length, row & column validity, and ship in straight line.
	assertTrue(!testCondition.placeShip(Ship{GridPosition("D2"), GridPosition("D2")}),
			"Ship of length 1 placed");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("J3"), GridPosition("J8")}),
			"Ship of length 6 placed on the edge");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("K1"), GridPosition("K5")}),
			"Ship of length 5 placed in invalid grid row");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("$-1"), GridPosition("A0")}),
			"Ship placed with invalid row and columns");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("C7"), GridPosition("D9")}),
			"Ship is not placed straight");

	//! Test placeShip for Ship length 2. No of Ships to place - 4.
	assertTrue(testCondition.placeShip(Ship{GridPosition("C9"), GridPosition("C10")}),
			"Ship of length 2 not placed Horizontally");
	assertTrue(testCondition.placeShip(Ship{GridPosition("J3"), GridPosition("J4")}),
			"Ship of length 2 not placed Horizontally");
	assertTrue(testCondition.placeShip(Ship{GridPosition("C6"), GridPosition("D6")}),
			"Ship of length 2 not placed Vertically");
	assertTrue(testCondition.placeShip(Ship{GridPosition("I7"), GridPosition("J7")}),
			"Ship of length 2 not placed Vertically");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("E10"), GridPosition("F10")}),
			"5th Ship of length 2 placed in blocked area");

	//! Test placeShip for Ship length 3, No of Ships to place - 3.
	//! One of them is already placed in B2-B4.
	assertTrue(!testCondition.placeShip(Ship{GridPosition("A2"), GridPosition("A4")}),
			"Ship of length 3 placed in blocked area");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("G1"), GridPosition("I3")}),
			"Ship of length 3 placed diagonally");
	assertTrue(testCondition.placeShip(Ship{GridPosition("H10"), GridPosition("J10")}),
			"2nd Ship of length 3 not placed on the edge");
	assertTrue(testCondition.placeShip(Ship{GridPosition("A8"), GridPosition("A10")}),
			"3rd Ship of length 3 not placed on the edge");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("C8"), GridPosition("C10")}),
			"4th Ship of length 3 placed");

	//! Test placeShip for Ship length 4, No of Ships to place - 2.
	//! Two of them are already placed in D4-G4 & F6-F9.
	assertTrue(!testCondition.placeShip(Ship{GridPosition("I4"), GridPosition("I7")}),
			"3rd Ship of length 4 placed");

	//! Test placeShip for Ship length 5. No of Ships to place - 1.
	assertTrue(testCondition.placeShip(Ship{GridPosition("F1"), GridPosition("J1")}),
			"1st Ship of length 5 not placed on the edge");
	assertTrue(!testCondition.placeShip(Ship{GridPosition("H5"), GridPosition("H9")}),
			"2nd Ship of length 5 placed");

	// cout << endl << "Placing all the possible 10 ships in the OwnGrid!!!" << endl << endl;
	// myConsole.print();

	// cout << endl << "==================Part 2 tests completed!!!!=================" << endl << endl;
}
