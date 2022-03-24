#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include"MGSimpleHead.h"

// Simple map of lAct meaning
// 1 = "+" 2 = "-" 3 = "*" 4 = "/"
// In order: Addition, substraction, multipltion, devidition


void Problem::CreateProblem()
{
	switch (lAction)
	{
	case 1:
	{
		nFirstI = rand() % (int)pow(10, lDif + 1) + 1;
		nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		break;
	}
	case 2:
	{
		do
		{
			nFirstI = rand() % (int)pow(10, lDif + 1) + 1;
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		} while (nSecondI > nFirstI);
		break;
	}
	case 3:
	{
		nFirstI = rand() % (int)pow(10, lDif) + 1;
		nSecondI = rand() % (int)pow(10, lDif) + 1;
		break;
	}
	case 4:
	{
		nFirstI = rand() % (int)pow(10, lDif + 1) + 1;
		do
		{
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		} while (nFirstI% nSecondI != 0 && (nSecondI != 1 && nSecondI != nFirstI));
		break;
	}
	}
	
}

char Problem::cCheckActionSymbol()
{
	switch (lAction)
	{
	case 1:
	{
		return '+';
		break;
	}
	case 2:
	{
		return '-';
		break;
	}
	case 3:
	{
		return '*';
		break;
	}
	case 4:
	{
		return '/';
		break;
	}
	}
}

void Problem::Display()
{
	CreateProblem();
	printf_s("%d %c %d = ", nFirstI, cCheckActionSymbol(), nSecondI);
}

