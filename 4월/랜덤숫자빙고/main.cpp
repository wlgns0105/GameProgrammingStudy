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

void set_matrix(int Min, int Max)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			bool is_same = false;
			Matrix[i][j].number = rand() % (Max - Min) + Min;
			for (int i1 = 0; i1 <= i; i1++)
			{
				for (int j1 = 0; i1*SIZE + j1 < i*SIZE + j; j1++)
				{
					if (Matrix[i][j].number == Matrix[i1][j1].number)
					{
						if (j == 0)
						{
							i--;
							j = SIZE - 1;
						}
						else
						{
							j--;
						}
						is_same = true;
						break;
					}
				}
				if (is_same) break;
			}
		}
	}
	return;
}

void reset_matrix(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Matrix[i][j].number = 0;
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

	int Min = NULL;
	int Max = NULL;
	
	bool is_valid = false;
	bool is_game_continue = true;
	bool is_setting_end = false;
	bool game_break = false;

	//////////////////////////////////////////////////////////////////
	///////////////////    ���� �ݺ�    //////////////////////////////
	//////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		//////////////////////////////////////////////////////////////////
		///////////////////    ���� �� ����    ///////////////////////////
		//////////////////////////////////////////////////////////////////
		Total_Bingo = 0;
		reset_matrix();
		shuffle_matrix();
		game_break = false;
		bool min_set = false;
		bool max_set = false;
		Min = 0;
		Max = 0;
		//////////////////////////////////////////////////////////////////
		///////////////////    ������ ����      //////////////////////////
		//////////////////////////////////////////////////////////////////
		is_setting_end = false;
		while (!is_setting_end)
		{

			system("cls");

			cout << "������ ������..." << endl;
			print_matrix();
			cout << "���� �� ���� : " << Min << " ~ " << Max << endl;
			cout << "1. �ּҰ� ���� 2. �ִ밪 ���� 3. ���� 4. ���� ���� 5. ����� :" << endl;

			is_valid = false;
			while (!is_valid)
			{
				cin >> Input;
				is_valid = is_valid_input(1<=Input && Input<=5);
			}

			switch (Input)
			{
			case 1:
				cout << "�ּҰ� �Է� :";
				is_valid = false;
				while (!is_valid)
				{
					cin >> Min;
					is_valid = is_valid_input(true);
				}
				min_set = true;
				break;
			case 2:
				cout << "�ִ밪 �Է� :";
				is_valid = false;
				while (!is_valid)
				{
					cin >> Max;
					is_valid = is_valid_input(true);
				}
				max_set = true;
				break;
				//////////////////////////////////////////////////////////////////
				///////////////////    ����      /////////////////////////////////
				//////////////////////////////////////////////////////////////////
			case 3:
				shuffle_matrix();
				break;
				//////////////////////////////////////////////////////////////////
				///////////////////    ���� ���� /////////////////////////////////
				//////////////////////////////////////////////////////////////////
			case 4:
				is_setting_end = true;
				break;
			case 5:
				//////////////////////////////////////////////////////////////////
				///////////////////    �����    /////////////////////////////////
				//////////////////////////////////////////////////////////////////
				is_setting_end = true;
				game_break = true;
				break;
			default:
				cout << "���� �߸��Ǿ����ϴ�" << endl;
				system("pause");
				break;
			}

			if (is_setting_end)
			{
				break;
			}

			if (min_set && max_set)
			{
				if (Min + SIZE * SIZE > Max)
				{
					cout << "�� ������ �ٽ� �����ϼ���" << endl;
					system("pause");
					Min = 0;
					Max = 0;
					min_set = false;
					max_set = false;
					continue;
				}
				else
				{
					set_matrix(Min, Max);
				}
			}
		}
		while (!game_break)
		{
			system("cls");
			cout << "���� ����: " << Total_Bingo << endl;
			print_matrix();
			cout << "���ڸ� �����ϼ��� (-1. ����� -2. ����) :" << endl;

			is_valid = false;
			while (!is_valid)
			{
				cin >> Input;
				is_valid = is_valid_input((Input >= Min && Input < Max) || Input == (-1) || Input == (-2));
			}

			switch (Input)
			{
			case -1:
				game_break = true;
				break;
			case -2:
				cout << "������ ���ڸ� �Է��ϼ��� (���� ����) :" << endl;

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
			Total_Bingo = check_row() + check_column() + check_dig();					//SIZE=1 �� �� �ߺ�ī��Ʈ

			//////////////////////////////////////////////////////////////////
			///////////////////    ��� ���� �޼� �� ���� ����    ////////////
			//////////////////////////////////////////////////////////////////
			if (Total_Bingo == 2 * SIZE + 2)
			{
				system("cls");
				cout << "���� ����: " << Total_Bingo << endl;
				print_matrix();
				cout << "�� �̻� ������ �� �����ϴ�." << endl;
				system("pause");
				game_break = true;
			}
		}
		is_game_continue = ContinueGame();
	}
	return 0;
}