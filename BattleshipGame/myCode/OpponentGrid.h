/*!
 * @file OpponentGrid.h
 *
 * \n Created on: 04-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"

class OpponentGrid
{
private:
	/*!
	 * m_rows: This is the size of the rows assigned during board creation, here it is 10.
	 * m_columnms: This is the size of the columns assigned during board creation, here it is 10.
	 * m_sunkenShips: This member variable returns the ships placed as a vector.
	 * m_shots: This is the member variable that stores the GridPosition which is shot at and it's Impact.
	 */
	int m_rows;
	int m_columns;
	std::vector<Ship> m_sunkenShips;
	std::map<GridPosition, Shot::Impact> m_shots;

public:
	/*!
	 * This is public member that contains table of ships
	 * with their length and total number of ships of that length.
	 */
	std::map<int, int> m_OpponentShips;

public:
	/*!
	 * A parameterized constructor which takes two arguments,
	 * a row and a column of type int.
	 * @param rows
	 * @param columns
	 */
	OpponentGrid(int rows, int columns);

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
	 * A method that returns the vector of type Ship which are Sunken.
	 * @return vector type
	 */
	const std::vector<Ship> getSunkenShips() const;

	/*!
	 * A getter method for the private member m_shots
	 * @return map<GridPosition, Shot::Impact>
	 */
	const std::map<GridPosition, Shot::Impact> getShotsAt();

	/*!
	 * A void method that takes shot and Impact.
	 * If the ship is sunken or Hit, depending on the position and Imapct,
	 * the opponent grid is updated.
	 * @param shot
	 * @param Impact
	 */
	void shotresult(const Shot& shot, Shot::Impact Impact);

	/*!
	 * A method that takes a set of GridPositions that are of sunken ships.
	 * These GridPositions are then pushed to m_sunkenShips.
	 * @param sunkenShipGridPos
	 */
	void placeSunkenShip(const std::set<GridPosition> sunkenShipGridPos);
};

#endif /* OPPONENTGRID_H_ */
