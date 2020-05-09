#include "Sudocu.h"
#include <iostream>
#include <iomanip>



Game::~Game()
{



}

Game::Game()
{


}

void Game::GameMenu::mainMenu()
{
	
	int x;

	std::cin >> x;
	
	switch (gm)
	{
	case 0: 
	
		gm = PLAY;
		break;

	case 1: break;
		gm = OPTIONS;
	case 2: break;
		gm = EXIT;
	case 3: break;
//		gm = PLAY;
	default:
		break;
	}


}

void Game::GameMenu::showMainMenu()
{

	std::string gamemenu[] = { "START","OPTIONS","EXIT" };
	
	for (int i=0;i<3;i++) 
	{
		std::cout <<  "\t" << "\t" << std::setw(16) << "----------------" << "\n";
		std::cout << "\t" << "\t" << "|" << std::setw(10) << gamemenu[i] << std::setw(5) << "|" << "\n";
		std::cout <<"\t"<< "\t" << std::setw(16) << "----------------" << "\n";
		std::cout <<"\n" << "\n" ;
	}

	
}






Game::Sudocu_Field::~Sudocu_Field()
{

}



Game::Game_Options::Game_Options()
{

}

Game::Game_Options::~Game_Options()
{

}







void Game::Sudocu_Field::ArrayRotate(int raw ,ROTATE_DiRECTION rotateDirection, int N_Rotate)
{

	
	if (rotateDirection == RIGHT )
	{
		for (int i = 0; i < N_Rotate; i++)
		{
			int LastElement = this->GameField[raw][this->Field_size - 1];

			for (int j = this->Field_size-1  ; j > 0; j--)
			{
				
				this->GameField[raw][j] = this->GameField[raw][j - 1];

				if (j == 1) { this->GameField[raw][0] = LastElement; }   //Return rotate elment

			}
		}
	}

	
	if (rotateDirection == LEFT)
	{
		for (int i = 0; i < N_Rotate; i++)
		{
			int FirstElement = this->GameField[raw][0];

			for (int j = 0; j < this->Field_size-1; j++)           
			{
				
				GameField[raw][j] = GameField[raw][j+1];

				if (j == this->Field_size-2 ) { this->GameField[raw][j+1] = FirstElement; }   //Return rotate elment
			}

		}
	
	}
	


	
}
	
void Game::Sudocu_Field::GenerateField()
{

	std::cout << "Rotate Field Started \n";


	for (int i = 1; i < this->Field_size; i++)  //We need to rotate 0 3 6 | 1 4 7 | 2 5 8
	{   

		int  N;
		int cof = (i % 3);                  //Cofficient for Step for start number 
		int start = start = i / 3; ;        //Start number (0,1,2)

		                                    
		N = start + (3 * cof);               //count number of Rotate 
		

		if (N > 4)                                         //Optimization for right and left Rotate
		{ 
			ArrayRotate(i, ROTATE_DiRECTION::LEFT, 9-N); 
		}
		else 
		{ 
			ArrayRotate(i, ROTATE_DiRECTION::RIGHT, N); 
		}
		
	
	}
	std::cout << "Rotate Field was end \n";
	

	


}

void Game::Sudocu_Field::print()
{

	for (int i = 0; i < this->Field_size; i++)
	{

		if (i % 3 == 0) { std::cout << " ________  ________  ________ \n"; }

		for (int j = 0; j < this->Field_size; j++)
		{
			std::cout << " " << this->GameField[i][j] << " ";
			if ((j + 1) % 3 == 0) { std::cout << "|"; }
		}
		std::cout << "\n";

		if ((i + 1) % 9 == 0) { std::cout << " ________  ________  ________ \n"; }
	}
}
Game::Sudocu_Field::Sudocu_Field()
{

	for (int i = 0; i < Field_size; i++)
	{
		for (int j = 0; j < this->Field_size; j++)
		{

			this->GameField[i][j] = j+1;
			
		}
		
     }

	std::cout << "Field is generated \n";

	for (int i = 0; i < this->Field_size; i++)
	{
		for (int j = 0; j < this->Field_size; j++)
		{

			std::cout << this->GameField[i][j] <<" ";
		}
		
		std::cout << "\n";

	}

}






