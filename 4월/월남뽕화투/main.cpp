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
	/////////////////////	덱 생성			//////////////////////////////
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
				Deck[i].shape = "홍";
				break;
			case 2:
				Deck[i].shape = "홍";
				break;
			case 3:
				Deck[i].shape = "홍";
				break;
			case 4:
				Deck[i].shape = "초";
				break;
			case 5:
				Deck[i].shape = "초";
				break;
			case 6:
				Deck[i].shape = "청";
				break;
			case 7:
				Deck[i].shape = "초";
				break;
			case 9:
				Deck[i].shape = "청";
				break;
			case 10:
				Deck[i].shape = "청";
				break;
			case 12:
				Deck[i].shape = "초";
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
				Deck[i].shape = "광";
				break;
			case 3:
				Deck[i].shape = "광";
				break;
			case 8:
				Deck[i].shape = "광";
				break;
			case 11:
				Deck[i].shape = "광";
				break;
			case 12:
				Deck[i].shape = "광";
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
	/////////////////////	게임 반복 ////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	while (is_game_continue)
	{
		CardCount = 0;
		Money = 10000;
		shuffle(Deck);
		while (Money >= MIN_BET && CardCount <= 48-3)
		{
			system("cls");
			cout << "월남뽕 게임" << endl;
			cout << "현재 소지금: " << Money << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////	1번째 카드 숫자 < 2번째 카드 숫자 ////////////////////
			//////////////////////////////////////////////////////////////////////

			if (Deck[CardCount].number> Deck[CardCount + 1].number)
			{
				HWATU temp = Deck[CardCount];
				Deck[CardCount] = Deck[CardCount + 1];
				Deck[CardCount + 1] = temp;
			}
			//////////////////////////////////////////////////////////////////////
			//////////////////////	3장의 카드 출력  /////////////////////////////
			//////////////////////////////////////////////////////////////////////
			print_card(Deck, CardCount);
			print_card(Deck, CardCount+1);
			cout << "??" << endl;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	배팅  ////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "배팅 금액 (최소 금액=100) : ";
			is_not_valid_input = true;
			while (is_not_valid_input)
			{
				cin >> Bet;
				is_not_valid_input = not_valid_input(Bet > Money || Bet < MIN_BET);
				if (Bet > Money)
				{
					cout << "배팅 금액이 너무 높습니다." << endl;
				}
				if (Bet < MIN_BET)
				{
					cout << "배팅 금액이 너무 낮습니다." << endl;
				}
			}

			//////////////////////////////////////////////////////////////////////
			//////////////////////	결과 출력  ///////////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if ((Deck[CardCount].number < Deck[CardCount + 2].number) && (Deck[CardCount + 2].number < Deck[CardCount + 1].number))
			{
				cout << "승리하셨습니다. 히든 카드는 ";
				print_card(Deck, CardCount + 2);
				Money += Bet;
			}
			else
			{
				cout << "패배하셨습니다. 히든 카드는 ";
				print_card(Deck, CardCount + 2);
				Money -= Bet;
			}
			cout << endl;
			CardCount += 3;

			//////////////////////////////////////////////////////////////////////
			//////////////////////	게임 종료 이슈 ///////////////////////////////
			//////////////////////////////////////////////////////////////////////
			system("pause");
			if (Money < MIN_BET)
			{
				cout << "소지금이 부족합니다." << endl;
			}
			if (CardCount > 48-3)
			{
				cout << "카드가 부족합니다." << endl;
			}
		}
		ContinueGame();
	}
	return 0;
}