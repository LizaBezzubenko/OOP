#pragma once

#include <iostream>
#include "MyException.h"

class ListException : public MyException {
public:
	explicit ListException(int code = 0) : MyException(code) {};
	void ErrorText() override;
};

void ListException::ErrorText() {
	std::cout << "������ (��� " << code << "): " << std::endl;
	switch (code) {
	case 1: {
		std::cout << "������ ����" << std::endl;
		break;
	}
	}
}

