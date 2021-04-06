#include <iostream>
#include <time.h>
#include "My_Functions.h"

#define SIZE	5

using namespace std;

struct Bingo
{
	int number;
	bool select;
};

Bingo Matrix[SIZE][SIZE];

void reset_matrix(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Matrix[i][j].number = SIZE * i + j;
			Matrix[i][j].select = false;
		}
	}
	return;
}
void print_matrix(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].select)
			{
				cout << "#" << "\t";
			}
			else
			{
				cout << Matrix[i][j].number << "\t";
			}
		}
		cout << endl << endl;
	}
	return;
}
void shuffle_matrix(void)
{
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				int dest1 = rand() % SIZE;
				int dest2 = rand() % SIZE;

				Bingo temp = Matrix[i][j];
				Matrix[i][j] = Matrix[dest1][dest2];
				Matrix[dest1][dest2] = temp;
			}
		}
	}
	return;
}
void erase_num(int number)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].number == number)
			{
				Matrix[i][j].select = true;
			}
		}
	}
	return;
}
void recover_num(int number)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].number == number)
			{
				Matrix[i][j].select = false;
			}
		}
	}
	return;
}
int check_row(void)
{
	int Bingo_row = 0;
	bool Bingo;

	for (int i = 0; i < SIZE; i++)
	{
		Bingo = true;
		for (int j = 0; j < SIZE; j++)
		{
			Bingo = Bingo && Matrix[i][j].select;
		}
		if (Bingo) Bingo_row++;
	}
	return Bingo_row;
}
int check_column(void)
{
	int Bingo_column = 0;
	bool Bingo;

	for (int i = 0; i < SIZE; i++)
	{
		Bingo = true;
		for (int j = 0; j < SIZE; j++)
		{
			Bingo = Bingo && Matrix[j][i].select;
		}
		if (Bingo) Bingo_column++;
	}
	return Bingo_column;
}
int check_dig(void)
{
	int Bingo_dig = 0;
	bool Bingo;

	Bingo = true;
	for (int i = 0; i < SIZE; i++)
	{
		Bingo = Bingo && Matrix[i][i].select;
	}
	if (Bingo) Bingo_dig++;

	Bingo = true;
	for (int i = 0; i < SIZE; i++)
	{
		Bingo = Bingo && Matrix[i][SIZE - 1 - i].select;
	}
	if (Bingo) Bingo_dig++;
	return Bingo_dig;
}

int main()
{
	srand((unsigned int)time(NULL));

	int Total_Bingo = 0;
	int Input = NULL;

	bool is_valid = false;
	bool is_game_continue = true;
	bool game_break = false;

	//////////////////////////////////////////////////////////////////
	///////////////////    게임 반복    //////////////////////////////
	//////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		//////////////////////////////////////////////////////////////////
		///////////////////    리셋 및 셔플    ///////////////////////////
		//////////////////////////////////////////////////////////////////
		Total_Bingo = 0;
		reset_matrix();
		shuffle_matrix();

		game_break = false;
		while (!game_break)
		{
			system("cls");
			cout << "빙고 개수: " << Total_Bingo << endl;
			print_matrix();
			cout << "숫자를 선택하세요 (-1. 재시작 -2. 수정) :" << endl;

			is_valid = false;
			while (!is_valid)
			{
				cin >> Input;
				is_valid = is_valid_input((Input >= 0 && Input < SIZE*SIZE) || Input == (-1) || Input == (-2));
			}

			switch (Input)
			{
			case -1:
				game_break = true;
				break;
			case -2:
				cout << "수정할 숫자를 입력하세요 (선택 해제) :" << endl;

				is_valid = false;
				while (!is_valid)
				{
					cin >> Input;
					is_valid = is_valid_input(Input >= 0 && Input < SIZE*SIZE);
				}

				recover_num(Input);
				break;
			default:
				erase_num(Input);
				break;
			}
			Total_Bingo = check_row() + check_column() + check_dig();					//SIZE=1 일 때 중복카운트

			//////////////////////////////////////////////////////////////////
			///////////////////    모든 빙고 달성 시 게임 종료    ////////////
			//////////////////////////////////////////////////////////////////
			if (Total_Bingo == 2 * SIZE + 2)
			{
				system("cls");
				cout << "빙고 개수: " << Total_Bingo << endl;
				print_matrix();
				cout << "더 이상 선택할 수 없습니다." << endl;
				system("pause");
				game_break = true;
			}
		}
		is_game_continue = ContinueGame();
	}
	return 0;
}