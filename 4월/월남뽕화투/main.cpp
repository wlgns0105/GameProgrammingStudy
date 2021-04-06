#include <iostream>
#include <string>
#include <time.h>

#include "My_Functions.h"

using namespace std;

#define MIN_BET 100

struct HWATU
{
	int		number;
	string	shape;
};

void shuffle(HWATU Deck[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			int dest = rand() % 48;
			HWATU temp = Deck[j];
			Deck[j] = Deck[dest];
			Deck[dest] = temp;
		}
	}
	return;
}
void print_card(HWATU Deck[], int number)
{
	cout << Deck[number].shape << Deck[number].number << "\t";
	return;
}
void print_deck(HWATU Deck[])
{
	for (int i = 0; i < 48; i++)
	{
		print_card(Deck, i);
		if (i % 12 == 11)
		{
			cout << endl;
		}
	}
	return;
}

int main()
{
	srand((unsigned int)time(NULL));

	HWATU Deck[48] = { NULL };
	HWATU Left_Deck[48] = { NULL };
	int Money = 10000;
	int Bet = 0;
	int CardCount = 0;

	bool is_game_continue = true;
	bool is_not_valid_input = true;

	//////////////////////////////////////////////////////////////////////
	/////////////////////	�� ����			//////////////////////////////
	//////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 48; i++)
	{
		Deck[i].number = i % 12 + 1;
		switch (i / 12)
		{
		case 0:
			switch (i % 12 + 1)
			{
			case 1:
				Deck[i].shape = "ȫ";
				break;
			case 2:
				Deck[i].shape = "ȫ";
				break;
			case 3:
				Deck[i].shape = "ȫ";
				break;
			case 4:
				Deck[i].shape = "��";
				break;
			case 5:
				Deck[i].shape = "��";
				break;
			case 6:
				Deck[i].shape = "û";
				break;
			case 7:
				Deck[i].shape = "��";
				break;
			case 9:
				Deck[i].shape = "û";
				break;
			case 10:
				Deck[i].shape = "û";
				break;
			case 12:
				Deck[i].shape = "��";
				break;
			default:
				Deck[i].shape = " ";
				break;
			}
			break;
		case 1:
			switch (i % 12 + 1)
			{
			case 1:
				Deck[i].shape = "��";
				break;
			case 3:
				Deck[i].shape = "��";
				break;
			case 8:
				Deck[i].shape = "��";
				break;
			case 11:
				Deck[i].shape = "��";
				break;
			case 12:
				Deck[i].shape = "��";
				break;
			default:
				Deck[i].shape = " ";
				break;
			}
			break;
		default:
			Deck[i].shape = " ";
			break;
		}
	}

	//////////////////////////////////////////////////////////////////////
	/////////////////////	���� �ݺ� ////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		CardCount = 0;
		Money = 10000;
		shuffle(Deck);
		while (Money >= MIN_BET && CardCount <= 48-3)
		{
			system("cls");
			cout << "������ ����" << endl;
			cout << "���� ������: " << Money << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////	1��° ī�� ���� < 2��° ī�� ���� ////////////////////
			//////////////////////////////////////////////////////////////////////

			if (Deck[CardCount].number> Deck[CardCount + 1].number)
			{
				HWATU temp = Deck[CardCount];
				Deck[CardCount] = Deck[CardCount + 1];
				Deck[CardCount + 1] = temp;
			}
			//////////////////////////////////////////////////////////////////////
			//////////////////////	3���� ī�� ���  /////////////////////////////
			//////////////////////////////////////////////////////////////////////
			print_card(Deck, CardCount);
			print_card(Deck, CardCount+1);
			cout << "??" << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	����  ////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "���� �ݾ� (�ּ� �ݾ�=100) : ";
			is_not_valid_input = true;
			while (is_not_valid_input)
			{
				cin >> Bet;
				is_not_valid_input = not_valid_input(Bet > Money || Bet < MIN_BET);
				if (Bet > Money)
				{
					cout << "���� �ݾ��� �ʹ� �����ϴ�." << endl;
				}
				if (Bet < MIN_BET)
				{
					cout << "���� �ݾ��� �ʹ� �����ϴ�." << endl;
				}
			}

			//////////////////////////////////////////////////////////////////////
			//////////////////////	��� ���  ///////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if ((Deck[CardCount].number < Deck[CardCount + 2].number) && (Deck[CardCount + 2].number < Deck[CardCount + 1].number))
			{
				cout << "�¸��ϼ̽��ϴ�. ���� ī��� ";
				print_card(Deck, CardCount + 2);
				Money += Bet;
			}
			else
			{
				cout << "�й��ϼ̽��ϴ�. ���� ī��� ";
				print_card(Deck, CardCount + 2);
				Money -= Bet;
			}
			cout << endl;
			CardCount += 3;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	���� ���� �̽� ///////////////////////////////
			//////////////////////////////////////////////////////////////////////
			system("pause");
			if (Money < MIN_BET)
			{
				cout << "�������� �����մϴ�." << endl;
			}
			if (CardCount > 48-3)
			{
				cout << "ī�尡 �����մϴ�." << endl;
			}
		}
		ContinueGame();
	}
	return 0;
}