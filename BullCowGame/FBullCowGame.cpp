#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxNumberOfTries() const { return MaxTry; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return HiddenWord.length(); }

bool FBullCowGame::IsGameWon() const{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if(false){
		return EGuessStatus::Not_Lovercase;
	}
	else if (Guess.length() < GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	HiddenWord = HIDDEN_WORD;
	MaxTry = MAX_TRIES;
	CurrentTry = 1;
}

// recives valid guess, increment try and return bulls and cows
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
	// setup return variable
	FBullCowCount BullCowCount;
	//increment try number
	CurrentTry++;
	//check all letters to the hidden word
	for (int32 i = 0; i < HiddenWord.length(); i++){
		for (int32 j = 0; j < Guess.length(); j++){
			if (Guess[j] == HiddenWord[i]) {
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
