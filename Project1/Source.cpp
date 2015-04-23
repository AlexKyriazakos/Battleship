#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<int, std::map<int, std::string>> m;

	m[1][3] = "Hello";

	std::cout << m[1][3] << std::endl;

	return 0;
}