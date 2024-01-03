/*!
 * @file Shot.cpp
 *
 * \n Created on: 11-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#include "Shot.h"

using namespace std;

Shot::Shot(GridPosition targetPosition) : m_targetPosition(targetPosition)
{
}

GridPosition Shot::getTargetPosition() const
{
	return this->m_targetPosition;
}
