#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

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

	constexpr int NUMBER_OF_TURNS = 5;

	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl;
	}
}

// get a guess from the player
std::string GetGuess() {
	
	std::cout << "Enter your guess: ";
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
