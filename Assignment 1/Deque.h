
#ifndef DEQUE_H_
#define DEQUE_H_

#include "header.h"
using namespace std;

template <class object>
class Deque
{
public:

	Deque();
	~Deque();

	void   FillDeque(string palindrome);
	void   Enqueue(const object& item);
	object Dequeue();
	void   RevEnQ(const object& item);
	object RevDeQ();
	object Front();
	int    Size(){return size;};
	bool   IsEmpty(){return head == NULL;};
	void   PrintDeque();
	void   ClearDeque();

private:

	struct node
	{
		object data;
		node* prev;
		node* next;
	};

	node* head;
	node* tail;
	int size;
};

template <class object>
Deque<object>::Deque()
: head(NULL), tail(NULL), size(0)
{ }

template <class object>
Deque<object>::~Deque()
{
	while(!IsEmpty())
	{
		Dequeue();
	}
}

template <class object>
void  Deque<object>::FillDeque(string palindrome)
{
	for(int index = 0; index < palindrome.size(); index ++)
	{
		Enqueue(palindrome[index]);
	}
}

template <class object>
void Deque<object>::Enqueue(const object& item)
{
	node* dataPtr = new node;
	dataPtr->data = item;
	dataPtr->prev = NULL;
	dataPtr->next = NULL;

	if (!IsEmpty())
	{
		tail->next = dataPtr;
		dataPtr->prev = tail;
		tail = dataPtr;
	}
	else
	{
		head = dataPtr;
		tail = dataPtr;
	}
	size++;
	dataPtr = NULL;
}

template <class object>
object Deque<object>::Dequeue()
{
	object frontData;
	if(!IsEmpty())
	{
		node* dataPtr = head;

		if(head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		frontData = dataPtr->data;
		delete dataPtr;
		dataPtr = NULL;
		size--;
		return frontData;
	}
	else
	{
		std::cout << "The Deque is empty, cannot dequeue!";
	}
}

template <class object>
void Deque<object>::RevEnQ(const object& item)
{
	node* dataPtr = new node;
	dataPtr->data = item;
	dataPtr->prev = NULL;
	dataPtr->next = NULL;

	if (!IsEmpty())
	{
		head->prev = dataPtr;
		dataPtr->next = head;
		head = dataPtr;
	}
	else
	{
		head = dataPtr;
		tail = dataPtr;
	}
	size++;
	dataPtr = NULL;
}

template <class object>
object Deque<object>::RevDeQ()
{
	object backData;
	if(!IsEmpty())
	{
		node* dataPtr = tail;

		if(head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}

		backData = dataPtr->data;
		delete dataPtr;
		dataPtr = NULL;
		size--;
		return backData;
	}
	else
	{
		std::cout << "The Deque is empty, cannot dequeue!";
	}
}

template <class object>
object Deque<object>::Front()
{
	if(!IsEmpty())
	{
		return head->data;
	}
	else
	{
		std::cout << "Nobody in FRONT, the Deque is empty!!";
	}
}

template <class object>
void Deque<object>::PrintDeque()
{
	node* printNode;
	printNode = head;

	if(IsEmpty())
	{
		std::cout << "The Deque is empty.\n";
	}
	while(printNode != NULL)
	{
		std::cout << printNode->data;
		printNode = printNode->next;
	}
}


template <class object>
void Deque<object>::ClearDeque()
{
	while(!IsEmpty())
	{
		Dequeue();
	}
}

#endif /* Deque_H_ */
