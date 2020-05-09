



class Game
{
public:
	class GameMenu 
	{

	public:
		enum GAME_MENU{ PLAY, OPTIONS,CONTINUE,EXIT };
		void mainMenu();
		void showMainMenu();
	};
	GameMenu gameMenu;


	class Sudocu_Field
	{
	private:
		enum ROTATE_DiRECTION { LEFT, RIGHT };
		const static int Field_size = 9;
		int GameField[Field_size][Field_size];

	public:
		virtual void ArrayRotate(int raw, ROTATE_DiRECTION rotateDirection, int N_Rotate);
		virtual void GenerateField();
		virtual void print();
		Sudocu_Field();
		~Sudocu_Field();

	};

	Sudocu_Field Myfield;

	class Game_Options
	{
	private:
	
		enum GAME_LEVEL { VERY_EASY, EASY, MIDDLE, HARD, VERY_HARD };
		
		const int window_size_x = 0;
		const int window_size_y = 0;
	
	public:
		GAME_LEVEL gl = EASY;

		Game_Options();
		~Game_Options();

	};
	Game_Options gOptions;


	Game();
	~Game();


};







