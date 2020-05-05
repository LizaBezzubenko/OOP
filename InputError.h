#pragma once

#include <iostream>
#include <string>
#include "MyException.h"
using namespace std;
class InputError : public MyException {
public:
	InputError(int code = 0) : MyException(code) {};

	void ErrorText() override {
		cout << "Ошибка ввода (код " << this->code << "): ";
		switch (this->code) {
		case 1: {
			cout << "Введён недопустимый символ." << endl;
			cout << "Ввод любых символов, кроме цифр, запрещён." << endl;
			break;
		}
		case 2: {
			cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!" << endl;
			break;
		}
		default:
			cout << "Повторите ввод" << endl;
			break;
		}
	}

	static int Input(int min, int max) {
		bool flag = true;
		int value;
		do {
			try {
				cin.sync();
				cin.clear();
				rewind(stdin);
				cin >> value;
				flag = true;
				if (!cin || cin.peek() != '\n') {
					flag = false;
					throw InputError(2);
				}
				if (value < min || value > max) {
					flag = false;
					throw "Limit error";
				}
			}
			catch (InputError e) {
				rewind(stdin);
				e.ErrorText();
				cin.sync();
				cin.clear();
			}
			catch (...) {
				rewind(stdin);
				cin.sync();
				cin.clear();
				cout << "Введено некорректное значение. Необходимо ввести значение в диапазоне (" << min << ","
					<< max << ")." << endl;
			}
		} while (!flag);
		return value;
	}

	static int InputNumber() {
		int input;
		try {
			rewind(stdin);
			cin.sync();
			cin.clear();
			cin >> input;
			if (!cin || cin.peek() != '\n') {
				throw InputError(2);
			}
		}
		catch (InputError e) {
			e.ErrorText();
			cin.clear();
			cin.sync();
			input = InputNumber();
		}
		rewind(stdin);
		return input;
	}

	static char *inputStringWithoutNumbers() {
		rewind(stdin);
		char input;
		char *buffer = new char[20];
		int i = 0;
		bool flag = true;
		while (flag) {
			try {
				input = cin.get();
				if (input != '\n' && (input < 'a' || input > 'z') && (input < 'A' || input > 'Z')) {
					throw (InputError(4));
				}
				if (input == '\n') {
					input = '\0';
					flag = false;
				}
				buffer[i] = input;
				i++;
			}
			catch (InputError e) {
				rewind(stdin);
				e.ErrorText();
				cin.clear();
				cin.sync();
			}
		}
		return buffer;
	}

	static char *inputDate() {
		rewind(stdin);
		char input;
		char *buffer = new char[11];
		int i = 0;
		bool flag = true;
		while (i != 10) {
			try {
				input = cin.get();
				switch (i) {
				case 0: {
					if (input < '0' || input > '3') throw (InputError(4));
					break;
				}
				case 1:
				case 4:
				case 6:
				case 7:
				case 8:
				case 9: {
					if (input < '0' || input > '9') throw (InputError(4));
					break;
				}
				case 2:
				case 5: {
					if (input != '.') throw (InputError(4));
					break;
				}
				case 3: {
					if (input != '1' && input != '0') throw (InputError(4));
					break;
				}
				}
				if (i == 4 && buffer[0] == '3' && buffer[3] == '0' && input == '2') throw (InputError(4));
				if (i == 4 && buffer[3] == '1' && input > '2') throw (InputError(4));
				buffer[i] = input;
				i++;
			}
			catch (InputError e) {
				rewind(stdin);
				e.ErrorText();
				cin.clear();
				cin.sync();
			}
		}
		buffer[10] = '\0';
		return buffer;
	}
};

