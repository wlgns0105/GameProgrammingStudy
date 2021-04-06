#include <iostream>
#include <time.h>
#include <string>
#include "My_Functions.h"

#define LINE 10

using namespace std;

struct Piece
{
	string line[LINE];
	//string line[6] = { NULL };
};
//
//void puzzle_swap(int num, Piece** Puzzle, int position_x, int position_y,int Column, int Row)
//{
//	int change_x;
//	int change_y;
//	switch (num)
//	{
//	case 2:
//		change_x = 0;
//		change_y = 1;
//		break;
//	case 4:
//		change_x = -1;
//		change_y = 0;
//		break;
//	case 6:
//		change_x = 1;
//		change_y = 0;
//		break;
//	case 8:
//		change_x = 0;
//		change_y = -1;
//		break;
//	default:
//		cout << "무언가 잘못되었습니다." << endl;
//		break;
//	}
//	if ((position_x + change_x >= 0) && (position_x + change_x < Column) && (position_y + change_y >= 0) && (position_y + change_y < Row))
//	{
//		Piece temp = Puzzle[position_y][position_x];
//		Puzzle[position_y][position_x] = Puzzle[position_y + change_y][position_x + change_x];
//		Puzzle[position_y + change_y][position_x + change_x] = temp;
//
//		position_x = position_x + change_x;
//		position_y = position_y + change_y;
//	}
//};

