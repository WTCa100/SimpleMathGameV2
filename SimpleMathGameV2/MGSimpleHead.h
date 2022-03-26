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
	long long nExpA = 0;
	long long nUserA = 0;
private:
	long long nFirstI, nSecondI; // Long is required so if the difficult level will be changed to a greater number
								//  The program won't crash as easliy
	char cCheckActionSymbol();
	long long nExpectedAswer();
public:
	void CreateProblem();
	void Display();
};