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
	
		nFirstI = rand() % (int)pow(10, lDif + 1) + 1; // May change from '1' to (int)pow(10, lDif - 1); 
		nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		break;
	
	case 2:
	
		do
		{
			nFirstI = rand() % (int)pow(10, lDif + 1) + 1;
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
		} while (nSecondI >= nFirstI);
		break;
	
	case 3:
	
		nFirstI = rand() % (int)pow(10, lDif) + 1;
		nSecondI = rand() % (int)pow(10, lDif) + 1;
		break;
	
	case 4:
	
		do
		{
			nFirstI = rand() % (int)pow(10, lDif + 1) + 1; // TODO: Check if is Prime - if yes reroll the number
			nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
			if (nFirstI % nSecondI != 0)
			{ 
				nSecondI = rand() % (int)pow(10, lDif + 1) + 1;
			}
		} while (nSecondI == nFirstI || nSecondI == 1 || nFirstI % nSecondI != 0);
		break;
	
	}
	nExpA = nExpectedAswer();
}

char Problem::cCheckActionSymbol()
{
	switch (lAction)
	{
	case 1:
		return '+';
	case 2:
		return '-';
	case 3:
		return '*';
	case 4:
		return '/';
	default:
		return '\0';
	}
}

void Problem::Display()
{
	std::cout << nFirstI << " " << cCheckActionSymbol() << " " << nSecondI<< " = ";
//	printf_s("%d %c %d", nFirstI, cCheckActionSymbol(), nSecondI); <- Don't know why but this doesn't work
}

int64_t Problem::nExpectedAswer()
{
	switch (lAction)
	{
	case 1:
		return nFirstI + nSecondI;
	case 2:
		return nFirstI - nSecondI;
	case 3:
		return nFirstI * nSecondI;
	case 4:
		return nFirstI / nSecondI;
	}
	return 0;
}