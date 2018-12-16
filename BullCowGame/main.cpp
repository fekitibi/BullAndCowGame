#include <iostream>
#include <string>

using namespace std;

int main() {
	constexpr int WORD_LENGTH = 5;

	// introduce the game
	cout << "Welcome to Bulls and Cows game"<< endl;
	cout << "Could you guess the " << WORD_LENGTH << " length isogram?\n";

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess;


	cout << endl;
	return 0;
}