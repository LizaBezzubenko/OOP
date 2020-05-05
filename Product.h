#pragma  once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
private:
	string name;
	int number;
	char date[11];
	int price;
public:
	explicit Product(const string &name = "", int number = 0, const char *date = "", int price = 0);

	const string &getName() const;
	void setName(const string &name);
	int getNumber() const;
	void setNumber(int number);
	const char *getDate() const;
	int getPrice() const;
	void setPrice(int price);

	friend ostream &operator<<(ostream &os, const Product &product);
	friend istream &operator>>(istream &is, Product &product);

	friend ofstream &operator<<(ofstream &os, const Product &product);
	friend ifstream &operator>>(ifstream &is, Product &product);

	friend Product read(ifstream &is);
	friend void write(ofstream &os, const Product &product);
};