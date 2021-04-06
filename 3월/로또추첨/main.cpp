#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int last_num[6] = { 10, 11, 20, 21, 25, 41 };
	int bonus_num = 40;
	int num[6];

	int num_correct = 0;
	int bonus_num_correct = 0;

	int choose_num;
	int breakpoint;

	int total_num = 0;
	char Ccontinue = 'a';
	bool B_continue = true;

	bool same = true;
	bool valid_choose_num = false;
	bool escape = false;

	while (B_continue)
	{
		system("cls");
		total_num = 0;
		num_correct = 0;
		bonus_num_correct = 0;
		Ccontinue = 'a';
		same = true;
		valid_choose_num = false;
		escape = false;


		cout << "956ȸ �ζ� ��ȣ" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << last_num[i] << "\t";
		}
		cout << "+\t" << bonus_num << endl;

		cout << "1. 1ȸ �̱�\n2. 1�� ���� ������ �̱�\n3. 2�� ���� ������ �̱�\n4. 3�� ���� ������ �̱�\n5. 4�� ���� ������ �̱�\n6. 5�� ���� ������ �̱�\n" << endl;
		cin >> choose_num;



		while (!valid_choose_num)
		{
			switch (choose_num)
			{
			case 1:
				escape = true;
				breakpoint = 6;
				valid_choose_num = true;
				break;
			case 2:
				breakpoint = 6;
				valid_choose_num = true;
				break;
			case 3:
				breakpoint = 15;
				valid_choose_num = true;
				break;
			case 4:
				breakpoint = 5;
				valid_choose_num = true;
				break;
			case 5:
				breakpoint = 4;
				valid_choose_num = true;
				break;
			case 6:
				breakpoint = 3;
				valid_choose_num = true;
				break;
			default:
				cout << "��ȣ�� �ٽ� �����ϼ���" << endl;
				cin >> choose_num;
				break;
			}
		}


		while (num_correct + 10 * bonus_num_correct - breakpoint)
		{
			total_num++;
			num_correct = 0;
			bonus_num_correct = 0;

			num[0] = rand() % 45 + 1;
			for (int i = 1; i < 6; i++)
			{
				same = true;
				while (same)
				{
					num[i] = rand() % 45 + 1;
					for (int j = 0; j < i; j++)
					{
						if (num[i] == num[j])
						{
							same = true;
							break;
						}
						else
						{
							same = false;
							continue;
						}
					}
				}
			}

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (num[i] == last_num[j])
					{
						num_correct++;
					}
				}
				if (num[i] == bonus_num)
				{
					bonus_num_correct++;
				}
			}
			if (escape)
			{
				break;
			}
		}

		cout << "�̹��� ���� �ζ� ��ȣ" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << num[i] << "\t";
		}
		cout << endl;

		switch (num_correct + 10 * bonus_num_correct)
		{
		case 6:
			cout << "1�� ��÷�Դϴ�." << endl;
			cout << "��÷�� 2,022,982,671��!" << endl;
			break;
		case 15:
			cout << "2�� ��÷�Դϴ�." << endl;
			cout << "��÷�� 27,270,600��!" << endl;
			break;
		case 5:
			cout << "3�� ��÷�Դϴ�." << endl;
			cout << "��÷�� 1,214,806��!" << endl;
			break;
		case 4:
			cout << "4�� ��÷�Դϴ�." << endl;
			cout << "��÷�� 50,000��!" << endl;
			break;
		case 3:
			cout << "5�� ��÷�Դϴ�." << endl;
			cout << "��÷�� 5,000��!" << endl;
			break;
		default:
			cout << "���Դϴ�." << endl;
			cout << "��÷�� 0��!" << endl;
			break;
		}

		cout << "�� Ƚ�� : " << total_num << endl;


		while (Ccontinue != 'y' && Ccontinue != 'n')
		{
			cout << "continue? (y / n)" << endl;
			cin >> Ccontinue;
			if (Ccontinue == 'y') B_continue = true;
			else if (Ccontinue == 'n') B_continue = false;
		}
	}


	return 0;
}