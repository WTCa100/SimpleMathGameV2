#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<conio.h>
#include"MGSimpleHead.h"

// uint16_t lMaxDif = 5 
// You can change the difficulty settings in code so you can have i.e. From 1 to 100.

std::string Nickname = "Dummy"; // This is for final ranking section of the game
uint32_t score = 0;
uint16_t lMainDifficult = 1;
bool bIsGameOn = true;
void chooseDif();
void problemDisplay(Problem Instance);
bool isUserAnswerCorrect(std::string UI);
void checkAndCollect(Problem Instance, int UserIn);
void finalScoreSum(std::string UserName);

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
		finalScoreSum(Nickname);
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
		std::string ActualA = "";
		int nActualA = 0;
		Instance.lAction = rand() % 4 + 1;
		Instance.CreateProblem();
		do
		{
			printf("%d Problem\t Score: %d\n", i + 1, score);
			Instance.Display();
			std::getline(std::cin, ActualA);
			if (isUserAnswerCorrect(ActualA) == false)
			{
				printf("Input a valid answer!");
				_getch();
				system("cls");
			}
			else
			{
				nActualA = std::stoi(ActualA);
			}
		} while (!isUserAnswerCorrect(ActualA));
		checkAndCollect(Instance, nActualA);
		system("cls");
	}
}

bool isUserAnswerCorrect(std::string UI)
{
	if (UI[0] == '\0')
		return false;
	for (int i = 0; i < UI.size(); i++)
	{
		if (UI[i] < '0' || UI[i] > '9')
			return false;
	}
	return true;
}

void checkAndCollect(Problem Instance, int UserIn)
{
	if (Instance.nExpA == UserIn)
	{
		score += 10 * lMainDifficult;
		printf("Correct! \t +%d points!", 10 * lMainDifficult);
		_getch();
	}
	else
	{
		printf("Incorrect! \t No points!");
		_getch();
	}
}

void finalScoreSum(std::string UserName)
{
	printf("You have earned %d points!", score);
	_getch();
	system("cls");
}