int main()
{
	srand((unsigned int)time(NULL));

	int Row = 3;
	int Column = 3;

	string Picture[30][3] = { { {"                    "}, {"  ..::::::::::::::.."}, {"                    "} },
							  { {"                  ::"}, {":=::::::::::::::::::"}, {":=::.               "} },
							  { {"              .:=:::"}, {"::::::::::::::::::::"}, {":::::=::            "} },
							  { {"            :=::::::"}, {"::::::::::::::::::::"}, {"::::::::=:.         "} },
							  { {"          :=::::::.."}, {"..  ..::::::::::::::"}, {":::::::::::=.       "} },
							  { {"        .=::::::.. ."}, {"..... .:::::::::::::"}, {":::::::::::.:+      "} },
							  { {"       =:.::::.. ..."}, {"......::::::::::::::"}, {"::::::::::::::*:    "} },
							  { {"      +.:::::. ....."}, {"... .:::::::::::::::"}, {":::::::::::::.=+=   "} },
							  { {"     +.::::::. ....."}, {". ..::::::::::::::::"}, {":::::::::::::::+++  "} },
							  { {"    +.::::::::.. ..."}, {".:::::::::::::::::::"}, {"::::::::::::::.==+: "} },
							  { {"   :::::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::::::::.=+=* "} },
							  { {"   +.:::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::::::::.=++=="} },
							  { {"  .=::::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::::::::.++==*"} },
							  { {"  ::::::::::::::::::"}, {"::::::::::::::::::::"}, {":::::::::::::::+===*"} },
							  { {"  =.::::::::::::::::"}, {"::::::::::::::::::::"}, {":::::::::::::.=+===*"} },
							  { {"  ::::::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::::::::+====*"} },
							  { {"   +.:::::::::::::::"}, {"::::::::::::::::::::"}, {":::::::::::::++====+"} },
							  { {"   =.:::::::::::::::"}, {"::::::::::::::::::::"}, {":::::::::::.=+====+:"} },
							  { {"    =.::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::::.=+=====* "} },
							  { {"    ::::::::::::::::"}, {"::::::::::::::::::::"}, {"::::::::.:=+=====*  "} },
							  { {"     ::.::::::::::::"}, {"::::::::::::::::::::"}, {"::::::..=++===+=*.  "} },
							  { {"      :+:..:::::::::"}, {"::::::::::::::::::::"}, {"::::.:=+++====+*    "} },
							  { {"        *+==::...:::"}, {":::::::::::::::::::."}, {".::==+++=====++     "} },
							  { {"         :*++++==:::"}, {":.............::::=="}, {"=+++++====+++.      "} },
							  { {"           :++++++++"}, {"+++=========++++++++"}, {"++======+++.        "} },
							  { {"             :=*++=="}, {"+++++++++++++++====="}, {"====++++=.          "} },
							  { {"                :=++"}, {"++++===++=====+====+"}, {"+++*+:.             "} },
							  { {"                    "}, {".:=++++++++++++++*++"}, {"=:.                 "} },
							  { {"                    "}, {"      ....:::...    "}, {"                    "} },
							  { {"                    "}, {"                    "}, {"                    "} } };

	Piece Puzzle[3][3];
	Piece Answer[3][3];

	int Input = NULL;
	
	int position_x = 0;
	int position_y = 0;

	bool is_game_continue = true;
	bool is_valid_input = false;

	while (is_game_continue)
	{

		//////////////////////////////////////////////////////////////////////
		/////////////////////	그림 및 정답 초기화  /////////////////////////
		//////////////////////////////////////////////////////////////////////
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				for (int k = 0; k < LINE; k++)
				{
					Puzzle[i][j].line[k] = Picture[LINE * i + k][j];
					Answer[i][j].line[k] = Picture[LINE * i + k][j];
				}
			}
		}

		//////////////////////////////////////////////////////////////////////
		/////////////////////	그림 셔플  ///////////////////////////////////
		//////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 3; i++)
		{
			int RanNum = rand() % 4;
			int change_x;
			int change_y;
			switch (RanNum)
			{
			case 0:
				change_x = 0;
				change_y = 1;
				break;
			case 1:
				change_x = -1;
				change_y = 0;
				break;
			case 2:
				change_x = 1;
				change_y = 0;
				break;
			case 3:
				change_x = 0;
				change_y = -1;
				break;
			default:
				cout << "무언가 잘못되었습니다." << endl;
				break;
			}
			if ((position_x + change_x >= 0) && (position_x + change_x < Column) && (position_y + change_y >= 0) && (position_y + change_y < Row))
			{
				Piece temp = Puzzle[position_y][position_x];
				Puzzle[position_y][position_x] = Puzzle[position_y + change_y][position_x + change_x];
				Puzzle[position_y + change_y][position_x + change_x] = temp;

				position_x = position_x + change_x;
				position_y = position_y + change_y;
			}
		}

		bool game_break = false;
		while (!game_break)
		{
			system("cls");

			//////////////////////////////////////////////////////////////////////
			/////////////////////	그림 출력  ///////////////////////////////////
			//////////////////////////////////////////////////////////////////////

			for (int i = 0; i < Row; i++)
			{
				for (int k = 0; k < LINE; k++)
				{
					for (int j = 0; j < Column; j++)
					{
						cout << Puzzle[i][j].line[k] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;

			//////////////////////////////////////////////////////////////////////
			/////////////////////	이동 방향 선택  //////////////////////////////
			//////////////////////////////////////////////////////////////////////

			cout << "2.아래쪽\n4.왼쪽\n6.오른쪽\n8.위쪽\n0.리게임" << endl;
			is_valid_input = false;
			while (!is_valid_input)
			{
				cin >> Input;
				is_valid_input = !not_valid_input(Input != 0 && Input != 2 && Input != 4 && Input != 6 && Input != 8);
			}

			int change_x = 0;
			int change_y = 0;

			switch (Input)
			{
			case 0:
				game_break = true;
				break;
			case 2:
				change_x = 0;
				change_y = 1;
				break;
			case 4:
				change_x = -1;
				change_y = 0;
				break;
			case 6:
				change_x = 1;
				change_y = 0;
				break;
			case 8:
				change_x = 0;
				change_y = -1;
				break;
			default:
				cout << "무언가 잘못되었습니다." << endl;
				break;
			}

			if (game_break)
			{
				break;
			}

			if ((position_x + change_x >= 0) && (position_x + change_x < Column) && (position_y + change_y >= 0) && (position_y + change_y < Row))
			{
				Piece temp = Puzzle[position_y][position_x];
				Puzzle[position_y][position_x] = Puzzle[position_y + change_y][position_x + change_x];
				Puzzle[position_y + change_y][position_x + change_x] = temp;

				position_x = position_x + change_x;
				position_y = position_y + change_y;
			}

			//////////////////////////////////////////////////////////////////////
			/////////////////////	클리어 판정 검사 /////////////////////////////
			//////////////////////////////////////////////////////////////////////
			
			bool GameClear = true;
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Column; j++)
				{
					for (int k = 0; k < LINE; k++)
					{
						if (Puzzle[i][j].line[k] != Answer[i][j].line[k])
						{
							GameClear = false;
							break;
						}
					}
				}
				if (!GameClear) 
				{
					break;
				}
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	클리어 시 ////////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if (GameClear)
			{
				system("cls");
				for (int i = 0; i < Row; i++)
				{
					for (int k = 0; k < LINE; k++)
					{
						for (int j = 0; j < Column; j++)
						{
							cout << Puzzle[i][j].line[k] << " ";
						}
						cout << endl;
					}
					cout << endl;
				}
				cout << endl;
				cout << "게임 클리어!" << endl;
				system("pause");
				break;
			}
		}
		is_game_continue = ContinueGame();
	}


	return 0;
}