#include <list>
#include <vector>
#include <limits>
#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[]) {
	std::vector<int> v;
	std::list<int> l1,l2;
	for (size_t i = 0; i < 10; i++) {
		v.emplace_back(i);
		if(i%2==0)
			l1.emplace_back(i);

			l2.emplace_back(i);
	}

	for (auto &e: l1)
		std::cout << e << '\n';

	for (auto e: l2) {
		std::cout << e << '\n';
		if (e%2==0)
			l2.erase(e)
	}

	for (auto &e: l2)
		std::cout << e << '\n';
	return 0;
}
