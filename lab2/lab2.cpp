#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	int i = 1;
	std::string::size_type pos_b, pos_e;
	std::string name, str;
	std::cout << "Enter file name: ";
	std::cin >> name;
	std::ifstream file(name);
	if (!file.is_open())
	{
		std::cout << "File not found" << std::endl;
		system("pause");
		return 1;
	}
	while (getline(file, str))
	{
		pos_b = str.find("/**");
		if (pos_b == std::string::npos)
		{
			continue;
		}
		else
		{
			pos_b = str.find("\\func");
			if (pos_b == std::string::npos)
			{
				getline(file, str);
				pos_b = str.find("\\func");
				pos_e = str.find("*/");
				if (pos_e == std::string::npos)
				{
					std::cout << i << ' ' << str.substr(pos_b + 6) << std::endl;
				}
				else
				{
					std::cout << i << ' ' << str.substr(pos_b + 6, pos_e - (pos_b + 6)) << "\n";
				}
			}
			else
			{
				pos_e = str.find("*/");
				if (pos_e == std::string::npos)
				{
					std::cout << i << ' ' << str.substr(pos_b + 6) << "\n";
				}
				else
				{
					std::cout << i << ' ' << str.substr(pos_b + 6, pos_e - (pos_b + 6)) << "\n";
				}
			}
		}
		++i;
	}
	file.close();
	system("pause");
	return 0;
}