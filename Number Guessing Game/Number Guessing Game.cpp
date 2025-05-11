/*
*	Author: Harrison Smith
*	Date: 2025-05-10
* 
*   Notes: The program is a simple number guessing game that has 3 levels of difficulty.
*   The user can choose a difficulty level, and the program will generate a random number within a specific range.
*   The user has to guess the number, and the program will provide feedback on whether the guess is too high or too low.
*   The user has a limited number of attempts to guess the number correctly.
*   The program will keep track of the number of attempts and display the number of attempts taken to guess the number correctly.
*/

#include <iostream>
#include "Level.h"

int main()
{
	Level game;
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "You have 3 levels of difficulty to choose from.\n";
	std::cout << "Level 1: Guess a number between 1 and 10 (5 attempts)\n";
	std::cout << "Level 2: Guess a number between 1 and 50 (3 attempts)\n";
	std::cout << "Level 3: Guess a number between 1 and 100 (2 attempts)\n";
	game.Play();
}
