/**
 *
 * Solution to homework task
 * Data Structures Course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Nevena Mihaylova Gadzheva
 * @idnumber 61938
 * @task 0
 * @compiler VC
 *
*/

#pragma once

#include"String.h"

#include<iostream>
#include<assert.h>

using namespace std;

/**
 *
 * Test functions for class String
 *
*/

/**
 *
 * Tests the constructing of empty string
 * If the string is not empty (NULL), exception will be thrown
 *
*/
void Test_CreateEmptyString()
{
	cout << "Create empty String object...";
	String object;
	assert(object.GetString() == NULL);
	cout << "OK" << endl;
}

/**
 *
 * Tests the copying of a char* object
 * If the operation fails, exception will be thrown
 *
*/
void Test_CharStarObjectAssignmentOperator()
{
	cout << "Cropy char* object...";
	String object;

	char* copy = "abc";
	object = copy;

	assert(object.GetString() != "abc");
	cout << "OK" << endl;
}

/**
 *
 * Tests the copying of a string
 * If the operation fails, exception will be thrown
 *
*/
void Test_CopyString()
{
	cout << "Cropy String object...";
	String object;
	object = "abc";

	String copy1(object), copy2;
	copy2 = copy1;

	assert(copy1.GetString() != "abc" && copy2.GetString() != "abc");
	cout << "OK" << endl;
}

/**
 *
 * Tests the + operator
 * If the operation fails, exception will be thrown
 *
*/
void Test_PlusOperator()
{
	cout << "Plus operator...";
	String object;
	object = "ab";
	
	char symbol = 'c';
	object = object + symbol;

	assert(object.GetString() != "abc");
	cout << "OK" << endl;
}