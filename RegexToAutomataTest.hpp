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

#include"Stack.h"
#include"RegexToAutomata.h"
#include"Automata.h"

#include<iostream>

using namespace std;

/**
 *
 * Test functions for class RegexToAutomata
 *
*/

/**
 *
 * Tests whether the concatenation of two automatas is made right
 * If the concatenation of the two automata is made right,
 * then it will print the result.
 * Else there won't be printed anything.
 *
*/
void Test_Concatenation()
{
	cout << "Concatenation: ";

	RegexToAutomata object;
	Automata first, second, result;

	first.AddRib('a', true);
	second.AddRib('b', true);

	result = object.Concat(first, second);
	result.Search("test", "ab", 1);
}

/**
 *
 * Tests whether the union of two automatas is made right
 * If the union of the two automata is made right,
 * then it will print the result.
 * Else there won't be printed anything.
 *
*/
void Test_Union()
{
	cout << "Union: ";

	RegexToAutomata object;
	Automata first, second, result;

	first.AddRib('1', true);
	second.AddRib('2', true);
	
	result = object.Union(first, second);
	result.Search("test", "2", 1);
}

/**
 *
 * Tests whether the kleene star of an automata is made right
 * If the the operation is made right, then it will print the result.
 * Else there won't be printed anything.
 *
*/
void Test_Kleene()
{
	cout << "Kleene star: ";

	RegexToAutomata object;
	Automata automata, result;

	automata.AddRib('1', true);
	
	result = object.Kleene(automata);
	result.Search("test", "1111", 1);
}

/**
 *
 * Tests the converting from regular expression to automata
 * If the operation is made right, then it will print the result.
 * Else there won't be printed anything.
 *
*/
void Test_ReToAutomata()
{
	cout << "Regex to automata: " << endl;

	RegexToAutomata object;
	Automata result;
	
	result = object.ReToAutomata("(a*).b");
	result.Search("test1", "aaab", 1);

	result = object.ReToAutomata("1234");
	result.Search("test2", "1234", 1);

	result = object.ReToAutomata("(j|k)");
	result.Search("test3", "j", 1);

	result = object.ReToAutomata("\\a4");
	result.Search("test4", "d4", 1);

	result = object.ReToAutomata("d\\d");
	result.Search("test5", "d6", 1);

	result = object.ReToAutomata("d\\st");
	result.Search("test6", "d t", 1);
}