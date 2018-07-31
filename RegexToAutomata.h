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

#ifndef REGEXTOAUTOMATA
#define REGEXTOAUTOMATA

#include "Automata.h"

/**
 *
 * Declaration of class RegexToAutomata which makes an automata from regular expression
 * The class uses class Automata and class Stack in order to make the automata
 *
*/

class RegexToAutomata
{
public:

/**
 *
 * Methods for making an automata from regular expression
 *
*/
	Automata Kleene(Automata);
	Automata Concat(Automata, Automata);
	Automata Union(Automata, Automata);
	Automata ReToAutomata(const char*);

/**
 *
 * Methods for checking whether a symbol is operand or upper case
 *
*/
	bool IsOperand(char) const;
	bool IsUpperCase(char) const;
	bool IsStarUnionOrConcatSymbol(char) const;
};
#endif 
