#include <list>
``#include <vector>
#include <iostream>

using namespace std;

int main() {
	auto v = std::vector<int> {1,2,3,4,5};
	auto c = list<int>{std::begin(v), std::end(v)};

	// for (auto &e : c)
	// std::cout << e << '\n';
	c.insert(c.end(),6);

	c.emplace_back(7);
	c.emplace_front(0);
	c.emplace(begin(c), -1);

	c.remove(3);
	// Remove odd numbers
	c.remove_if([](int a){return a%2==0;});
	// c.erase(std::find(begin(c), end(c), 3));
	// c.erase(std::find(c, 2), std::find(c,4));
	for (auto &e : c)
		std::cout << e << '\n';

	std::list<int> list1{1,3,5,7};
	std::list<int> list2{2,4,6,8,10};

	list1.splice(list1.begin(), list2, list2.begin(), list2.end());

	std::cout << "list1 after splice" << '\n';
	for (auto &e : list1)
		std::cout << e << '\n';

	return 0;
}
