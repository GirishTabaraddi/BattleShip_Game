/*!
 * @file tests.h
 *
 * \n Created on: 06-Dec-2023
 * @author Girish Tabaraddi
 *
 * Built on: \showdate "%A %d-%m-%Y %H:%M:%S"
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "ConsoleView.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, std::string failedMessage);

/*!
 * This function checks for all the conditions for task 2.1 Basic Classes.
 */
void part1tests ();

/*!
 * This function checks for all the conditions for task 2.2 Arrangement Rules.
 */
void part2tests ();

/*!
 * This function checks for all the conditions for task 2.3 Shots.
 */
void part3tests ();

#endif /* TESTS_H_ */
