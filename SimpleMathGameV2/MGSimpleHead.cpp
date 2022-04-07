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
		nFirstI = rand() % (int)pow(10, lDif + 1) + 1; // May change from '1' to (int)pow(10, lDif - 1); 
		nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		break;
	}
	case 2:
	{
		do
		{
			nFirstI = rand() % (int)pow(10, lDif + 1) + 1;
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		} while (nSecondI >= nFirstI);
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
		do
		{
			nFirstI = rand() % (int)pow(10, lDif + 1) + 1; // TODO: Check if is Prime - if yes reroll the number
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
			if (nFirstI % nSecondI != 0)
			{
				nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
			}
		} while (nSecondI == nFirstI || nSecondI == 1 || nSecondI == nFirstI || nFirstI % nSecondI != 0);
		break;
	}
	}
	nExpA = nExpectedAswer();
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
	std::cout << nFirstI << " " << cCheckActionSymbol() << " " << nSecondI<< " = ";
//	printf_s("%d %c %d", nFirstI, cCheckActionSymbol(), nSecondI); <- Don't know why but this doesn't work
}

long long Problem::nExpectedAswer()
{
	switch (lAction)
	{
	case 1:
		return (static_cast<long>(nFirstI) + static_cast<long long>(nSecondI));
		break;
	case 2:
		return (static_cast<long long>(nFirstI) - static_cast<long long>(nSecondI));
		break;
	case 3:
		return (static_cast<long long>(nFirstI) * static_cast<long long>(nSecondI));
		break;
	case 4:
		return nFirstI / nSecondI;
		break;
	}
	return 0;
}