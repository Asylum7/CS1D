#include "header.h"
using namespace std;

bool IsPalindrome(Deque<char>palindrome)
{
	bool isPal = true;

	unsigned int count = 0;
	string compareStr;
	string reverseStr;

	for(count = 0; count < palindrome.Size(); count ++)
	{
		if(isalpha(palindrome.Front()))
		{
			compareStr[count] = toupper(palindrome.Dequeue());
		}
	}

	count = 0;

	while(isPal && count < compareStr.size())
	{
		if(compareStr[count] == compareStr[((compareStr.size()-count))-1])
		{
			count++;
		}
		else
		{
			isPal = false;
		}
	}

	return isPal;
}

void PrintPalindrome(Deque<char>palindrome)
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
