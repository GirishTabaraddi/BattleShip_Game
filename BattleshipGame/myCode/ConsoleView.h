/*!
 * @file ConsoleView.h
 *
 * \n Created on: 06-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

#include <memory>

class ConsoleView
{
private:
	/*!
	 * assigning a shared pointer of class type Board.
	 */
	std::shared_ptr<Board> m_board;

public:
	/*!
	 * A parameterized constructor that will be pointing to the board assigned.
	 * It uses shared pointer instead of raw pointer.
	 * @param board: a shared pointer of type class Board.
	 */
	ConsoleView(std::shared_ptr<Board> board);

	/*!
	 * This method returns the board of type shared_ptr
	 * @return shared_ptr
	 */
	std::shared_ptr<Board>& getBoard();

	/*!
	 * A void method to print the own board and opponent board.
	 */
	void print();

	/*!
	 * A method which takes row and column as input and modifies the OwnGrid.
	 * @param row
	 * @param column
	 * @return char type value
	 */
	char modifyOwnGrid(char row, int column);

	/*!
	 * A method which takes row and column as input and modifies the OpponentGrid.
	 * @param row
	 * @param column
	 * @return char type value
	 */
	char modifyOpponentGrid(char row, int column);
};

#endif /* CONSOLEVIEW_H_ */
