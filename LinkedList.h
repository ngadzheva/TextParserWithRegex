/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Nevena Mihaylova Gadzheva
* @idnumber 61938
* @task 5
* @compiler VC
*
*/

#ifndef LINKEDLIST
#define LINKEDLIST

template<class DataType>
struct Node
{
	DataType data;
	Node* next;
};

template<class DataType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);

	void InsertFirst(DataType&);
	void InsertLast(DataType&);
	void InsertAt(int, DataType&);
	void RemoveFirst();
	void RemoveLast();
	void RemoveAt(int);
	void RemoveAll();

	bool IsEmpty() const;

	void IterStart(Node<DataType>* = NULL);

	Node<DataType>* Iterator()
	{
		Node<DataType>* temp = current;
		if (current)
			current = current->next;

		return temp;
	}


private:
	Node<DataType>* start, *end, *current;

	void Copy(const LinkedList&);
};

template<class DataType>
LinkedList<DataType>::LinkedList()
{
	start = end = NULL;
}

template<class DataType>
LinkedList<DataType>::~LinkedList()
{
	RemoveAll();
}

template<class DataType>
LinkedList<DataType>::LinkedList(const LinkedList& other)
{
	start = end = NULL;
	Copy(other);
}

template<class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		RemoveAll();
		Copy(other);
	}

	return *this;
}

template<class DataType>
void LinkedList<DataType>::InsertFirst(DataType& inputData)
{
	Node<DataType>* temp = new Node<DataType>;
	temp->data = inputData;
	tem->next = start;
	start = temp;

	if (!end)
		end = start;
}

template<class DataType>
void LinkedList<DataType>::InsertLast(DataType& inputData)
{
	if (!start)
	{
		InsertFirst(inputData);
		return;
	}

	end->next = new Node<DataType>;
	end = end->next;
	end->data = inputData;
	end->next = NULL;
}

template<class DataType>
void LinkedList<DataType>::InsertAt(int pos, DataType& inputData)
{
	if (pos < 1)
		return;

	if (pos == 1)
	{
		InsertFirst(inputData);
		return;
	}

	Node<DataType>* temp = start;
	int i = 2;
	while (i != pos && temp)
	{
		temp = temp->next;
		i++;
	}

	if (!temp)
		return;

	Node<DataType>* tmp = new Node<DataType>;
	tmp->data = inputData;
	tmp->next = temp->next;
	temp->next = tmp;

	if (temp == end)
		end = tmp;
}

template<class DataType>
void LinkedList<DataType>::RemoveFirst()
{
	if (!start)
		return;

	Node<DataType>* temp = start;
	start = start->next;
	delete temp;

	if (!start)
		end = NULL;
}

template<class DataType>
void LinkedList<DataType>::RemoveLast()
{
	if (!start)
		return;

	if (start == end)
	{
		delete start;
		start = end = NULL;
		return;
	}

	Node<DataType>* temp = start;
	while (start->next != end)
		start = start->next;

	start->next = NULL;
	delete end;
	end = temp;
}

template<class DataType>
void LinkedList<DataType>::RemoveAt(int pos)
{
	if (pos < 1)
		return;

	if (pos == 1)
	{
		RemoveFirst();
		return;
	}

	Node<DataType>* temp = start;

	if (!temp)
		return;

	int i = 2;
	while (i != pos && temp->next)
	{
		temp = temp->next;
		i++;
	}

	if (!temp->next)
		return;

	Node<DataType>* tmp = temp->next;
	temp->next = temp->next->next;
	delete tmp;

	if (tmp == end)
		end = temp;
}

template<class DataType>
void LinkedList<DataType>::RemoveAll()
{
	Node<DataType>* temp;

	while (start)
	{
		temp = start;
		start = start->next;
		delete temp;
	}

	end = NULL;
}

template<class DataType>
bool LinkedList<DataType>::IsEmpty() const
{
	return start == NULL;
}

template<class DataType>
void LinkedList<DataType>::IterStart(Node<DataType>* input)
{
	if (input)
		current = input;
	else
		current = start;
}

template<class DataType>
void LinkedList<DataType>::Copy(const LinkedList& other)
{
	Node<DataType>* temp = other.start;
	Node<DataType>* p;

	if (temp)
	{
		start = end = new Node<DataType>;
		while (temp)
		{
			end->data = temp->data;
			end->next = NULL;
			temp = temp->next;

			if (temp)
			{
				p = end;
				end = new Node<DataType>;
				p->link = end;
			}
		}
	}
	else
		start = end = NULL;
}
#endif 
