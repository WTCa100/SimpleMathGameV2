#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<stdio.h>

class Problem
{
public:
	uint16_t lDif = 1;
	uint16_t lAction = rand()% 4 + 1;
private:
	int nFirstI, nSecondI;
	void CreateProblem(uint16_t lDifficult, uint16_t lAct);
public:
	void Display();
};