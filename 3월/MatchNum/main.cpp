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
		cout << "숫자 범위: " << Nlow << " ~ " << Nhigh << " 입니다." << endl << endl;
		cout << "값을 입력하세요" << endl;
		cin >> Ntest;

		if (Ntest > Nanswer)
		{
			cout << "입력한 숫자가 큽니다." << endl;
			if (Ntest < Nhigh)
			{
				Nhigh = Ntest;
			}
		}
		else if (Ntest < Nanswer)
		{
			cout << "입력한 숫자가 작습니다." << endl;
			if (Ntest > Nlow)
			{
				Nlow = Ntest;
			}
		}
		else
		{
			cout << "답을 맞췄습니다." << endl;
		}

	}

	return 0;
}
