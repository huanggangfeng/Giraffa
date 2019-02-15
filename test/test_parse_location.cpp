#include <string>
#include <iostream>

using namespace std;

int main()
{
		std::string s = "https://oss-cn-shanghai.aliyuncs.com";
		std::string::size_type n = s.find("oss-");
		std::string::size_type n2 = s.find(".aliyuncs.com");
		std::cout << n << "\n" << n2 << "\n";
		string substr = s.substr(n,n2-n);
		std::cout << substr << "\n";
		return 0;
}
