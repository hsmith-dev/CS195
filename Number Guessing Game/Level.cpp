/*
* Author: Harrison Smith
* Date: 2025-05-10
*/
#include "Level.h"
#include <cstdlib>
#include <ctime>

const int MIN_LEVELS = 1; // Minimum number of levels
const int MAX_LEVELS = 3; // Maximum number of levels
const int MIN_RANGE = 1; // Minimum range for guessing
const int MAX_RANGE = 100; // Maximum range for guessing

void Level::SetLevel() {
	std::cout << "Enter level (" << MIN_LEVELS << "-" << MAX_LEVELS << "): ";
	std::cin >> level;

	if (level > MAX_LEVELS) {
		level = MAX_LEVELS; // Set to maximum level if input exceeds
	}
	else if (level < MIN_LEVELS) {
		level = MIN_LEVELS; // Set to minimum level if input is less
	}

	// For simplicity we are only going to handle the three cases, could do a for loop and do an algorithmic approach to calculating these.
	minRange = MIN_RANGE; // Set minimum range to the constant value
	isActive = true; // Set the level as active by default
	attempts = 0; // Initialize attempts to 0
	if (level == 1) {
		maxRange = 10;
		maxAttempts = 5;
	}
	else if (level == 2) {
		maxRange = 50;
		maxAttempts = 3;
	}
	else if (level == 3) {
		maxRange = 100;
		maxAttempts = 2;
	}
	else {
		maxRange = MAX_RANGE; // Set maximum range to the constant value
		maxAttempts = 1; // Set maximum attempts to 1 if level is not valid
	}
}

int Level::GenerateRandomNumber(int max) {
	srand(time(0)); // Seed the random number generator
	return rand() % max + 1; // Generate a random number between 1 and max
}

void Level::Play() {
	SetLevel();
	int randomNum = GenerateRandomNumber(maxRange);
	std::cout << "Welcome to Level " << level << "!\n";

	while (isActive) {
		int guess;
		std::cout << "You have used " << attempts << " of " << maxAttempts << " attempts to guess the number.\n";
		std::cout << "Guess a number between " << minRange << " and " << maxRange << ".\n";
		std::cin >> guess;
		attempts++; // Increment attempts after each guess

		if (guess == randomNum) {
			std::cout << "Congratulations! You guessed the number " << randomNum << " correctly!\n";
			std::cout << "You have used " << attempts + 1 << " of " << maxAttempts << " attempts.\n";
			std::cout << "You have completed this level!\n";
			isActive = false; // Deactivate the level after a correct guess
		}
		else if (guess < randomNum) {
			std::cout << "Your guess is too low.\n";
		}
		else {
			std::cout << "Your guess is too high.\n";
		}

		if (attempts >= maxAttempts) {
			std::cout << "Maximum attempts reached. Level is now inactive.\n";
			isActive = false; // Deactivate the level if maximum attempts are reached
			std::cout << "The correct number was " << randomNum << ".\n";
		}
		else {
			std::cout << "You have used " << attempts << " of " << maxAttempts << " attempts.\n";
			std::cout << "Try guessing again!\n";
		}
	}
}