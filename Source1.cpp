#pragma once
#include"Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack newStack;
	int choice, x, N;
	bool flag = true;
	while (flag) {
		cout << "1.������� ���� ��������� ���������" << endl;
		cout << "2.����������� ����" << endl;
		cout << "3.������ ������� �����" << endl;
		cout << "4.������� �������" << endl;
		cout << "5.������� ������" << endl;
		cout << "6.C��������� �����" << endl;
		cout << "0.�����" << endl;
		switch (newStack.unnumericInputProtection())
		{
		case 1:
			cout << " ������� ������������ ����� ��������� ������������ ��� ���������� �����" << endl;
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				cin >> newStack;
			}
			break;
		case 2:
			try
			{
				cout << newStack;
			}
			catch (Stack::AnError)
			{
				cout << "� ���� ����!" << endl << endl;
			}
			break;
		case 3:
			cin >> newStack;
			break;
		case 4:
			try
			{
				newStack.Pop();
			}
			catch (Stack::AnError)
			{
				cout << "� ���� ����!" << endl;
			}
			break;
		case 5: newStack.~Stack(); break;
		case 6:
			newStack.ShellSort();
			break;
		case 0:flag = false;
			break;
		default:cout << "������������ ����" << endl;
			break;
		}
	}
	return 0;
}
