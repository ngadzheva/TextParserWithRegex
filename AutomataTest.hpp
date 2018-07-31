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

#include"Automata.h"

#include<iostream>
#include<assert.h>

using namespace std;

/**
 *
 * Test functions for class Automata
 *
*/

/**
 *
 * Tests the constructing of empty automata
 *
*/
void Test_CreateEmptyAutomata()
{
	cout << "Create empty Automata object...";
	Automata object;
	cout << "OK" << endl;
}

/**
 *
 * Tests the adding a rib to the automata
 * If the operation fails, there will be thrown an exception
 *
*/
void Test_AddRib()
{
	cout << "Add rib...";
	Automata object;
	object.AddRib('!', true);
	assert(object.IsRib(0,2) && object.GetMarker(0, 2) == '!' && object.IsFinalState(0, 2));
	cout << "OK" << endl;
}

/**
 *
 * Tests the adding a number ribs (ribs to all beginning positions 
 * in the automata where should have a number) to the automata
 * If the operation fails, there will be thrown an exception
 *
*/
void Test_AddNumberRib()
{
	cout << "Add number rib...";
	Automata object;
	object.AddNumberRib(true);
	assert(object.IsRib(0, 20) && object.GetMarker(0, 20) == '3' && object.IsFinalState(0, 20));
	cout << "OK" << endl;
}

/**
 *
 * Tests the adding a lower case ribs (ribs to all beginning positions
 * in the automata where should have a lower case) to the automata
 * If the operation fails, there will be thrown an exception
 *
*/
void Test_AddLowerCaseRib()
{
	cout << "Add lower case rib...";
	Automata object;
	object.AddLowerCaseRib(true);
	assert(object.IsRib(0, 75) && object.GetMarker(0, 75) == 'j' && object.IsFinalState(0, 75));
	cout << "OK" << endl;
}

/**
 *
 * Tests the copying of an automata
 * If the operation fails, there will be thrown an exception
 *
*/
void Test_CopyAutomata()
{
	cout << "Copy automata...";
	Automata object;
	object.AddRib('!', true);

	Automata copy1(object), copy2;
	copy2 = copy1;

	assert(copy1.IsRib(0, 2) && copy1.GetMarker(0, 2) == '!' && copy1.IsFinalState(0, 2));
	assert(copy2.IsRib(0, 2) && copy2.GetMarker(0, 2) == '!' && copy2.IsFinalState(0, 2));
	cout << "OK" << endl;
}