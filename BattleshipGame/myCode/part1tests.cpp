/**
 * @file part1tests.cpp
 *
 * \n Created on: 03-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */
#include "tests.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (condition == false) {
        cout << failedMessage << endl;
    }
}

/*!
 * This function checks for all the conditions for task 2.1 Basic Classes.
 */
void part1tests ()
{
	// cout << endl << "==================Part 1 tests started!!!!!!=================" << endl << endl;

    //! Test GridPosition constructor
    assertTrue(GridPosition{'A', 1}.isValid(), "A1 not considered valid");
    assertTrue(!GridPosition{'A', -1}.isValid(), "A-1 considered valid");
    assertTrue(!GridPosition{'@', 1}.isValid(), "@1 considered valid");
    GridPosition fromRowCol{'A', 1};
    GridPosition fromString{"A1"};
    assertTrue(fromRowCol.getRow() == fromString.getRow()
            && fromRowCol.getColumn() == fromString.getColumn(),
            "different constructors return different objects");

    //! Test getters and cast to string
    GridPosition pos1(GridPosition{'B', 13});
    assertTrue(pos1.getRow() == 'B',
            "GridPosition::GridPosition doesn't set row properly.");
    assertTrue(pos1.getColumn() == 13,
            "GridPosition::GridPosition doesn't set column properly.");
    assertTrue((string)pos1 == "B13", "Conversion to string fails.");

    //! Test comparison
    assertTrue(!(GridPosition{"A1"} < GridPosition{"A1"}),
            "Same positions considered different by '<'");
    assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
            "Position with bigger row not considered greater");
    assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
            "Position with bigger column not considered greater");
    assertTrue(GridPosition{"C21"} == GridPosition{"C21"},
    		"Equal positions not considered equal.");

    //! Test Ship Constructor
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"C3"}}.isValid(),
            "Can create non-aligned ship.");
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B2"}}.isValid(),
            "Can create ship of size 1.");
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B7"}}.isValid(),
            "Can create ship of size 6.");

	//! Testing Valid GridPositions for Bow and Stern
	assertTrue(!Ship{GridPosition{"@1"}, GridPosition{"@3"}}.isValid(),
			"Can create ship with invalid grid value");
	assertTrue(!Ship{GridPosition{"A0"}, GridPosition{"C0"}}.isValid(),
			"Can create ship with invalid grid value");

    //! Length
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B2"}}.length() == 1,
			"Length is 1");
	assertTrue(Ship{GridPosition{"@2"}, GridPosition{"@2"}}.length() == 0,
			"Length is 1 of ship @2, which is invalid");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
            "Length is not 3");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
            "Length is not 4");

    //! Occupied area
    assertTrue(Ship{GridPosition{"A1"}, GridPosition{"A1"}}.occupiedArea()
    		!= set<GridPosition>{GridPosition{"A1"}},
			"Ship of Length 1 has an Occupied Area");

    assertTrue(Ship{GridPosition{"Z1"}, GridPosition{'@', -1}}.occupiedArea()
    		!= set<GridPosition>{GridPosition{"@-1"}, GridPosition{"Z1"}},
			"Invalid Ship has an Occupied Area");

    assertTrue(Ship{GridPosition{"A1"}, GridPosition{"A6"}}.occupiedArea()
    		!= set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
    	GridPosition{"A3"}, GridPosition{"A4"}, GridPosition{"A5"}, GridPosition{"A6"}},
		"Ship of Length 6 has an Occupied Area");

    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea()
    		== set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
    	GridPosition{"D2"}, GridPosition{"E2"}},
		"Vertical Occupied area not correct");

    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B5"}}.occupiedArea()
    		== set<GridPosition>{GridPosition{"B2"}, GridPosition{"B3"},
    	GridPosition{"B4"}, GridPosition{"B5"}},
		"Horizontal Occupied area not correct");

    //! Blocked area
	assertTrue(!(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
			== set<GridPosition>{GridPosition{"B2"}, GridPosition{"B3"},
		GridPosition{"B4"}}), "B2-B4 Blocked area is correct");

	assertTrue((Ship{GridPosition{"B2"}, GridPosition{"B3"}}.blockedArea()
			== set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
		GridPosition{"A3"}, GridPosition{"A4"},
		GridPosition{"B1"}, GridPosition{"B2"},
		GridPosition{"B3"}, GridPosition{"B4"},
		GridPosition{"C1"}, GridPosition{"C2"},
		GridPosition{"C3"}, GridPosition{"C4"}}),
			"B2-B3 Blocked area not correct");

	assertTrue((Ship{GridPosition{"A1"}, GridPosition{"A2"}}.blockedArea()
			== set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
		GridPosition{"A3"},GridPosition{"B1"},
		GridPosition{"B2"},GridPosition{"B3"}}),
			"A1-A2 Blocked area not correct");

	assertTrue((Ship{GridPosition{"A1"}, GridPosition{"A1"}}.blockedArea()
			!= set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
		GridPosition{"B1"}, GridPosition{"B2"}}),
			"Ship of Length 1 has a Blocked area");

	assertTrue((Ship{GridPosition{"@1"}, GridPosition{"?-1"}}.blockedArea()
			!= set<GridPosition>{GridPosition{"@1"}, GridPosition{"?-1"}}),
			"Invalid Ship has a Blocked area");

    // cout << endl << "==================Part 1 tests completed!!!!=================" << endl << endl;
}
