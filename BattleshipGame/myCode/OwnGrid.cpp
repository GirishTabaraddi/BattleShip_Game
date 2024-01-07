/*!
 * @file OwnGrid.cpp
 *
 * \n Created on: 04-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "OwnGrid.h"

#include <algorithm>

using namespace std;

OwnGrid::OwnGrid(int rows, int columns) : m_rows(rows), m_columns(columns)
{
	m_OwnShips = {{2,4}, {3,3}, {4,2}, {5,1}};
}

int OwnGrid::getRows() const
{
	return this->m_rows;
}

int OwnGrid::getColumns() const
{
	return this->m_columns;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return this->m_ships;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	//! isValid checks for horizontal or vertical ship placement.
	if(ship.isValid() &&
			GridPosition("A1") < ship.getBow() &&
			ship.getStern() < GridPosition('A' + getRows() - 1, getColumns()+1))
	{
		const std::set<GridPosition> occupiedShips = ship.occupiedArea();

		set<GridPosition> intersectionShips;

		for(const Ship& ships: getShips())
		{
			//! for the ships placed, check it's blocked area.
			//! blocked ship's area and new ship occupied area should be empty to place it.
			const std::set<GridPosition> blockedShips = ships.blockedArea();

			for(const GridPosition& pos: occupiedShips)
			{
				if(blockedShips.count(pos))
				{
					return false;
				}
			}
		}

		if(m_OwnShips[ship.length()] > 0)
		{
			this->m_ships.push_back(ship);
			m_OwnShips[ship.length()]--;
			return true;
		}
	}

	return false;
}

/*
// Mahima's Logic
bool OwnGrid::placeShip(const Ship &ship)
{
	char maxRow = static_cast<char>('A'+getRows()-1)+1;

	if(ship.isValid())
	{
		//Edge placement
		if((ship.getBow().getRow() >= 'A') && (ship.getBow().getRow() < maxRow)
				&& (ship.getStern().getRow() >= 'A') && (ship.getStern().getRow() < maxRow)
				&& (ship.getBow().getColumn() >= 1) && (ship.getBow().getColumn() < getColumns()+1)
				&& (ship.getStern().getColumn() >= 1) && (ship.getStern().getColumn() < getColumns()+1))
		{
			std::set<GridPosition> placedBlocked;
			std::set<GridPosition> currentOccupied;

			currentOccupied = ship.occupiedArea();

			for(const auto& placedShips: getShips())
			{
				placedBlocked = placedShips.blockedArea();

				//set to store intersection
				std::set<GridPosition> intersection;

				//find the intersection
				std::set_intersection(
						currentOccupied.begin(), currentOccupied.end(),
						placedBlocked.begin(), placedBlocked.end(),
						std::inserter(intersection, intersection.begin()));

				if(!intersection.empty())
				{
				    return false;
				    break;
				}
			}
	        if (m_OwnShips[ship.length()] > 0)
	        {
	            // Place the ship, update ship count, and return true
	            this->m_ships.push_back(ship);
	            m_OwnShips[ship.length()]--;
	            return true;
	        }
		}
	}

	return false;
}
*/
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	GridPosition shotAtGridPos(shot.getTargetPosition());

	if(shotAtGridPos.isValid())
	{
		set<GridPosition> result;

		bool shipHit = false;

		for(const Ship& ships: this->m_ships)
		{
			const set<GridPosition> ShipsPos = ships.occupiedArea();

			// this checks if shotAtGridPos is a part of ShipsPos and
			// if yes, then evaluate to true
			if(ShipsPos.count(shotAtGridPos) > 0)
			{
				shipHit = true;
				this->m_shotAt.insert(shotAtGridPos);

				// this computes the intersection between the Ships occupied area and
				// set of shot positions "shotAt" and the result is stored "result" set.
				set_intersection(ShipsPos.begin(), ShipsPos.end(),
						this->m_shotAt.begin(), this->m_shotAt.end(), inserter(result, result.begin()));

				if(result.size() == ShipsPos.size())
				{
					return Shot::Impact::SUNKEN;
				}
				else
				{
					return Shot::Impact::HIT;
				}
			}
		}
		if(shipHit == false)
		{
			this->m_shotAt.insert(shotAtGridPos);
			return Shot::Impact::NONE;
		}
	}

	return Shot::Impact::NONE;
}

const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return this->m_shotAt;
}
