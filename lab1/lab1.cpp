#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream ifs1, ifs2;
	ifs1.open("file1.txt");
	string str1, str2;
	int snum = 1;
	while (!ifs1.eof()) {
		getline(ifs1, str1);
		bool suchstring = false;
		ifs2.open("file2.txt");
		while (!ifs2.eof() && !suchstring) {
			getline(ifs2, str2);
			if (str1 == str2) {
				suchstring = true;
			}
		}
		ifs2.close();
		if (!suchstring) cout << "file1.txt " << snum << " " << str1 << endl;
		snum++;
	}
	ifs1.close();

	ifs1.open("file2.txt");
	snum = 1;
	while (!ifs1.eof()) {
		getline(ifs1, str1);
		bool suchstring = false;
		ifs2.open("file1.txt");
		while (!ifs2.eof() && !suchstring) {
			getline(ifs2, str2);
			if (str1 == str2) {
				suchstring = true;
			}
		}
		ifs2.close();
		if (!suchstring) cout << "file2.txt " << snum << " " << str1 << endl;
		snum++;
	}
	ifs1.close();
	system("pause");
	return 0;
}