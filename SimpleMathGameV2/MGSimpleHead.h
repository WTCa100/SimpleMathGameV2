#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<stdio.h>

class Problem
{
public:
	uint16_t lDif = 1;
	uint16_t lAction = 1;
private:
	int nFirstI, nSecondI;
	void CreateProblem();
	char cCheckActionSymbol();
public:
	void Display();
};