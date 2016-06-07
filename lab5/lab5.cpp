#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

class Error {
	std::string inf;
public:
	Error(std::string str) {
		inf = str;
	}
	std::string what() {
		return inf;
	}
};


class Tree {
	std::vector<int> tree;
	public:
		Tree() {};
		void add(int num);
		int get() const;
		void del();
		~Tree() {};
};
 
void Tree::add(int num) {
	tree.push_back(num);
	int i = tree.size() - 1;
	for (int j = tree.size() - 2; j >= 0; j--) {
		if (tree[i] < tree[j]) {
			int change = tree[i];
			tree[i] = tree[j];
			tree[j] = change;
			i--;
		}
	}

}

int Tree::get() const{
	if (tree.empty()) throw Error("Tree is empty");
	else return tree[0];
}

void Tree::del() {
	if (tree.empty()) throw Error("Tree is empty");
	tree.erase(tree.begin());
	for (size_t i = tree.size() - 1; i > 1; i--) {
		if (tree[i] < tree[i - 1]) {
			int change = tree[i];
			tree[i] = tree[i-1];
			tree[i-1] = change;
		}
	}
}

int main() {
	try {
		Tree Main;
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::string str;
			std::cin >> str;
			if (str == "add") {
				int num;
				std::cin >> num;
				Main.add(num);
			}
			if (str == "get") {
				std::cout << Main.get() << '\n';
			}
			if (str == "del") {
				Main.del();
			}
		}
	}
	catch (Error& e) {
		std::cout << e.what();
	}
	
	system("pause");
	return 0;
}