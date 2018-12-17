#include "FBullCowGame.h"

int FBullCowGame::GetMaxNumberOfTries() const { return MaxTry; }
int FBullCowGame::GetCurrentTry() const { return CurrentTry; }

void FBullCowGame::Reset(){
}

bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess){
	return false;
}
