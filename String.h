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

#ifndef STRING
#define STRING


/** 
 * 
 * Declaration of a help class String which is implementing a pseudo string and is used from class Automata
 * 
*/
class String
{
public:

/** 
 * 
 * Constructors, destructor and copy assignment operator
 * 
*/
	String();
	~String();
	String(const String&);
	String& operator=(const String&);

/**
 * 
 * Returns a string
 * 
*/
	char* GetString() const;

/**
 * 
 * Predefined operators 
 * 
*/
	const char* operator=(const char*);
	char& operator[](int) const;
	friend String operator+(const String&, const char&);

/**
 * 
 * Prints the string
 * 
*/
	void Print() const;

private:
	char* symbol;
	int size;

/**
 * 
 * Help function for making a copy of the string
 * 
*/
	void Copy(const String&);
};
#endif
