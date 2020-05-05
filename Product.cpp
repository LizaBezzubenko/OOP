#include "Product.h"
#include "InputError.h"
#include <cstring>
Product::Product(const string &name, int number, const char *date, int price) : name(name), number(number),
price(price) {
	strcpy_s(this->date, date);
}

const string &Product::getName() const {
	return name;
}

void Product::setName(const string &name) {
	Product::name = name;
}

int Product::getNumber() const {
	return number;
}

void Product::setNumber(int number) {
	Product::number = number;
}

const char *Product::getDate() const {
	return date;
}

int Product::getPrice() const {
	return price;
}

void Product::setPrice(int price) {
	Product::price = price;
}

ostream &operator<<(ostream &os, const Product &product) {
	os << "name: " << product.name << " number: " << product.number << " date: " << product.date << " price: "
		<< product.price;
	return os;
}

istream &operator>>(istream &is, Product &product) {
	cout << "Write the name of the product: ";
	product.name = string(InputError::inputStringWithoutNumbers());
	cout << "Write the number of the product: ";
	product.number = InputError::Input(0, 100000);
	cout << "Write the receipt date: ";
	char* receiptDate = InputError::inputDate();
	strcpy(product.date, receiptDate);
	cout << "Write the price of the product: ";
	product.price = InputError::Input(0, 100000);
	return is;
}

ofstream &operator<<(ofstream &os, const Product &product) {
	os << product.name << endl;
	os << product.price << " " << product.date << " " << product.number << endl;
	return os;
}

ifstream &operator>>(ifstream &is, Product &product) {
	getline(is, product.name);
	is >> product.price;
	char date[11];
	is >> date;
	strcpy(product.date, date);
	is >> product.number;
	return is;
}

Product read(ifstream &is) {
	int val1; string val2; int val3; char val4[11]; int val5;
	is.read((char*)&val1, sizeof(val1));
	is.read((char*)&val2, val1);
	is.read((char*)&val3, sizeof(val3));
	is.read((char*)&val4, 11);
	is.read((char*)&val5, sizeof(val5));
	return Product(val2, val3, val4, val5);
}

void write(ofstream &os, const Product &product) {
	int val = product.name.size();
	os.write((char*)&(val), sizeof(val));
	os.write((char*)&(product.name), product.name.size());
	os.write((char*)&(product.price), sizeof(product.price));
	os.write((char*)&(product.date), 11);
	os.write((char*)&(product.number), sizeof(product.number));
}
