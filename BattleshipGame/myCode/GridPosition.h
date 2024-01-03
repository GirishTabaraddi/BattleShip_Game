/*!
 * @file GridPosition.h
 *
 * \n Created on: 02-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
#include <iostream>

//! A GridPosition Class
/*!
 * Most basic class Grid Position.
 * The class is immutable and represents a Grid Position.
 */
class GridPosition
{
private:
	/**
	 * m_row is a private variable that stores char type value 'A' <= m_row <= 'Z'.
	 * m_column is a private variable that stores int type values m_column > 0
	 */
	char m_row;
	int m_column;

public:
	/*!
	 *	A parameterized constructor which takes row and column as parameters.
	 *	row is of type char and the column is of type int.
	 * @param row
	 * @param col
	 */
	GridPosition(char row, int col);

	/*!
	 *	A parameterized constructor which takes string as a parameter.
	 *	This method separates the char and int from the entered string using string stream header.
	 * @param position
	 */
	GridPosition(std::string position);

	/*!
	 *	The method checks if the entered row and column are valid.
	 *	For 'A' <= m_row <= 'Z' and m_column > 0.
	 * @return true or false
	 */
	bool isValid() const;

	/*!
	 * A getter method, to fetch the row value stored in the private m_row variable.
	 * @return char value
	 */
	char getRow() const;

	/*!
	 *	A getter method, to fetch the column value stored in the private m_column variable.
	 * @return int value
	 */
	int getColumn() const;

	/*!
	 *	This overloaded operator method returns a string.
	 *	It takes a char row and int column and stitches together to return a string value.
	 *	This is implicitly called, no need for explicit call of this function.
	 * @return string value.
	 */
	operator std::string() const;

	/*!
	 *	This overloaded operator method compares the row and column value of two objects
	 *	and returns true if they are same.
	 * @param other
	 * @return true or false
	 */
	bool operator==(GridPosition other) const;

	/*!
	 *	This overloaded operator method compares the row value of two objects and
	 *	returns a boolean value based on the condition, it also checks for column value.
	 *	If both row and column are same, it returns false.
	 * @param other
	 * @return true or false
	 */
	bool operator<(GridPosition other) const;

};

#endif /* GRIDPOSITION_H_ */
