#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;


int getroot(vector<int> v)
{
	for (unsigned i = 0; i < v.size(); i++)
		if (v.at(i) == -1) return i;
	return -1;
}


int getleftson(vector<int> v, int nod)
{
	for (unsigned i = 0; i < v.size(); i++)
		if (v.at(i) == nod) return i;
	return -1;
}


int getanc(vector<int> v, int nod)
{
	return v.at(nod);
}


int getrightbro(vector<int> v, int nod)
{
	int anc = getanc(v, nod);
	for (unsigned i = (nod + 1); i < v.size(); i++)
		if (v.at(i) == anc) return i;
	return -1;
}


int getsonnum(vector<int> v, int nod)
{
	int num = 0;
	for (unsigned i = 0; i < v.size(); i++)
		if (v.at(i) == nod) num++;
	return num;
}


void _str(vector<int> v, int nod)
{
	cout << nod << " ";
	int num = getsonnum(v, nod);
	if (num == 0) return;
	int l = getleftson(v, nod);
	_str(v, l);
	for (int i = 0; i < (num - 1); i++)
	{
		_str(v, getrightbro(v, l));
		l = getrightbro(v, l);
	}
}


void straight(vector<int> v)
{
	_str(v, getroot(v));
	cout << endl;
}


void _back(vector<int> v, int nod)
{
	int num = getsonnum(v, nod);
	if (num == 0)
	{
		cout << nod << " ";
		return;
	}
	int l = getleftson(v, nod);
	_back(v, l);
	for (int i = 0; i < (num - 1); i++)
	{
		_back(v, getrightbro(v, l));
		l = getrightbro(v, l);
	}
	cout << nod << " ";
}


void back(vector<int> v)
{
	_back(v, getroot(v));
	cout << endl;
}


void _sym(vector<int> v, int nod)
{
	int num = getsonnum(v, nod);
	if (num == 0)
	{
		cout << nod << " ";
		return;
	}
	int l = getleftson(v, nod);
	_sym(v, l);
	cout << nod << " ";
	for (int i = 0; i < (num - 1); i++)
	{
		_sym(v, getrightbro(v, l));
		l = getrightbro(v, l);
	}
}


void symmetric(vector<int> v)
{
	_sym(v, getroot(v));
	cout << endl;
}


int main()
{
	int x, n = 0;
	cout << "Enter N:" << endl;
	cin >> n;
	vector<int> v;
	cout << "Enter cursors array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	straight(v);
	back(v);
	symmetric(v);
	system("pause");
	return 0;
}
