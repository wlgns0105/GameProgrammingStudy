#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int Nanswer = rand()%900 + 100;
	int Ntest = 999;

	int Nlow = 100;
	int Nhigh = 999;

	while (Ntest - Nanswer)
	{
		system("cls");
		cout << "���� ����: " << Nlow << " ~ " << Nhigh << " �Դϴ�." << endl << endl;
		cout << "���� �Է��ϼ���" << endl;
		cin >> Ntest;

		if (Ntest > Nanswer)
		{
			cout << "�Է��� ���ڰ� Ů�ϴ�." << endl;
			if (Ntest < Nhigh)
			{
				Nhigh = Ntest;
			}
		}
		else if (Ntest < Nanswer)
		{
			cout << "�Է��� ���ڰ� �۽��ϴ�." << endl;
			if (Ntest > Nlow)
			{
				Nlow = Ntest;
			}
		}
		else
		{
			cout << "���� ������ϴ�." << endl;
		}

	}

	return 0;
}
