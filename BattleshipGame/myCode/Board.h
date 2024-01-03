/*!
 * @file Board.h
 *
 * \n Created on: 06-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

class Board
{
private:
	/*!
	 * m_ownGrid: A member variable as an OwnGrid object.
	 * m_opponentGrid: A member variable as an OpponentGrid object.
	 */
	OwnGrid m_ownGrid;
	OpponentGrid m_opponentGrid;

public:
	/*!
	 * A parameterized constructor that takes rows and columns as input arguments.
	 * @param rows
	 * @param columns
	 */
	Board(int rows = 10, int columns = 10);

	/*!
	 * A method to return the rows
	 * @return integer value
	 */
	int getRows() const;

	/*!
	 * A method that return the columns
	 * @return integer value
	 */
	int getColumns() const;

	/*!
	 * A method that returns the own grid.
	 * @return OwnGrid class type
	 */
	OwnGrid& getOwnGrid();

	/*!
	 * A method that returns opponent'S grid.
	 * @return OpponentGrid class type
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
