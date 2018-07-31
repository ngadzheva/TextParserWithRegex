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
#include<fstream>
#include<stdexcept>
#include"dirent.h"

using namespace std;

#include"Queries.h"
#include"RegexToAutomata.h"
#include"Stack.h"

/**
 *
 * Implementation of class Querries
 *
*/

/**
 *
 * Constructs an empty automata
 *
*/
Queries::Queries()
{
	automata.Init();
}

/**
 *
 * Reads the file(s) and the regular expression.
 * Validates the regular expression and if it's valid
 * makes an automata and searches for the regular expression
 * in the file(s).
 * If the regular expression is the empty string, then prints all
 * lines of the file(s).
 * If the regular expression contains not valid symbols, the function 
 * prints a message for error
 * 
 * @param inputFile 
 *      The name of the file or directory
 * @param inputRegExpr
 *      The regular expression
 * @see void CheckRegExpr(const char* regExpr)
 * @see void PrintFile(const char* fileName) const
 * @see void ReadFileAndSearch(const char* inputFileName, const char* regExpr)
 *
*/
void Queries::Read(const char* inputFile, const char* inputRegExpr)
{
	if (CheckRegExpr(inputRegExpr))
	{
		if (inputRegExpr == "\e")
			PrintFile(inputFile);
		else
			ReadFileAndSearch(inputFile, inputRegExpr);
	}
	else
		cout << "Invalid regular expression!" << endl;
}


/**
 *
 * Reads the file(s) and the regular expression,
 * makes an automata and searches for the regular expression
 * in the file(s).
 * If the file(s) can't be opened, prints a message for this.
 *
 * @param inputFileName
 *      The name of the file or directory
 * @param regExpr
 *      The regular expression
 * @see void MakeAutomata(const char* regExpr)
 * @see void Search(const char* fileName, const char* fileLine, int lineCount) in class Automata
 *
*/
void Queries::ReadFileAndSearch(const char* inputFileName, const char* regExpr)
{
	MakeAutomata(regExpr);

	char fileLine[100];
	int lineCount = 0;

	DIR* dir = NULL;
	struct dirent* dirFiles = NULL;
	dir = opendir(inputFileName);

	ifstream file(inputFileName, ios::in);
	if (file.is_open())
	{
		while (file.good())
		{
			file.getline(fileLine, sizeof(file));
			lineCount++;
			automata.Search(inputFileName, fileLine, lineCount);
		}
	}
	else if (dir)
	{
		file.close();
		while (dirFiles = readdir(dir))
		{
			if (strcmp(dirFiles->d_name, ".") != 0 && strcmp(dirFiles->d_name, "..") != 0)
			{

				ifstream dirFile(dirFiles->d_name, ios::in);
				if (dirFile.is_open())
				{
					while (dirFile.good())
					{
						dirFile.getline(fileLine, sizeof(file));
						lineCount++;
						automata.Search(dirFiles->d_name, fileLine, lineCount);
					}
				}
				else
					cout << "Couldn't open the file!" << endl;
				dirFile.close();
			}
		}
	}
	else
		cout << "Couldn't open the file or wrong path!" << endl;
	
	closedir(dir);
	file.close();
}

/**
 *
 * Prints the whole file(s)
 * If the file(s) can't be opened, prints a message for this
 *
 * @param inputFileName
 *      The name of the file or directory
 *
*/
void Queries::PrintFile(const char* fileName) const
{
	char fileLine[100];
	int lineCount = 0;

	DIR* dir = NULL;
	struct dirent* dirFiles = NULL;
	dir = opendir(fileName);

	ifstream file(fileName, ios::in);
	if (file.is_open())
	{
		while (file.good())
		{
			file.getline(fileLine, sizeof(file));
			lineCount++;
			cout << fileName << ":" << lineCount << ":" << fileLine << endl;
		}
	}
	else if (dir)
	{
		file.close();
		while (dirFiles = readdir(dir))
		{
			if (strcmp(dirFiles->d_name, ".") != 0 && strcmp(dirFiles->d_name, "..") != 0)
			{

				ifstream dirFile(dirFiles->d_name, ios::in);
				if (dirFile.is_open())
				{
					while (dirFile.good())
					{
						dirFile.getline(fileLine, sizeof(file));
						lineCount++;
						cout << dirFiles->d_name << ":" << lineCount << ":" << fileLine << endl;
					}
				}
				else
					cout << "Couldn't open the file!" << endl;
				dirFile.close();
			}
		}
	}
	else
		cout << "Couldn't open the file or wrong path!" << endl;

	closedir(dir);
	file.close();
}

/**
 *
 * Makes an automata from the regular expression
 * 
 * @param regExpr the regular expression
 * @see Automata ReToAutomata(const char* regularExpression) in class RegexToAutomata
 *
*/
void Queries::MakeAutomata(const char* regExpr)
{
	RegexToAutomata regex;
	automata = regex.ReToAutomata(regExpr);
}

/**
 *
 * Validates the regular expression
 *
 * @param regExpr the regular expression
 * @return
 *    true if the regular expression contains valid symbols
 *    false if the regular expression contains not valid symbol
 *
*/
bool Queries::CheckRegExpr(const char* regExpr)const
{
	int i = 0;
	int size = strlen(regExpr) - 1;

	while (i < size && regExpr[i] >= 33 && regExpr[i] <= 126)
		i++;

	if (regExpr[i] < 33 || regExpr[i] > 126)
		return false;

	return true;
}