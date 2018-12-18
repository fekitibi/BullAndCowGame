#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxNumberOfTries() const { return MaxTry; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

void FBullCowGame::Reset(){

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	HiddenWord = HIDDEN_WORD;
	MaxTry = MAX_TRIES;
	CurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString Guess){
	return false;
}

// recives valid guess, increment try and return bulls and cows
BullCowCount FBullCowGame::SubmitGuess(FString guess){
	// setup return variable
	BullCowCount BullCowCount;
	//increment try number
	CurrentTry++;
	//check all letters to the hidden word
	//return bulls and cows
	return BullCowCount;
}
