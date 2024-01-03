/*!
 * @file Shot.h
 *
 * \n Created on: 11-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

class Shot
{
private:
	/*!
	 * m_targetPosition: This is a member variable which stores the GridPosition which is a target.
	 */
	GridPosition m_targetPosition;

public:
	/*!
	 * A parameterized constructor of class Shot.
	 * @param targetPosition
	 */
	Shot(GridPosition targetPosition);

	/*!
	 * A method to obtain the grid position where the shot is aimed at.
	 * @return of type class GridPosition
	 */
	GridPosition getTargetPosition() const;

	/*!
	 * An Enum of type Impact which has NONE as 0, HIT as 1 and SUNKEN as 2, as it's members.
	 */
	typedef enum
	{
		NONE = 0, /*!< NONE */
		HIT = 1,  /*!< HIT */
		SUNKEN = 2/*!< SUNKEN */
	}Impact;
};

#endif /* SHOT_H_ */
