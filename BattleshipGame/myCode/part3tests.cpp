/*!
 * @file part3tests.cpp
 *
 * \n Created on: 12-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */
#include "tests.h"

using namespace std;

/*!
 * This function checks for all the conditions for task 2.3 Shots
 */
void part3tests ()
{
	auto myBoard =  make_shared<Board>(10,10);

	ConsoleView	myConsole(myBoard);

	OwnGrid& owngrid = myConsole.getBoard()->getOwnGrid();

//	cout << endl << "==================Part 3 tests started!!!!!!=================" << endl << endl;

	//! Test placeShip function.
	assertTrue(owngrid.placeShip(Ship{GridPosition("B2"), GridPosition("B4")}),
			"1st Ship of length 3 not placed Horizontally");
	assertTrue(owngrid.placeShip(Ship{GridPosition("D4"), GridPosition("G4")}),
			"1st Ship of length 4 not placed Vertically");
	assertTrue(owngrid.placeShip(Ship{GridPosition("F6"), GridPosition("F9")}),
			"2nd Ship of length 4 not placed Horizontally");

	//! Testing takeBlow for Ship B2-B3-B4
	assertTrue(!(owngrid.takeBlow(Shot(GridPosition("B5")))  != Shot::Impact::NONE),
			"Expected NONE Impact, it's should have been a miss hit.");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("Z11")}) != Shot::Impact::NONE),
			"Expected NONE Impact, it's out of boundary.");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("B3")})  != Shot::Impact::HIT),
			"Ship did not get HIT");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("B4")})  != Shot::Impact::HIT),
			"Ship did not get HIT");

	//! Testing takeBlow for Ship D4-E4-F4-G4
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("K4")})  != Shot::Impact::NONE),
			"Ship did get HIT 1");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("&0")})  != Shot::Impact::NONE),
			"Ship did get HIT");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("-1A")}) != Shot::Impact::NONE),
			"Ship did not get HIT");
	assertTrue(!(owngrid.takeBlow(Shot{GridPosition("FF")})  != Shot::Impact::NONE),
			"Ship did not get SUNKEN");

//	cout << endl << "Sample output for the board after shooting at B3, B4 and B5:" << endl << endl;
//	myConsole.print();

	OpponentGrid& opponentgrid = myConsole.getBoard()->getOpponentGrid();

	opponentgrid.shotresult(Shot{GridPosition{"C3"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"C4"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"C5"}}, Shot::Impact::SUNKEN);
	opponentgrid.shotresult(Shot{GridPosition{"C2"}}, Shot::Impact::NONE);
	opponentgrid.shotresult(Shot{GridPosition{"G5"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"G6"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"G4"}}, Shot::Impact::NONE);
	opponentgrid.shotresult(Shot{GridPosition{"F5"}}, Shot::Impact::NONE);
	opponentgrid.shotresult(Shot{GridPosition{"I5"}}, Shot::Impact::NONE);

	map<GridPosition, Shot::Impact> testMap;

	testMap = opponentgrid.getShotsAt();

	assertTrue(!(testMap[GridPosition("C3")] != Shot::Impact::SUNKEN),
			"C3 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C4")] != Shot::Impact::SUNKEN),
			"C4 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C5")] != Shot::Impact::SUNKEN),
			"C5 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C2")] == Shot::Impact::HIT),
			"C2 is NONE, but HIT detected");
	assertTrue(!(testMap[GridPosition("G5")] == Shot::Impact::NONE),
			"G5 is HIT, but NONE detected");
	assertTrue(!(testMap[GridPosition("G6")] == Shot::Impact::SUNKEN),
			"G6 is HIT, but SUNKEN detected");
	assertTrue(!(testMap[GridPosition("G4")] == Shot::Impact::HIT),
			"G4 is NONE, but HIT detected");
	assertTrue(!(testMap[GridPosition("F5")] == Shot::Impact::HIT),
			"F5 is NONE, but HIT detected");
	assertTrue(!(testMap[GridPosition("I5")] == Shot::Impact::HIT),
			"I5 is NONE, but HIT detected");

//	cout << endl << "Output after C3-C4-C5 is Sunk" << endl << endl;
//	myConsole.print();

	opponentgrid.shotresult(Shot{GridPosition{"A1"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"A2"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"A4"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"A3"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"A5"}}, Shot::Impact::SUNKEN);

	testMap = opponentgrid.getShotsAt();

	assertTrue(!(testMap[GridPosition("A1")] == Shot::Impact::HIT),
			"A1 is SUNKEN, but HIT detected");
	assertTrue(!(testMap[GridPosition("A2")] == Shot::Impact::HIT),
			"A2 is SUNKEN, but HIT detected");
	assertTrue(!(testMap[GridPosition("A3")] == Shot::Impact::NONE),
			"A3 is SUNKEN, but NONE detected");
	assertTrue(!(testMap[GridPosition("A4")] == Shot::Impact::NONE),
			"A4 is SUNKEN, but NONE detected");
	assertTrue(!(testMap[GridPosition("A5")] != Shot::Impact::SUNKEN),
			"A5 is SUNKEN, but not detected");

