#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;



bool condition_check(int num1, int num2, int strike, int ball, int Digit)
{
	int temp_strike = 0;
	int temp_ball = 0;

	int temp_num1[9] = { 0 };
	int temp_num2[9] = { 0 };

	for (int j = 0; j < Digit; j++)
	{
		temp_num1[Digit - 1 - j] = num1 % 10;
		num1 = num1 / 10;
		temp_num2[Digit - 1 - j] = num2 % 10;
		num2 = num2 / 10;
	}

	for (int i = 0; i < Digit; i++)
	{
		for (int j = 0; j < Digit; j++)
		{
			if (temp_num1[i] == temp_num2[j])
			{
				if (i == j) temp_strike++;
				else temp_ball++;
			}
		}
	}

	return ((temp_strike == strike) && (temp_ball == ball));
}


int main()
{
	srand(time(NULL));
	int temp;

	int Num[9] = { 0 };
	int UNum[9] = { 0 };
	int Digit = 3;
	bool valid_digit = true;

	int User_Num[100] = { 0 };
	int strike[100] = { 0 };
	int ball[100] = { 0 };

	char Ccontinue = 'a';
	bool B_continue = true;

	int total_trial = 0;
	int answer = 0;

	int Com_Num = 0;
	
	int mode;
	bool valid_mode = false;

	int rand_index = rand() % 9;


	int temp_num[9];
	bool is_same = false;
	bool is_zero = false;
	int hint_num = 0;
	bool bool_temp = false;
	
	int num_low = 0;

	while (B_continue)
	{
		valid_digit = true;
		valid_mode = false;
		Ccontinue = 'a';
		total_trial = 0;
		system("cls");

		cout << "숫자 야구를 시작합니다." << endl;
		cout << "자리 수를 입력하세요. (3~9)" << endl;

		////////////////////////////////////자리 수 설정///////////////////////////////////////////////

		while (valid_digit)
		{
			cin >> Digit;
			if ((Digit != 3) && (Digit != 4) && (Digit != 5) && (Digit != 6) && (Digit != 7) && (Digit != 8) && (Digit != 9))
			{
				valid_digit = true;
				cout << "자리 수를 다시 입력하세요. (3~9)" << endl;
				cin.clear();												//4a 입력시 오류
				cin.ignore(INT_MAX, '\n');
			}
			else
			{
				valid_digit = false;
			}

		}

		//////////////////////////////////// 셔플 및 n 개 수 생성 ///////////////////////////////////////////////

		for (int i = 0; i < 9; i++)
		{
			Num[i] = i + 1;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				rand_index = rand() % 9;

				temp = Num[j];
				Num[j] = Num[rand_index];
				Num[rand_index] = temp;
			}
		}

		//////////////////////////////////// n 개 수 -> n 자리 수 생성 ///////////////////////////////////////////////

		Com_Num = 0;
		for (int i = 0; i < Digit; i++)
		{
			Com_Num *= 10;
			Com_Num += Num[i];
		}

		//cout << Com_Num << endl;

		cout << "1. 일반 모드\n2. 힌트 모드" << endl;

		while (!valid_mode)
		{
			cin >> mode;
			switch (mode)
			{
			case 1:
				valid_mode = true;
				break;
			case 2:
				valid_mode = true;
				break;
			default:
				cout << "모드를 다시 선택하세요" << endl;
				cin.clear();												//4a 입력시 오류
				cin.ignore(INT_MAX, '\n');
				break;
			}
		}



		//////////////////////////////////// 힌트 모드 최소값 설정 ///////////////////////////////////////////////

		for (int i = 0; i < Digit; i++)
		{
			num_low = num_low * 10;
			num_low += (i + 1);
		}


		//////////////////////////////////// 맞출 때까지 반복 ///////////////////////////////////////////////

		while (Com_Num - answer)
		{
			is_same = false;
			is_zero = false;
			hint_num = 0;


			total_trial++;
			strike[total_trial - 1] = 0;
			ball[total_trial - 1] = 0;

			cout << Digit << "자리 숫자를 입력하세요." << endl;
			cin >> User_Num[total_trial - 1];
			answer = User_Num[total_trial - 1];


			//////////////////////////////////// 입력한 n 자리 숫자 체크 ///////////////////////////////////////////////

			if (cin.fail())
			{
				cout << "입력이 int 형이 아닙니다." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				total_trial--;
				continue;	
			}
			else if (User_Num[total_trial - 1] < pow(10, Digit - 1) || User_Num[total_trial - 1] >= pow(10, Digit))
			{
				cout << "입력이 " << Digit << "자리 수가 아닙니다." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				total_trial--;
				continue;
			}		


			//////////////////////////////////// 입력한 n 자리 숫자 -> n 개 숫자 ///////////////////////////////////////////////

			temp = User_Num[total_trial - 1];
			for (int i = 0; i < Digit; i++)
			{
				UNum[Digit - i - 1] = temp % 10;
				temp = temp / 10;
			}


			//////////////////////////////////// strike, ball 판별 ///////////////////////////////////////////////
			for (int i = 0; i < Digit; i++)
			{
				for (int j = 0; j < Digit; j++)
				{
					if (UNum[i] == Num[j])
					{
						if (i == j) strike[total_trial - 1]++;
						else ball[total_trial - 1]++;
					}
				}
			}
			cout << strike[total_trial - 1] << " Strike\t" << ball[total_trial - 1] << " Ball\n" << endl;


			//////////////////////////////////// 힌트모드 ///////////////////////////////////////////////
			//////////////////////////////////// 힌트모드 ///////////////////////////////////////////////
			if (mode == 2)
			{

				cout << "Hint (10)" << endl;
				for (int i = num_low; i < pow(10, Digit); i++)
				{
					is_same = false;
					is_zero = false;
					temp = i;

					//////////////////////////////////// 자리 수 중 0 이 포함된 것 제외 ///////////////////////////////////////////////
					for (int j = 0; j < Digit; j++)
					{
						temp_num[Digit - 1 - j] = temp % 10;
						temp = temp / 10;
						if (temp_num[Digit - 1 - j] == 0)
						{
							is_zero = true;
							break;
						}
					}
					if (is_zero)
					{
						continue;
					}

					//////////////////////////////////// 겹치는 숫자가 있으면 제외 ///////////////////////////////////////////////

					for (int j = 0; j < Digit; j++)
					{
						for (int k = j + 1; k < Digit; k++)
						{
							if (temp_num[j] == temp_num[k])
							{
								is_same = true;
								break;
							}
						}
						if (is_same)
						{
							break;
						}
					}

					if (!is_same)
					{
						bool_temp = true;
						for (int j = 0; j < total_trial; j++)
						{

							//////////////////////////////////// 지금까지의 입력, strike, ball 을 만족하는 후보 ///////////////////////////////////////////////
							bool_temp = bool_temp && condition_check(i, User_Num[j], strike[j], ball[j], Digit);
							if (!bool_temp)
							{
								break;
							}
						}
						if (bool_temp)
						{
							if (hint_num == 0)
							{
								num_low = i;
							}
							hint_num++;
							cout << i << "\t";
						}
					}

					if (hint_num == 5)
					{
						break;
					}
				}
			}
			cout << endl;
		} 

		cout << "정답은 " << Com_Num << "입니다." << endl;

		cout << "시도 횟수 : " << total_trial << endl;

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