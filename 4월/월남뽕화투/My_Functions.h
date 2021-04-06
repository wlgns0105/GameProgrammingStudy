#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#pragma once

#include <iostream>

using namespace std;


bool not_valid_input(bool Condition)
{
	bool return_ = NULL;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "��ȿ�� �Է� ������ �ƴմϴ�." << endl;
		return_ = true;
	}
	else if (Condition)
	{
		return_ = true;
		cout << "��ȿ�� �Է� ������ �ƴմϴ�." << endl;
	}
	else
	{
		return_ = false;
	}
	if (return_)
	{
		cout << "�ٽ� �Է����ּ���" << endl;
	}
	return return_;
}

bool ContinueGame(void)
{
	char C_GameContinue = NULL;
	bool B_GameContinue = NULL;
	bool B_not_valid = true;

	cout << "������ �ٽ� �����ϰڽ��ϱ�? (y/n)" << endl;
	while (B_not_valid)
	{
		cin >> C_GameContinue;
		B_not_valid = not_valid_input(C_GameContinue != 'y' && C_GameContinue != 'n');
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