#include <iostream>
#include <time.h>
#include <string>
#include "My_Functions.h"

#define SIZE	5

using namespace std;

struct Bingo
{
	string word;
	bool select;
};

Bingo Matrix[SIZE][SIZE];

void reset_matrix(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Matrix[i][j].word = "";
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
				cout << Matrix[i][j].word << "\t";
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
void select_num(string word)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].word == word)
			{
				Matrix[i][j].select = true;
			}
		}
	}
	return;
}
void unselect_num(string word)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].word == word)
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

bool continue_fill_matrix(string word)
{
	bool is_continue = false;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].word != "")
			{
				continue;
			}
			else
			{
				Matrix[i][j].word = word;
				is_continue = true;
				break;
			}
		}
		if (is_continue) break;
	}
	return is_continue;
}
bool edit(string word, string edit_word)
{
	bool is_edit = false;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].word == word)
			{
				Matrix[i][j].word = edit_word;
				is_edit = true;
				break;
			}
		}
		if (is_edit) break;
	}
	return is_edit;
}
bool scan_same(string word)
{
	bool is_scan_same = false;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].word == word)
			{
				is_scan_same = true;
				break;
			}
		}
		if (is_scan_same) break;
	}
	return is_scan_same;
}

void print_selected(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (Matrix[i][j].select)
			{
				cout << Matrix[i][j].word << "\t";
			}
		}
	}
	return;
}

int main()
{
	srand((unsigned int)time(NULL));

	int Total_Bingo = 0;
	int Input = NULL;
	string Word = { NULL };
	string Word2 = { NULL };

	bool is_valid = false;
	bool is_game_continue = true;
	bool game_break = false;
	bool is_setting_end = false;

	//////////////////////////////////////////////////////////////////
	///////////////////    게임 반복    //////////////////////////////
	//////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		Total_Bingo = 0;
		//////////////////////////////////////////////////////////////////
		///////////////////    리셋      /////////////////////////////////
		//////////////////////////////////////////////////////////////////
		reset_matrix();
		//////////////////////////////////////////////////////////////////
		///////////////////    빙고판 세팅      //////////////////////////
		//////////////////////////////////////////////////////////////////
		is_setting_end = false;
		game_break = false;
		while (!is_setting_end)
		{
			system("cls");
			cout << "빙고판 생성중..." << endl;
			print_matrix();
			cout << "1. 이어서 입력 2. 수정 3. 셔플 4. 생성 종료 5. 재시작 6. 자동채우기 :" << endl;
			is_valid = false;
			while (!is_valid)
			{
				cin >> Input;
				is_valid = is_valid_input(Input >= 1 && Input <= 6);
			}

			switch (Input)
			{
			//////////////////////////////////////////////////////////////////
			///////////////////    이어서 입력      //////////////////////////
			//////////////////////////////////////////////////////////////////
			case 1:
				cout << "문자열 입력 :";
				cin >> Word;
				if (scan_same(Word))
				{
					cout << "이미 해당 문자열이 있습니다." << endl;
					system("pause");
					break;
				}
				if (!continue_fill_matrix(Word))	
				{
					cout << "빈 공간이 부족합니다" << endl;
					system("pause");
				}
				break;
			//////////////////////////////////////////////////////////////////
			///////////////////    수정      /////////////////////////////////
			//////////////////////////////////////////////////////////////////
			case 2:
				cout << "수정할 문자열을 입력하세요 (선택 해제) :";
				cin >> Word;
				if (!scan_same(Word))
				{
					cout << "해당 문자열이 없습니다." << endl;
					system("pause");
					break;
				}
				cout << "문자열 입력 :";
				cin >> Word2;
				edit(Word,Word2);
				break;
			//////////////////////////////////////////////////////////////////
			///////////////////    셔플      /////////////////////////////////
			//////////////////////////////////////////////////////////////////
			case 3:
				shuffle_matrix();
				break;
				//////////////////////////////////////////////////////////////////
				///////////////////    생성 종료 /////////////////////////////////
				//////////////////////////////////////////////////////////////////
			case 4:
				if (continue_fill_matrix(""))
				{
					cout << "빈 공간이 남아있습니다" << endl;
					system("pause");
				}
				else
				{
					is_setting_end = true;
				}
				break;
			case 5:
				//////////////////////////////////////////////////////////////////
				///////////////////    재시작    /////////////////////////////////
				//////////////////////////////////////////////////////////////////
				is_setting_end = true;
				game_break = true;
				break;
			case 6:
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						Matrix[i][j].word = (char)(i*SIZE + j + 33);
					}
				}
				break;
			default:
				cout << "무언가 잘못되었습니다" << endl;
				system("pause");
				break;
			}
		}
		//////////////////////////////////////////////////////////////////
		///////////////////   빙고 게임 시작    //////////////////////////
		//////////////////////////////////////////////////////////////////
		while (!game_break)
		{
			system("cls");
			cout << "빙고 게임" << endl;
			cout << "지금까지 선택된 문자열" << endl << endl;
			print_selected();
			cout << endl << endl;
			cout << "빙고 개수 :" << Total_Bingo << endl;
			print_matrix();
			cout << "1. 문자열 선택 2. 선택 취소 3. 재시작) :";
			is_valid = false;
			cin >> Input;
			switch (Input)
			{
			case 1:
				cout << "선택할 문자열을 입력하세요 :";
				cin >> Word;
				select_num(Word);
				break;
			case 2:
				cout << "수정할 문자열을 입력하세요 (선택 해제) :";
				cin >> Word;
				unselect_num(Word);
				break;
			case 3:
				game_break = true;
				break;
			default:
				cout << "무언가 잘못되었습니다" << endl;
				system("pause");
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