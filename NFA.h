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

#ifndef NFA
#define NFA

#include"DynamicArray.h"
#include"Stack.h"

struct Transitions
{
	int vertexFrom, vertexTo;
	char transitionSymbol;
};

class NonFiniteAutomata
{
public:
	NonFiniteAutomata();
	~NonFiniteAutomata();
	NonFiniteAutomata(const NonFiniteAutomata&);
	NonFiniteAutomata& operator=(const NonFiniteAutomata&);

	int GetVertexCount() const;
	void SetVertex(int);
	void SetTransition(int, int, char);
	DynamicArray<Transitions> GetTransitions() const;
	void SetFinalState(int);
	int GetFinalState() const;

private:
	DynamicArray<int> vertex;
	DynamicArray<Transitions> transitions;
	int finalState;
};

#endif 