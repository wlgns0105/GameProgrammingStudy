#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int Ncom;
	int Nuser;
	float Fwinrate = 0;
	int Ncount = 0;
	int Nwin = 0;

	bool B_valid_input;
	bool B_tie;
	bool B_continue = true;
	char Ccontinue = 'a';
	while (B_continue)
	{
		Ncount++;
		B_tie = true;
		B_valid_input = true;
		Ccontinue = 'a';

		system("cls");
		cout << "Round " << Ncount << endl;
		cout << "������������ �����մϴ�." << endl;
		cout << "0. ���� 1. ���� 2. ��" << endl;

		while (B_tie)
		{
			Ncom = rand() % 3;
			cin >> Nuser;
			B_valid_input = (Nuser == 0 || Nuser == 1 || Nuser == 2);

			while (!B_valid_input)
			{
				cout << "�ٽ� �Է��ϼ��� : ";
				cin >> Nuser;
				B_valid_input = (Nuser == 0 || Nuser == 1 || Nuser == 2);
			}

			if (Ncom == 0) cout << "��ǻ�� (����)\t";
			else if (Ncom == 1) cout << "��ǻ�� (����)\t";
			else if (Ncom == 2) cout << "��ǻ�� (��)\t";

			cout << "vs\t";

			if (Nuser == 0) cout << "���� (����)" << endl;
			else if (Nuser == 1) cout << "���� (����)" << endl;
			else if (Nuser == 2) cout << "���� (��)" << endl;

			if (Ncom == (Nuser + 1) % 3)
			{
				cout << "������ �����ϴ�." << endl;
				B_tie = false;
			}
			else if (Ncom == Nuser)
			{
				cout << "�����ϴ�." << endl;		
				cout << "0. ���� 1. ���� 2. ��" << endl;
				B_tie = true;
			}
			else
			{
				cout << "������ �̰���ϴ�." << endl;
				B_tie = false;
				Nwin++;
			}
		}
		Fwinrate = (float)Nwin / (float)Ncount;
		cout << "���ݱ����� �·� : " << 100*Fwinrate << "%"<< endl;
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
