#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<conio.h>
#include"MGSimpleHead.h"

// uint16_t lMaxDif = 5 
// You can change the difficulty settings in code so you can have i.e. From 1 to 100.


uint32_t score = 0;
uint16_t lMainDifficult = 1;
bool bIsGameOn = true;
void chooseDif();
void problemDisplay(Problem Instance);

int main()
{
	system("title Simple Math Game V2 - by Jan \"WTCa100\" Bielawa");
	std::vector<Problem> Pset;
	srand(time(NULL));
	Problem initialize;
	do
	{
		score = 0;
		chooseDif();
		initialize.lDif = lMainDifficult;
		problemDisplay(initialize);
		_getch();
		system("cls");
	} while (bIsGameOn);
}

void chooseDif()
{
	std::string tmp = "0"; // Initiate a string 
	do
	{
		printf("Choose your difficult level:\n");
		printf("1. Easy\n");
		printf("2. Moderate\n");
		printf("3. Advanced\n");
		printf("4. Hard\n");
		std::getline(std::cin, tmp);
		if (tmp[0] < '1' || tmp[0] > '4' || tmp[0] == '\0') // TODO - Better check if answer is valid
		{
			printf("Enter a valid answer!");
			_getch();
			system("cls");
		}
		else
		{
			if (std::stoi(tmp) > 5)
			{
				printf("Enter a valid answer!");
				_getch();
				system("cls");
			}
			else
			{
				lMainDifficult = std::stoi(tmp);
			}
			system("cls");
		}
	} while (tmp[0] < '1' || tmp[0] > '4' || tmp[0] == '\0' || std::stoi(tmp) > 5); // You can replace std::stoi(tmp) > 5 with std::stoi(tmp) > lMaxDif

}
void problemDisplay(Problem Instance)
{
	for (int i = 0; i < 5 * lMainDifficult; i++)
	{
		printf("%d Problem\n", i + 1);
		Instance.lAction = rand() % 4 + 1;
		Instance.Display();
		printf("\n");
	}
}