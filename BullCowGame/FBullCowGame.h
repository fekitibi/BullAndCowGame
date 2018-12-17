#pragma once
#include <string>

class FBullCowGame{

public:
	void Reset(); // TODO: later could return something
	int GetMaxNumberOfTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string Guess); // TODO: later could return something
	int GetNumberOfBulls();
	int GetNumberOfCows();


private:

};
