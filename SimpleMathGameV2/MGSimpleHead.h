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
	int64_t nExpA = 0;
	int64_t nUserA = 0;
private:
	int64_t nFirstI = 0, nSecondI = 0;  // Long is required so if the difficult level will be changed to a greater number
								//  The program won't crash as easliy
	char cCheckActionSymbol();
	int64_t nExpectedAswer();
public:
	void CreateProblem();
	void Display();
};