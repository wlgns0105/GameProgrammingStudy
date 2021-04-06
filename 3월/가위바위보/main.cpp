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
		cout << "가위바위보를 시작합니다." << endl;
		cout << "0. 가위 1. 바위 2. 보" << endl;

		while (B_tie)
		{
			Ncom = rand() % 3;
			cin >> Nuser;
			B_valid_input = (Nuser == 0 || Nuser == 1 || Nuser == 2);

			while (!B_valid_input)
			{
				cout << "다시 입력하세요 : ";
				cin >> Nuser;
				B_valid_input = (Nuser == 0 || Nuser == 1 || Nuser == 2);
			}

			if (Ncom == 0) cout << "컴퓨터 (가위)\t";
			else if (Ncom == 1) cout << "컴퓨터 (바위)\t";
			else if (Ncom == 2) cout << "컴퓨터 (보)\t";

			cout << "vs\t";

			if (Nuser == 0) cout << "유저 (가위)" << endl;
			else if (Nuser == 1) cout << "유저 (바위)" << endl;
			else if (Nuser == 2) cout << "유저 (보)" << endl;

			if (Ncom == (Nuser + 1) % 3)
			{
				cout << "유저가 졌습니다." << endl;
				B_tie = false;
			}
			else if (Ncom == Nuser)
			{
				cout << "비겼습니다." << endl;		
				cout << "0. 가위 1. 바위 2. 보" << endl;
				B_tie = true;
			}
			else
			{
				cout << "유저가 이겼습니다." << endl;
				B_tie = false;
				Nwin++;
			}
		}
		Fwinrate = (float)Nwin / (float)Ncount;
		cout << "지금까지의 승률 : " << 100*Fwinrate << "%"<< endl;
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
