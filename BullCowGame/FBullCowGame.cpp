#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxNumberOfTries() const { return MaxTry; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

void FBullCowGame::Reset(){

	constexpr int32 MAX_TRIES = 8;

	MaxTry = MAX_TRIES;
	CurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString Guess){
	return false;
}
