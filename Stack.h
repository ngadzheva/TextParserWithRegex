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


#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include<stdexcept>

/**
 *
 * Implementation of a template of a class, which shows a linked stack
 * 
*/
template<class DataType>
class Stack
{
	struct Box
	{
		DataType data;  
		Box* next;      
	};

public:

/** 
 * 
 * Constructors, destructor and copy assignment operator
 * 
*/
	Stack();
	~Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);


/**
 * 
 * Adding and removing elements and returning the element on the top of the stack
 * 
*/
	void Push(const DataType&);
	DataType Pop();
	DataType Top() const;

/**
 * 
 * Information methods
 * 
*/
	int GetSize() const;
	bool IsEmpty() const;

private:
	Box* top;      
	int usedSize;  

/**
 * 
 * Help functions
 * 
*/
	void Init();
	void Remove();
	void Copy(const Stack&);
};

/**
 * 
 * Constructs an empty stack
 * @see Init()
 * 
*/
template<class DataType>
Stack<DataType>::Stack()
{
	Init();
}

/**
 * 
 * Destructor
 * @see Remove()
 * 
*/
template<class DataType>
Stack<DataType>::~Stack()
{
	Remove();
}

/**
 * 
 * Copy constructor
 * @see Init()
 * @see void Copy(const Stack& other)
 * @exception bad_alloc
 *      If the copy operation fails
 * 
*/
template<class DataType>
Stack<DataType>::Stack(const Stack& other)
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
 * @see void Copy(cost Stack& other)
 * @exception bad_alloc
 *      If the copy operation fails
 * 
*/
template<class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& other)
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
 * Adds an element on top of the stack
 *
 * @param element the element which will be added
 * 
*/
template<class DataType>
void Stack<DataType>::Push(const DataType& element)
{
	
	Box* newBox = top;
	top = new Box;
	top->data = element;
	top->next = newBox;

	usedSize++;
}

/**
 * 
 * Removes and returns the element on top of the stack
 * 
*/
template<class DataType>
DataType Stack<DataType>::Pop()
{ 
	assert(top);
	
	Box* newBox;

	DataType element = top->data;
	newBox = top;
	top = top->next;

	delete newBox;

	usedSize--;

	return element;
	
}

/**
 *
 * Returns the element on the top of the stack
 *
*/
template<class DataType>
DataType Stack<DataType>::Top() const
{
	assert(usedSize != 0);

	return top->data;
}

/**
 * 
 * Returns the number of elements currunetly stored in the stack
 * 
*/
template<class DataType>
int Stack<DataType>::GetSize() const
{
	return usedSize;
}

/**
 * 
 * Checks whether the stack is empty
 * @return
 *     true if the stack is empty (uesedSize == 0)
 *     false if the stack is not empty (usedSize != 0)
 * 
*/
template<class DataType>
bool Stack<DataType>::IsEmpty() const
{
	return usedSize == 0;
}

/**
 * 
 * Initializes the data members of the object
 * 
*/
template<class DataType>
void Stack<DataType>::Init()
{
	top = 0;
	usedSize = 0;
}

/** 
 * 
 * Removes all elements in the stack and frees the allocated memory
 * 
*/
template<class DataType>
void Stack<DataType>::Remove()
{
	Box* newBox;   

	while (top)            
	{
		newBox = top;      
		top = top->next;   
		delete newBox;     
	}

	Init();
}

/**
 * 
 * Makes a copy of the stack
 * @param other the stack which will be copied
 * @exception bad_alloc
 *      If the copy operation fails
 * 
*/
template<class DataType>
void Stack<DataType>::Copy(const Stack& other)
{
	/**
	 * Checking whether the stack is empty
	*/
	assert(IsEmpty()); 

	/**
	 * If the stack is empty, there is nothing for copying
	*/
	if (!other.top) 
		return;  
	try
	{
		Box* newBox = other.top;
		top = new Box;
		Box* bottom = top;
			top->data = newBox->data;
		newBox = newBox->next;

		while (newBox)
		{
			bottom->next = new Box;
			bottom = bottom->next;
			bottom->data = newBox->data;
			newBox = newBox->next;
		}

		bottom->next = NULL;
	}
	catch (bad_alloc&)
	{
		Remove();

		throw;
	}
}

#endif