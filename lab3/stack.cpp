#include "stdafx.h"
#include <iostream>
#include <string>

int number = -1;
const int threshold = 100;

class Error {
public:
	std::string str;

	Error(std::string text) {
		str = text;
	}
};

size_t qualifier(std::string str) {
	if (str == "add") return 1;
	if (str == "get") return 2;
	if (str == "del") return 3;
}

void add(int* p, int data) {

	if (number >= threshold)
		throw Error("No more place");
	++number;
	p[number] = data;

}

int get(int* p) {
	if (number == -1)
		throw Error("Empty");
	return p[number];
}

void del() {
	if (number == -1)
		throw Error("Empty");
	--number;
}

int main() {
	size_t n;
	int array[threshold];

	std::cin >> n;

	for (size_t i = 0; i < n; i++) {
		int data;

		std::string str;
		std::cin >> str;

		switch (qualifier(str)) {
		case 1:
			std::cin >> data;
			try {
				add(array, data);
			}
			catch (Error& e) {
				std::cout << e.str << std::endl;
			}
			break;
		case 2:
			try {
				std::cout << get(array) << std::endl;
			}
			catch (Error& e) {
				std::cout << e.str << std::endl;
			}
			break;
		case 3:
			try {
				del();
			}
			catch (Error& e) {
				std::cout << e.str << std::endl;
			}
			break;
		}

	}
	system("pause");
	return 0;
}