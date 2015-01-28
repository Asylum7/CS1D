/************************************************************************
* AUTHOR 		: James Davis
* ASSIGNMENT # 	: 1
* CLASS 		: CS1D
* SECTION 		: T Th 5:30pm
* DUE DATE 		: 1/27/2015
************************************************************************/
#include "header.h"

int main()
{
	Deque<char>strList[10];

	strList[0].FillDeque("dad");
	strList[1].FillDeque("radar");
	strList[2].FillDeque("Otto");
	strList[3].FillDeque("mom");
	strList[4].FillDeque("tigers");
	strList[5].FillDeque("A man, a plan, a canal, Panama");
	strList[6].FillDeque("Isn't this class cool?");
	strList[7].FillDeque("Was it a car or a cat I saw?");
	strList[8].FillDeque("Sit on a potato pan, Otis");
	strList[9].FillDeque("Saddleback is a great place to learn");

	for(int count = 0; count < 10; count ++)
	{
		PrintPalindrome(strList[count]);
	}

	return 0;
}
