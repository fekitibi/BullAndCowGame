#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

// the entry point to our application
int main() {

	PrintIntro();

	// repeat the guess back to them
	cout << "Your guess was: " << GetGuess();


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