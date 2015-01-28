/************************************************************************
* AUTHOR 		: James Davis
* ASSIGNMENT # 	: 1
* CLASS 		: CS1D
* SECTION 		: T Th 5:30pm
* DUE DATE 		: 1/27/2015
************************************************************************/
#include "header.h"
using namespace std;

bool IsPalindrome(Deque<char>&palindrome)
{
	bool isPal = true;

	unsigned int count = 0;
	string compareStr;
	string reverseStr;

	Deque<char>paliForward;
	Deque<char>paliReverse;

	for(count = 0; count < palindrome.Size(); count ++)
	{
		if(isalpha(palindrome.Front()))
		{
			paliForward.Enqueue(toupper(palindrome.Front()));
			paliReverse.RevEnQ(toupper(palindrome.Front()));
		}
		palindrome.Enqueue(palindrome.Dequeue());
	}

	count = 0;

	while(isPal && count < paliForward.Size())
	{
		if(paliForward.Front() == paliReverse.Front())
		{
			paliForward.Dequeue();
			paliReverse.Dequeue();
		}
		else
		{
			isPal = false;
		}
	}

	return isPal;
}

void PrintPalindrome(Deque<char>&palindrome)
{

	if(palindrome.IsEmpty())
	{
		std::cout << "The Deque is empty.\n";
	}
	else if(IsPalindrome(palindrome))
	{
		palindrome.PrintDeque();
		std::cout << "\nIS a palindrome!" << endl << endl;
	}
	else
	{
		palindrome.PrintDeque();
		std::cout << "\nIs NOT a Palindrome!" << endl << endl;
	}
}
