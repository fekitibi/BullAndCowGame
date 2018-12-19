/* This is a console executable, that make use of BullCow class.
This acts as the view in the MVC pattern, FBullCowGame class has the game logic.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry point to our application
int main() {

	do {

		PrintIntro();
		PlayGame();
		BCGame.Reset();

	} while (AskToPlayAgain());


	std::cout << std::endl;
	return 0;
}

// introduce the game
void PrintIntro() {

	std::cout << "\n\nWelcome to Bulls and Cows game" << std::endl;
	std::cout << "Could you guess the " << BCGame.GetHiddenWordLength() << " length isogram?" << std::endl;

	return;
}

// repeat the guess back to the player
void PlayGame() {

	int32 MaxTries = BCGame.GetMaxNumberOfTries();

	// TODO in the future switch to while loop
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){

		FText Guess = GetValidGuess();

		// submit valid guess for the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// TODO print bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;
	}

	// TODO add game summary
}

// get a guess from the player
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do{
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "\nYour number of tries: " << CurrentTry << " Enter your guess: ";
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

bool AskToPlayAgain(){

	FText Response = "";
	
	std::cout << "Do you want to play again?(y/n)";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y') ? true : false;
}
