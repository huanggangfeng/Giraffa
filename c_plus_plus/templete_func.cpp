#include <iostream>
#include <string>

using namespace std;
template <typename T>
inline T const& Max(T const &a, T const &b) 
{
	return a > b ? a:b;
}

int main(int argc, char const *argv[])
{
	int i = 39, j = 20;
	cout << "Max(i,j): " << Max(i, j) << std::endl;
	double x = 10.5, y = 10.49;
	cout << "Max(i,j): " << Max(x, y) << std::endl;
	return 0;
}