/*

What i know about c++ on 10 april 2020/


*/

#include "Sudocu.h"

#include <iostream>

int main() 
{

//	SudocuField field;
	Game game;
	game.gameMenu.showMainMenu();
	game.gameMenu.mainMenu();

	game.Myfield.GenerateField();
	game.Myfield.print();

	system("pause");
	return 0;
}