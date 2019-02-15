#include <string>
#include <iostream>
#include <regex>

using namespace std;
auto main() -> int
{
	string s = "hello ";

	cout << s << endl;
	s.append("hello", 3);
	cout << s << endl;
	s.clear();

	cout << s << endl;
	cout << s.size() << endl;

	s =  {"Call 737-223-5325 to reach hhh"};
	auto m = smatch{};
	auto r = regex{R"((\d{3})-(\d{3})-(\d{4}))"};
	regex_search(s, m, r);

	for (auto & sub: m)
		std::cout << sub << '\n';
	return 0;
}
