#include <vector>
#include <string>
#include <iostream>
struct test{
	std::string str1;
	std::string str2;
};

static std::vector<struct test> v;

int main(int argc, char const *argv[]) {
	struct test t1{"test1","value1"};
	struct test t2{"test2","value2"};

	for (size_t i = 0; i <10 ; i++) {
		if(i%2)
			v.push_back(t1);
		else
			v.push_back(t2);
	}

	std::cout << "size of struct test" << sizeof(struct test)<< '\n';

	for (auto e : v)
		std::cout << "str1:" << e.str1 << " str2:" << e.str2 << '\n';

	struct test t3{"test3",std::string(100, 'x')};
	// replace the v[0] with t3
	v[0] = t3;

	std::cout << "The vector after replace t[0]" << '\n';
	for (auto e : v)
		std::cout << "str1:" << e.str1 << " str2:" << e.str2 << '\n';

	std::cout << "size of struct test" << sizeof(v[0])<< '\n';
	return 0;
}
