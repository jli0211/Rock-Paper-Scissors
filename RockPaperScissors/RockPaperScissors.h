// RockPaperScissors.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <cstdio>
#include <iostream>
#include <string>

// TODO: Reference additional headers your program requires here.

class RockPaperScissorGame {

public: 
	RockPaperScissorGame(std::string PlayerName) 
	{
		printf("Player %s has entered the Game\n", PlayerName.c_str());  // Prints the integer using C-style formatting
	};
	int score[2] = { 0,0 };
	int userMove;
	void getUserInput();
	void getComputerInput();

};