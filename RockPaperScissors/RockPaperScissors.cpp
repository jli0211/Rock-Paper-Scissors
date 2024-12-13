// RockPaperScissors.cpp : Defines the entry point for the application.
//

#include "RockPaperScissors.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



void RockPaperScissorGame::getUserInput()
{
	std::cout << "Please enter your move:\n0: Rock\n1: Paper\n2: Scissors\n";


	// Validate input
	try {
		std::cin >> userMove;

		// Check if the input was valid
		if (std::cin.fail()) {
			throw std::runtime_error("Invalid input! Please enter a valid integer.");
		}

		// Check if the move is within the valid range
		if (userMove < 0 || userMove > 2) {
			throw std::runtime_error("Move not allowed! Number entered out of range.");
		}
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << e.what() << std::endl;
		// Clear the error state of cin and ignore invalid input
		std::cin.clear();  // Reset the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
		// Optionally, you can ask the user to re-enter input after the error
		getUserInput();  // Recursively call the function to prompt the user again
	}
}

void RockPaperScissorGame::getComputerInput()
{
	int randomNum = rand() % 3;
	switch (randomNum) {
		case 0:
			std::cout << "The Computer Played Rock\n";
			if (userMove > 0) {
				std::cout << "User Wins!";
				score[0]++;
			}
			else {
				std::cout << "Draw!";
			}
			break;
		case 1:
			std::cout << "The Computer Played Paper\n";
			if (userMove == 0) {
				std::cout << "User Played Rock\n";
				std::cout << "User Win!\n";
				score[0]++;
			}
			else if (userMove == 2) {
				std::cout << "User Played Scissors\n";
				std::cout << "User Lost!\n";
				score[1]++;
			}
			else {
				std::cout << "User Played Paper\n";
				std::cout << "It's a Draw!\n";
			}
			break;
		case 2:
			std::cout << "The Computer Played Scissors\n";
			if (userMove == 0) {
				std::cout << "User Played Rock\n";
				std::cout << "User Lost!\n";
				score[1]++;
			}
			else if (userMove == 2) {
				std::cout << "User Played Scissors\n";
				std::cout << "It's a Draw!\n";
			}
			else {
				std::cout << "User Played Paper\n";
				std::cout << "User Win!\n";
				score[0]++;
			}
			break;

	}
	printf("Current score: \nUser: %d\nComputer: %d\n", score[0], score[1]);
}



int main()
{
	std::cout << "Rock Paper Scissor Game Starts! \n";
	std::string name;
	std::cout << "Please enter your name: \n";
	std::cin >> name;
	RockPaperScissorGame game1(name);
startAgain:
	game1.getUserInput();
	game1.getComputerInput();
	int playAgain;
	std::cout << "0: Play Again\n1: Exit\n";
	std::cin >> playAgain;
	if (!playAgain) {
		goto startAgain;
	}
	else {
		exit(0);
	}

	return 0;
}

