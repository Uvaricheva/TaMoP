#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "switch.h"

__interface InterfaceQueue
{
	void create(const std::size_t size);
	void add(const int data);
	int get() const;
	void del();
};

int main()
{
	init_switch();
	std::wstring libName;
	std::wcin >> libName;
	LPCWSTR wLibName = libName.c_str();
	HINSTANCE lib = LoadLibrary(wLibName);
	if (!lib) {
		std::cout << "Library has not been found\n";
		system("pause");
		return 0;
	}
	std::size_t n;
	std::cin >> n;
	std::string enter;
	std::vector<int> out;
	InterfaceQueue *(*getQueue)() = (InterfaceQueue *(*)())GetProcAddress(lib, "GetIQueue");
	if (!getQueue)
		return 0;
	InterfaceQueue *pQueue = getQueue();
	if (!pQueue)
		return 0;
	pQueue->create(10);
	for (std::size_t i = 0; i < n; ++i)
	{
		std::cin >> enter;
		switch (cmd_map[enter])
		{
		case add:
			int value;
			std::cin >> value;
			pQueue->add(value);
			break;
		case get:
			out.push_back(pQueue->get());
			break;
		case del:
			pQueue->del();
			break;
		}
	}
	for (auto a : out)
		std::cout << a << std::endl;
	FreeLibrary(lib);
	system("pause");
	return 0;
}