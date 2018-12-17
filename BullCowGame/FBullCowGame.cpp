#include "FBullCowGame.h"

int FBullCowGame::GetMaxNumberOfTries() { return MaxTry; }
int FBullCowGame::GetCurrentTry() { return CurrentTry; }

void FBullCowGame::Reset(){
}

bool FBullCowGame::IsGameWon(){
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess){
	return false;
}
