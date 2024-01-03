/*!
 * @file Ship.cpp
 *
 * \n Created on: 03-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "Ship.h"

using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern)
: m_bow(bow), m_stern(stern)
{
}

GridPosition Ship::getBow() const
{
	return this->m_bow;
}

GridPosition Ship::getStern() const
{
	return this->m_stern;
}

bool Ship::isValid() const
{
	int shipLength = length();

	if(shipLength > 1 && shipLength < 6)
	{
		if(getBow().getRow() == getStern().getRow())
		{
			return true;
		}
		else if(getBow().getColumn() == getStern().getColumn())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int Ship::length() const
{
	int shipLength = 0;

	if(getBow().getRow() == getStern().getRow() &&
			getBow().getColumn() < getStern().getColumn())
	{
		shipLength = abs(getStern().getColumn() - getBow().getColumn()) + 1;
	}
	else if(getBow().getRow() < getStern().getRow())
	{
		shipLength = abs(getStern().getRow() - getBow().getRow()) + 1;
	}

	return shipLength;
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> shipOccupiedPositions;

	if(getBow().getRow() == getStern().getRow() &&
			getBow().getColumn() < getStern().getColumn())
	{
		for(int col = getBow().getColumn(); col <= getStern().getColumn(); col++)
		{
			shipOccupiedPositions.insert(GridPosition(getBow().getRow(), col));
		}
	}
	else if(getBow().getRow() < getStern().getRow())
	{
		for(char row = getBow().getRow(); row <= getStern().getRow(); row++)
		{
			shipOccupiedPositions.insert(GridPosition(row, getBow().getColumn()));
		}
	}

	return shipOccupiedPositions;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> blockedGridPositions;

	set<GridPosition> shipOccupiedArea = occupiedArea();

	for(auto itr = shipOccupiedArea.begin(); itr != shipOccupiedArea.end(); itr++)
	{
		for(int rowIndex = itr->getRow() - 1; rowIndex <= itr->getRow() + 1; rowIndex++)
		{
			for(char colIndex = itr->getColumn() - 1; colIndex <= itr->getColumn() + 1; colIndex++)
			{
				blockedGridPositions.insert(GridPosition(rowIndex, colIndex));
			}
		}
	}

	return blockedGridPositions;
}
