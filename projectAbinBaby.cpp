#include "pch.h"
#include <iostream>
#include<string>
#include <ctime>
using namespace std;

void printGameName();
int randomNumberGenerator();
string getWord(int randomNumber);
int getLength(string word);
void insertDash(char array[], int size);
void printOutputArray(char array[], int size);
char getUserInput();
void insertIntoOutputArray(char outputArray[], int index, char userInput);
void isPresent(char outputArray[], int size, char userInput, string word, int &chances, char userAttemptedChar[], int & currentCounter);
void insertIntoUserInputArray(char userInputArray[], char userInput, int &currentCounter, int size, int &chances);
bool isDashPresentInOutPutArray(char outputArray[], int size);

int main()
{

	int choice = 0;
	do
	{
		system("cls");
		printGameName();
		int randomNumber = randomNumberGenerator();
		string word = getWord(randomNumber);
		int length = getLength(word);
		char * outputArray = new char[length];
		insertDash(outputArray, length);
		printOutputArray(outputArray, length);
		int chances = 6;
		char * userAttemptedChar = new char[chances];
		int currentCounter = 0;

		while (isDashPresentInOutPutArray(outputArray, length) && chances > 0)
		{
			char userInput = getUserInput();
			isPresent(outputArray, length, userInput, word, chances, userAttemptedChar, currentCounter);
		}
		if (!isDashPresentInOutPutArray(outputArray, length))
		{
			cout << "\n Bravo...! you just made it...!" << endl;
		}
		cout << "Press 1 to continue and 0 to exit: ";
		cin >> choice;
	} while (choice != 0);
}

int randomNumberGenerator()
{
	srand(time(0));
	int random = rand();
	return random % 20;
}

string getWord(int randomNumber)
{
	string array[20] = { "montreal","britishcolumbia","montroyal","nunavut","vancouver","novascotia","quebec","toronto","halifax","winnipeg","ontario","mississauga","brampton","radisson" };
	return array[randomNumber];
}

int getLength(string word)
{
	int length = 0;
	while (word[length] != '\0')
	{
		++length;
	}
	return length;
}

void insertDash(char array[], int size)
{
	for (int index = 0; index < size; index++)
	{
		array[index] = '_';
	}
}

void printOutputArray(char array[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << array[index] << " ";
	}
}

void printUserInputArray(char array[], int size)
{
	cout << "\nWrong character(s) inputed by the player are:[";
	for (int index = 0; index < size; index++)
	{
		cout << array[index] << " ";
	}
	cout << "]";
	cout << endl;
}

char getUserInput()
{
	char userInput;
	cout << "\n\nEnter user Input: ";
	cin >> userInput;
	cout << endl;
	return userInput;
}



void isPresent(char outputArray[], int size, char userInput, string word, int &chances, char userAttemptedChar[], int &currentCounter)
{
	bool isPresent = false;
	for (int index = 0; index < size; index++)
	{
		if (word.at(index) == userInput)
		{
			insertIntoOutputArray(outputArray, index, userInput);
			isPresent = true;
		}
	}
	if (!isPresent)
	{
		//decrease chance
		//chances = chances - 1;
		insertIntoUserInputArray(userAttemptedChar, userInput, currentCounter, size, chances);
		if (chances != 0) {
			cout << "Oh no...Unfortunately your guess went wrong...!" << "\tDon't  panic...Be cool...Try again!" << endl;
		}


		cout << "You Have ";
		if (chances == 5)
		{
			cout << "Five Chances Remaining!" << endl;
			cout << "   +--- +" << endl;
			cout << "   |    |" << endl;
			cout << "	|" << endl;
			cout << "	|" << endl;
			cout << "	| " << endl;
			cout << "	|  " << endl;
			cout << "========= " << endl;
		}
		if (chances == 4)
		{
			cout << "Four Chances Remaining!" << endl;
			cout << "	 +-- -" << endl;
			cout << "	 |   |" << endl;
			cout << "	 O   |" << endl;
			cout << "	     |" << endl;
			cout << "             |" << endl;
			cout << "	     |" << endl;
			cout << "      ======== =" << endl;

		}
		if (chances == 3)
		{
			cout << "Three Chances Remaining!" << endl;
			cout << "	 +-- - +" << endl;
			cout << "	 |   |" << endl;
			cout << "	 O   |" << endl;
			cout << "	 |   |" << endl;
			cout << "	     |" << endl;
			cout << "	     |" << endl;
			cout << "\t======== =" << endl;

		}
		if (chances == 2)
		{
			cout << "Two Chances Remaining!" << endl;
			cout << " \t +-- - +" << endl;
			cout << "	 |   |" << endl;
			cout << "	 O   |" << endl;
			cout << "	 /|  |" << endl;
			cout << "	     |" << endl;
			cout << "	     |" << endl;
			cout << "	 ========= " << endl;
		}
		if (chances == 1)
		{
			cout << "One Chances Remaining!" << endl;
			cout << "+-----+" << endl;
			cout << "  |   |" << endl;
			cout << "  O   |" << endl;
			cout << " /|\\  |" << endl;
			cout << "       |" << endl;
			cout << "      |" << endl;
			cout << "=========" << endl;
		}

	}
	else
	{
		cout << endl;
		printOutputArray(outputArray, size);
	}


	if (chances == 0)
	{
		cout << "\nOh no...You Lose,Better luck next time...!\n";
		cout << "The original word was " << word << "." << endl;
		cout << "+-----+" << endl;
		cout << "  |   |" << endl;
		cout << "  O   |" << endl;
		cout << " /|\\  |" << endl;
		cout << " / \\  |" << endl;
		cout << "      |" << endl;
		cout << "=========" << endl;
	}

}

