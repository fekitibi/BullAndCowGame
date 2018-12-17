#pragma once
#include <string>

class FBullCowGame{

public:
	int GetMaxNumberOfTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: later could return something
	bool CheckGuessValidity(std::string Guess); // TODO: later could return something


private:
	int CurrentTry = 1;
	int MaxTry = 5;
};
