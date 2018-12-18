#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lovercase
};

class FBullCowGame{

public:
	FBullCowGame();

	int32 GetMaxNumberOfTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;


	void Reset(); // TODO: later could return something
	//bull and cow counting and increase try number method assuming valid guess
	FBullCowCount SubmitGuess(FString Guess);

private:
	// see constructor for initialization
	int32 CurrentTry;
	int32 MaxTry;
	FString HiddenWord;
};
