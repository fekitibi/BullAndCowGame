/*
Class which contains the game logic
*/
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
	Invalid_Status,
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


	void Reset(int32 NumberOfLetters); 
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	// see constructor for initialization
	int32 CurrentTry;
	FString HiddenWord;
	bool bIsGameWon;

	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;
};
