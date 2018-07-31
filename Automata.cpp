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

#include"stdafx.h"

#include<string.h>
#include<iostream>
#include<stdexcept>
#include<assert.h>

using namespace std;

#include"Automata.h"
#include"String.h"

/**
 *
 * Declaration of class Automata
 *
*/

const int MAX_SIZE = 96;
const int FIND_POSITION = 31;
const int START_NUMBER_POSITION = 17;
const int END_NUMBER_POSITION = 26;
const int START_LOWER_CASE_POSITION = 66;
const int END_LOWER_CASE_POSITION = 91;

/**
 *
 * Constructs an empty automata
 * @see Init()
 *
*/
Automata::Automata()
{
	Init();
}

/**
 *
 * Desructor
 * @see Remove()
 *
*/
Automata::~Automata()
{
	Remove();
}

/**
 *
 * Makes a copy of the automata
 * 
 * @see Init()
 * @see void Copy(const Automata& other)
 * @exception bad_alloc
 *     If the copy operation fails
 *
*/
Automata::Automata(const Automata& other)
{
	Init();
	Copy(other);
}

/**
 *
 * Assignment operator
 * The operator frees the currently allocated memory and then performs the copying
 *
 * @see Remove()
 * @see void Copy(const Automata& other)
 * @exception bad_alloc
 *      If the copy operation fails
 *
*/
Automata& Automata::operator=(const Automata& other)
{
	if (this != &other)
	{
		Remove();
		Copy(other);
	}

	return *this;
}

/**
 *
 * Returns the marker of the automata on position (i,j)
 * 
 * @param i the row of the automata
 * @param j the column of the automata
 *
*/
char Automata::GetMarker(int i, int j) const
{
	return adjacencyMatrix[i][j].marker;
}

/**
 *
 * Sets a marker of the automata on position (i,j)
 *
 * @param i the row of the automata
 * @param j the column of the automata
 * @param data the marker which should be set
 *
*/
void Automata::SetMarker(int i, int j, char data)
{
	adjacencyMatrix[i][j].marker = data;
}

/**
 *
 * Checks if there is a rib on position (i,j)
 *
 * @param i the row of the automata
 * @param j the column of the automata
 * @return
 *     true if there is a rib on position (i,j)
 *     false if there isn't a rib on position (i,j)
 *
*/
bool Automata::IsRib(int i, int j) const
{
	return adjacencyMatrix[i][j].rib;
}

/**
 *
 * Sets a rib of the automata on position (i,j)
 *
 * @param i the row of the automata
 * @param j the column of the automata
 *
*/
void Automata::SetRib(int i, int j)
{
	adjacencyMatrix[i][j].rib = true;
}

/**
 *
 * Checks whether the rib on position (i,j) is final
 *
 * @param i the row of the automata
 * @param j the column of the automata
 * @return
 *      true if the rib on position (i,j) is final
 *      false if the rib on position (i,j) is not final
 *
*/
bool Automata::IsFinalState(int i, int j) const
{
	return adjacencyMatrix[i][j].isFinalState;
}

/**
 *
 * Sets a final state on position (i,j)
 *
 * @param i the row of the automata
 * @param j the column of the automata
 *
*/
void Automata::SetState(int i, int j, bool state)
{
	adjacencyMatrix[i][j].isFinalState = state;
}

/**
 *
 * Returns the size of the adjacency matrix of the automata
 *
*/
int Automata::GetSize() const
{
	return vertexCount;
}

/**
 *
 * Adds a rib(element) on position (0,position) where position is the ASCII 
 * code of the symbol(element) which will be added to the automata - FIND_POSITION
 *
 * @param symbol the symbol(element) which will be added to the automata
 * @param state the state of the rib which is added to the automata
 * @ exception bad_alloc
 *     If the adding operation fails
 *
*/
void Automata::AddRib(char symbol, bool state)
{
	try
	{
		int position = (int)symbol - FIND_POSITION;

		assert(adjacencyMatrix[0][position].rib == false);

		adjacencyMatrix[0][position].rib = true;
		adjacencyMatrix[0][position].marker = symbol;
		adjacencyMatrix[0][position].isFinalState = state;
	}
	catch (bad_alloc&)
	{
		Remove();
		Init();

		throw;
	}
}

/**
 *
 * Adds a rib(element) on positions (0,i) where i is the ASCII
 * code of all number symbols - FIND_POSITION
 *
 * @param symbol the symbol(element) which will be added to the automata
 * @param state the state of the rib which is added to the automata
 * @ exception bad_alloc
 *     If the adding operation fails
 *
*/
void Automata::AddNumberRib(bool state)
{
	char number = '0';
	try
	{
		for (int i = START_NUMBER_POSITION; i < END_NUMBER_POSITION; i++)
		{
			assert(adjacencyMatrix[0][i].rib == false);

			adjacencyMatrix[0][i].rib = true;
			adjacencyMatrix[0][i].marker = number;
			adjacencyMatrix[0][i].isFinalState = state;

			number++;
		}
	}
	catch (bad_alloc&)
	{
		Remove();
		Init();

		throw;
	}
}

