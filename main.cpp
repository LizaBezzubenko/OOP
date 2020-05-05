#include <iostream>
#include "List.h"
#include "Product.h"
#include "InputError.h"
#include "ListException.h"

int main() {
	List<Product> list;
	int input;
	while (true) {
		cout << "Choose the variant:\n"
			"1. Add the product\n"
			"2. Delete last product\n"
			"3. Read the text file with the products\n"
			"4. Write the products to the text file\n"
			"5. Output the list of products\n"
			"6. Complete the task\n"
			"7. Sort\n"
			"8. Exit\n";
		input = InputError::Input(1, 8);
		switch (input) {
		case 1: {
			Product product;
			cin >> product;
			list.pushTail(product);
			break;
		}
		case 2: {
			if (list.size() < 1) {
				throw ListException(1);
			}
			else {
				list.popTail();
			}
			break;
		}
		case 3: {
			if (list.size() > 0) {
				list.deleteAll();
			}
			ifstream in;
			in.open("products.txt");
			if (!in.is_open()) {
				cout << "We can't open the file!" << endl;
				break;
			}
			while (EOF) {
				Product product;
				in >> product;
				if (product.getName().empty()) break;
				list.pushTail(product);
				in.get();
			}
			break;
		}
		case 4: {
			if (list.size() < 1) {
				throw ListException(1);
			}
			else {
				ofstream on("products.txt");
				for (Node<Product>* tmp = list.begin(); tmp; tmp = tmp->next) {
					on << tmp->data;
				}
			}
			break;
		}
		case 5: {
			if (list.size() < 1) {
				throw ListException(1);
			}
			else {
				list.output();
			}
			break;
		}
		case 6: {
			if (list.size() < 1) {
				throw ListException(1);
			}
			else {
				int numberOfDays, price;
				char *today;
				cout << "Write the date of today: ";
				today = InputError::inputDate();
				cout << "Write the numbers of the day: ";
				numberOfDays = InputError::Input(0, 1000000);
				cout << "Write the price: ";
				price = InputError::Input(0, 1000000);
				List<Product> taskList;
				for (Node<Product> *tmp = list.begin(); tmp; tmp = tmp->next) {
					int number1 = tmp->data.getDate()[0] * 10 + tmp->data.getDate()[1] +
						(tmp->data.getDate()[3] * 10 + tmp->data.getDate()[4]) * 30 +
						(tmp->data.getDate()[6] * 1000 + tmp->data.getDate()[7] * 100 +
							tmp->data.getDate()[8] * 10 + tmp->data.getDate()[9]) * 365 +
						numberOfDays;

					int number2 = today[0] * 10 + today[1] + (today[3] * 10 + today[4]) * 30 +
						(today[6] * 1000 + today[7] * 100 + today[8] * 10 + today[9]) * 365;
					if (number1 > number2 && price < tmp->data.getPrice()) {
						taskList.pushTail(tmp->data);
					}
				}
				taskList.sort(1);
				taskList.output();
				break;
			}
		}
		case 7: {
			if (list.size() < 1) {
				throw ListException(1);
			}
			else {
				list.output();
				cout << "\nChoose the variant to sort:\n"
					"1. Name (High)\n"
					"2. Name (Low)\n"
					"3. Number (High)\n"
					"4. Number (Low)\n"
					"5. Price (High)\n"
					"6. Price (Low)\n"
					"7. Date (High)\n"
					"8. Date (Low)\n\n\n";
				int type = InputError::Input(1, 8);
				list.sort(type);
				list.output();
				break;
			}
		}
		case 8: {
			return 0;
		}
		}
	}
	return 0;
}
