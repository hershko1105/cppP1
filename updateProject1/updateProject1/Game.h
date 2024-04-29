#pragma once
#include <iostream>
#include "Ship.h"
#include "life.h"
#include "time.h"

#define WIDTH 80
#define HEIGHT 2025

using namespace std;

class Game
{
private:
	Ship _bigShip;
	Ship _smallShip;
	life _life;
	char _board[HEIGHT][WIDTH];

	void showEntryMenu(/*,Game* this*/);
	int getUserSelect(/*,Game* this*/);
	void startNewGame(/*,Game* this*/);
	void printInstructions(/*,Game* this*/);
	void exitGame(/*,Game* this*/);
	void initBoard(/*,Game* this*/);
	void showBoard(/*,Game* this*/);
	void menu(/*,Game* this*/);
	//for showing life


public:
	void run(/*,Game* this*/);
	void printingCurrLife();
	bool checkIfBlockFall();
	char retBoardInfo(int xPlace, int yPlace);
	void printTime();


	void Printinstructions()
	{
		cout << "The keys to the game are" << endl;
		cout << "Left - a / A" << endl;
		cout << "Right - d / D" << endl;
		//todo - complete
		cout << "Up - w / W" << endl;
		cout << "Down - x / X" << endl;
		cout << "switch to the big ship - B / b" << endl;
		cout << "switch to the big ship - S / s" << endl;
	}

};