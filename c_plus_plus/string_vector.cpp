#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int test1()
{
	std::vector<int> v;

	for (int i = 0; i < 10 ; ++i)
	{
		v.push_back(i);
	}

	for (auto it = std::begin(v); it != std::end(v); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

int main()
{
	std::vector<std::string> myVector;
	for (int i = 0; i < 10; ++i)
	{
		std::string str = std::to_string(i);
		myVector.push_back(str);
	}

	for (auto it = std::begin(myVector); it != std::end(myVector); ++it)
	{
		std::cout << ' ' << *it;
	}

	std::cout << std::endl;

	test1();
	return 0;
}
