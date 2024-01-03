/*!
 * @file ConsoleView.cpp
 *
 * \n Created on: 06-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "ConsoleView.h"

using namespace std;

ConsoleView::ConsoleView(std::shared_ptr<Board> board) : m_board(board)
{
}

std::shared_ptr<Board>& ConsoleView::getBoard()
{
	return this->m_board;
}

void ConsoleView::print()
{
	int rows = getBoard()->getRows();
	int columns = getBoard()->getColumns();

	//! Print the column numbers
	for(int x = 1; x <= 21; x++)
	{
		if( x%21 != 0)
			cout << " ";
		else if(x % 21 == 0)
			cout << 1;
	}
	for(int x = 1; x <= 22; x++)
	{
		if( x%22 != 0)
			cout << " ";
		else if(x % 22 == 0)
			cout << 1;
	}
	cout << endl;

	//! Column indexing for OwnGrid
	cout << "  ";
	for (int colIdx = 1; colIdx <= columns; colIdx++)
	{
		cout << colIdx % 10 << " ";
	}

	//! Column indexing for OpponentGrid
	cout << "  ";
	for (int colIdx = 1; colIdx <= columns; colIdx++)
	{
		cout << colIdx % 10 << " ";
	}
	cout << endl;

	//! Print the board
	//! The rowIndex loop is iterating from ASCII 65 to ASCII 75('K'),
	//! here rows + 'A' is done to check from 'A' to 'K' rows.
	for (int rowIndex = 'A'; rowIndex < rows + 'A'; rowIndex++)
	{
		for(unsigned int gridIndex = 0; gridIndex < 2; gridIndex++)
		{
			cout << (char)rowIndex << " ";
			for (int colIndex = 1; colIndex <= columns; colIndex++)
			{
				if(gridIndex == 0)
				{
					//! print own grid
					cout << modifyOwnGrid(rowIndex, colIndex) << " ";
				}
				else if(gridIndex == 1)
				{
					//! print opponent grid
					cout << modifyOpponentGrid(rowIndex, colIndex) << " ";
				}
			}
		}
		cout << endl;
	}
}

char ConsoleView::modifyOwnGrid(char row, int column)
{
    OwnGrid owngrid = getBoard()->getOwnGrid();

    GridPosition gridRef(row, column);

    for (const Ship& ship : owngrid.getShips())
    {
        if (ship.occupiedArea().count(gridRef) > 0)
        {
            if (owngrid.getShotAt().count(gridRef) > 0)
            {
                return '0'; //! Ship hit
            }
            else
            {
                return '#'; //! Ship part, not hit
            }
        }
    }
    if (owngrid.getShotAt().count(gridRef) > 0)
    {
        return '^'; //! Missed shot
    }

    return '~'; //! Empty sea
}

char ConsoleView::modifyOpponentGrid(char row, int column)
{
    OpponentGrid opponentgrid = getBoard()->getOpponentGrid();

    GridPosition gridRef(row, column);

    for (const Ship& ship : opponentgrid.getSunkenShips())
    {
        if (ship.occupiedArea().count(gridRef) > 0)
        {
        	return '#'; //! Ship Hit and Sunk.
        }
    }

	auto shotsAt = opponentgrid.getShotsAt();

	auto shotsHit = shotsAt.find(gridRef);

    if (shotsHit != shotsAt.end())
    {
        if (shotsHit->second == Shot::Impact::HIT)
        {
            //! Not sunk but hit
            return '0';
        }
        else if(shotsHit->second == Shot::Impact::NONE)
        {
            //! Missed Shot
            return '^';
        }
    }

    return '~'; //! Empty sea
}
