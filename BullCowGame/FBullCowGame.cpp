#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map // Override the calling of the map just to be more close to the Unreal one

FBullCowGame::FBullCowGame() { Reset(-1); }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetMaxNumberOfTries() const {
	TMap<int32, int32> MaxTriesFromWordLength{ {2, 4}, {3, 7}, {4, 11},{5, 15}, {6, 17} };
	return MaxTriesFromWordLength[GetHiddenWordLength()];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (!IsIsogram(Guess)) { // If the guess isnt an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) { // If the guess isnt all lovercase 
		return EGuessStatus::Not_Lovercase;
	}
	else if (Guess.length() < GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset(int32 NumberOfLetters) {

	TMap<int32, FString> FromWordSelect{ {2, "ab"}, {3, "alu"}, {4, "moas"}, {5, "plato"}, {6, "planet"} };

	bIsGameWon = false;
	HiddenWord = FromWordSelect[NumberOfLetters];
	CurrentTry = 1;
}

// recives valid guess, increment try and return bulls and cows
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	FBullCowCount BullCowCount;
	CurrentTry++;
	//check all letters to the hidden word
	for (int32 i = 0; i < HiddenWord.length(); i++) {
		for (int32 j = 0; j < Guess.length(); j++) {
			if (Guess[j] == HiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}

			}
		}
	}

	if (BullCowCount.Bulls == GetHiddenWordLength() && Guess.length() == GetHiddenWordLength()) {
		bIsGameWon = true;
	}
	else {
		bIsGameWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
	// treat zero and 1 letter strings as isograms
	if (Word.length() <= 1) { return true; }

	// set up the map
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we do not have an isogram
		}
		else {
			LetterSeen[Letter] = true; // add the letter to the map as seen	
		}


	}

	return true; // for example in case where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter)) { // if not a lowercase letter
			return false;
		}
	}
	return true;
}
