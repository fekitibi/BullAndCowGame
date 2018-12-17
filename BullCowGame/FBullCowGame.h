#pragma once
#include <string>

class FBullCowGame{

public:
	void Reset(); // TODO: later could return something
	int GetMaxNumberOfTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string Guess); // TODO: later could return something


private:
	int CurrentTry = 1;
	int MaxTry = 5;
};
