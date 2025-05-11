/*
* Author: Harrison Smith
* Date: 2025-05-10
*/
#pragma once
#include <iostream>
#include <string>

class Level {
public: 
	void Play();

private: 
	void SetLevel();
	int GenerateRandomNumber(int max);
	int level;
	int minRange;
	int maxRange;
	int maxAttempts;
	int attempts;
	bool isActive;
	static const int MIN_LEVELS = 1; // Minimum number of levels
	static const int MAX_LEVELS = 3; // Maximum number of levels
	static const int MIN_RANGE = 1; // Minimum range for guessing
	static const int MAX_RANGE = 100; // Maximum range for guessing
};