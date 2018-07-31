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
#include<assert.h>
#include<stdexcept>

using namespace std;

#include"Stack.h"
#include"Automata.h"
#include"RegexToAutomata.h"

/**
 *
 * Implementation of class RegexToAutomata
 *
*/

/**
 *
 * Makes a concatenation of two automatas
 * 1. If the beginning state of the second automata (this on position (0,0)) 
 *    is final, then the final states of the first automata are final in the new automata. 
 *    Else the final states of the first automata are not final in the new automata
 * 2. Every final state rib of the first automata has to simulate the ribs 
 *    of the beginnig states of the second automata (the beginnig states 
 *    are on row 0). So we sets rib on position (j,k) where j is the column
 *    of the final state rib of the first automata and k is the column of 
 *    the beginning rib of the second automata.
 * 3. Every rib of two automatas is rib of the new automata
 *
 * @param first the first automata
 * @param second the second automata
 * @return 
 *    The function returns the concatenation of the two automatas
 * 
*/
Automata RegexToAutomata::Concat(Automata first, Automata second)
{
	Automata automata;
	automata = first;
	int sizeFirst = first.GetSize();

	if (!second.IsFinalState(0, 0))
	{
		for (int i = 0; i < sizeFirst; i++)
		{
			for (int j = 0; j < sizeFirst; j++)
				if (automata.IsRib(i, j) && automata.IsFinalState(i, j))
					automata.SetState(i, j, false);
		}
	}

	int sizeSecond = second.GetSize();
	for (int i = 0; i < sizeFirst; i++)
	{
		for (int j = 0; j < sizeFirst; j++)
		{
			if (first.IsRib(i, j) && first.IsFinalState(i, j))
			{
				for (int k = 1; k < sizeSecond; k++)
				{
					if (second.IsRib(0, k))
					{
						automata.SetRib(j, k);
						automata.SetMarker(j, k, second.GetMarker(0, k));
						automata.SetState(j, k, second.IsFinalState(0, k));
					}
				}
			}
		}
	}

	for (int i = 1; i < sizeSecond; i++)
	{
		for (int j = 1; j < sizeSecond; j++)
		{
			if (second.IsRib(i, j))
			{
				automata.SetRib(i, j);
				automata.SetMarker(i, j, second.GetMarker(i, j));
				automata.SetState(i, j, second.IsFinalState(i, j));
			}
		}
	}

	return automata;
}

/**
 *
 * Makes a Kleene star of an automata
 * 1. Makes the beginning state of the new automata final (this on position(0,0))
 * 2. Every rib of the automata is rib of the new automata
 * 3. Every final state of the automata and the beginning state of the new automata
 *    have to simulate the ribs of the beginning states of the old automata. 
 * 4. If some of the beginning states of the automata is final, we set rib in the new
 *    automata on position (i,i) where i is the column of the rib of the beginning state 
 *    of the old automata.
 * 5. For every other rib of the old automata which is final we set rib in the new automata
 *    on position (i,k) where i is the row of the rib of the old automata which is final and 
 *    k is the column of one of the beginning states of the old automata
 *
 * @param input the automata which should be made a Kleene star
 * @return 
 *     The function returns the Kleene star of the automata
 *
*/
Automata RegexToAutomata::Kleene(Automata input)
{
	Automata automata;
	automata = input;
	automata.SetState(0, 0, true);

	int size = input.GetSize();

	for (int i = 0; i < size; i++)
	{
		if (input.IsRib(0, i) && input.IsFinalState(0, i))
		{
			automata.SetRib(i, i);
			automata.SetMarker(i, i, input.GetMarker(0, i));
			automata.SetState(i, i, input.IsFinalState(0, i));
		}
	}

	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (input.IsRib(i, j) && input.IsFinalState(i, j))
			{
				for (int k = 1; k < size; k++)
				{
					if (input.IsRib(0, k))
					{
						automata.SetRib(i, k);
						automata.SetMarker(i, k, input.GetMarker(0, k));
						automata.SetState(i, k, input.IsFinalState(0, k));
					}
				}
			}
		}
	}

	return automata;
}

/**
 *
 * Makes union of two automatas
 * 1. Every rib of the two automatas is rib in the new automata. So we
 *    copy the first automata and then add the ribs of the second automata.
 *
 * @param first the first automata
 * @param second the second automata
 * @return 
 *      The function returns the or selection of the two automatas
 *
*/
Automata RegexToAutomata::Union(Automata first, Automata second)
{
	Automata automata;
	automata = first;

	int sizeSecond = second.GetSize();

	for (int i = 0; i < sizeSecond; i++)
	{
		for (int j = 0; j < sizeSecond; j++)
		{
			if (second.IsRib(i, j) && !automata.IsRib(i, j))
			{
				automata.SetRib(i, j);
				automata.SetMarker(i, j, second.GetMarker(i, j));
				automata.SetState(i, j, second.IsFinalState(i, j));
			}
		}
	}

	return automata;
}

