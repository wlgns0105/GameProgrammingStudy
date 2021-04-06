#include <iostream>
#include <string>
#include <time.h>

#include "My_Functions.h"

using namespace std;

struct CARD
{
	int		number;
	char	alphabet;
	string	shape;
};

int main()
{
	srand((unsigned int)time(NULL));

	CARD		Deck[52] = { NULL };

	bool		B_GameContinue = true;
	bool		B_not_valid = true;

	int			Money = 10000;

	int			Select = NULL;
	int			Bet = NULL;

	int			Mode = NULL;
	int			CardCount = 0;

	//////////////////////////////////////////////////////////////////////
	/////////////////////	덱 생성			/////////////////////////////
	//////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 52; i++)
	{
		Deck[i].number = i % 13 + 1;

		switch (i % 13 + 1)
		{
		case 11:
			Deck[i].alphabet = 'J';
			break;
		case 12:
			Deck[i].alphabet = 'Q';
			break;
		case 13:
			Deck[i].alphabet = 'K';
			break;
		case 1:
			Deck[i].alphabet = 'A';
			break;
		default:
			break;
		}

		switch ((int)(i / 13))
		{
		case 0:
			Deck[i].shape = "♠";
			break;
		case 1:
			Deck[i].shape = "◆";
			break;
		case 2:
			Deck[i].shape = "♥";
			break;
		case 3:
			Deck[i].shape = "♣";
			break;
		default:
			cout << "무언가 잘못되었습니다" << endl;
			break;
		}
	}

	while (B_GameContinue)
	{
		Money = 10000;
		CardCount = 0;
		Bet = NULL;
		Mode = NULL;

		cout << "하이 로우 세븐 게임을 시작합니다" << endl;
		//////////////////////////////////////////////////////////////////////
		/////////////////////	모드 선택		//////////////////////////////
		//////////////////////////////////////////////////////////////////////
		cout << "1. 일반모드\t2.디버그모드" << endl;
		B_not_valid = true;
		while (B_not_valid)
		{
			cin >> Mode;
			B_not_valid = not_valid_input(Mode != 1 && Mode != 2);
		}

		//돈이 부족하거나 카드가 부족해질때까지 반복
		while (Money > 100 && CardCount < 52-6)	
		{
			system("cls");
			cout << "소지금 : " << Money << endl;
			//////////////////////////////////////////////////////////////////////
			/////////////////////	덱 셔플			/////////////////////////////
			//////////////////////////////////////////////////////////////////////
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 52; j++)
				{
					int dest = rand() % 52;
					CARD temp;

					temp = Deck[j];
					Deck[j] = Deck[dest];
					Deck[dest] = temp;
				}
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	6장의 카드 출력	/////////////////////////////
			//////////////////////////////////////////////////////////////////////
			switch (Mode)
			{
			//	일반모드
			case 1:
				for (int i = 0; i < 5; i++)
				{
					cout << Deck[CardCount + i].shape;
					//숫자가 2~10 이면 숫자출력
					if (Deck[CardCount + i].number > 1 && Deck[CardCount + i].number < 11)	
					{
						cout << Deck[CardCount + i].number << "\t";
					}
					//이외의 경우 해당되는 알파벳 출력 (A/K/Q/J)
					else
					{
						cout << Deck[CardCount + i].alphabet << "\t";							
					}
				}
				cout << "?" << endl;
				break;
			//	디버그모드
			case 2:
				for (int i = 0; i < 7; i++)
				{
					system("cls");
					cout << "소지금 : " << Money << endl;

					//지금까지 생성한 카드 출력
					for (int j = 0; j < 6; j++)
					{
						if (j>=i)
						{
							cout << "??\t";
						}
						else
						{
							cout << Deck[CardCount + j].shape;
							if (Deck[CardCount + j].number > 1 && Deck[CardCount + j].number < 11)
							{
								cout << Deck[CardCount + j].number << "\t";
							}
							else
							{
								cout << Deck[CardCount + j].alphabet << "\t";
							}
						}
					}
					cout << endl;
					if (i == 6)break;

					//i번째 카드 문양 설정
					cout << i + 1 << "번째 카드 문양을 고르기" << endl;
					cout << "1. ♠\t2. ◆\t3. ♥\t4. ♣" << endl;
					B_not_valid = true;
					while (B_not_valid)
					{
						cin >> Select;
						B_not_valid = not_valid_input(Select != 1 && Select != 2 && Select != 3 && Select != 4);
					}
					switch (Select)
					{
					case 1:
						Deck[CardCount + i].shape = "♠";
						break;
					case 2:
						Deck[CardCount + i].shape = "◆";
						break;
					case 3:
						Deck[CardCount + i].shape = "♥";
						break;
					case 4:
						Deck[CardCount + i].shape = "♣";
						break;
					default:
						cout << "무언가 잘못되었다." << endl;
						break;
					}
					//i번째 카드 숫자 설정
					cout << i + 1 << "번째 카드 숫자를 고르기(1~13)" << endl;
					B_not_valid = true;
					while (B_not_valid)
					{
						cin >> Select;
						B_not_valid = not_valid_input(Select < 1 || Select > 13);
					}
					Deck[CardCount + i].number = Select;

					switch (Select)
					{
					case 11:
						Deck[CardCount + i].alphabet = 'J';
						break;
					case 12:
						Deck[CardCount + i].alphabet = 'Q';
						break;
					case 13:
						Deck[CardCount + i].alphabet = 'K';
						break;
					case 1:
						Deck[CardCount + i].alphabet = 'A';
						break;
					default:
						break;
					}
				}
				break;
			default:
				cout << "무언가 잘못되었다." << endl;
				break;
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	하이/로우/세븐 결정	//////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "1. 하이\t2. 로우\t3. 세븐(10배)" << endl;

			B_not_valid = true;
			while (B_not_valid)
			{
				cin >> Select;
				B_not_valid = not_valid_input(Select != 1 && Select != 2 && Select != 3);
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	배팅금 결정			//////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "배팅금을 입력해주세요 : ";
			B_not_valid = true;
			while (B_not_valid)
			{
				cin >> Bet;
				B_not_valid = not_valid_input(Bet < 100 || Bet > Money);
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	결과에 따른 소지금 변화	//////////////////////
			//////////////////////////////////////////////////////////////////////
			bool WinCondition = (Select == 1 && Deck[CardCount + 5].number > 7) 
				|| (Select == 2 && Deck[CardCount + 5].number < 7) 
				|| (Select == 3 && Deck[CardCount + 5].number == 7);
			if (WinCondition)
			{
				//세븐으로 이기면 10배
				if (Select == 3)
				{
					Bet *= 10;
				}
				cout << "이겼다 (+" << Bet << ")" << endl;
				Money += Bet;
			}
			else
			{
				cout << "졌다 (-" << Bet << ")" << endl;
				Money -= Bet;
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	히든 카드 공개	//////////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "히든 카드 : ";
			cout << Deck[CardCount + 5].shape;
			if (Deck[CardCount + 5].number > 1 && Deck[CardCount + 5].number < 11)
			{
				cout << Deck[CardCount + 5].number << "\t";
			}
			else
			{
				cout << Deck[CardCount + 5].alphabet << "\t";
			}
			CardCount += 6;
			system("pause");
			//////////////////////////////////////////////////////////////////////
			/////////////////////	게임 중지 이슈	//////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if (Money <= 100)
			{
				cout << "소지금이 부족합니다." << endl;
				break;
			}
			if (CardCount > 52)
			{
				cout << "남은 카드가 부족합니다." << endl;
				break;
			}
		}
		//게임 재시작
		ContinueGame();
	}

	return 0;
}