//	cout << "Test Map values after shots on A1 to A5:" << endl;
//	for (const auto& entry : testMap) {
//	    cout << entry.first.getRow() << entry.first.getColumn() << ": " << entry.second << endl;
//	}

//	cout << endl << "Output after A1-A2-A3-A4-A5 is Sunk" << endl << endl;
//	myConsole.print();

	opponentgrid.shotresult(Shot{GridPosition{"J1"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"J2"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"J3"}}, Shot::Impact::SUNKEN);

	testMap = opponentgrid.getShotsAt();

	assertTrue(!(testMap[GridPosition("J1")] != Shot::Impact::SUNKEN),
			"J1 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("J2")] == Shot::Impact::NONE),
			"J2 is SUNKEN, but NONE detected");
	assertTrue(!(testMap[GridPosition("J3")] != Shot::Impact::SUNKEN),
			"J3 is SUNKEN, but not detected");

//	cout << endl << "Output after J1-J2-J3 is Sunk" << endl << endl;
//	myConsole.print();

	opponentgrid.shotresult(Shot{GridPosition{"I8"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"I9"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"I10"}}, Shot::Impact::SUNKEN);

	testMap = opponentgrid.getShotsAt();

	assertTrue(!(testMap[GridPosition("I8")] != Shot::Impact::SUNKEN),
			"I8 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("I9")] == Shot::Impact::NONE),
			"I9 is SUNKEN, but NONE detected");
	assertTrue(!(testMap[GridPosition("I10")] == Shot::Impact::HIT),
			"I10 is SUNKEN, but HIT detected");

//	cout << endl << "Output after I8-I9-I10 is Sunk" << endl << endl;
//	myConsole.print();
//
//	cout << endl << "Trying to place another Ship D6 to D10 of length 5" << endl << endl;

	opponentgrid.shotresult(Shot{GridPosition{"D6"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"D7"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"D8"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"D9"}}, Shot::Impact::HIT);
	opponentgrid.shotresult(Shot{GridPosition{"D10"}}, Shot::Impact::SUNKEN);

	testMap = opponentgrid.getShotsAt();

	assertTrue(!(testMap[GridPosition("D6")] != Shot::Impact::HIT),
			"D6 is HIT, but not detected");
	assertTrue(!(testMap[GridPosition("D7")] != Shot::Impact::HIT),
			"D7 is HIT, but not detected");
	assertTrue(!(testMap[GridPosition("D8")] == Shot::Impact::NONE),
			"D8 is HIT, but NONE detected");
	assertTrue(!(testMap[GridPosition("D9")] == Shot::Impact::NONE),
			"D9 is HIT, but NONE detected");
	assertTrue(!(testMap[GridPosition("D10")] != Shot::Impact::SUNKEN),
			"D10 is SUNKEN, but not detected");

//	cout << endl << "No Ship at D6-D7-D8-D9-D10" << endl << endl;
//	myConsole.print();

//	cout << endl << "Testing Charan's assert statements-----------------" << endl;
//
//	//! Testing Shots on Opponent Grid
//	opponentgrid.shotresult(Shot(GridPosition("E1")), Shot::Impact::HIT);
//	opponentgrid.shotresult(Shot(GridPosition("E2")), Shot::Impact::HIT);
//	opponentgrid.shotresult(Shot(GridPosition("G8")), Shot::Impact::HIT);
//	opponentgrid.shotresult(Shot(GridPosition("G7")), Shot::Impact::NONE);
//	opponentgrid.shotresult(Shot(GridPosition("H8")), Shot::Impact::NONE);
//	opponentgrid.shotresult(Shot(GridPosition("F8")), Shot::Impact::NONE);
//	opponentgrid.shotresult(Shot(GridPosition("G9")), Shot::Impact::HIT);
//
//	testMap = opponentgrid.getShotsAt();
//
//	assertTrue(!(testMap[GridPosition("E1")] != Shot::Impact::HIT),
//			"HIT not detected at E1");
//	assertTrue(!(testMap[GridPosition("E2")] != Shot::Impact::HIT),
//			"HIT not detected at E2");
//	assertTrue(!(testMap[GridPosition("G8")] == Shot::Impact::NONE),
//			"NONE wrongly detected at G8");
//	assertTrue(!(testMap[GridPosition("G9")] == Shot::Impact::SUNKEN),
//			"SUNKEN wrongly detected at G9");
//
//	opponentgrid.shotresult(Shot(GridPosition("G10")), Shot::Impact::SUNKEN);
//
//	testMap = opponentgrid.getShotsAt();
//
//	assertTrue(!(testMap[GridPosition("G10")] != Shot::Impact::SUNKEN),
//			"SUNKEN not detected at G10");
//	assertTrue(!(testMap[GridPosition("G8")] == Shot::Impact::HIT),
//			"HIT wrongly detected at G8");
//
//	cout << endl;
//	myConsole.print();

//	cout << endl << "==================Part 3 tests completed!!!!=================" << endl << endl;
}