/**
 *
 * Makes an automata from a regular expression
 * Implementation of sort of Thompson's algorithm(construction)
 *
 * @param fregularExpression the regular expression which should be made to automata
 * @return 
 *     The function returns the automata
 * @exception invalid_argument("Invalid regular expression!")
 *     If the regular expression has an syntax error, e.g. two operators one after other,
 *     more opening brackets than closing or more closing brackets than opening 
 *
*/
Automata RegexToAutomata::ReToAutomata(const char* regularExpression)
{
	Stack<char> operators;
	Stack<Automata> operands;

	char operatorSymbol;
	char currentSymbol;

	Automata operand1;
	Automata operand2;

	int regExprSize = strlen(regularExpression);

	int openBracket = 0;
	int closeBracket = 0;

	for (int i = 0; i < regExprSize; i++)
	{
		currentSymbol = regularExpression[i];

		if (IsOperand(currentSymbol))
		{
			if (currentSymbol == '\\' && i < regExprSize - 1 && regularExpression[i + 1] == 'a')
			{
				Automata newAutomata;
				newAutomata.AddLowerCaseRib(true);
				operands.Push(newAutomata);
				i++;

				if (i < regExprSize - 1 && IsOperand(regularExpression[i + 1]))
					operators.Push('.');
			}
			else if (currentSymbol == '\\' && i < regExprSize - 1 && regularExpression[i + 1] == 'd')
			{
				Automata newAutomata;
				newAutomata.AddNumberRib(true);
				operands.Push(newAutomata);
				i++;

				if (i < regExprSize - 1 && IsOperand(regularExpression[i + 1]))
					operators.Push('.');
			}
			else
			{
				if (currentSymbol == '\\' && i < regExprSize - 1 && regularExpression[i + 1] == 's')
				{
					currentSymbol = ' ';
					i++;
				}

				if (IsUpperCase(currentSymbol))
					currentSymbol = currentSymbol - 'A' + 'a';

				Automata newSymbol;
				newSymbol.AddRib(currentSymbol, true);
				operands.Push(newSymbol);

				if (i < regExprSize - 1 && IsOperand(regularExpression[i + 1]))
					operators.Push('.');
			}
		}
		else
		{
			if (currentSymbol == '*')
			{
				if (i < regExprSize - 1 && IsStarUnionOrConcatSymbol(regularExpression[i + 1]))
					throw invalid_argument("Invalid regular expression!");

				Automata starSymbol = operands.Pop();
				operands.Push(Kleene(starSymbol));
				operators.Pop();
				i++;
				closeBracket++;
			}
			else if (currentSymbol == '.')
			{
				if (i < regExprSize - 1 && IsStarUnionOrConcatSymbol(regularExpression[i + 1]))
					throw invalid_argument("Invalid regular expression!");

				operators.Push(currentSymbol);
			}
			else if (currentSymbol == '|')
			{
				if (i < regExprSize - 1 && IsStarUnionOrConcatSymbol(regularExpression[i + 1]))
					throw invalid_argument("Invalid regular expression!");

				if (operators.Top() == '.')
				{
					operand2 = operands.Pop();
					operand1 = operands.Pop();
					operands.Push(Concat(operand1, operand2));
					operators.Pop();
				}

				operators.Push(currentSymbol);
			}
			else if (currentSymbol == '(')
			{
				operators.Push(currentSymbol);

				openBracket++;
			}
			else
			{
				closeBracket++;

				operatorSymbol = operators.Pop();

				if (operatorSymbol == '(') continue;

				while (operatorSymbol != '(')
				{
					if (operatorSymbol == '.')
					{
						operand2 = operands.Pop();
						operand1 = operands.Pop();
						operands.Push(Concat(operand1, operand2));
					}
					else if (operatorSymbol == '|')
					{
						operand2 = operands.Pop();
						operand1 = operands.Pop();
						operands.Push(Union(operand1, operand2));
					}

					operatorSymbol = operators.Pop();
				}
			}
		}
	}

	assert(openBracket == closeBracket);

	if (!operators.IsEmpty())
	{
		while (!operators.IsEmpty())
		{
			operand2 = operands.Pop();
			operand1 = operands.Pop();
			operands.Push(Concat(operand1, operand2));
			operators.Pop();
		}
	}

	return operands.Top();
}

/**
 *
 * Checks whether a symbol is operand or not
 *
 * @param symbol the symbol which should be checked
 * @return
 *     true if the symbol is operand
 *     false if the symbol is not operand
 *
*/
bool RegexToAutomata::IsOperand(char symbol) const
{
	if (symbol != '(' && symbol != ')' && symbol != '*' && symbol != '|' && symbol != '.')
		return true;
	return false;
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
bool RegexToAutomata::IsUpperCase(char symbol) const
{
	if (symbol >= 65 && symbol <= 90)
		return true;
	return false;
}

/**
 *
 * Checks whether a symbol is star, union (|) or concatenation (.) symbol or not
 *
 * @param symbol the symbol which should be checked
 * @return
 *     true if the symbol is star, union (|) or concatenation (.) symbol
 *     false if the symbol is star, union (|) or concatenation (.) symbol
 *
*/
bool RegexToAutomata::IsStarUnionOrConcatSymbol(char symbol) const
{
	if (symbol == '*' | symbol == '|' | symbol == '.')
		return true;
	return false;
}