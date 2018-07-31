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

#include<iostream>

using namespace std;

#include"DynamicArray.h"
#include"Stack.h"
#include"NFA.h"

NonFiniteAutomata::NonFiniteAutomata()
{
	vertex.Init();
	transitions.Init();
	finalState = 0;
}

NonFiniteAutomata::~NonFiniteAutomata()
{
	vertex.~DynamicArray();
	transitions.~DynamicArray();
}

NonFiniteAutomata::NonFiniteAutomata(const NonFiniteAutomata& other)
{
	vertex.Copy(other.vertex);
	transitions.Copy(other.transitions);
	finalState = other.finalState;
}

NonFiniteAutomata& NonFiniteAutomata::operator=(const NonFiniteAutomata& other)
{
	if (this != &other)
	{
	/*	vertex.Remove();
		transitions.Remove();
		vertex.Copy(other.vertex);
		transitions.Copy(other.transitions);
		finalState = other.finalState;*/
	}
	return *this;
}

int NonFiniteAutomata::GetVertexCount() const
{
	return vertex.GetSize();
}

void NonFiniteAutomata::SetVertex(int vertexCount)
{
	for (int i = 0; i < vertexCount; i++)
		vertex.Add(i);
}

void NonFiniteAutomata::SetTransition(int vertexFrom, int vertexTo, char transitionSymbol)
{
	Transitions newTransition;
	newTransition.vertexFrom = vertexFrom;
	newTransition.vertexTo = vertexTo;
	newTransition.transitionSymbol = transitionSymbol;
	transitions.Add(newTransition);
}

DynamicArray<Transitions> NonFiniteAutomata::GetTransitions() const
{
	return transitions;
}

void NonFiniteAutomata::SetFinalState(int inputFinalState)
{
	finalState = inputFinalState;
}

int NonFiniteAutomata::GetFinalState() const 
{
	return finalState;
}