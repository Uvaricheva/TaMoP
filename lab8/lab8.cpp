#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Base {
protected:
	int value;
public:
	virtual void show() = 0;
};
class A : public Base {
public:
	A(int a) {
		value = a;
	}
	void show() { cout << "class A: " << value << endl; }
};
class B : public Base {
public:
	B(int a) {
		value = a;
	}
	void show() { cout << "class B: " << value << endl; }
};
class C : public Base {
public:
	C(int a) {
		value = a;
	}
	void show() { cout << "class C: " << value << endl; }
};

class Functor {
public:
	virtual void operator() (vector<Base*> &vec) {};
};
class FbShow {
public:
	FbShow() {};
	void showall(vector<Base*> &vec) {
		for (int i = 0; i < vec.size(); i++) {
			vec[i]->show();
		}
	}
};
class FrAddA : public Functor {
	int value;
public:
	FrAddA() {};
	void operator() (vector<Base*> &vec) {
		cin >> value;
		vec.push_back(new A(value));
	}
};
class FrAddB : public Functor {
	int value;
public:
	FrAddB() {};
	void operator() (vector<Base*> &vec) {
		cin >> value;
		vec.push_back(new B(value));
	}
};
class FrAddC : public Functor {
	int value;
public:
	FrAddC() {};
	void operator() (vector<Base*> &vec) {
		cin >> value;
		vec.push_back(new C(value));
	}
};

int main() {
	map<string, Functor*> mp;
	Functor *fra = new FrAddA;
	Functor *frb = new FrAddB;
	Functor *frc = new FrAddC;
	mp["create A"] = fra;
	mp["create B"] = frb;
	mp["create C"] = frc;
	FbShow fbs;
	int num;
	string s;
	cout << "Number of commands: ";
	cin >> num;
	vector<Base*> vec;
	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "create") {
			string str;
			cin >> str;
			s += " ";
			s += str;
		}
		Functor *f = mp[s];
		if (f) (*f)(vec);
		if (s == "showall") {
			fbs.showall(vec);
		}
	}
	system("pause");
	return 0;
}