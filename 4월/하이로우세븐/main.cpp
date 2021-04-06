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
	/////////////////////	�� ����			/////////////////////////////
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
			Deck[i].shape = "��";
			break;
		case 1:
			Deck[i].shape = "��";
			break;
		case 2:
			Deck[i].shape = "��";
			break;
		case 3:
			Deck[i].shape = "��";
			break;
		default:
			cout << "���� �߸��Ǿ����ϴ�" << endl;
			break;
		}
	}

	while (B_GameContinue)
	{
		Money = 10000;
		CardCount = 0;
		Bet = NULL;
		Mode = NULL;

		cout << "���� �ο� ���� ������ �����մϴ�" << endl;
		//////////////////////////////////////////////////////////////////////
		/////////////////////	��� ����		//////////////////////////////
		//////////////////////////////////////////////////////////////////////
		cout << "1. �Ϲݸ��\t2.����׸��" << endl;
		B_not_valid = true;
		while (B_not_valid)
		{
			cin >> Mode;
			B_not_valid = not_valid_input(Mode != 1 && Mode != 2);
		}

		//���� �����ϰų� ī�尡 �������������� �ݺ�
		while (Money > 100 && CardCount < 52-6)	
		{
			system("cls");
			cout << "������ : " << Money << endl;
			//////////////////////////////////////////////////////////////////////
			/////////////////////	�� ����			/////////////////////////////
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
			/////////////////////	6���� ī�� ���	/////////////////////////////
			//////////////////////////////////////////////////////////////////////
			switch (Mode)
			{
			//	�Ϲݸ��
			case 1:
				for (int i = 0; i < 5; i++)
				{
					cout << Deck[CardCount + i].shape;
					//���ڰ� 2~10 �̸� �������
					if (Deck[CardCount + i].number > 1 && Deck[CardCount + i].number < 11)	
					{
						cout << Deck[CardCount + i].number << "\t";
					}
					//�̿��� ��� �ش�Ǵ� ���ĺ� ��� (A/K/Q/J)
					else
					{
						cout << Deck[CardCount + i].alphabet << "\t";							
					}
				}
				cout << "?" << endl;
				break;
			//	����׸��
			case 2:
				for (int i = 0; i < 7; i++)
				{
					system("cls");
					cout << "������ : " << Money << endl;

					//���ݱ��� ������ ī�� ���
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

					//i��° ī�� ���� ����
					cout << i + 1 << "��° ī�� ������ ����" << endl;
					cout << "1. ��\t2. ��\t3. ��\t4. ��" << endl;
					B_not_valid = true;
					while (B_not_valid)
					{
						cin >> Select;
						B_not_valid = not_valid_input(Select != 1 && Select != 2 && Select != 3 && Select != 4);
					}
					switch (Select)
					{
					case 1:
						Deck[CardCount + i].shape = "��";
						break;
					case 2:
						Deck[CardCount + i].shape = "��";
						break;
					case 3:
						Deck[CardCount + i].shape = "��";
						break;
					case 4:
						Deck[CardCount + i].shape = "��";
						break;
					default:
						cout << "���� �߸��Ǿ���." << endl;
						break;
					}
					//i��° ī�� ���� ����
					cout << i + 1 << "��° ī�� ���ڸ� ����(1~13)" << endl;
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
				cout << "���� �߸��Ǿ���." << endl;
				break;
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	����/�ο�/���� ����	//////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "1. ����\t2. �ο�\t3. ����(10��)" << endl;

			B_not_valid = true;
			while (B_not_valid)
			{
				cin >> Select;
				B_not_valid = not_valid_input(Select != 1 && Select != 2 && Select != 3);
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	���ñ� ����			//////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "���ñ��� �Է����ּ��� : ";
			B_not_valid = true;
			while (B_not_valid)
			{
				cin >> Bet;
				B_not_valid = not_valid_input(Bet < 100 || Bet > Money);
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	����� ���� ������ ��ȭ	//////////////////////
			//////////////////////////////////////////////////////////////////////
			bool WinCondition = (Select == 1 && Deck[CardCount + 5].number > 7) 
				|| (Select == 2 && Deck[CardCount + 5].number < 7) 
				|| (Select == 3 && Deck[CardCount + 5].number == 7);
			if (WinCondition)
			{
				//�������� �̱�� 10��
				if (Select == 3)
				{
					Bet *= 10;
				}
				cout << "�̰�� (+" << Bet << ")" << endl;
				Money += Bet;
			}
			else
			{
				cout << "���� (-" << Bet << ")" << endl;
				Money -= Bet;
			}
			//////////////////////////////////////////////////////////////////////
			/////////////////////	���� ī�� ����	//////////////////////////////
			//////////////////////////////////////////////////////////////////////
			cout << "���� ī�� : ";
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
			/////////////////////	���� ���� �̽�	//////////////////////////////
			//////////////////////////////////////////////////////////////////////
			if (Money <= 100)
			{
				cout << "�������� �����մϴ�." << endl;
				break;
			}
			if (CardCount > 52)
			{
				cout << "���� ī�尡 �����մϴ�." << endl;
				break;
			}
		}
		//���� �����
		ContinueGame();
	}

	return 0;
}