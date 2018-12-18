#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame{

public:
	FBullCowGame();

	int32 GetMaxNumberOfTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO: later could return something
	bool CheckGuessValidity(FString Guess); // TODO: later could return something
	//bull and cow counting and increase try number method assuming valid guess
	BullCowCount SubmitGuess(FString guess);

private:
	// see constructor for initialization
	int32 CurrentTry;
	int32 MaxTry;
	FString HiddenWord;
};
