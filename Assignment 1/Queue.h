
#ifndef DEQUE_H_
#define DEQUE_H_

#include "header.h"

template <class object>
class Deque
{
public:

	Deque();
	~Deque();

	void Enqueue(const object& item);
	void Dequeue();
	object Front();
	int Size(){return size;};
	bool IsEmpty(){return head == NULL;};
	void PrintDeque();
	void PrintPalindromes();
	void ClearDeque();

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
	delete head;
	delete tail;
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
void Deque<object>::Dequeue()
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

		delete dataPtr;
		dataPtr = NULL;
		size--;
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
		std::cout << printNode->data << ", ";
		printNode = printNode->next;
	}
}

template <class object>
void Deque<object>::PrintPalindromes()
{
	node* printNode;
	printNode = head;

	if(IsEmpty())
	{
		std::cout << "The Deque is empty.\n";
	}
	while(printNode != NULL)
	{
		if(IsPalindrome(printNode->data))
		{
			std::cout << "This is a Palindrome:\n" << printNode->data << endl << endl;
		}
		else
		{
			std::cout << "This is not a Palindrome:\n" << printNode->data << endl << endl;
		}
	}

	printNode = printNode->next;
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
