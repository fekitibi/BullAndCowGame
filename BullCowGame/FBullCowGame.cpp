#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int FBullCowGame::GetMaxNumberOfTries() const { return MaxTry; }
int FBullCowGame::GetCurrentTry() const { return CurrentTry; }

void FBullCowGame::Reset(){

	constexpr int MAX_TRIES = 8;

	MaxTry = MAX_TRIES;
	CurrentTry = 1;
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess){
	return false;
}
