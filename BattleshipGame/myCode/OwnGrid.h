/**
 * @file OwnGrid.h
 *
 * \n Created on: 04-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"

class OwnGrid
{
private:
	/*!
	 * m_rows: This is the size of the rows assigned during board creation, here it is 10.
	 * m_columnms: This is the size of the columns assigned during board creation, here it is 10.
	 * m_ships: This member variable returns the ships placed as a vector.
	 * m_shotAt: This member variable stores the GridPosition which is shot at.
	 */
	int m_rows;
	int m_columns;
	std::vector<Ship> m_ships;
	std::set<GridPosition> m_shotAt;

public:
	/*!
	 * This is public member that contains table of ships
	 * with their length and total number of ships of that length.
	 */
	std::map<int, int> m_OwnShips;

public:
	/*!
	 * A parameterized constructor which takes two arguments,
	 * a row and a column of type int.
	 * @param rows
	 * @param columns
	 */
	OwnGrid(int rows, int columns);

	/*!
	 * The method to obtain rows.
	 * @return integer type
	 */
	int getRows() const;

	/*!
	 * The method to obtain columns.
	 * @return integer type
	 */
	int getColumns() const;

	/*!
	 * A method to arrange the ship in the own grid.
	 * @param ship of type Ship class
	 * @return boolean type
	 */
	bool placeShip(const Ship& ship);

	/*!
	 * A method that returns the vector of type Ship.
	 * @return vector type
	 */
	const std::vector<Ship> getShips() const;

	/*!
	 * This method takes Shot as argument and if the ship is hit or miss,
	 * depending on the enum Impact it returns the value.
	 * @param shot
	 * @return enum Impact type
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/*!
	 * This method returns the shotAt position as a set of GridPosition.
	 * @return set<GridPosition>
	 */
	const std::set<GridPosition> getShotAt() const;
};

#endif /* OWNGRID_H_ */
