/* This is a console executable, that make use of BullCow class.
This acts as the view in the MVC pattern, this class is responsible for player interactions.
*/
#pragma once;

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void AskLetters();

FBullCowGame BCGame;

// the entry point to our application
int main() {
	AskLetters();// To initialize NumberOfLetters with a valid number
	do {
		BCGame.Reset();
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	std::cout << std::endl;
	return 0;
}

// introduce the game
void PrintIntro() {

	std::cout <<
		R"(
 .-=-.                .-=-.            .=     ,        =.
  `) )              ( (`      _  _   /'/    )\,/,/(_   \ \
 .' /                \ '.      `//-.|  (  ,\\)\//\)\/_  ) |
(  (   _.-'`::`'-._   )  )     //___\   `\\\/\\/\/\\///'  /
 \  `'`    .::.    `'`  /   ,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
  `-._\`~`      `~`/_.-'    \       `-.  '_`.      .'_` \ ,-"~`/
 _,=` /            \ `=,_    `.__.-'`/   (-\        /-) |-.__,'
(    ,(^\        /^),    )     ||   |     \O)  /^\ (O/  |
 `~~` \0)\      /(0/ `~~`      `\\  |         /   `\    /
       | /`    '\ |              \\  \       /      `\ /
       |          |               `\\ `-.  /' .---.--.\
       |          |                 `\\/`~(, '()      ('
       |          |                  /(O) \\   _,.-.,_)
       /          \                 //  \\ `\'`      /
       \()      ()/               / |  ||   `""""~"`
        `._-==-_.'               /'  |__||
           `""`                        `o
           BULL           AND                 COW
                   A funny word game
)";
	std::cout << "\tCould you guess the " << BCGame.GetHiddenWordLength() << " length isogram?" << std::endl;

	return;
}

// repeat the guess back to the player
void PlayGame() {

	int32 MaxTries = BCGame.GetMaxNumberOfTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValidGuess();

		// submit valid guess for the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;
	}
}

// get a guess from the player
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "\nYour number of tries: " << CurrentTry << " out of " << BCGame.GetMaxNumberOfTries() << "\n" << "Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a isogram(all letters in the word are different)" << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " length isogram" << std::endl;
			break;
		case EGuessStatus::Not_Lovercase:
			std::cout << "Please enter all lovercase letters" << std::endl;
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain() {
	FText Response = "";
	bool Continue = false;

	std::cout << "Do you want to play again?(y/n)";
	getline(std::cin, Response);

	Continue = (Response[0] == 'y' || Response[0] == 'Y') ? true : false;

	AskLetters();
	return Continue;
}

void AskLetters() {

	FText Response = "";

	std::cout << "How long should be the isogram?(2, 3, 4, 5, 6)";
	getline(std::cin, Response);
	std::cin.clear();

	switch (Response[0]) {
	case '2':
		BCGame.SetHiddenWordDifficulity(2);
		break;
	case '3':
		BCGame.SetHiddenWordDifficulity(3);
		break;
	case '4':
		BCGame.SetHiddenWordDifficulity(4);
		break;
	case '5':
		BCGame.SetHiddenWordDifficulity(5);
		break;
	case '6':
		BCGame.SetHiddenWordDifficulity(6);
		break;
	default:
		BCGame.SetHiddenWordDifficulity(-1);
		break;
	}
}
