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

#ifndef QUERIES
#define QUERIES

#include"Automata.h"

/**
 * 
 * Declaration of class Queries which reads a file or a set of files from directory and a regular expression
 * The class uses class Automata and class RegexToAutomata in order to make an automata from the regular expression
 * and then to search in the file(s) for this regular expression
 * 
*/

class Queries
{
public:

/**
 * 
 * Default constructor
 * 
*/
	Queries();

/**
 *
 * Methods for reading the files and the regular expression, making an automata and validating the
 * regular expression
 *
*/
	void Read(const char*, const char*);
	void ReadFileAndSearch(const char*, const char*);
	void PrintFile(const char*) const;
	void MakeAutomata(const char*);
	bool CheckRegExpr(const char*) const;

private:
	Automata automata;
};
#endif 
