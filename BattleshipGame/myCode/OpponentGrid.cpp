/*!
 * @file OpponentGrid.cpp
 *
 * \n Created on: 04-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "OpponentGrid.h"

#include <algorithm>

using namespace std;

OpponentGrid::OpponentGrid(int rows, int columns) : m_rows(rows), m_columns(columns)
{
	m_OpponentShips = {{2,4}, {3,3}, {4,2}, {5,1}};
}

int OpponentGrid::getRows() const
{
	return this->m_rows;
}

int OpponentGrid::getColumns() const
{
	return this->m_columns;
}

const std::vector<Ship> OpponentGrid::getSunkenShips() const
{
	return this->m_sunkenShips;
}

const std::map<GridPosition, Shot::Impact> OpponentGrid::getShotsAt()
{
	return this->m_shots;
}

void OpponentGrid::shotresult(const Shot &shot, Shot::Impact Impact)
{
	GridPosition targetPos(shot.getTargetPosition());

	if(targetPos.isValid())
	{
		this->m_shots[targetPos] = Impact;

		if(Impact == Shot::Impact::SUNKEN)
		{
			set<GridPosition> sunkenShipGridPos;
			int maxShipLength = 5;

			vector<pair<int, int>> directions =
			{
					{0, 0},  // CurrentPos
					{0, -1}, // Left
					{0, +1}, // Right
					{-1, 0}, // Up
					{+1, 0}  // Down
			};

			for (const pair<int, int> &dir : directions)
			{
				char row = targetPos.getRow();
				int col = targetPos.getColumn();

				for (int step = 0; step < maxShipLength; ++step)
				{
					int newRow = row + dir.first * step;
					int newCol = col + dir.second * step;

					GridPosition neighbor{static_cast<char>(newRow), newCol};

					auto itr = m_shots.find(neighbor);

					if (itr != m_shots.end() && (itr->second == Shot::Impact::HIT
							|| itr->second == Shot::Impact::SUNKEN))
					{
						sunkenShipGridPos.insert(neighbor);
					}
					else
					{
						break; // Stop searching in this direction if no HIT or SUNKEN is found
					}
				}
			}

//			cout << "sunkenShipGridPos: " << endl;
//			for(const auto& pos: sunkenShipGridPos)
//			{
//				cout << pos.getRow() << pos.getColumn() << endl;
//			}

			// Call the placeSunkenShip function to place them.
			placeSunkenShip(sunkenShipGridPos);

//			cout << "m_shots after placesunkenship: " << endl;
//			for (const auto& entry : this->m_shots)
//			{
//				std::cout << entry.first.getRow() << entry.first.getColumn() << ": " << entry.second << std::endl;
//			}
		}
	}
}

void OpponentGrid::placeSunkenShip(const std::set<GridPosition> sunkenShipGridPos)
{
//	cout << "Verify sunkenShipGridPos" << endl;
//	for(const auto& pos: sunkenShipGridPos)
//	{
//		cout << pos.getRow() << pos.getColumn() << endl;
//	}
//
//	cout << "m_shots: " << endl;
//	for (const auto& entry : this->m_shots)
//	{
//		std::cout << entry.first.getRow() << entry.first.getColumn() << ": " << entry.second << std::endl;
//	}

	GridPosition bow = *sunkenShipGridPos.begin();
	GridPosition stern = *std::prev(sunkenShipGridPos.end());

	Ship sunkenShip(bow, stern);

	int& shipCount = m_OpponentShips[sunkenShip.length()];

//	cout << "ShipLength: " << sunkenShip.length() << endl;
//	cout << "before adding sunkenship shipCount: " << shipCount << endl;

	// Check if there are remaining ships of the same length
	if(shipCount > 0)
	{
		// Check if the number of ships of this length is not exceeded
		// Add the ship to m_sunkenShips only if the count is not exceeded
		this->m_sunkenShips.push_back(sunkenShip);
		shipCount--;

		for(const GridPosition& pos: sunkenShipGridPos)
		{
			this->m_shots[pos] = Shot::Impact::SUNKEN;
		}
//		cout << "ShipLength: " << sunkenShip.length() << endl;
//		cout << "after adding sunkenship shipCount: " << shipCount << endl;
	}
	else
	{
//		cout << "why i am here" << endl;
//		cout << "this length: " << sunkenShip.length() << endl;

		// Erase the positions from sunkenShipGridPos if there are no remaining ships of this length
//		for (const GridPosition &pos : sunkenShipGridPos)
//		{
//			this->m_shots[pos] = Shot::Impact::NONE;
//
//			cout << "Missed ships shots: " << pos.getRow() << pos.getColumn() << " ";
//		}
//		cout << endl;
	}
//	cout << endl << "end of placesunkenShip func" << endl << endl;
}
