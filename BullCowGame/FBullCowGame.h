#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame{

public:
	FBullCowGame();

	int32 GetMaxNumberOfTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: later could return something
	bool CheckGuessValidity(FString Guess); // TODO: later could return something
	// TODO provide method for bul and cow counting and increase try number

private:
	// see constructor for initialization
	int32 CurrentTry;
	int32 MaxTry;
};
