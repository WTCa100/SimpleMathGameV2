#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<conio.h>
#include"MGSimpleHead.h"

// uint16_t lMaxDif = 5 
// You can change the difficulty settings in code so you can have i.e. From 1 to 100.

std::vector<Problem> Pset; // This will be used for storing purposes
std::string Nickname = "Dummy"; // This is for final ranking section of the game
uint32_t score = 0;
uint16_t lMainDifficult = 1;
int gameRepeat = 5;
bool bIsGameOn = true;
void chooseDif();
void problemDisplay(Problem Instance);
bool isUserAnswerCorrect(std::string UI);
void checkAndCollect(Problem Instance, int64_t UserIn);
void finalScoreSum(std::string UserName); // The std::string arg is going to be handy once the highscore and ranking wil be applied
void nextAction();
void howManyGames();
void showProblems();

int main()
{
	system("title Simple Math Game V2 - by Jan \"WTCa100\" Bielawa");
	srand((unsigned int)time(NULL));
	printf("Hello and welcome to the second version of my first project!\n");
	printf("This time to play with classes, objects and methods so you can enjoy much greater challanges.\n");
	printf("Press any key to continue\n");
	(void)_getch();
	system("cls");
	printf("The idea of the game is simple.\n");
	printf("1st You choose your difficult level.\n");
	printf("2nd The program will automatically generate random mathemtaical problems for you to solve\n");
	printf("3rd You have only one chance to solve it - if you are correct you get points if you are not you don\'t\n");
	printf("And that is all you need to know!\n");
	printf("Press any key to continue\n");
	(void)_getch();
	system("cls");
	Problem initialize;
	do
	{
		score = 0;
		Pset.clear();
		chooseDif();
		howManyGames();
		initialize.lDif = lMainDifficult;
		problemDisplay(initialize);
		finalScoreSum(Nickname);
		nextAction();
	} while (bIsGameOn);
}
void howManyGames() // TODO Finish
{
	std::string tmp = "1";
	bool isNumericAnswerValid = true;
	do
	{
	printf("How many problems would you like to solve?\n");
	printf("NOTICE: Max number of games is 1000\n");
	std::getline(std::cin, tmp);
	if (!isUserAnswerCorrect(tmp))
	{
		printf("Invalid answer! The input only accepts numeric values\n");
		(void)_getch();
		system("cls");
	}
	else if(isUserAnswerCorrect(tmp))
	{
		gameRepeat = std::stoi(tmp);
		if (gameRepeat <= 0 || gameRepeat > 1000)
		{
			isNumericAnswerValid = false;
			printf("Your input is out of range!\n");
			(void)_getch();
			system("cls");
		}
		else
		{
			isNumericAnswerValid = true;
			system("cls");
		}
	}
	} while (!isUserAnswerCorrect(tmp) || !isNumericAnswerValid);


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
		printf("5. Very Hard\n");
		std::getline(std::cin, tmp);
		if (!isUserAnswerCorrect(tmp) || std::stoi(tmp) < 1 || std::stoi(tmp) > 5) // TODO - Better check if answer is valid
		{
			printf("Enter a valid answer!");
			(void)_getch();
			system("cls");
		}
		else
		{

			lMainDifficult = std::stoi(tmp);
			system("cls");
		}
	} while (std::stoi(tmp) < 1 || std::stoi(tmp) > 5 || !isUserAnswerCorrect(tmp)); // You can replace std::stoi(tmp) > 5 with std::stoi(tmp) > lMaxDif

}
void problemDisplay(Problem Instance)
{

	for (int i = 0; i < gameRepeat; i++) 
	{																			
		std::string ActualA = "";
		int64_t nActualA = 0;
		Instance.lAction = rand() % 3 + 1;
		Instance.CreateProblem();
		do
		{
			printf("%d Problem\t Score: %d\n", i + 1, score);
			Instance.Display();
			std::getline(std::cin, ActualA);
			if (!isUserAnswerCorrect(ActualA))
			{
				printf("Input a valid answer!");
				(void)_getch();
				system("cls");
			}
			else
			{
				nActualA = std::stoi(ActualA);
				Instance.nUserA = nActualA;
				Pset.push_back(Instance);
			}
		} while (!isUserAnswerCorrect(ActualA));
		checkAndCollect(Instance, nActualA);
		system("cls");
	}
}

bool isUserAnswerCorrect(std::string UI) // UI stands for User Input
{
	if (UI[0] == '\0')
		return false;
	for (auto i = 0u; i < UI.size(); i++)
	{
		if (UI[i] < '0' || UI[i] > '9')
			return false;
	}
	return true;
}

void checkAndCollect(Problem Instance, int64_t UserIn)
{
	if (Instance.nExpA == UserIn)
	{
		score += 10 * lMainDifficult;
		printf("Correct! \t +%d points!", 10 * lMainDifficult);
		(void)_getch();
	}
	else
	{
		printf("Incorrect! \t No points!");
		(void)_getch();
	}
}

void finalScoreSum(std::string UserName)
{
	printf("You have earned %d points!", score);
	(void)_getch();
	system("cls");
}

void nextAction()
{
	std::string tmp = "3";
	int nNextMove = 3;
	printf("What would you like to do next?\n");
	printf("1. New Game.\n");
	printf("2. Show problems and answers\n");
	printf("3. Exit the game\n");
//	printf("N. Show ranking"); This is going to be added later on 
	std::getline(std::cin, tmp);
	do
	{
		if (!isUserAnswerCorrect(tmp))
		{
			printf("Entar a valid answer!\n");
			(void)_getch();
			system("cls");
		}
		else
		{
			nNextMove = std::stoi(tmp);
			if (nNextMove < 1 || nNextMove > 3)
			{
				printf("Enter a valid answer!\n");
				(void)_getch();
				system("cls");
			}
			else
			{
				system("cls");
			}
		}
	} while (!isUserAnswerCorrect(tmp) && (nNextMove < 1 || nNextMove > 3));
	switch (nNextMove)
	{
	case 1:
		break;
	case 2:
		showProblems();
		break;
	case 3:
		bIsGameOn = false;
		break;
	}
}

void showProblems()
{
	for (auto i = 0u; i < Pset.size(); i++)
	{
		printf("%d Problems: ", i + 1);
		Pset[i].Display();
		printf("\n");
		printf("Expected answer was %lld . Your's was %lld\n", Pset[i].nExpA, Pset[i].nUserA);
		if (Pset[i].nExpA == Pset[i].nUserA)
		{
			printf("It was correct!\n");
		}
		else
		{
			printf("It was incorrect!\n");
		}
		printf("\n");
		if (i % 20 == 0 && i > 0)
		{
			printf("End of the page\n");
			printf("Press any key to continue to diplay the next page\n");
			(void)_getch();
			system("cls");
		}
	}
	printf("End of the list.\n");
	printf("Press any key to continue.\n");
	(void)_getch();
	system("cls");
	nextAction();
}