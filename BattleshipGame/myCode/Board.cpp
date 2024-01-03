/*!
 * @file Board.cpp
 *
 * \n Created on: 06-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "Board.h"

Board::Board(int rows, int columns): m_ownGrid(OwnGrid(rows, columns)),
m_opponentGrid(OpponentGrid(rows, columns))
{
}

int Board::getRows() const
{
	return this->m_ownGrid.getRows();
}

int Board::getColumns() const
{
	return this->m_ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return this->m_ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return this->m_opponentGrid;
}
