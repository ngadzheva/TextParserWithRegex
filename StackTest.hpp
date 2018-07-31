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

#include<iostream>
#include<assert.h>

using namespace std;

/**
 * 
 * Test functions for class Stack
 * 
*/

/**
 *
 * Tests the constructing of an empty stack
 * If the stack is not empty, exception will be thrown
 *
*/
void Test_CreateEmptyStack()
{
	cout << "Create empty stack from char objects...";
	Stack<char> object;
	assert(object.IsEmpty());
	cout << "OK" << endl;
}

/**
 *
 * Tests whether the function EmptyStack() works right
 * when the stack is empty
 * If it doesn't work right, the exception will be thrown
 * 
*/
void Test_EmptyStack()
{
	cout << "Empty stack...";
	Stack<char> object;

	assert(object.IsEmpty());
	cout << "OK" << endl;	
}

/**
 *
 * Tests whether the function EmptyStack() works right
 * when the stack is not empty
 * If it doesn't work right, the exception will be thrown
 *
*/
void Test_NotEmptyStack()
{
	cout << "Empty stack...";
	Stack<char> object;
	object.Push('a');

	assert(!object.IsEmpty());
	cout << "OK" << endl;
}

/**
 *
 * Tests whether the adding and removing an element from
 * the stack is processed right
 * If the stack is empty after adding an element, the removed 
 * element is not the same as the one which was added or the 
 * the stack is not empty after removing the element, the 
 * exception will be thrown
 *
*/
void Test_AddAndRemoveValue()
{
	cout << "Add and remove value...";
	Stack<char> object;
	object.Push('a');

	assert(!object.IsEmpty());

	char symbol = object.Pop();

	assert(symbol == 'a' && object.IsEmpty());
	cout << "OK" << endl;
}

/**
 *
 * Tests whether the value on the top of the stack is the same
 * as the last added one
 * If the value on the top of the stack is not the same as the 
 * last added one or the stack is empty, exception will be thrown
 *
*/
void Test_TopValue()
{
	cout << "Return the top value...";
	Stack<char> object;
	object.Push('a');

	char symbol = object.Top();

	assert(symbol == 'a' && !object.IsEmpty());
	cout << "OK" << endl;
}

/**
 * Tests whether the last added element is the first removed one
 * If the last added element is not the first removed one, 
 * exception will be thrown
 *
*/
void Test_RightSequence()
{
	cout << "Right sequence...";
	Stack<char> object;
	object.Push('a');
	object.Push('b');

	char symbol1 = object.Pop();
	char symbol2 = object.Pop();

	assert(symbol1 == 'b' && symbol2 == 'a');
	cout << "OK" << endl;
}

/**
 *
 * Tests the copying of a stack
 * If the operation fails, there will be thrown an exception
 *
*/
void Test_CopyStack()
{
	cout << "Copy stack...";
	Stack<char> object;
	object.Push('6');

	Stack<char> copy1(object), copy2;
	char symbol1 = copy1.Top();
	copy2 = copy1;
	char symbol2 = copy2.Top();

	assert(symbol1 == '6' && symbol2 == '6');
	cout << "OK" << endl;
}