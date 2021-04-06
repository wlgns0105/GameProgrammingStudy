#include <iostream>
using namespace std;
int main()

{
	int num;
	int op;
	int operand;
	bool valid = true;

	cout << "숫자를 입력하세요." << endl;
	cin >> num;

	while (true)
	{
		valid = true;
		system("cls");
		cout << "현재 값은 " << num << "입니다\n" << endl;
		cout << "연산자를 선택하세요." << endl;
		cout << "1. 덧셈" << endl;
		cout << "2. 뺄셈" << endl;
		cout << "3. 곱셈" << endl;
		cout << "4. 나눗셈" << endl;

		cin >> op;

		while (valid)
		{
			switch (op)
			{
				case 1:
					cout << "피연산자를 입력하세요." << endl;
					cin >> operand;
					num = num + operand;
					valid = false;
					break;
				case 2:
					cout << "피연산자를 입력하세요." << endl;
					cin >> operand;
					num = num - operand;
					valid = false;
					break;
				case 3:
					cout << "피연산자를 입력하세요." << endl;
					cin >> operand;
					num = num * operand;
					valid = false;
					break;
				case 4:
					cout << "피연산자를 입력하세요." << endl;
					cin >> operand;
					num = num / operand;
					valid = false;
					break;

				default:
					cout << "연산자를 다시 선택하세요." << endl;
					cin >> op;
					break;
			}
		}
	}


	system("Pause");
	return 0;

}