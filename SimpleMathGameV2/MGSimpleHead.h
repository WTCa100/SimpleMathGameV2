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
	int nExpA = 0;
	int nUserA = 0;
private:
	int nFirstI, nSecondI;
	char cCheckActionSymbol();
	int nExpectedAswer();
public:
	void CreateProblem();
	void Display();
};