//! Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;

//! Add your project's header files here
#include "tests.h"

//! Main program
int main ()
{
	cout << "BattleshipGame started." << endl << endl;

	part1tests();

	part2tests();

	part3tests();

	cout << endl << "==================Start of Testing BattleShip Game!!!!!!=================" << endl << endl;

	auto myBoard = make_shared<Board>(10,10);

	ConsoleView myConsoleView(myBoard);

	OwnGrid& myOwnGrid = myConsoleView.getBoard()->getOwnGrid();

	//! Placing Ships at B2-B4, D4-G4 & F6-F9 in OwnGrid.
	myOwnGrid.placeShip(Ship(GridPosition{"B2"}, GridPosition{"B4"}));
	myOwnGrid.placeShip(Ship(GridPosition{"D4"}, GridPosition{"G4"}));
	myOwnGrid.placeShip(Ship(GridPosition{"F6"}, GridPosition{"F9"}));

	//! OwnGrid takes blow at B3, B4 and Miss Hit at B5
	myOwnGrid.takeBlow(Shot(GridPosition{"B3"}));	// HIT
	myOwnGrid.takeBlow(Shot(GridPosition{"B4"}));	// HIT
	myOwnGrid.takeBlow(Shot(GridPosition{"B5"}));	// MISS

	OpponentGrid& myOpponentGrid = myConsoleView.getBoard()->getOpponentGrid();

	//! A SunkenSHip at C3-C4-C5 in OpponentGrid and Miss Hit at C2
	myOpponentGrid.shotresult(Shot(GridPosition{"C3"}), Shot::Impact::HIT);		// HIT
	myOpponentGrid.shotresult(Shot(GridPosition{"C4"}), Shot::Impact::HIT);		// HIT
	myOpponentGrid.shotresult(Shot(GridPosition{"C5"}), Shot::Impact::SUNKEN);	// SUNKEN
	myOpponentGrid.shotresult(Shot(GridPosition{"C2"}), Shot::Impact::NONE);	// MISS

	//! A Ship Hit at G5, G6 and Miss hits at F5, G4 & I5.
	myOpponentGrid.shotresult(Shot(GridPosition{"G5"}), Shot::Impact::HIT);		// HIT
	myOpponentGrid.shotresult(Shot(GridPosition{"G6"}), Shot::Impact::HIT);		// HIT
	myOpponentGrid.shotresult(Shot(GridPosition{"F5"}), Shot::Impact::NONE);	// MISS
	myOpponentGrid.shotresult(Shot(GridPosition{"G4"}), Shot::Impact::NONE);	// MISS
	myOpponentGrid.shotresult(Shot(GridPosition{"I5"}), Shot::Impact::NONE);	// MISS

	myConsoleView.print();

	cout << endl << endl << "===================End of Testing BattleShip Game!!!!!!==================" << endl;
	return 0;
}

