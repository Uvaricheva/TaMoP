#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

size_t number = 0;

struct Man {
	int age;
	int index;
	Man* pNext;
};

void addFirst(Man*& pF, Man* ptr) {
	ptr->pNext = pF;
	pF = ptr;
	++number;

	Man* p = ptr->pNext;
	while (p) {
		p->index++;
		p = p->pNext;
	}
}

bool add(Man*& pF, Man* ptr) {

	if (ptr->index > number) {
		cout << "There's no index in the List!";
		return 0;
	}

	if (ptr->index == 0) {
		addFirst(pF, ptr);
		return 1;
	}

	Man* p = pF;

	while (p->index != ptr->index && p->index < number - 1)
		p = p->pNext;

	if (number == ptr->index) {
		p->pNext = ptr;
		ptr->pNext = 0;
		++number;
		return 1;
	}

	Man* pPrevious = pF;
	while (pPrevious->pNext != p)
		pPrevious = pPrevious->pNext;

	pPrevious->pNext = ptr;
	ptr->pNext = p;

	while (p) {
		p->index++;
		p = p->pNext;
	}

	++number;
	return 1;
}

bool del(Man*& pF, int id) {

	if (id >= number) {
		cout << "There's no index in the List!";
		return 0;
	}

	if (id == 0) {

		Man* p = pF;
		pF = pF->pNext;
		delete p;
		Man* ptr = pF;

		while (ptr) {
			ptr->index--;
			ptr = ptr->pNext;
		}
		--number;

		return 1;
	}

	Man* pPrev = pF;

	while (pPrev->index + 1 != id) {
		pPrev = pPrev->pNext;
	}

	Man* ptr = pPrev->pNext;
	pPrev->pNext = ptr->pNext;
	delete ptr;

	Man* p = pPrev->pNext;
	while (p) {
		p->index--;
		p = p->pNext;
	}
	--number;
	return 1;
}

bool get(Man*& pF, int id) {

	if (id >= number) {
		cout << "There's no index in the List!";
		return 0;
	}

	Man* ptr = pF;

	while (ptr->index != id) {
		ptr = ptr->pNext;
	}

	cout << ptr->age << endl;
	return 1;
}

void DelAll(Man*& pF) {
	if (pF) {
		Man* p = pF;
		pF = pF->pNext;
		delete p;
		DelAll(pF);
	}
}


int main() {
	Man* pF = 0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "add") {
			int data;
			size_t id;
			cin >> id >> data;

			Man* ptr = new Man;
			ptr->age = data;
			ptr->index = id;

			add(pF, ptr);
		}

		if (str == "get") {
			size_t id;
			cin >> id;
			get(pF, id);
		}

		if (str == "del") {
			size_t id;
			cin >> id;
			del(pF, id);
		}
	}

	DelAll(pF);
	system("pause");
	return 0;
}