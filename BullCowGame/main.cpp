#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

// the entry point to our application
int main() {

	constexpr int NUMBER_OF_TURNS = 5;

	PrintIntro();

	// repeat the guess back to them
	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		cout << "Your guess was: " << GetGuess() << endl;
	}
	

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

// get a guess from the player
string GetGuess() {
	
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}