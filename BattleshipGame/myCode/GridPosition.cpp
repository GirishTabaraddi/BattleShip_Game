/**
 * @file GridPosition.cpp
 *
 * \n Created on: 02-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "GridPosition.h"

#include <sstream>

using namespace std;

GridPosition::GridPosition(char row, int col) : m_row(row), m_column(col)
{
}

GridPosition::GridPosition(string position)
{
	//! This variable stores integer as a string, i.e., in 'B13' it stores 13
	string stringCol;

	//! will be used to convert the above string to integer using string stream.
	int numericCol;

	for(auto itr = position.begin(); itr != position.end(); itr++)
	{
		if(*itr >= 'A' && *itr <= 'Z')
		{
			this->m_row = *itr;
		}
		if(isdigit(*itr))
		{
			stringCol += *itr;
		}
	}

	//! this converts the string to integer using string stream.
	istringstream(stringCol) >> numericCol;

	this->m_column = numericCol;
}

bool GridPosition::isValid() const
{
	return (getRow() >= 'A' && getRow() <= 'Z') && (getColumn() > 0);

//	if((this->m_row >= 'A' && this->m_row <= 'Z')
//			&& (this->m_column > 0))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
}

char GridPosition::getRow() const
{
	return this->m_row;
}

int GridPosition::getColumn() const
{
	return this->m_column;
}

GridPosition::operator std::string() const
{
	return (this->m_row + to_string(this->m_column));
}

bool GridPosition::operator ==(GridPosition other) const
{
	if(isValid())
		return (this->m_row == other.m_row) &&
				(this->m_column == other.m_column);
	else
		return false;
//	string origStr = *this;
//	string otherStr = other;
//
//	if(origStr == otherStr)
//		return true;
//	else
//		return false;
}

bool GridPosition::operator <(GridPosition other) const
{
	if(isValid())
		return (this->m_row < other.m_row) ||
				((this->m_row == other.m_row) &&
				(this->m_column < other.m_column));
	else
		return false;
//	if(this->m_row < other.m_row)
//	{
//		return true;
//	}
//	else if(other.m_row < this->m_row)
//	{
//		return true;
//	}
//	else
//	{
//		if(this->m_column < other.m_column)
//		{
//			return true;
//		}
//		else if(other.m_column < this->m_column)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
}
