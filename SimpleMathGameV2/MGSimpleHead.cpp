#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include"MGSimpleHead.h"

// Simple map of lAct meaning
// 1 = "+" 2 = "-" 3 = "*" 4 = "/"
// In order: Addition, substraction, multipltion, devidition


void Problem::CreateProblem(uint16_t lDifficult, uint16_t lAct)
{
	switch (lAct)
	{
	case 1:
	{
		nFirstI = rand() % (int)pow(10, lDifficult + 1) + 1;
		nSecondI = rand() % (int)pow(10, lDifficult + 1) + 1;
		break;
	}
	case 2:
	{
		do
		{
			nFirstI = rand() % (int)pow(10, lDifficult + 1) + 1;
		} while (nSecondI > nFirstI);
		break;
	}
	case 3:
	{

		break;
	}
	case 4:
	{

		break;
	}
	}
	
}

void Problem::Display()
{
	char cAct = ' ';
	switch (lAction)
	{
	case 1:
	{
		cAct = '+';
		break;
	}
	case 2:
	{
		cAct = '-';
		break;
	}
	case 3:
	{
		cAct = '*';
		break;
	}
	case 4:
	{
		cAct = '/';
		break;
	}
	}
	printf_s("%d %c %d = ", nFirstI, cAct, nSecondI);
}

