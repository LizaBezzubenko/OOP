#pragma once
#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template <class T>
class List {
private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int amount = 0;
public:
	List() {};
	~List();

	//Длина списка
	int size() { return this->amount; }
	void pushHead(T obj);
	void pushTail(T input_object);
	T popHead();
	T popTail();
	T& operator[](int num);
	Node<T>* begin();
	Node<T>* end();
	void sort(int type);
	void output();
	void deleteAll();
};

template<class T>
void List<T>::pushHead(T obj) {
	if (head == nullptr) {
		head = new Node<T>;
		head->data = obj;
		head->next = nullptr;
		tail = head;
		amount++;
	}
	else {
		auto *node = new Node<T>;
		node->data = obj;
		node->next = head;
		head = node;
		amount++;
	}
}

//Добавление в хвост
template<class T>
void List<T>::pushTail(T input_object) {
	if (head == nullptr) {
		head = new Node<T>;
		head->data = input_object;
		head->next = nullptr;
		tail = head;
		amount++;
		return;
	}
	auto *node = new Node<T>;
	node->data = input_object;
	node->next = nullptr;
	tail->next = node;
	tail = node;
	amount++;
}

//Удаление от головы
template<class T>
T List<T>::popHead() {
	if (!(head)) return T();
	T data = head->data;
	Node<T>* node = head;
	if (head != tail) {
		head = head->next;
	}
	else {
		head = tail = nullptr;
	}
	delete node;
	amount--;
	return data;
}

//Удаление из хвоста
template<class T>
T List<T>::popTail() {
	if (!(head)) return T();
	T data = tail->data;
	Node<T> *node = tail;
	if (tail != head) {
		Node<T> * tmp = head;
		while (tmp->next != tail) {
			tmp = tmp->next;
		}
		tail = tmp;
		tail->next = nullptr;
	}
	else {
		head = tail = nullptr;
	}
	delete node;
	amount--;
	return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& List<T>::operator[](int num) {
	Node<T> *curr = head;
	if (num < 0 || num >= amount) return curr->data;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

// Функции для работы с итератором
template<class T>
Node<T>* List<T>::begin() { return head; }

template<class T>
Node<T>* List<T>::end() {
	if (tail != nullptr) return tail->next;
	return tail;
}

// Вывод на экран содержимого списка
template<class T>
void List<T>::output() {
	for (Node<T> *node = head; node != nullptr; node = node->next) {
		std::cout << node->data;
		std::cout << std::endl;
	}
}



template<class T>
List<T>::~List() { while (this->head) { this->popHead(); } }


template<class T>
void List<T>::deleteAll() {
	while (this->head) { this->popHead(); }
}

template<class T>
void List<T>::sort(int type) {
	switch (type) {
	case 1: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getName() > this->operator[](j + d).getName()) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 2: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getName() < this->operator[](j + d).getName()) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 3: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getNumber() > this->operator[](j + d).getNumber()) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 4: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getNumber() < this->operator[](j + d).getNumber()) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 5: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getPrice() > this->operator[](j + d).getPrice()) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 6: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0 && this->operator[](j).getPrice() < this->operator[](j + d).getPrice) {
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 7: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0) {
					T tmp = this->operator[](j);
					T tmp1 = this->operator[](j + d);
					int number1 = tmp.getDate()[0] * 10 + tmp.getDate()[1] + (tmp.getDate()[3] * 10 + tmp.getDate()[4]) * 30 +
						(tmp.getDate()[6] * 1000 + tmp.getDate()[7] * 100 + tmp.getDate()[8] * 10 + tmp.getDate()[9]) * 365;
					int number2 = tmp1.getDate()[0] * 10 + tmp1.getDate()[1] + (tmp1.getDate()[3] * 10 + tmp1.getDate()[4]) * 30 +
						(tmp1.getDate()[6] * 1000 + tmp1.getDate()[7] * 100 + tmp1.getDate()[8] * 10 + tmp1.getDate()[9]) * 365;
					if (number2 >= number1) break;
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	case 8: {
		int d = size() / 2;
		while (d > 0) {
			for (int k = 0; k < size() - d; ++k) {
				int j = k;
				while (j >= 0) {
					T tmp = this->operator[](j);
					T tmp1 = this->operator[](j + d);
					int number1 = tmp.getDate()[0] * 10 + tmp.getDate()[1] + (tmp.getDate()[3] * 10 + tmp.getDate()[4]) * 30 +
						(tmp.getDate()[6] * 1000 + tmp.getDate()[7] * 100 + tmp.getDate()[8] * 10 + tmp.getDate()[9]) * 365;
					int number2 = tmp1.getDate()[0] * 10 + tmp1.getDate()[1] + (tmp1.getDate()[3] * 10 + tmp1.getDate()[4]) * 30 +
						(tmp1.getDate()[6] * 1000 + tmp1.getDate()[7] * 100 + tmp1.getDate()[8] * 10 + tmp1.getDate()[9]) * 365;
					if (number1 >= number2) break;
					T tmp = this->operator[](j);
					this->operator[](j) = this->operator[](j + d);
					this->operator[](j + d) = tmp;
					j--;
				}
			}
			d /= 2;
		}
		break;
	}
	}
}