/**
 *
 * Adds a rib(element) on positions (0,i) where i is the ASCII
 * code of all lower case symbols - FIND_POSITION
 *
 * @param symbol the symbol(element) which will be added to the automata
 * @param state the state of the rib which is added to the automata
 * @ exception bad_alloc
 *     If the adding operation fails
 *
*/
void Automata::AddLowerCaseRib(bool state)
{
	char lowerCase = 'a';
	try
	{
		for (int i = START_LOWER_CASE_POSITION; i < END_LOWER_CASE_POSITION; i++)
		{
			assert(adjacencyMatrix[0][i].rib == false);

			adjacencyMatrix[0][i].rib = true;
			adjacencyMatrix[0][i].marker = lowerCase;
			adjacencyMatrix[0][i].isFinalState = state;

			lowerCase++;
		}
	}
	catch (bad_alloc&)
	{
		Remove();
		Init();

		throw;
	}
}

/**
*
* Searches for regular expression in the automata 
* If the regular expression is found, prints the name of the file,
* the line where it's found and the found expression 
*
* @param fileName the name of the file where we search
* @param fileLine the line from the file where we search
* @param lineCount the number of the line of the file where we search
*
*/
void Automata::Search(const char* fileName, char* fileLine, int lineCount)
{
	int row = 0;
	int column;
	int size = strlen(fileLine);
	char symbol;

	String expression;
	expression = "";

	for (int i = 0; i < size; i++)
	{
		if (IsUpperCase(fileLine[i]))
			symbol = fileLine[i] - 'A' + 'a';
		else
			symbol = fileLine[i];

		column = (int)symbol - FIND_POSITION;

		if (i == 0 && !adjacencyMatrix[row][column].rib)
			break;

		if (adjacencyMatrix[row][column].rib)
		{
			expression = expression + fileLine[i];

			if (adjacencyMatrix[row][column].isFinalState)
			{
				if (IsUpperCase(fileLine[i + 1]))
					symbol = fileLine[i + 1] - 'A' + 'a';
				else
					symbol = fileLine[i + 1];

				if (symbol == adjacencyMatrix[column][column].marker)
					row = column;

				if (i == size - 1)
				{
					cout << fileName << ":" << lineCount << ":";
					expression.Print();
					expression = "";
					row = 0;
				}
			}
			else
			{
				row = column;

				if (IsUpperCase(fileLine[i + 1]))
					symbol = fileLine[i + 1] - 'A' + 'a';
				else
					symbol = fileLine[i + 1];

				column = int(symbol) - FIND_POSITION;

				if (!adjacencyMatrix[row][column].rib)
				{
					row = 0;
					expression = "";
				}
			}
		}
		else
			break;
	}
}

/**
 *
 * Checks whether a symbol is upper case or not
 *
 * @param symbol the symbol which should be checked
 * @return
 *     true if the symbol is upper case
 *     false if the symbol is not upper case
*
*/
bool Automata::IsUpperCase(char symbol) const
{
	if (symbol >= 65 && symbol <= 90)
		return true;
	return false;
}


/**
 *
 * Help function for initializing the automata
 * Constructs an empty adjacency matrix with 
 * MAX_SIZE rows and columns.
 * There is a rib on position (0,0) because this
 * is the beginning state of every automata.
 *
*/
void Automata::Init()
{
	vertexCount = MAX_SIZE;
	adjacencyMatrix = new Edge*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		adjacencyMatrix[i] = new Edge[vertexCount];
		for (int j = 0; j < vertexCount; j++)
		{
			if (i == 0 && j == 0)
			{
				adjacencyMatrix[i][j].rib = true;
				adjacencyMatrix[i][j].marker = NULL;
				adjacencyMatrix[i][j].isFinalState = false;
			}
			else
			{
				adjacencyMatrix[i][j].rib = false;
				adjacencyMatrix[i][j].marker = NULL;
				adjacencyMatrix[i][j].isFinalState = false;
			}
		}
	}
}

/**
 *
 * Help function for deleting the automata
 *
*/
void Automata::Remove()
{
	for (int i = 0; i < vertexCount; i++)
		delete[] adjacencyMatrix[i];
	delete[] adjacencyMatrix;
}

/**
 *
 * Help function for making a copy of the automata
 * @param other the automata which we copy
 * @ exception bad_alloc
 *     If the copy operation fails
 *
*/
void Automata::Copy(const Automata& other)
{
	try
	{
		vertexCount = other.vertexCount;
		adjacencyMatrix = new Edge*[vertexCount];
		for (int i = 0; i < vertexCount; i++)
		{
			adjacencyMatrix[i] = new Edge[vertexCount];
			for (int j = 0; j < vertexCount; j++)
			{
				adjacencyMatrix[i][j].rib = other.adjacencyMatrix[i][j].rib;
				adjacencyMatrix[i][j].isFinalState = other.adjacencyMatrix[i][j].isFinalState;
				adjacencyMatrix[i][j].marker = other.adjacencyMatrix[i][j].marker;
			}
		}
	}
	catch (bad_alloc&)
	{
		Remove();
		Init();

		throw;
	}
}