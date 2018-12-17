#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// the entry point to our application
int main() {

	do {

		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());


	cout << endl;
	return 0;
}

// introduce the game
void PrintIntro() {

	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows game" << endl;
	cout << "Could you guess the " << WORD_LENGTH << " length isogram?" << endl;

	return;
}

// repeat the guess back to the player
void PlayGame() {

	constexpr int NUMBER_OF_TURNS = 5;

	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		cout << "Your guess was: " << GetGuess() << endl;
	}
}

// get a guess from the player
string GetGuess() {
	
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain(){

	string Response = "";
	
	cout << "Do you want to play again?(y/n)";
	getline(cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y') ? true : false;
}
