/*!
 * @file Ship.h
 *
 * \n Created on: 03-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"

#include <map>
#include <set>
#include <vector>

//! A Ship Class.
/**
 * A ship class has data members as two grid fields.
 * Bow: Front end of the Ship
 * Stern: Rear end of the Ship
 * Ship class is immutable.
 */
class Ship
{
private:
	/*!
	 *  m_bow is a private member of type Class GridPosition, it represents bow of the Ship.
	 *  m_stern is a private member of type Class GridPosition, it represents stern of the Ship.
	 */
	GridPosition m_bow;
	GridPosition m_stern;

public:
	/**
	 * A parameterized constructor that takes bow and stern as arguments.
	 * @param bow is assigned to m_bow.
	 * @param stern is assigned to m_stern.
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/*!
	 * isValid() function checks if valid bow and stern are passed or not.
	 * It checks for shipLength as well, returns true iff ship length is between 2 and 5
	 * @return true or false.
	 */
	bool isValid() const;

	/*!
	 *	This method return the value stored in m_bow.
	 * @return GridPosition
	 */
	GridPosition getBow() const;

	/*!
	 * This method return the value stored in m_stern.
	 * @return
	 */
	GridPosition getStern() const;

	/*!
	 *  This function calculates the length of the ship and returns the value.
	 * @return int
	 */
	int length() const;

	/*!
	 * The method occupiedArea() returns all grid positions that are occupied by the ship.
	 * If the ship's bow is at B2 and its stern is at E2, then it should return B2, C2, D2, E2.
	 * @return a set of values of GridPosition type
	 */
	const std::set<GridPosition> occupiedArea() const;

	/*!
	 * It returns the set of grid positions occupied by the ship and all surrounding grid positions.
	 * @return a set of values of GridPosition type
	 */
	const std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
