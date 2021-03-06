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
	/////////////////////	郸 积己			//////////////////////////////
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
				Deck[i].shape = "全";
				break;
			case 2:
				Deck[i].shape = "全";
				break;
			case 3:
				Deck[i].shape = "全";
				break;
			case 4:
				Deck[i].shape = "檬";
				break;
			case 5:
				Deck[i].shape = "檬";
				break;
			case 6:
				Deck[i].shape = "没";
				break;
			case 7:
				Deck[i].shape = "檬";
				break;
			case 9:
				Deck[i].shape = "没";
				break;
			case 10:
				Deck[i].shape = "没";
				break;
			case 12:
				Deck[i].shape = "檬";
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
				Deck[i].shape = "堡";
				break;
			case 3:
				Deck[i].shape = "堡";
				break;
			case 8:
				Deck[i].shape = "堡";
				break;
			case 11:
				Deck[i].shape = "堡";
				break;
			case 12:
				Deck[i].shape = "堡";
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
	/////////////////////	霸烙 馆汗 ////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		CardCount = 0;
		Money = 10000;
		shuffle(Deck);
		while (Money >= MIN_BET && CardCount <= 48-3)
		{
			system("cls");
			cout << "岿巢煌 霸烙" << endl;
			cout << "泅犁 家瘤陛: " << Money << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////	1锅掳 墨靛 箭磊 < 2锅掳 墨靛 箭磊 ////////////////////
			//////////////////////////////////////////////////////////////////////

			if (Deck[CardCount].number> Deck[CardCount + 1].number)
			{
				HWATU temp = Deck[CardCount];
				Deck[CardCount] = Deck[CardCount + 1];
				Deck[CardCount + 1] = temp;
			}
			//////////////////////////////////////////////////////////////////////
			//////////////////////	3厘狼 墨靛 免仿  /////////////////////////////
			//////////////////////////////////////////////////////////////////////
			print_card(Deck, CardCount);
			print_card(Deck, CardCount+1);
			cout << "??" << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	硅泼  ////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "硅泼 陛咀 (弥家 陛咀=100) : ";
			is_not_valid_input = true;
			while (is_not_valid_input)
			{
				cin >> Bet;
				is_not_valid_input = not_valid_input(Bet > Money || Bet < MIN_BET);
				if (Bet > Money)
				{
					cout << "硅泼 陛咀捞 呈公 臭嚼聪促." << endl;
				}
				if (Bet < MIN_BET)
				{
					cout << "硅泼 陛咀捞 呈公 撤嚼聪促." << endl;
				}
			}

			//////////////////////////////////////////////////////////////////////
			//////////////////////	搬苞 免仿  ///////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if ((Deck[CardCount].number < Deck[CardCount + 2].number) && (Deck[CardCount + 2].number < Deck[CardCount + 1].number))
			{
				cout << "铰府窍继嚼聪促. 洒电 墨靛绰 ";
				print_card(Deck, CardCount + 2);
				Money += Bet;
			}
			else
			{
				cout << "菩硅窍继嚼聪促. 洒电 墨靛绰 ";
				print_card(Deck, CardCount + 2);
				Money -= Bet;
			}
			cout << endl;
			CardCount += 3;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	霸烙 辆丰 捞酱 ///////////////////////////////
			//////////////////////////////////////////////////////////////////////
			system("pause");
			if (Money < MIN_BET)
			{
				cout << "家瘤陛捞 何练钦聪促." << endl;
			}
			if (CardCount > 48-3)
			{
				cout << "墨靛啊 何练钦聪促." << endl;
			}
		}
		ContinueGame();
	}
	return 0;
}