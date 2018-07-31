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

#ifndef AUTOMATA
#define AUTOMATA

/**
 *
 * Declaration of class Automata which makes an automata and searches for a regular expression
 * The automata is represented with adjacency matrix which elements are the objects of struct Edge
 *
*/
class Automata
{
	struct Edge
	{
		char marker;
		bool isFinalState;
		bool rib;
	};
public:

/**
 *
 * Constructor, destructor, copy constructor and assignmened operator
 *
*/
	Automata();
	~Automata();
	Automata(const Automata&);
	Automata& operator=(const Automata&);

/**
 *
 * Getters and setters
 *
*/
	char GetMarker(int, int) const;
	void SetMarker(int, int, char);

	bool IsRib(int, int) const;
	void SetRib(int, int);

	bool IsFinalState(int, int) const; 
	void SetState(int, int, bool);

	int GetSize() const;

/**
 *
 * Other methods
 *
*/
	void AddRib(char, bool);
	void AddNumberRib(bool);
	void AddLowerCaseRib(bool);
	void Search(const char*, char*, int);
	bool IsUpperCase(char) const;

	void Init();

private:
	Edge** adjacencyMatrix;
	int vertexCount;

/**
 *
 * Help functions
 *
*/
	void Remove();
	void Copy(const Automata&);
};
#endif 