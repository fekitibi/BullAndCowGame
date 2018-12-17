#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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

	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows game" << std::endl;
	std::cout << "Could you guess the " << WORD_LENGTH << " length isogram?" << std::endl;

	return;
}

// repeat the guess back to the player
void PlayGame() {

	int MaxTries = BCGame.GetMaxNumberOfTries();

	// TODO in the future switch to while loop
	for (int i = 0; i < MaxTries; i++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl; // TODO check for valid guess
		// TODO submit valid guess for the game
		// TODO print bulls and cows
	}

	// TODO add game summary
}

// get a guess from the player
std::string GetGuess() {
	
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Your number of tries: " << CurrentTry << " Enter your guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain(){

	std::string Response = "";
	
	std::cout << "Do you want to play again?(y/n)";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y') ? true : false;
}
