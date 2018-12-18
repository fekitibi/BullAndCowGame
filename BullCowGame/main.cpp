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
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry point to our application
int main() {

	do {

		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());


	std::cout << std::endl;
	return 0;
}

// introduce the game
void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows game" << std::endl;
	std::cout << "Could you guess the " << BCGame.GetHiddenWordLength() << " length isogram?" << std::endl;

	return;
}

// repeat the guess back to the player
void PlayGame() {

	int32 MaxTries = BCGame.GetMaxNumberOfTries();

	// TODO in the future switch to while loop
	for (int32 i = 0; i < MaxTries; i++) {

		FText Guess = GetGuess();

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		// submit valid guess for the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// TODO print bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;
	}

	// TODO add game summary
}

// get a guess from the player
FText GetGuess() {
	
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Your number of tries: " << CurrentTry << " Enter your guess: ";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain(){

	FText Response = "";
	
	std::cout << "Do you want to play again?(y/n)";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y') ? true : false;
}
