#include "stdafx.h"
#include <iostream>
#include <string>

const int threshold = 100;
int top = -1, bottom = -1;
size_t length = 0;


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

	if (length >= threshold)
		throw Error("No  more place");

	if (bottom == threshold - 1) bottom = 0;
	else ++bottom;

	if (top == -1) top++;

	p[bottom] = data;
	length++;
}

int get(int* p) {

	if (!length)
		throw Error("Empty");

	return p[top];
}

void del() {

	if (!length)
		throw Error("Empty");

	if (length == 1) {
		bottom = -1;
		top = -1;
	}
	else
		if (top == threshold - 1 && length < threshold) {
			top = 0;
		}
		else {
			++top;
		}
		--length;
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