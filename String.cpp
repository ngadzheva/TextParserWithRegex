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

#include "stdafx.h"

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<assert.h>
#include<stdexcept>

using namespace std;

#include "String.h"

/**
 *
 * Implementation of class String
 *
*/

/**
 *
 * Constructs an empty char* array
 *
*/
String::String()
{
	size = 0;
	symbol = NULL;
}

/**
 *
 * Destructor
 *
*/
String::~String()
{
	if(size != 0)
		delete[] symbol;
}

/**
 * 
 * Copy constructor
 * @param other the string which will be copied
 * @see void Copy(const String& other)
 * @exception bad_alloc
 *      If the copy operation fails
 *
*/
String::String(const String& other)
{
	if (other.symbol)
	{
		Copy(other);
	}
	else
	{
		symbol = NULL;
		size = 0;
	}
}

/**
 *
 * Assignment operator
 * The operator frees the currently allocated memory and then performs the copying
 * 
 * @param other the string which will be copied
 * @see void Copy(const String& other)
 * @exception bad_alloc
 *      If the copy operation fails
 *
*/
String& String::operator=(const String& other)
{
	if (other.symbol)
	{
		{
			if (other.symbol != symbol)
			{
				if (symbol)
					delete[] symbol;
				Copy(other);
			}
		}
	}
	else if (symbol)
	{
		delete[] symbol;
		symbol = NULL;
		size = 0;
	}

	return *this;
}

/**
 * 
 * Assignment operator for char* object
 * @param other the char* object which will be copied
 * @exception bad_alloc
 *      If the copy operation fails
 *
*/
const char* String::operator=(const char* other)
{
	try
	{
		if (other)
		{
			if (other != symbol)
			{
				if (symbol)
					delete[] symbol;
				size = strlen(other);
				symbol = new char[size + 1];
				for (int i = 0; i < size; i++)
				{
					symbol[i] = other[i];
				}
			}
		}
		else if (symbol)
		{
			delete[] symbol;
			symbol = NULL;
			size = 0;
		}

		return symbol;
	}
	catch (bad_alloc&)
	{
		throw;
	}
}

/** 
 * 
 * Returns the string
 *
*/
char* String::GetString() const
{
	return symbol;
}

/**
 *
 * Constant operation function for indexing
 *
*/
char& String::operator[](int index) const
{
	return symbol[index];
}

/**
 *
 * Operation function for adding a const char object to the char* array using +
 * @param left the char* array to which the char object will be added
 * @param right the char object which will be added to the char* array
 * @exception bad_alloc
 *      If the concatenation operation fails
 *
*/
String operator+(const String& left, const char& right)
{
	String newString;
	int newSize = 0;

	try
	{
		newString.symbol = new char[left.size + 2];

		for (int i = 0; i < left.size; i++)
		{
			newString.symbol[i] = left.symbol[i];
			newSize++;
		}

		newString.symbol[newSize] = right;
		newSize++;

		newString[newSize] = NULL;
		newString.size = newSize;

		return newString;
	}
	catch (bad_alloc&)
	{
		throw;
	}
}

/**
 * 
 * Makes a copy of a string
 * @param other the string which will be copied
 * @exception bad_alloc
 *      If the copy operation fails
 * 
*/
void String::Copy(const String& other)
{
	try
	{
		symbol = new char[other.size + 1];
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			symbol[i] = other.symbol[i];
		}
	}
	catch (bad_alloc&)
	{
		throw;
	}
}

/**
 *
 * Prints the string
 * 
*/
void String::Print() const
{
	for (int i = 0; i < size; i++)
	{
		if (symbol[i] >= 32 && symbol[i] <= 126)
			cout << symbol[i];
	}

	cout << endl;
}