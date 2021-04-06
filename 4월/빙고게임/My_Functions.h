#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#pragma once

#include <iostream>

using namespace std;
//
//int is_valid_input_int(int input, bool Condition)
//{
//	int Input = input;
//	bool is_valid = false;
//	while (!is_valid)
//	{
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(256, '\n');
//			cout << "유효한 입력 형식이 아닙니다." << endl;
//			cout << "다시 입력해주세요" << endl;
//			is_valid = false;
//			cin >> Input;
//		}
//		else if (!Condition)
//		{
//			cin.clear();
//			cin.ignore(256, '\n');
//			cout << "유효한 입력 범위가 아닙니다." << endl;
//			cout << "다시 입력해주세요" << endl;
//			is_valid = false;
//			cin >> Input;
//		}
//		else
//		{
//			is_valid = true;
//			break;
//		}
//	}
//	return Input;
//}

bool is_valid_input(bool Condition)
{
	bool return_ = NULL;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "유효한 입력 형식이 아닙니다." << endl;
		cout << "다시 입력해주세요" << endl;
		return_ = false;
	}
	else if (!Condition)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "유효한 입력 범위가 아닙니다." << endl;
		cout << "다시 입력해주세요" << endl;
		return_ = false;
	}
	else
	{
		return_ = true;
	}
	return return_;
}

bool ContinueGame(void)
{
	char C_GameContinue = NULL;
	bool B_GameContinue = NULL;
	bool B_valid = false;

	cout << "게임을 다시 시작하겠습니까? (y/n)" << endl;
	while (!B_valid)
	{
		cin >> C_GameContinue;
		B_valid = is_valid_input(C_GameContinue == 'y' || C_GameContinue == 'n');
	}
	if (C_GameContinue == 'y')
	{
		B_GameContinue = true;
		system("cls");
	}
	else if (C_GameContinue == 'n')
	{
		B_GameContinue = false;
	}
	return B_GameContinue;
}

#endif // MYFUNCTIONS_H