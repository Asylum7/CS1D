#include "header.h"

bool IsPalindrome(string aString)
{
	bool isPal = true;

	int count = 0;
	int letter = 0;
	string compareStr;
	string reverseStr;

	for(count = 0; count < aString.size(); count ++)
	{
		if(isalpha(aString[count]))
		{
			compareStr[count] = aString[letter];
			letter++;
		}
	}

	count = 0;

	while(isPal && count < compareStr.size())
	{
		if(compareStr[count] == compareStr[(compareStr.size()-count)])
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
