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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
	// setup return variable
	FBullCowCount BullCowCount;
	//increment try number
	CurrentTry++;
	//check all letters to the hidden word
	for (int32 i = 0; i < HiddenWord.length(); i++){
		for (int32 j = 0; j < HiddenWord.length(); j++){
			if (Guess[i] == HiddenWord[i]) {
				if(i == j){
					BullCowCount.Bulls++;
				}
				else{
					BullCowCount.Cows++;
				}
				
			}
		}
	}
	//return bulls and cows
	return BullCowCount;
}