void insertIntoOutputArray(char outputArray[], int index, char userInput)
{
	outputArray[index] = userInput;
}

bool isDashPresentInOutPutArray(char outputArray[], int size)
{
	for (int index = 0; index < size; index++)
	{
		if (outputArray[index] == '_')
			return true;
	}
	return false;
}

void insertIntoUserInputArray(char userInputArray[], char userInput, int &currentCounter, int size, int &chances)
{
	bool isPresent = false;
	for (int index = 0; index < size; index++)
	{
		if (userInputArray[index] == userInput)
		{
			isPresent = true;
			cout << "\nYou already tried this character ,Try something new...!\n";
		}
	}
	if (!isPresent)
	{
		userInputArray[currentCounter] = userInput;
		++currentCounter;
		chances = chances - 1;
		//printPatternIfMismatchHappens(chances);
		printUserInputArray(userInputArray, currentCounter);
	}
}

void printGameName()
{
	cout << "hhhhhhh    hhhhhhhh	" << endl;
	cout << "h:::::h    h::::::h	" << endl;
	cout << "h:::::h    h::::::h	 " << endl;
	cout << "h:::::h    h::::::h	" << endl;
	cout << "h::::h hhhh h:::::h     aaaaaaaaaaaaa  nnnn  nnnnnnnn       ggggggggg   ggggg   mmmmmmm    mmmmmmm     aaaaaaaaaaaaa  nnnn  nnnnnnnn   " << endl;
	cout << "h::::hh::::::hhhhh    a::::::::::::a n:::nn::::::::nn    g:::::::::ggg::::g mm:::::::m  m:::::::mm   a::::::::::::a n:::nn::::::::nn  " << endl;
	cout << "h::::::::::::::::hh  aaaaaaaaa:::::an::::::::::::::nn  g:::::::::::::::::gm::::::::::mm::::::::::m  aaaaaaaaa:::::an::::::::::::::nn " << endl;
	cout << "h:::::::hhh:::::::h           a::::ann:::::::::::::::ng::::::ggggg::::::ggm::::::::::::::::::::::m           a::::ann:::::::::::::::n " << endl;
	cout << "h::::::h   h::::::h    aaaaaaa:::::a  n:::::nnnn:::::ng:::::g     g:::::g m:::::mmm::::::mmm:::::m    aaaaaaa:::::a  n:::::nnnn:::::n " << endl;
	cout << "h:::::h     h:::::h  aa::::::::::::a  n::::n    n::::ng:::::g     g:::::g m::::m   m::::m   m::::m  aa::::::::::::a  n::::n    n::::n " << endl;
	cout << "h:::::h     h:::::h a::::aaaa::::::a  n::::n    n::::ng:::::g     g:::::g m::::m   m::::m   m::::m a::::aaaa::::::a  n::::n    n::::n " << endl;
	cout << "h:::::h     h:::::ha::::a    a:::::a  n::::n    n::::ng::::::g    g:::::g m::::m   m::::m   m::::ma::::a    a:::::a  n::::n    n::::n " << endl;
	cout << "h:::::h     h:::::ha::::a    a:::::a  n::::n    n::::ng:::::::ggggg:::::g m::::m   m::::m   m::::ma::::a    a:::::a  n::::n    n::::n" << endl;
	cout << "h:::::h     h:::::ha:::::aaaa::::::a  n::::n    n::::n g::::::::::::::::g m::::m   m::::m   m::::ma:::::aaaa::::::a  n::::n    n::::n " << endl;
	cout << "h:::::h     h:::::h a::::::::::aa:::a n::::n    n::::n  gg::::::::::::::g m::::m   m::::m   m::::m a::::::::::aa:::a n::::n    n::::n " << endl;
	cout << "hhhhhhh     hhhhhhh  aaaaaaaaaa  aaaa nnnnnn    nnnnnn    gggggggg::::::g mmmmmm   mmmmmm   mmmmmm  aaaaaaaaaa  aaaa nnnnnn    nnnnnn " << endl;
	cout << "                                                                  g:::::g                                                                " << endl;
	cout << "                                                      gggggg      g:::::g                                                                 " << endl;
	cout << "                                                      g:::::gg   gg:::::g                                                                    " << endl;
	cout << "                                                       g::::::ggg:::::::g                                                                       " << endl;
	cout << "                                                             gggggg                                                                               " << endl;
	cout << "                                                        gg:::::::::::::g                                                                       " << endl;
	cout << "                                                          ggg::::::ggg                                                                          " << endl;
}
