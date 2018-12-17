#pragma once
#include <string>

class FBullCowGame{

public:
	FBullCowGame();

	int GetMaxNumberOfTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: later could return something
	bool CheckGuessValidity(std::string Guess); // TODO: later could return something
	// TODO provide method for bul and cow counting and increase try number

private:
	// see constructor for initialization
	int CurrentTry;
	int MaxTry;
};
