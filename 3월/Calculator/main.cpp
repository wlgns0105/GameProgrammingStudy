#include <iostream>
using namespace std;
int main()

{
	int num;
	int op;
	int operand;
	bool valid = true;

	cout << "���ڸ� �Է��ϼ���." << endl;
	cin >> num;

	while (true)
	{
		valid = true;
		system("cls");
		cout << "���� ���� " << num << "�Դϴ�\n" << endl;
		cout << "�����ڸ� �����ϼ���." << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ������" << endl;

		cin >> op;

		while (valid)
		{
			switch (op)
			{
				case 1:
					cout << "�ǿ����ڸ� �Է��ϼ���." << endl;
					cin >> operand;
					num = num + operand;
					valid = false;
					break;
				case 2:
					cout << "�ǿ����ڸ� �Է��ϼ���." << endl;
					cin >> operand;
					num = num - operand;
					valid = false;
					break;
				case 3:
					cout << "�ǿ����ڸ� �Է��ϼ���." << endl;
					cin >> operand;
					num = num * operand;
					valid = false;
					break;
				case 4:
					cout << "�ǿ����ڸ� �Է��ϼ���." << endl;
					cin >> operand;
					num = num / operand;
					valid = false;
					break;

				default:
					cout << "�����ڸ� �ٽ� �����ϼ���." << endl;
					cin >> op;
					break;
			}
		}
	}


	system("Pause");
	return 0;

}