#include <iostream>
#include <time.h>

using namespace std;

void print_shape(int Shape)
{
	switch (Shape)
	{
	case 0:
		cout << "♠";
		break;
	case 1:
		cout << "◆";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "♣";
		break;
	default:
		cout << "무언가 잘못되었습니다." << endl;
		break;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int Card[52] = { NULL };
	int Money = 10000;
	int Bet = 0;
	int Shape = 0;
	int Total_Game = 0;

	int Left_Card[52] = { NULL };

	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
		Left_Card[i] = i;
	}

	bool new_game = true;
	char continue_ = 'a';

	while (new_game)
	{
		Total_Game = 0;
		Money = 10000;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				int dest = rand() % 52;
				int temp = Card[j];
				Card[j] = Card[dest];
				Card[dest] = temp;
			}
		}


		while (Money > 100 && Total_Game < 17)
		{
			system("cls");
			cout << "월남뽕 게임" << endl;
			cout << "현재 소지금: " << Money << endl;


			cout << "남은 카드" << endl;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					bool skip = false;
					for (int k = 0; k < Total_Game * 3; k++)
					{
						if (Card[k] == (i * 13 + j))
						{
							skip = true;
							cout << "\t";
							break;
						}
					}
					if (!skip)
					{
						cout << j + 1;
						print_shape(i);
						cout << "\t";
					}
				}
				cout << endl;
			}

			cout << endl;


			if (Card[Total_Game * 3] % 13 > Card[Total_Game * 3 + 1] % 13)
			{
				int temp = Card[Total_Game * 3];
				Card[Total_Game * 3] = Card[Total_Game * 3 + 1];
				Card[Total_Game * 3 + 1] = temp;
			}

			cout << Card[Total_Game * 3] % 13 + 1;
			print_shape(Card[Total_Game * 3] / 13);
			cout << "\t";
			cout << Card[Total_Game * 3 + 1] % 13 + 1;
			print_shape(Card[Total_Game * 3 + 1] / 13);
			cout << "\t";
			cout << "?" << endl;

			cout << "배팅 금액 (최소 금액=100) : ";
			cin >> Bet;

			while (Bet > Money) 
			{
				cout << "배팅 금액이 너무 높습니다." << endl;
				cout << "금액을 다시 입력하세요." << endl;
				cin >> Bet;
			}


			while (Bet < 100) 
			{
				cout << "배팅 금액이 너무 낮습니다." << endl;
				cout << "금액을 다시 입력하세요." << endl;
				cin >> Bet;
			}


			if ((Card[Total_Game * 3] % 13 < Card[Total_Game * 3 + 2] % 13) && (Card[Total_Game * 3 + 2] % 13 < Card[Total_Game * 3 + 1] % 13))
			{
				cout << "승리하셨습니다. 히든 카드는 ";
				cout << Card[Total_Game * 3 + 2] % 13 + 1;
				print_shape(Card[Total_Game * 3 + 2] / 13);
				Money += Bet;
			}
			else
			{
				cout << "패배하셨습니다. 히든 카드는 ";
				cout << Card[Total_Game * 3 + 2] % 13 + 1;
				print_shape(Card[Total_Game * 3 + 2] / 13);
				Money -= Bet;
			}
			cout << endl;
			Total_Game++;


			system("pause");
		}


		while (continue_ != 'y' && continue_ != 'n')
		{
			cout << "continue? (y / n)" << endl;
			cin >> continue_;
			if (continue_ == 'y') new_game = true;
			else if (continue_ == 'n') new_game = false;
		}
	}
	return 0;
}