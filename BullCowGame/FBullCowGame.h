#pragma once

class FBullCowGame{

public:
	void Reset(); // TODO: later could return something
	int GetMaxNumberOfTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(string Guess); // TODO: later could return something
	int GetNumberOfBulls();
	int GetNumberOfCows();


private:

};
