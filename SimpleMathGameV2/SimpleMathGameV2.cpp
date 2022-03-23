#include<iostream>
#include"MGSimpleHead.h"
#include<ctime>
#include<Windows.h>
#include<string>
#include<vector>
uint32_t score = 0;
int mainDif = 1;
Problem PArr[30];


int main()
{
	system("title Simple Math Game V2 - By John \"WTCa100\" Bielawa");
	srand(time(NULL));
	std::vector<Problem> PSet;
	Problem Test;
	Test.Display();
	printf("\nSet of problems:\n");
	for (int i = 0; i < 5 * mainDif; i++)
	{
		printf("Vector: ");
		PSet.push_back(Test);
		PSet[i].Display();
		printf("\nArray: ");
		PArr[i].Display();
		printf("\n");
	}
}